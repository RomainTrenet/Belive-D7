<?php

/**
 * @file
 * The registration relaunch batch functions.
 */

/**
 *
 *
 * @param int $nid
 *
 * @param bool $progressive
 *   Used to display progressive bar or not.
 * @param date $timestamp
 *   Is.
 */

/**
 * Setup batch and operations to perform. We create a list of batch operations.
 *
 * @param bool $progressive
 *   Used to display progressive bar or not.
 * @param null $nid
 *   The node id for which relaunch registrations.
 * @param bool $today
 *   Is the current day or not.
 */
function _band_booking_registration_reminder_setup_batch($progressive = FALSE, $nid = NULL, $is_today = TRUE, $timestamp = NULL) {

  //$timestamp = time();
  //$timestamp = 1525273200;
  //$timestamp = 'truc';
  //$timestamp = NULL;
  //$today = time();
  $is_today = FALSE;
  //$nid = 424;

  dpm('ts avant : ' . $timestamp);
  //dpm('today : ' . $today);

  // Ensure timestamp.
  $timestamp = _bbr_ensure_reminder_timestamp($timestamp, $is_today);

  dpm('ts après : ' . $timestamp);

  // Batch declaration.
  $batch = array(
    // Declare operations.
    'operations' => array(
      array(
        '_band_booking_registration_reminder_batch_process',
        array($progressive, $nid, $is_today, $timestamp),
      ),
    ),
    'finished' => 'band_booking_registration_reminder_finished_method',
    // @todo : title.
    'title' => t('Band booking relaunch batch'),
    'init_message' => t('Initialization of band booking relaunches'),
    // @todo.
    // 'progress_message' => t(''),.
    'error_message' => t('An error occurred trying to relaunch band booking registrations'),
  );

  // Batch initialization.
  batch_set($batch);
  $batch =& batch_get();

  // Add progress bar if batch is launched manualy.
  $batch['progressive'] = $progressive;

  // Finally process batch.
  batch_process();

  return('<p>Uncomment that line to have a page view with dpm.</p>');
}

/**
 * Get the reminder amount.
 *
 * @param int $nid
 *   The node id for which relaunch registrations.
 * @param int $timestamp
 *   Is the current day or not.
 *
 * @return int
 *   The amount of reminder to send.
 */
function _bbrr_get_reminder_amount($nid = NULL, $timestamp = NULL) {
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

  // Only the registration id is needed.
  $query->fields('r', array('registration_id'));

  // Execute and return amount.
  return $query->execute()->rowCount();
}

function _band_booking_registration_reminder_batch_process($progressive = FALSE, $nid = NULL, $is_today = TRUE, $timestamp = NULL, &$context = array()) {
  // Init the batch.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;

    // Record amount of results.
    $row_count = _bbrr_get_reminder_amount($nid, $timestamp);
    $context['sandbox']['max'] = $row_count;
    dpm('Résultats : ' . $row_count);
  }
  return;

  // @todo : if max exist.
  // If there are results, batch the operations.
  if ($context['sandbox']['max'] > 0) {

    // Limit is set in the begining of the .module file.
    $limit = BATCH_LIMIT;

    $query = db_select('users', 'u');
    $query->join('registration', 'r', 'r.user_uid = u.uid');
    $query->join('node', 'n', 'n.nid = r.entity_id');
    $query->join('field_data_field_mail_content', 'mc', 'mc.entity_id = n.nid');
    $query->join('field_data_field_objet_du_mail', 'mo', 'mo.entity_id = n.nid');

    $query->fields('u', array('uid', 'name', 'mail'))
      ->fields('r', array('registration_id'))
      ->fields('n', array('nid', 'title'))
      ->fields('mc', array('field_mail_content_value'))
      ->fields('mo', array('field_objet_du_mail_value'))

      ->condition('u.status', 1, '=')
      ->condition('n.status', 1, '=')
      ->condition('r.state', 'waiting', '=');

    // If day, filter by daily relaunches.
    if ($timestamp) {
      $query->join('field_data_field_relaunch', 'dr', 'dr.entity_id = n.nid');
      $startDate = time();
      $min_day = date(REMINDER_DATE_FORMAT, $startDate);
      $max_day = date(REMINDER_DATE_FORMAT, strtotime('+1 day', $startDate));
      $query->condition('dr.field_relaunch_value', $min_day, '>=')
        ->condition('dr.field_relaunch_value', $max_day, '<');
    }
    // If nid specified, filter by node id, to.
    ($nid != 'NULL') ? $query->condition('n.nid', $nid, '=') : NULL;

    $query->range($context['sandbox']['progress'], $limit);
    $result = $query->execute();

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
          /*//Send mail to website email and set message to website
          //$body = 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation <a href="' .$base_url . $base_path . 'node/'.  $relaunch->nid . '">' . $relaunch->title . '</a>.';
          $body = '<html><body>Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()) . '.</body></html>';

          $params_mail_website = array(
            'body' => $body,
            'subject' => 'Relance effectuée à '.$relaunch->name .' pour la prestation ' . $relaunch->title,
          );
          drupal_mail('band_booking_registration_reminder_', 'send_relaunch_mail', $from, language_default(), $params_mail_website, $from, TRUE);*/
          watchdog('Belive relaunch', 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()));
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
}

/**
 * @ todo
 * @param $success
 * @param $results
 * @param $operations
 */
function band_booking_registration_reminder_finished_method($success, $results, $operations) {
  drupal_set_message(t('Relaunch proceeding succesfully applied'));
}