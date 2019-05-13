<?php

module_load_include('inc', 'band_booking_registration', 'includes/band_booking_registration_functions');

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
function band_booking_registration_unregister_many_users_form($form, &$form_state, $node) {
  // Get registered artists.
  $registered_artists = _get_node_registered_users($node->nid);

  if (empty($registered_artists)) {
    $form['markup_form']['no_users'] = [
      '#type' => 'item',
      '#weight' => 0,
      '#markup' => '<p>' . t('No registered artist.') . '</p>',
    ];
  } else {
    $registered_artists_options = array();
    foreach ($registered_artists as $uid => $registered_artist) {
      $registered_artists_options[$uid] = $registered_artist->name;
    }

    // Alphabetically sort results.
    asort($registered_artists_options);

    // Users list values and users form field
    $users_list = array(
      '#type' => 'value',
      '#value' => $registered_artists_options,
    );
    // Default values.
    $default_users = !empty($form_state['input']['remove_users']) ? $form_state['input']['remove_users'] : array();

    // Construct form.
    $form = [
      'registration_user_form' => [
        'registered_artists' => [
          '#type' => 'value',
          '#value' => $registered_artists_options,
        ],
        'remove_users' => [
          '#type' => 'multiple_select_field',
          '#required' => FALSE,
          '#multiple' => TRUE,
          '#title' => t('Remove artists'),
          '#description' => t('Select the artists you want to remove from performance. Only artists already registered will appear.'),
          '#default_value' => $default_users,
          '#size' => 5,
          '#weight' => 0,
          '#options' => $users_list['#value'],
          '#element_validate' => array('band_booking_registration_unregister_many_users_form_users_validate'),
        ]
      ],
      'submit' => [
        '#type' => 'submit',
        '#value' => t('Unregister users'),
      ]
    ];
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

function band_booking_registration_unregister_many_users_form_users_validate($element, &$form_state, $form) {
	// Set Error if element is required and empty
	if ($element['#required'] == TRUE && empty($element['#value'])) {
		form_error($element, t('This field is required !'));
		form_set_error($element['#id'], t('No users selected.'));
		return;
	}
	$users_to_delete = $form_state['values']['remove_users'];
	$registered_artists = $form_state['values']['registered_artists'];

	// Set Error if users selected aren't in availables users list
	foreach ($users_to_delete as $key => $value) {
		if (!array_key_exists($value, $registered_artists)) {
			form_error($element, t('This field is faulty.'));
			form_set_error($element['#id'], t('One user does not exist.'));
		}
	}
	return $element;
}

function band_booking_registration_unregister_many_users_form_validate($form, &$form_state) {
  if (!user_access('registrate users to performance registration')) {
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

function band_booking_registration_unregister_many_users_form_submit($form, &$form_state) {
	if (isset($form_state['values']['remove_users'])) {
    //from node id and users id , get the registrations id
    $registrations_ids = _get_node_registrations_id_for_users( arg(1), $form_state['values']['remove_users']);
    entity_delete_multiple('registration', $registrations_ids);
	}
}