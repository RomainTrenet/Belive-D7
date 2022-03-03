<?php
/**
 * Field handler to generate a link to edit a given registration.
 */
class band_booking_registration_views_handler_field_registration_accept_link extends views_handler_field_node_link {
  
  function construct() {
    parent::construct();
    $this->additional_fields['registration_id'] = array(
      'table' => 'registration',
      'field' => 'registration_id',
    );
    $this->additional_fields['state'] = array(
      'table' => 'registration',
      'field' => 'state',
    );
  }

  function render($values) {
    global $user;

    $rid = $values->{$this->aliases['registration_id']};
    $workflow = workflow_load_single(BB_REGISTRATION_WORKFLOW);
    $registration_state_id = _get_workflow_status_id_from_machine_name($workflow->states, $values->{$this->aliases['state']});
    $statuses = _get_band_booking_registration_worklflow_possible_statuses($workflow->transitions, $registration_state_id, $user->roles );

    if (array_key_exists('accepted', $statuses)) {
      return (drupal_get_form('band_booking_registration_views_determine_form_accept_'.$rid, 'accept', $rid));
    } else {
      return '';
    }
  }

}
