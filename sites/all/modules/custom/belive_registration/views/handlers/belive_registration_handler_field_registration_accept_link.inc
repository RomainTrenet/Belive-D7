<?php
/**
 * Field handler to generate a link to edit a given registration.
 */
class belive_registration_handler_field_registration_accept_link extends views_handler_field_node_link {
  
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
    $rid = $values->{$this->aliases['registration_id']};
    global $user;

    //TODO get workflow from registration
    $workflow = workflow_load_single('workflow_belive_booking');
    $registration_state_id = _get_workflow_status_id_from_machine_name($workflow->states, $values->{$this->aliases['state']});
    $statuses = _get_belive_registration_worklflow_possible_statuses($workflow->transitions, $registration_state_id, $user->roles );
    if (array_key_exists('accepted', $statuses)) {
      return (drupal_get_form('belive_registration_determine_form_accept_'.$rid, 'accept', $rid));
    }
  }

}