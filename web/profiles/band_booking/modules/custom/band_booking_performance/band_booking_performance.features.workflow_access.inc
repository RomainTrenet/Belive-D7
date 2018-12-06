<?php

/**
 * @file
 * band_booking_performance.features.workflow_access.inc
 */

/**
 * Implements hook_workflow_access_features_default_settings().
 */
function band_booking_performance_workflow_access_features_default_settings() {
  $workflows = array();

  $workflows['bb_confirmation_workflow'] = array();

  return $workflows;
}
