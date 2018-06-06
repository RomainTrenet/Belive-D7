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
    'uuid' => 'd30539fb-731a-44c8-9895-d3ffe1237acd',
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
    'uuid' => 'e10e3490-9f61-46b1-84ee-921c0b71d370',
  );

  return $roles;
}
