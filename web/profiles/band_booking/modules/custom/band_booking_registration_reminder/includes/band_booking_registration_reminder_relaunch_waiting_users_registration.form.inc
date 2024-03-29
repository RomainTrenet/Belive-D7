<?php

/**
* @file
* Code for the form to
*/

function band_booking_registration_reminder_admin_relaunch_waiting_users_registration_view () {
  global $base_url;
  global $base_path;
  $destination = current_path();
  $content = '<p>' . l(t('Relaunch waiting registrations for today'), $base_url . $base_path . 'relaunch_batch_manually_today', $options = array('query' => array('destination' => $destination))). '<br />'
    . t('This includes every performance, and figure the days scheduled for the relaunch.') . '</p>'
  . '<p>' . l(t('Relaunch waiting registrations for everyday'), $base_url . $base_path . 'relaunch_batch_manually_everyday', $options = array('query' => array('destination' => $destination))). '<br />'
    . t('This includes every performance, and does not figure the days scheduled for the relaunch.') . '</p>';
  return ($content);
}
