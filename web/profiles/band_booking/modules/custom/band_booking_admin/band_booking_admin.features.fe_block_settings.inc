<?php
/**
 * @file
 * band_booking_admin.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function band_booking_admin_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-a706d17bbba6a75208302bf3ade61ce4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'a706d17bbba6a75208302bf3ade61ce4',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/band_booking_dashboard',
    'roles' => array(
      'administrateur' => 3,
      'Gérant' => 4,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'band_booking_admin' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'band_booking_admin',
        'weight' => -17,
      ),
      'band_booking_front' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_front',
        'weight' => 0,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-last_registrations_change-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'last_registrations_change-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/band_booking_dashboard',
    'roles' => array(
      'administrateur' => 3,
      'Gérant' => 4,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'band_booking_admin' => array(
        'region' => 'sidebar_right',
        'status' => 1,
        'theme' => 'band_booking_admin',
        'weight' => -16,
      ),
      'band_booking_front' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_front',
        'weight' => -17,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-registrations_unchanged-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'registrations_unchanged-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/band_booking_dashboard',
    'roles' => array(
      'administrateur' => 3,
      'Gérant' => 4,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'band_booking_admin' => array(
        'region' => 'sidebar_right',
        'status' => 1,
        'theme' => 'band_booking_admin',
        'weight' => -15,
      ),
      'band_booking_front' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_front',
        'weight' => -16,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
