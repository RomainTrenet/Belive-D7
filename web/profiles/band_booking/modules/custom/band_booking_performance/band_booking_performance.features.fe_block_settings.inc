<?php

/**
 * @file
 * band_booking_performance.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function band_booking_performance_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['band_booking_registration-bbr_register_many'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'bbr_register_many',
    'module' => 'band_booking_registration',
    'node_types' => array(
      0 => 'performance',
    ),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_admin',
        'weight' => -19,
      ),
      'band_booking_front' => array(
        'region' => 'sidebar_right',
        'status' => 1,
        'theme' => 'band_booking_front',
        'weight' => -19,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => 0,
      ),
    ),
    'title' => 'Inscrire des artistes',
    'visibility' => 0,
  );

  $export['band_booking_registration-bbr_unregister_many'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'bbr_unregister_many',
    'module' => 'band_booking_registration',
    'node_types' => array(
      0 => 'performance',
    ),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_admin',
        'weight' => -18,
      ),
      'band_booking_front' => array(
        'region' => 'sidebar_right',
        'status' => 1,
        'theme' => 'band_booking_front',
        'weight' => -18,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => 0,
      ),
    ),
    'title' => 'Désinscrire des artistes',
    'visibility' => 0,
  );

  $export['band_booking_registration_reminder-bbrr_performance_reminder'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'bbrr_performance_reminder',
    'module' => 'band_booking_registration_reminder',
    'node_types' => array(
      0 => 'performance',
    ),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_admin',
        'weight' => -17,
      ),
      'band_booking_front' => array(
        'region' => 'sidebar_right',
        'status' => 1,
        'theme' => 'band_booking_front',
        'weight' => -20,
      ),
      'band_booking_global' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'band_booking_global',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
