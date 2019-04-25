<?php

/**
 * @file
 * band_booking_performance.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function band_booking_performance_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|performance|full';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_date',
      2 => 'field_place',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-main field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_main|node|performance|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relaunch|node|performance|form';
  $field_group->group_name = 'group_relaunch';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'performance';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relances',
    'weight' => '6',
    'children' => array(
      0 => 'field_relaunch',
      1 => 'field_objet_du_mail',
      2 => 'field_mail_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Relances',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-relaunch field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_relaunch|node|performance|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main');
  t('Relances');

  return $field_groups;
}
