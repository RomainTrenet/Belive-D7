<?php

module_load_include('inc', 'belive_registration', 'includes/belive_registration_functions');

/**
 * @file
 * Code for the form to 
 */

/**
 * Build the form for accepting existing registrations.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   The state of the form to build (not currently used).
 * @param stdClass $register
 *   The fully-loaded signup object with data about the signup to accept.
 * @param string $type
 *   The type of signup accept form to render, can be 'node', 'tab', or 'admin'.
 *
 * @return array
 *   The FAPI form array for the signup accept form.
 */

function belive_registration_state_registration_view ($node, $uid) {
  drupal_set_title($node->title);
  return drupal_get_form('belive_registration_state_registration_form', $node, $uid);
}

function belive_registration_state_registration_form($form, &$form_state, $node, $uid) {
  $registration_user = user_load($uid);
  $rid = _get_registration_id($node->nid, $registration_user->uid);
  $registration = entity_load_single('registration', $rid);
  $registration_author = user_load($registration->author_uid);
  $status_combinations = belive_registration_get_status_combinations();

  $workflow = workflow_load_single('workflow_belive_booking');
  $registration_state_id = _get_workflow_status_id_from_machine_name($workflow->states, $registration->state);
  $statuses = _get_belive_registration_worklflow_possible_statuses($workflow->transitions, $registration_state_id, $registration_user->roles );

  //Pass status to form validate to prevent changing to wrong status
  $form['allowed_statuses'] = array(
    '#type' => 'value',
    '#value' => $statuses,
  );
  $form['current_status'] = array(
    '#type' => 'value',
    '#value' => $registration->state,
  );
  $form['registration_id'] = array(
    '#type' => 'value',
    '#value' => $rid,
  );
  
  $presentation_markup = '<p>' . $node->field_date['und'][0]['value'] . ' - ' . $node->field_place['und'][0]['value'] . '<br/>' . $registration_author->name . ' vous a ajouté à l\'évènement</p>';

  $form['presentation_markup'] = array(
    '#type' => 'item',
	  '#title' => $node->title,
    '#title_display' => 'before',
    '#markup' => $presentation_markup,
  );
  $form['current_status_markup'] = array(
    '#type' => 'item',
    '#title' => t('Current status for your registration'),
    '#title_display' => 'before',
    '#markup' => '<p>' . $status_combinations[$registration->state] . '</p>',
  );
  $statuses_list = array(
    '#type' => 'value',
    '#value' => $statuses,
  );
  if (!empty($statuses)) {
    $form['status'] = array(
      '#type' => 'select',
      '#required' => FALSE,
      '#title' => t('Change state of your registration'),
      '#title_display' => 'before',
      '#default_value' => $registration->state,
      '#options' => $statuses_list['#value'],
      '#element_validate' => array('belive_registration_state_registration_form_state_validate'),
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Change status'),
    );
  } else {
    $form['status'] = array(
      '#type' => 'item',
      '#markup' => '<p>'. t('There are no status changement possible') .'</p>',
    );
  }

  return $form;
}

/**
 * Validates the user id on the admin form to register another user.
 *
 * @param array $form
 *   Form array for the username field.
 * @param array $form_state
 *   The form state array containing node ID of the node the user is being signed up for.
 */

function belive_registration_state_registration_form_state_validate($element, &$form_state, $form) {
	// Set Error if element is required and empty
	if ($element['#required'] == TRUE && empty($element['#value'])) {
		form_error($element, t('This field is required !'));
		form_set_error($element['#id'], t('No status selected.'));
		return;
	}
	$status_to_change = $form_state['values']['status'];
  $allowed_statuses = $form_state['values']['allowed_statuses'];

	// Set Error if status selected is not in allowed status
  //Testé ok
  if (!array_key_exists($status_to_change, $allowed_statuses)) {
    form_error($element, t('This field is faulty.'));
    form_set_error($element['#id'], t('One status does not exist.'));
  }


  $current_status = $form_state['values']['current_status'];
	//TODO check if new status is allowed from old status


	return $element;
}

function belive_registration_state_registration_form_validate($form, &$form_state) {
	if (!user_access('edit own performance registration status')) {
		form_set_error('title', t('You are not allowed to state registration.'));
		return FALSE;
	}

	//TODO if user is concerned (rid <-> uid);

	//else { dpm('cest ok tas le droit'); }
}

/**
 * Submit handler for the user register form.
 *
 * @param array $form
 *   The form being submitted.
 * @param array $form_values
 *   The state of the form, including the submitted values.
 */

function belive_registration_state_registration_form_submit($form, &$form_state) {
  if (isset($form_state['values']['status'])) {
    $registration_wrapper = entity_metadata_wrapper('registration', $form_state['values']['registration_id']);
    $registration_wrapper->state = $form_state['values']['status'];
    $registration_wrapper->save();
	}
}