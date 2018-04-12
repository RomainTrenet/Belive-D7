<?php
/**
 * @file
 * artists_position.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function artists_position_taxonomy_default_vocabularies() {
  return array(
    'position' => array(
      'name' => 'Poste de l\'artiste',
      'machine_name' => 'position',
      'description' => 'Poste de l\'artiste',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
