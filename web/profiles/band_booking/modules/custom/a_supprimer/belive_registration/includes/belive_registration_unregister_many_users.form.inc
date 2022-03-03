<?php

module_load_include('inc', 'belive_registration', 'includes/belive_registration_functions');

/**
 * @file
 * Code for the form to 
 */

/**
 * Build the form for accepting existing registrations.
 * 
 TODO
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

function belive_registration_unregister_many_users_view ($node) {
    drupal_set_title($node->title);
    return drupal_get_form('belive_registration_unregister_many_users_form', $node);//, 'admin', FALSE);
}

function belive_registration_unregister_many_users_form($form, &$form_state, $node) {//, $register_type = 'auth') {
    //Attached custom js
    $form['#attached'] = array(
        'js' => array(
            drupal_get_path('module', 'belive_registration') . '/js/belive_registration.js' => array(
                'scope' => 'footer',
            ),
        ),
    );

  //Default values
  $default_users = !empty($form_state['input']['users']) ? $form_state['input']['users'] : array();

  //Vars
  $registered_musicians = _get_node_registered_users( $node->nid );
  //$available_musicians = _get_node_available_users( $registered_musicians );

  $registered_musicians_options = array();
  foreach ($registered_musicians as $uid => $registered_musician) {
      $registered_musicians_options[$uid] = $registered_musician->name;
  }

	//Construct form
	$registration_form = array();
  $registration_form['registered_musicians'] = array(
      '#type' => 'value',
      '#value' => $registered_musicians_options,
  );
  //Users list values and users form field
  $users_list = array(
      '#type' => 'value',
      '#value' => $registered_musicians_options,
  );
  $registration_form['users'] = array(
      '#type' => 'bootstrap_multiselect_field',
      '#required' => TRUE,
      '#multiple' => TRUE,
      '#title' => t('Remove musicians'),
      '#description' => t('Select the musicians you want to remove from performance. Only musicians already registered will appear.'),
      '#default_value' => $default_users,
      '#size' => 5,
      '#weight' => 0,
      '#options' => $users_list['#value'],
      '#element_validate' => array('belive_registration_unregister_many_users_form_users_validate'),
  );
  $form['registration_user_form'] = $registration_form;

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Unregister users'),
  );
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

function belive_registration_unregister_many_users_form_users_validate($element, &$form_state, $form) {
	// Set Error if element is required and empty
	if ($element['#required'] == TRUE && empty($element['#value'])) {
		form_error($element, t('This field is required !'));
		form_set_error($element['#id'], t('No users selected.'));
		return;
	}
	$users_to_delete = $form_state['values']['users'];
	$registered_musicians = $form_state['values']['registered_musicians'];

	// Set Error if users selected aren't in availables users list
	foreach ($users_to_delete as $key => $value) {
		if (!array_key_exists($value, $registered_musicians)) {
			form_error($element, t('This field is faulty.'));
			form_set_error($element['#id'], t('One user does not exist.'));
		}
	}
	return $element;
}

function belive_registration_unregister_many_users_form_validate($form, &$form_state) {
	if (!user_access('registrate users to belive performance')) {
		form_set_error('title', t('You are not allowed to unregister people.'));
		return FALSE;
	}
}

/**
 * Submit handler for the user register form.
 *
 * @param array $form
 *   The form being submitted.
 * @param array $form_values
 *   The state of the form, including the submitted values.
 */

function belive_registration_unregister_many_users_form_submit($form, &$form_state) {
	if (isset($form_state['values']['users'])) {
    //from node id and users id , get the registrations id
    $registrations_ids = _get_node_registrations_id_for_users( arg(1), $form_state['values']['users']);
    entity_delete_multiple('registration', $registrations_ids);
	}
}