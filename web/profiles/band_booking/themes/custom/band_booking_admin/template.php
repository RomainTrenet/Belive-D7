<?php

/**
 * Override or insert variables into the html template.
 */
function band_booking_admin_preprocess_html(&$vars) {
  // Get adminimal folder path.
  $band_booking_admin_path = drupal_get_path('theme', 'band_booking_admin');

  // Add default styles, to fight with Adminimal Theme, Had weight 1000
  drupal_add_css($band_booking_admin_path . '/css/band_booking_admin.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 1000));
}