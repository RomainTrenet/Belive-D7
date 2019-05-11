<?php

/**
 * @file
 * Code for Relaunch admin block.
 */

/**
 * View of Admin relaunch block.
 *
 * @return string
 *   The HTML content.
 */
function _band_booking_registration_reminder_admin_block_content() {
  global $base_url;
  global $base_path;
  $destination = current_path();

  $today_relaunch = l(
    t('Relaunch waiting registrations for today'),
    $base_url . $base_path . REMINDER_MANUAL_TODAY,
    array('query' => array('destination' => $destination))
  );
  $everyday_relaunch = l(
    t('Relaunch waiting registrations for everyday'),
    $base_url . $base_path . REMINDER_MANUAL_EVERYDAY,
    array('query' => array('destination' => $destination))
  );

  $content = '<p>' . $today_relaunch . '<br />';
  $content .= t('This includes every performance, and figure the days scheduled for the relaunch.') . '</p>';
  $content .= '<p>' . $everyday_relaunch . '<br />';
  $content .= t('This includes every performance, and does not figure the days scheduled for the relaunch.') . '</p>';
  return ($content);
}
