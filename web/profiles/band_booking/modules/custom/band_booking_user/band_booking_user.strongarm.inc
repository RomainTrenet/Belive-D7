<?php
/**
 * @file
 * band_booking_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function band_booking_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_position_pattern';
  $strongarm->value = 'artistes/[term:name]';
  $export['pathauto_taxonomy_term_position_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = '[user:roles]/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  return $export;
}
