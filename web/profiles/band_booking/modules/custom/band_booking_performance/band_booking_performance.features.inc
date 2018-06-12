<?php
/**
 * @file
 * band_booking_performance.features.inc
 */

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
