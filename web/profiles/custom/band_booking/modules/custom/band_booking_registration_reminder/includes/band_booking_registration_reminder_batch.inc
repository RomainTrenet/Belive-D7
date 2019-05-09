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
 */
function _band_booking_registration_reminder_setup_batch($progressive = FALSE, $nid = NULL, $is_today = TRUE, $timestamp = NULL) {
  // Ensure timestamp.
  $timestamp = _bbr_ensure_reminder_timestamp($timestamp, $is_today);

  // Batch declaration.
  $batch_definition = array(
    // Declare operations.
    'operations' => array(
      array(
        '_band_booking_registration_reminder_batch_process',
        array($progressive, $nid, $is_today, $timestamp),
      ),
    ),
    'finished' => 'band_booking_registration_reminder_batch_finished',
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

  // Finally process batch and redirect to admin.
  batch_process(REMINDER_ADMIN_PAGE);

  //return('<p>Uncomment that line to have a page view with dpm.</p>');
}

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
 */
function _band_booking_registration_reminder_batch_process($progressive = FALSE, $nid = NULL, $is_today = TRUE, $timestamp = NULL, &$context = array()) {
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
      _bbr_send_mail($reminder, $progressive);

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

function _bbr_send_mail ($reminder, $progressive) {
  // Prepare mail parts.
  $node = node_load($reminder->nid);
  $user = user_load($reminder->uid);
  $subject = token_replace($reminder->field_objet_du_mail_value, array('node' => $node));
  $body = token_replace($reminder->field_mail_content_value, array('node' => $node, 'user' => $user));
  $to = $reminder->mail;
  $from = variable_get('site_mail', '');

  // @TODO if manual : drupal set message; if auto = send mail.
  // @todo : remove.
  $to = 'romain.trenet@gmail.com';

  // Send out the e-mail.
  $message = array(
    'headers' => array(
      'MIME-Version' => '1.0',
      'Content-Type' => 'text/html;',
      // 'multipart/mixed;'.
    ),
    'module' => 'band_booking_registration_reminder',
    'key' => '',
    'to' => $to,
    'from' => $from,
    'subject' => $subject,
    'body' => $body,
  );
  $message = mimemail_prepare_message($message);

  // Send mail with mimemail.
  if (mimemail_mailengine('send', $message)) {
    global $base_url;
    global $base_path;

    // @todo : use t().
    drupal_set_message('Relance envoyée à '.$reminder->name .' pour la prestation ' .l($reminder->title, $base_url . $base_path . 'node/'.  $reminder->nid, $options = array()));

    // If manual, print message.
    if ($progressive) {
      // If auto (cron), send mail to site.
    } else {
      // @todo.
      //Send mail to website email and set message to website
      //watchdog('Belive relaunch', 'Bonjour,<br>Relance effectuée à '.$reminder->name .' pour la prestation ' .l($reminder->title, $base_url . $base_path . 'node/'.  $reminder->nid, $options = array()));
    }
  }
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

  // Check if User and Node are active, and registration is waiting.
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
 * Get the common reminder query part.
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

/*
function _bbr_send_mail ($result, $progressive, &$context) {
  while ($relaunch = $result->fetchObject()) {
    // Treatment of the batch.
    // Send mail.
    $node = node_load($relaunch->nid);
    $user = user_load($relaunch->uid);
    $subject = token_replace($relaunch->field_objet_du_mail_value, array('node' => $node));
    $message = token_replace($relaunch->field_mail_content_value, array('node' => $node, 'user' => $user));
    $to = $relaunch->mail;
    $from = variable_get('site_mail', '');

    $params = array(
      'body' => $message,
      'subject' => $subject,
    );

    // TODO if manual : drupal set message; if auto = send mail.

    // @todo : remove.
    $to = 'romain.trenet@gmail.com';

    if (drupal_mail('band_booking_registration_reminder_', 'send_relaunch_mail', $to, language_default(), $params, $from, TRUE)) {
      global $base_url;
      global $base_path;

      // If manual, print message.
      if ($progressive) {
        //
        drupal_set_message('Relance envoyée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()));
        // If auto (cron), send mail to site.
      } else {
        //Send mail to website email and set message to website
        //$body = 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation <a href="' .$base_url . $base_path . 'node/'.  $relaunch->nid . '">' . $relaunch->title . '</a>.';
        //$body = '<html><body>Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()) . '.</body></html>';

        //$params_mail_website = array(
          //'body' => $body,
          //'subject' => 'Relance effectuée à '.$relaunch->name .' pour la prestation ' . $relaunch->title,
        //);
        //drupal_mail('band_booking_registration_reminder_', 'send_relaunch_mail', $from, language_default(), $params_mail_website, $from, TRUE);
        //watchdog('Belive relaunch', 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()));
      }
    }
    else {
      drupal_set_message("Une erreur s'est produite lors de l'envoi de votre email");
    }

    //Increment progress and record current subscription id.
    $context['sandbox']['progress']++;
  }

  //If batch is not at the end, record progress (use for percentage of progression)
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}
*/

/**
 * The batch finish handler.
 * @ todo
 * @param $success
 * @param $results
 * @param $operations
 */
function band_booking_registration_reminder_batch_finished($success, $results, $operations) {
  //dpm($results);
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
  drupal_set_message(l(t('Run again'), 'my_module/batch_fix'));
}
