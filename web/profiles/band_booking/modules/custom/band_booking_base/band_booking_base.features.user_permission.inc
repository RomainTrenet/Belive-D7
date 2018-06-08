<?php
/**
 * @file
 * band_booking_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function band_booking_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
