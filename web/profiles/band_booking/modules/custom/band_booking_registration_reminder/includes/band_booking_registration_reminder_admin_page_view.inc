<?php

/**
 * @file
 * Code for Relaunch admin page.
 */

/**
 * View of Admin relaunch page.
 *
 * @return string
 *   The HTML content.
 */
function _band_booking_registration_reminder_admin_page_view() {
  module_load_include('inc', 'band_booking_registration_reminder', 'includes/band_booking_registration_reminder_admin_block_content');
  return _band_booking_registration_reminder_admin_block_content();
}
