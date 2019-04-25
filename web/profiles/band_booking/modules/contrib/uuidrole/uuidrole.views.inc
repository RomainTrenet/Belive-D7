<?php

/**
 * Implements hook_views_data_alter().
 */
function uuidrole_views_data_alter(&$data) {
  $data['role']['uuid'] = array(
    'title' => t('Role UUID'),
    'help' => t('The universally unique ID of the role.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}