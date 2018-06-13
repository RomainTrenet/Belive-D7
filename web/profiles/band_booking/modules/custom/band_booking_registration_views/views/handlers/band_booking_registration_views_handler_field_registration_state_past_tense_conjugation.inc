<?php

module_load_include('inc', 'band_booking_registration', 'includes/band_booking_registration_functions');
/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */

/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
// @todo : check
// OLD : band_booking_registration_handler_field_state_past_tense_conjugation
class band_booking_registration_views_handler_field_registration_state_past_tense_conjugation extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['state'] = array(
      'table' => 'registration',
      'field' => 'state',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    return _get_registration_states_past_tense_conjugation($values->registration_state);
  }
}
