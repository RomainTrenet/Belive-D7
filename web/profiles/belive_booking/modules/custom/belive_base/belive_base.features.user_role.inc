<?php
/**
 * @file
 * belive_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function belive_base_user_default_roles() {
  $roles = array();

  // Exported role: Gérant.
  $roles['Gérant'] = array(
    'name' => 'Gérant',
    'weight' => 3,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
