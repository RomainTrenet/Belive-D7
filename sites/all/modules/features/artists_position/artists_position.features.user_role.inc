<?php
/**
 * @file
 * artists_position.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function artists_position_user_default_roles() {
  $roles = array();

  // Exported role: Musicien.
  $roles['Musicien'] = array(
    'name' => 'Musicien',
    'weight' => 4,
  );

  return $roles;
}
