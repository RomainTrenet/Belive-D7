<?php
/**
 * @file
 * artists_position.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function artists_position_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_postition'.
  $field_bases['field_postition'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_postition',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'position',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
