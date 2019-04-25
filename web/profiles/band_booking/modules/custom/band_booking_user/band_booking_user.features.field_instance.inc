<?php

/**
 * @file
 * band_booking_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function band_booking_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_poste_de_l_artiste'.
  $field_instances['user-user-field_poste_de_l_artiste'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vous pouvez ajouter autant de postes que vous souhaitez, séparés par une virgule suivie d\'un espace.
C\'est un champ à auto-complétion qui enregistre chacun des postes séparément.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_poste_de_l_artiste',
    'label' => 'Poste de l\'artiste',
    'required' => 1,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Poste de l\'artiste');
  t('Vous pouvez ajouter autant de postes que vous souhaitez, séparés par une virgule suivie d\'un espace.
C\'est un champ à auto-complétion qui enregistre chacun des postes séparément.');

  return $field_instances;
}
