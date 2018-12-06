<?php

/**
 * @file
 * band_booking_performance.features.inc
 */

/**
 * Implements hook_default_Workflow().
 */
function band_booking_performance_default_Workflow() {
  $workflows = array();

  // Exported workflow: 'bb_confirmation_workflow'
  $workflows['bb_confirmation_workflow'] = entity_import('Workflow', '{
    "name" : "bb_confirmation_workflow",
    "tab_roles" : [],
    "options" : [],
    "states" : {
      "(creation)" : {"weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "accepted" : {"weight":"-18","sysid":"0","state":"Accepted","status":"1","name":"accepted"},
      "refused" : {"weight":"-17","sysid":"0","state":"Refused","status":"1","name":"refused"},
      "waiting" : {"weight":"-19","sysid":"0","state":"Waiting","status":"1","name":"waiting"}
    },
    "transitions" : {
      "_creation_to_accepted" : {"roles":{"4":4},"name":"_creation_to_accepted","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"accepted"},
      "_creation_to_refused" : {"roles":{"4":4},"name":"_creation_to_refused","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"refused"},
      "_creation_to_waiting" : {"roles":{"-1":-1},"name":"_creation_to_waiting","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"waiting"},
      "accepted_to_accepted" : {"roles":{"-1":-1,"3":3,"4":4,"5":5},"name":"accepted_to_accepted","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"accepted"},
      "accepted_to_refused" : {"roles":{"4":4},"name":"accepted_to_refused","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"refused"},
      "accepted_to_waiting" : {"roles":{"4":4},"name":"accepted_to_waiting","label":"","rdf_mapping":[],"start_state":"accepted","end_state":"waiting"},
      "refused_to_accepted" : {"roles":{"4":4},"name":"refused_to_accepted","label":"","rdf_mapping":[],"start_state":"refused","end_state":"accepted"},
      "refused_to_refused" : {"roles":{"-1":-1,"3":3,"4":4,"5":5},"name":"refused_to_refused","label":"","rdf_mapping":[],"start_state":"refused","end_state":"refused"},
      "refused_to_waiting" : {"roles":{"4":4},"name":"refused_to_waiting","label":"","rdf_mapping":[],"start_state":"refused","end_state":"waiting"},
      "waiting_to_accepted" : {"roles":{"4":4,"5":5},"name":"waiting_to_accepted","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"accepted"},
      "waiting_to_refused" : {"roles":{"4":4,"5":5},"name":"waiting_to_refused","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"refused"},
      "waiting_to_waiting" : {"roles":{"-1":-1,"3":3,"4":4,"5":5},"name":"waiting_to_waiting","label":"","rdf_mapping":[],"start_state":"waiting","end_state":"waiting"}
    },
    "label" : "bb_confirmation_workflow",
    "typeMap" : [],
    "rdf_mapping" : [],
    "system_roles" : {
      "-1" : "(auteur)",
      "3" : "administrateur",
      "4" : "G\\u00e9rant",
      "5" : "Artiste"
    }
  }');

  return $workflows;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function band_booking_performance_ctools_plugin_api($module = NULL, $api = NULL) {
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
function band_booking_performance_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function band_booking_performance_node_info() {
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
