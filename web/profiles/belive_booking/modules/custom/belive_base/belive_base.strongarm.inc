<?php
/**
 * @file
 * belive_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function belive_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'fr',
    'name' => 'French',
    'native' => 'Français',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n>1)',
    'domain' => '',
    'prefix' => 'fr',
    'weight' => '0',
    'javascript' => 'wh1sGfiNxW0JOdEIZBm8iMiT4UCcHbYyihbOZQW2GmY',
  );
  $export['language_default'] = $strongarm;

  return $export;
}
