<?php
/**
 * @file
 * belive_registration.features.inc
 */

/**
 * Implements hook_views_api().
 */
function belive_registration_views_api($module = NULL, $api = NULL) {
  return array(
    "api" => "3.0"

  );
}

/**
 * Implements hook_default_registration_state().
 */
function belive_registration_default_registration_state() {
  $items = array();
  $items['accepted'] = entity_import('registration_state', '{
    "name" : "accepted",
    "label" : "Accept\\u00e9",
    "description" : "L\\u0027inscription est accept\\u00e9e",
    "default_state" : "0",
    "active" : "1",
    "held" : "0",
    "show_on_form" : "1",
    "weight" : "-13",
    "rdf_mapping" : []
  }');
  $items['refused'] = entity_import('registration_state', '{
    "name" : "refused",
    "label" : "Refus\\u00e9",
    "description" : "L\\u0027inscription est refus\\u00e9e",
    "default_state" : "0",
    "active" : "1",
    "held" : "0",
    "show_on_form" : "1",
    "weight" : "-12",
    "rdf_mapping" : []
  }');
  $items['waiting'] = entity_import('registration_state', '{
    "name" : "waiting",
    "label" : "En attente",
    "description" : "Default registration state",
    "default_state" : "1",
    "active" : "1",
    "held" : "0",
    "show_on_form" : "1",
    "weight" : "-15",
    "rdf_mapping" : []
  }');
  return $items;
}
