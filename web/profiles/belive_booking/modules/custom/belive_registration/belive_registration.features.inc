<?php
/**
 * @file
 * belive_registration.features.inc
 */

/**
 * Implements hook_default_Workflow().
 */
function belive_registration_default_Workflow() {
  $workflows = array();

  // Exported workflow: 'workflow_belive_booking'
  $workflows['workflow_belive_booking'] = entity_import('Workflow', '{
    "name" : "workflow_belive_booking",
    "tab_roles" : [],
    "options" : [],
    "states" : {
      "(creation)" : {"weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "accepted" : {"weight":"-18","sysid":"0","state":"Accepted","status":"1","name":"accepted"},
      "postponed" : {"weight":"-16","sysid":"0","state":"Postponed","status":"0","name":"postponed"},
      "refused" : {"weight":"-17","sysid":"0","state":"Refused","status":"1","name":"refused"},
      "waiting" : {"weight":"-19","sysid":"0","state":"Waiting","status":"1","name":"waiting"}
    },
    "transitions" : {
      "_creation_to_accepted" : {"roles":[],"name":"_creation_to_accepted","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"accepted"},
      "_creation_to_refused" : {"roles":[],"name":"_creation_to_refused","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"refused"},
      "_creation_to_waiting" : {"roles":{"-1":-1},"name":"_creation_to_waiting","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"waiting"},
      "accepted_to_accepted" : {"roles":{"-1":-1,"4":4},"name":"accepted_to_accepted","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"accepted"},
      "accepted_to_refused" : {"roles":{"4":4},"name":"accepted_to_refused","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"refused"},
      "accepted_to_waiting" : {"roles":{"4":4},"name":"accepted_to_waiting","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"waiting"},
      "refused_to_accepted" : {"roles":{"4":4},"name":"refused_to_accepted","label":"","rdf_mapping":[],"start_state":"refused","end_state":"accepted"},
      "refused_to_refused" : {"roles":{"-1":-1,"4":4},"name":"refused_to_refused","label":"","rdf_mapping":[],"start_state":"refused","end_state":"refused"},
      "refused_to_waiting" : {"roles":{"4":4},"name":"refused_to_waiting","label":"","rdf_mapping":[],"start_state":"refused","end_state":"waiting"},
      "waiting_to_accepted" : {"roles":{"4":4},"name":"waiting_to_accepted","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"accepted"},
      "waiting_to_refused" : {"roles":{"4":4},"name":"waiting_to_refused","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"refused"},
      "waiting_to_waiting" : {"roles":{"-1":-1,"4":4},"name":"waiting_to_waiting","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"waiting"}
    },
    "label" : "workflow_belive_booking",
    "typeMap" : [],
    "rdf_mapping" : [],
    "system_roles" : { "-1" : "(auteur)", "4" : "G\\u00e9rant" }
  }');

  return $workflows;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function belive_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function belive_registration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function belive_registration_node_info() {
  $items = array(
    'performance' => array(
      'name' => t('Prestation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nom de la prestation'),
      'help' => t('Veuillez donner un nom à votre prestation.
Pensez à inclure la date et le lieu afin de faciliter la lecture de la liste des prestations.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
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

/**
 * Implements hook_default_registration_type().
 */
function belive_registration_default_registration_type() {
  $items = array();
  $items['performance'] = entity_import('registration_type', '{
    "name" : "performance",
    "label" : "Inscriptions aux performances",
    "locked" : "0",
    "default_state" : "waiting",
    "data" : { "held_expire" : "1", "held_expire_state" : "waiting" },
    "weight" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
