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

function band_booking_registration_register_many_users_view ($node) {
  //drupal_set_title($node->title);
  return drupal_get_form('band_booking_registration_register_many_users_form', $node);
}

/**
 * @param $form
 * @param $form_state
 * @param $node
 *
 * @return mixed
 */
function band_booking_registration_register_many_users_form($form, &$form_state, $node) {

  // Prepare variables.
  $registered_artists = _get_node_registered_users($node->nid);
  $total_registered_artists = count($registered_artists);
  $available_artists = _get_node_available_users($registered_artists);
  $available_artists_options = array();
  foreach ($available_artists as $uid => $available_artist) {
      $available_artists_options[$uid] = $available_artist->name;
  }

  // Registered artists.
  $registered_artists_text = '';
  if ($total_registered_artists == 0) {
    $registered_artists_text = t('None');
  } else {
    $count = 1;
    foreach ($registered_artists as $uid => $registered_user) {
      $registered_artists_text .= $registered_user->name . ($total_registered_artists != $count ? ', ' : '.');
      $count++;
    }
  }
  $form['markup_form']['registered_artists'] = [
    '#type' => 'item',
    '#title' => t('Artists already registered') . ' :',
    '#weight' => 0,
    '#markup' => '<p>' . $registered_artists_text . '</p>',
  ];

  // If all artists are already booked.
  if (empty($available_artists)) {
    $form['markup_form']['no_users'] = [
      '#type' => 'item',
      '#weight' => 0,
      '#markup' => '<p>' . t('All artists are already registered.') . '</p>',
    ];
  } else {

    // User position form element.
    $positions_list = array(
      '#type' => 'value',
      '#value' => _get_taxonomy_terms_options_formatted(2),
    );
    $form['position_filter_form']['position'] = array(
      '#type' => 'multiple_select_field',
      '#required' => FALSE,
      '#multiple' => TRUE,
      '#title' => t('Filter by position'),
      '#description' => t('Select the artists position to filter artists list.'),
      '#size' => 5,
      '#weight' => 0,
      '#options' => $positions_list['#value'],
      '#ajax' => array(
        'callback' => 'band_booking_registration_register_users_filter_position_callback',
        'event' => 'change',
      ),
    );

    // Registration user form element.
    // Prepare users list and default users values.
    $users_list = array(
      '#type' => 'value',
      '#value' => $available_artists_options,
    );
    $default_users = !empty($form_state['input']['add_users']) ? $form_state['input']['add_users'] : array();

    $form['registration_user_form'] = [
      // Pass available artists to form validate to prevent adding fake users.
      'available_artists' => [
        '#type' => 'value',
        '#value' => $available_artists_options,
      ],
      'registered_artists' => [
        '#type' => 'value',
        '#value' => $registered_artists,
      ],
      'add_users' => [
        '#type' => 'multiple_select_field',
        '#required' => TRUE,
        '#multiple' => TRUE,
        '#title' => t('Add artists'),
        '#description' => t('Select the artists you want to add. Artists already registered wont appear.'),
        '#default_value' => $default_users,
        '#size' => 5,
        '#weight' => 20,
        '#options' => $users_list['#value'],
        '#element_validate' => array('band_booking_registration_form_users_validate'),
        '#prefix' => '<div id="register_many_users">',
        '#suffix' => '</div>',
      ]
    ];

    // Submit.
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Register users'),
    );

    // The base registration array, used to create each registration object.
    global $user;
    $entity_type = 'node';
    $nid = $node->nid;
    $registration_type = $node->field_inscriptions['und'][0]['registration_type'];
    $registration_default_state = band_booking_registration_get_registration_type_default_state($registration_type);

    $registration_base = array(
      'entity_type' => $entity_type,
      'entity_id' => $nid,
      'type' => $registration_type,
      'count' => 1,//Only one user by registration
      'author_uid' => $user->uid,
      'state' => $registration_default_state,
      'is_new' => TRUE,
    );

    //Attach registration object to form
    $form_state['registration_base'] = $registration_base;
    field_attach_form('registration_base', $registration_base, $form, $form_state);

    // Attached custom js.
    $form['#attached'] = array(
      'js' => array(
        drupal_get_path('module', 'band_booking_registration') . '/js/band_booking_registration.js' => array(
          'scope' => 'footer',
          'weight' => 101
        ),
      ),
    );
  }

  return $form;
}

/**
 * Callback element needs only select the portion of the form to be updated.
 * Since #ajax['callback'] return can be HTML or a renderable array (or an
 * array of commands), we can just return a piece of the form.
 */
function band_booking_registration_register_users_filter_position_callback($form, $form_state) {
  $available_artists_options = $form['registration_user_form']['available_artists']['#value'];
  $registered_artists = $form['registration_user_form']['registered_artists']['#value'];
  $artists_with_position = _get_node_available_users_id_with_position( $registered_artists, $form_state['values']['position']);
  $artists_to_hide=array_diff_key($available_artists_options,$artists_with_position);

  $commands[] = array(
    'command' => 'afterAjaxCallbackExample',
    'artists_with_position' => $artists_with_position,
    'artists_to_hide' => $artists_to_hide,
  );

  return array(
    '#type' => 'ajax',
    '#commands' => $commands
  );
}

/**
 * Validates the user id on the admin form to register another user.
 *
 * @param array $form
 *   Form array for the username field.
 * @param array $form_state
 *   The form state array containing node ID of the node the user is being signed up for.
 */

function band_booking_registration_form_users_validate($element, &$form_state, $form) {
	// Set Error if element is required and empty
	if ($element['#required'] == TRUE && empty($element['#value'])) {
		form_error($element, t('This field is required !'));
		form_set_error($element['#id'], t('No users selected.'));
		return;
	}
	$users_to_add = $form_state['values']['add_users'];
	$available_artists_options = $form_state['values']['available_artists'];

	// Set Error if users selected aren't in availables users list
	foreach ($users_to_add as $key => $value) {
		if (!array_key_exists($value, $available_artists_options)) {
			form_error($element, t('This field is faulty.'));
			form_set_error($element['#id'], t('One user does not exist.'));
		}
	}
	return $element;
}

function band_booking_registration_register_many_users_form_validate($form, &$form_state) {
  if (!user_access('registrate users to performance registration')) {
    form_set_error('title', t('You are not allowed to register people.'));
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

function band_booking_registration_register_many_users_form_submit($form, &$form_state) {

	if (isset($form_state['values']['add_users'])) {
		$registration_base = $form_state['registration_base'];
		//$nid = $registration_base['entity_id'];
		$accounts = user_load_multiple( $form_state['values']['add_users'] );

		$registrations = array();

		$i = 0;
		foreach ($accounts as $key => $account) {
			$registrations[$i] = entity_get_controller('registration')->create($registration_base);
			$registrations[$i]->user_uid = $account->uid;
            $registrations[$i]->save();
			$i++;
		}
	}
}