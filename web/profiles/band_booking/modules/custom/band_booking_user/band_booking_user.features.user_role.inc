<?php

/**
 * @file
 * band_booking_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function band_booking_user_user_default_roles() {
  $roles = array();

  // Exported role: Artiste.
  $roles['Artiste'] = array(
    'name' => 'Artiste',
    'weight' => 4,
    'uuid' => '81722714-b82d-4a8a-a81b-5cef63fc2d25',
  );

  // Exported role: Gérant.
  $roles['Gérant'] = array(
    'name' => 'Gérant',
    'weight' => 3,
    'uuid' => 'f0ac2711-4adf-44c2-9817-d41d7d2a8f95',
  );

  // Exported role: administrateur.
  $roles['administrateur'] = array(
    'name' => 'administrateur',
    'weight' => 2,
    'uuid' => 'cd2238ab-5aba-4c45-9bd1-4dae948daebf',
  );

  return $roles;
}
