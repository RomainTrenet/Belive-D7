<?php
/**
 * @file
 * band_booking_performance.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function band_booking_performance_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_inscriptions'.
  $permissions['create field_inscriptions'] = array(
    'name' => 'create field_inscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inscriptions'.
  $permissions['edit field_inscriptions'] = array(
    'name' => 'edit field_inscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inscriptions'.
  $permissions['edit own field_inscriptions'] = array(
    'name' => 'edit own field_inscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inscriptions'.
  $permissions['view field_inscriptions'] = array(
    'name' => 'view field_inscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inscriptions'.
  $permissions['view own field_inscriptions'] = array(
    'name' => 'view own field_inscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
