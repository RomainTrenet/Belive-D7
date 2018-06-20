<?php
/**
 * @file
 * band_booking_registration.features.workflow_access.inc
 */

/**
 * Implements hook_workflow_access_features_default_settings().
 */
function band_booking_registration_workflow_access_features_default_settings() {
  $workflows = array();

  $workflows['bb_registration_workflow'] = array();

  return $workflows;
}
