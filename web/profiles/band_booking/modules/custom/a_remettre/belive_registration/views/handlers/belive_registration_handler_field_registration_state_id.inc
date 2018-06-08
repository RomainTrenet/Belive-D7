<?php

module_load_include('inc', 'belive_registration', 'includes/belive_registration_functions');
/**
 * Field handler to generate a link to edit a given registration.
 */
class belive_registration_handler_field_registration_state_id extends views_handler_field {
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
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    return $values->registration_state;
  }
}