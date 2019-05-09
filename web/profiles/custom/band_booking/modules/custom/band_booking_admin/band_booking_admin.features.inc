<?php
/**
 * @file
 * band_booking_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function band_booking_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function band_booking_admin_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function band_booking_admin_default_profile2_type() {
  $items = array();
  $items['profil_musicien'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "profil_musicien",
    "label" : "Profil artiste",
    "weight" : "0",
    "data" : { "registration" : 0, "roles" : { "5" : "5" } },
    "rdf_mapping" : []
  }');
  return $items;
}
