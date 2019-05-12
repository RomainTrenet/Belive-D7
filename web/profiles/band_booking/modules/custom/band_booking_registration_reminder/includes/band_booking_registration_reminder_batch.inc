<?php

/**
 * @file
 * The registration relaunch batch functions.
 */

/**
 * Setup batch and operations to perform. We create a list of batch operations.
 *
 * @param bool $progressive
 *   Display progressive bar or not.
 * @param int $nid
 *   The node id specified or not.
 * @param bool $is_today
 *   Is the current day or not.
 * @param int $timestamp
 *   Date specified or not.
 * @param string $redirect
 *   Redirect path.
 */
function _band_booking_registration_reminder_setup_batch($progressive = FALSE, $nid = NULL, $is_today = TRUE, $timestamp = NULL, $redirect = NULL) {
  // Ensure timestamp, get one if is today.
  $timestamp = _bbr_ensure_reminder_timestamp($timestamp, $is_today);

  // Manual = progressive.
  $manual = $progressive;

  // Batch declaration.
  $batch_definition = array(
    // Declare operations.
    'file' => drupal_get_path('module', 'band_booking_registration_reminder') . '/includes/band_booking_registration_reminder_batch.inc',
    'operations' => array(
      array(
        '_band_booking_registration_reminder_batch_process',
        array(
          $manual,
          $nid,
          $timestamp,
        ),
      ),
    ),
    'finished' => '_band_booking_registration_reminder_batch_finished',
    'title' => t('Band booking relaunch batch'),
    'init_message' => t('Initialization of band booking relaunches'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('An error occurred trying to relaunch band booking registrations'),
  );

  // Batch initialization.
  batch_set($batch_definition);
  $batch_definition =& batch_get();

  // Add progress bar if batch is launched manualy.
  $batch_definition['progressive'] = $progressive;

  // Manage redirect.
  if (isset($nid)) {
    $redirect = 'node/' . $nid;
  }

  // Finally process batch and redirect to admin.
  batch_process($redirect);

  //return('<p>Uncomment that line to have a page view with dpm.</p>');
}

/**
 * Setup batch and operations to perform. We create a list of batch operations.
 *
 * @param bool $manual
 *   Is manual action or not.
 * @param int $nid
 *   The node id specified or not.
 * @param int $timestamp
 *   Date specified or not.
 * @param array $context
 *   The context variables.
 */
function _band_booking_registration_reminder_batch_process($manual = FALSE, $nid = NULL, $timestamp = NULL, array &$context = array()) {


  watchdog(WATCHDOG_DEBUG, 'ROMAINNNN');


  // Init the batch.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_rid'] = 0;

    // Record amount of results.
    $context['sandbox']['max'] = _bbrr_get_reminder_amount($nid, $timestamp);
  }

  // If there are results, batch the operations.
  if ($context['sandbox']['max'] > 0) {
    // Get list of reminders.
    $reminders = _bbrr_get_reminder_list($nid, $timestamp, $context);

    foreach ($reminders as $reminder) {
      // Send mail.
      _bbr_send_mail($reminder, $manual);

      // Record state.
      $context['sandbox']['progress']++;
      $context['sandbox']['current_rid'] = $reminder->registration_id;
    }

    // Record .
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
}

/**
 * Get the reminder common query part.
 *
 * @param int $nid
 *   The node id specified or not.
 * @param int $timestamp
 *   Is the current day or not.
 *
 * @return \SelectQuery
 *   The common query part.
 */
function _bbr_get_common_reminder_query($nid = NULL, $timestamp = NULL) {
  // Select tables.
  $query = db_select('users', 'u');
  $query->join('registration', 'r', 'r.user_uid = u.uid');
  $query->join('node', 'n', 'n.nid = r.entity_id');

  // Check if User and Node are active, and registration is waiting.
  $query
    ->condition('u.status', 1, '=')
    ->condition('n.status', 1, '=')
    ->condition('r.state', WAITING_SYSTEM_NAME, '=');

  // If timestamp is set, filter by daily relaunches.
  if (isset($timestamp) && is_numeric($timestamp)) {
    $query->join('field_data_field_relaunch', 'dr', 'dr.entity_id = n.nid');
    $min_day = date(REMINDER_DATE_FORMAT, $timestamp);
    $max_day = date(REMINDER_DATE_FORMAT, strtotime('+1 day', $timestamp));
    $query->condition('dr.field_relaunch_value', $min_day, '>=')
      ->condition('dr.field_relaunch_value', $max_day, '<');
  }

  // If nid specified, filter by node id, to.
  isset($nid) && is_numeric($nid) ? $query->condition('n.nid', $nid, '=') : NULL;

  // Return result query.
  return $query;
}

/**
 * Get the reminder amount.
 *
 * @param int $nid
 *   The node id specified or not.
 * @param int $timestamp
 *   Is the current day or not.
 *
 * @return int
 *   The amount of reminder to send.
 */
function _bbrr_get_reminder_amount($nid = NULL, $timestamp = NULL) {
  // Get the common query.
  $query = _bbr_get_common_reminder_query($nid, $timestamp);
  // Only the registration id is needed.
  $query->fields('r', array('registration_id'));

  // Execute and return amount.
  return $query->execute()->rowCount();
}

/**
 * Get the reminder list.
 *
 * @param int $nid
 *   The node id specified or not.
 * @param int $timestamp
 *   Is the current day or not.
 * @param array $context
 *   The context variables.
 *
 * @return array
 *   The reminder list.
 */
function _bbrr_get_reminder_list($nid, $timestamp, array &$context) {
  // Get the common query.
  $query = _bbr_get_common_reminder_query($nid, $timestamp);

  // Limit is set in the begining of the .module file.
  $limit = BATCH_LIMIT;

  $query->join('field_data_field_mail_content', 'mc', 'mc.entity_id = n.nid');
  $query->join('field_data_field_objet_du_mail', 'mo', 'mo.entity_id = n.nid');

  // Check if user and node are active, and registration is waiting.
  $query->fields('u', array('uid', 'name', 'mail'))
    ->fields('r', array('registration_id'))
    ->fields('n', array('nid', 'title'))
    ->fields('mc', array('field_mail_content_value'))
    ->fields('mo', array('field_objet_du_mail_value'));

  $query->range($context['sandbox']['progress'], $limit);

  // Execute and return.
  return $query->execute()->fetchAllAssoc('registration_id');
}

/**
 * Send mail for remind.
 *
 * @param object $reminder
 *   The curent remind.
 * @param bool $manual
 *   Is manual action or not.
 */
function _bbr_send_mail($reminder, $manual) {
  // Prepare mail parts.
  $node = node_load($reminder->nid);
  $user = user_load($reminder->uid);
  $subject = token_replace($reminder->field_objet_du_mail_value, array('node' => $node));
  $body = token_replace($reminder->field_mail_content_value, array('node' => $node, 'user' => $user));
  $to = $reminder->mail;
  $from = variable_get('site_mail', '');

  // @todo : remove.
  $to = 'romain.trenet@gmail.com';

  // Send out the e-mail.
  $message = array(
    'headers' => array(
      'MIME-Version' => '1.0',
      'Content-Type' => 'text/html;',
    ),
    'module' => 'band_booking_registration_reminder',
    'key' => '',
    'to' => $to,
    'from' => $from,
    'subject' => $subject,
    'body' => $body,
  );
  $message = mimemail_prepare_message($message);

  // Prepare log.
  global $base_url;
  global $base_path;
  $perf_path = $base_url . $base_path . 'node/' . $reminder->nid;

  // Try to send mail with mimemail.
  try {
    mimemail_mailengine('send', $message);
    $log_text = t('Reminder sent to @name for performance <a href="@perf_path" target="_blank">@perf_name</a>', array(
      '@name' => $reminder->name,
      '@perf_path' => $perf_path,
      '@perf_name' => $reminder->title,
    ));
    $success = TRUE;
  }
  catch (Exception $e) {
    $log_text = t('Could not send reminder to @name for performance  <a href="@perf_path" target="_blank">@perf_name</a>', array(
      '@name' => $reminder->name,
      '@perf_path' => $perf_path,
      '@perf_name' => $reminder->title,
    ));
    $success = FALSE;
  }

  // Log result.
  band_booking_base_log($log_text, $success, $manual);
}

/**
 * The batch finish handler.
 * @ todo
 * @param $success
 * @param $results
 * @param $operations
 */
function _band_booking_registration_reminder_batch_finished($success, $results, $operations) {
  dpm($success);
  dpm($results);
  dpm($operations);

  if ($success) {
    drupal_set_message(t('Relaunch proceeding succesfully applied'));
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
  //@todo : path.
  drupal_set_message(l(t('Run again'), 'my_module/batch_fix'));
}
