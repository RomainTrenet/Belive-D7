<?php
/**
 * @file
 * Provides support for Views integration.
 *
 * This exposes registration-related data and declares handlers (fields, filters)
 * and plugins (argument validators).
 */

/**
 * Implements hook_views_data().
 */
function belive_registration_views_data() {
  $data['registration']['wait_link'] = array(
    'title' => t('User: Wait registration'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_registration_wait_link',
      'help' => t('Link to wait this particular registration.'),
    ),
  );
  $data['registration']['postpone_link'] = array(
    'title' => t('User: Postpone registration'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_registration_postpone_link',
      'help' => t('Link to postpone this particular registration.'),
    ),
  );
  $data['registration']['accept_link'] = array(
    'title' => t('User: Accept registration'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_registration_accept_link',
      'help' => t('Link to accept this particular registration.'),
    ),
  );

  $data['registration']['refuse_link'] = array(
    'title' => t('User: Refuse registration'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_registration_refuse_link',
      'help' => t('Link to refuse this particular registration.'),
    ),
  );
  $data['registration']['state_id'] = array(
    'title' => t('Registration: State id'),
    'help' => t('State id of a registration.'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_registration_state_id',
    ),
  );
  $data['registration']['state_past_tense_conjugation'] = array(
    'title' => t('Registration: State past tense conjugation'),
    'help' => t('Conjugation past tense for "Registration state".'),
    'field' => array(
      'handler' => 'belive_registration_handler_field_state_past_tense_conjugation',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 *
 * Register information about all of the views handlers provided by the Signup
 * module.
 */
function belive_registration_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'belive_registration') . '/views/handlers',
    ),
    'handlers' => [
      'belive_registration_handler_field_registration_wait_link' => [
        'parent' => 'views_handler_field_node_link',
      ],
      'belive_registration_handler_field_registration_postpone_link' => [
        'parent' => 'views_handler_field_node_link',
      ],
      'belive_registration_handler_field_registration_accept_link' => [
        'parent' => 'views_handler_field_node_link',
      ],
      'belive_registration_handler_field_registration_refuse_link' => [
        'parent' => 'views_handler_field_node_link',
      ],
      'belive_registration_handler_field_registration_state_id' => [
        'parent' => 'views_handler_field',
      ],
      'belive_registration_handler_field_registration_state_past_tense_conjugation' => [
        'parent' => 'views_handler_field',
      ],

    ],
  );
}
