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

function belive_registration_register_many_users_view ($node) {
  drupal_set_title($node->title);
  return drupal_get_form('belive_registration_register_many_users_form', $node);//, 'admin', FALSE);
}

function belive_registration_register_many_users_form($form, &$form_state, $node) {//, $register_type = 'auth') {
    //Attached custom js
    $form['#attached'] = array(
        'js' => array(
            drupal_get_path('module', 'belive_registration') . '/js/belive_registration.js' => array(
                'scope' => 'footer',
	              'weight' => 101
            ),
        ),
    );

	//Default values
	$default_users = !empty($form_state['input']['users']) ? $form_state['input']['users'] : array();

	//Vars
	$registered_musicians = _get_node_registered_users( $node->nid );
	$available_musicians = _get_node_available_users( $registered_musicians );
    $available_musicians_options = array();
    foreach ($available_musicians as $uid => $available_musician) {
        $available_musicians_options[$uid] = $available_musician->name;
    }

	//Construct form
    $markup_form = array();
    $position_form = array();
	$registration_form = array();

	global $user;

	$entity_type = 'node';
	$nid = $node->nid;
	$registration_type = $node->field_inscriptions['und'][0]['registration_type'];
	$registration_default_state = belive_registration_get_registration_type_default_state($registration_type);

    //Registered users markup
    $total_registered_musicians = count($registered_musicians);
    $registered_musicians_markup = $total_registered_musicians == 0 ? t('None') : '';
    $count = 1;
    foreach ($registered_musicians as $uid => $registered_user) {
        $registered_musicians_markup .= $registered_user->name . ($total_registered_musicians != $count ? ', ' : '.');
        $count++;
    }
    $markup_form['registered_musicians'] = array(
        '#type' => 'item',
        '#title' => t('Musicians already registered') . ' :',
        '#weight' => 0,
        '#markup' => '<p>' . $registered_musicians_markup . '</p>',
    );

    //Users list values and users form field
    $positions_list = array(
        '#type' => 'value',
        '#value' => _get_taxonomy_terms_options_formatted(2),
    );
    $position_form['position'] = array(
        '#type' => 'bootstrap_multiselect_field',
        '#required' => FALSE,
        '#multiple' => TRUE,
        '#title' => t('Filter by position'),
        '#description' => t('Select the musicians position to filter artists list.'),
        '#size' => 5,
        '#weight' => 0,
        '#options' => $positions_list['#value'],
        '#ajax' => array(
            'callback' => 'belive_registration_register_users_filter_position_callback',
            'event' => 'change',
        ),
    );

	//Pass available musicians to form validate to prevent adding fake users
	$registration_form['available_musicians'] = array(
	  '#type' => 'value',
	  '#value' => $available_musicians_options,
	);

    //Pass registered musicians to form validate
    $registration_form['registered_musicians'] = array(
        '#type' => 'value',
        '#value' => $registered_musicians,
    );

    //Users list values and users form field
    $users_list = array(
        '#type' => 'value',
        '#value' => $available_musicians_options,
    );

    $registration_form['users'] = array(
        '#type' => 'bootstrap_multiselect_field',
        '#required' => TRUE,
        '#multiple' => TRUE,
        '#title' => t('Add musicians'),
        '#description' => t('Select the musicians you want to add. Musicians already registered wont appear.'),
        '#default_value' => $default_users,
        '#size' => 5,
        '#weight' => 20,
        '#options' => $users_list['#value'],
        '#element_validate' => array('belive_registration_form_users_validate'),
        '#prefix' => '<div id="register_many_users">',
        '#suffix' => '</div>',
	);
    $form['markup_form'] = $markup_form;
    $form['position_filter_form'] = $position_form;
	$form['registration_user_form'] = $registration_form;

	//The base registration array, used to create each registration object
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
	

  	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Register users'),
	);
	return $form;
}

/**
 * Callback element needs only select the portion of the form to be updated.
 * Since #ajax['callback'] return can be HTML or a renderable array (or an
 * array of commands), we can just return a piece of the form.
 */
function belive_registration_register_users_filter_position_callback($form, $form_state) {
    $available_musicians_options = $form['registration_user_form']['available_musicians']['#value'];//$form['registration_user_form']['users']['#options'];
    $registered_musicians = $form['registration_user_form']['registered_musicians']['#value'];
    $musicians_with_position = _get_node_available_users_id_with_position( $registered_musicians, $form_state['values']['position']);
    $musicians_to_hide=array_diff_key($available_musicians_options,$musicians_with_position);

//    dpm($available_musicians_options);
//    dpm($musicians_with_position);
//    dpm($musicians_to_hide);

    $commands[] = array(
        'command' => 'afterAjaxCallbackExample',
        'musicians_with_position' => $musicians_with_position,
        'musicians_to_hide' => $musicians_to_hide,
    );

    return array('#type' => 'ajax','#commands' => $commands);
}

/**
 * Validates the user id on the admin form to register another user.
 *
 * @param array $form
 *   Form array for the username field.
 * @param array $form_state
 *   The form state array containing node ID of the node the user is being signed up for.
 */

function belive_registration_form_users_validate($element, &$form_state, $form) {
	// Set Error if element is required and empty
	if ($element['#required'] == TRUE && empty($element['#value'])) {
		form_error($element, t('This field is required !'));
		form_set_error($element['#id'], t('No users selected.'));
		return;
	}
	$users_to_add = $form_state['values']['users'];
	$available_musicians_options = $form_state['values']['available_musicians'];

	// Set Error if users selected aren't in availables users list
	foreach ($users_to_add as $key => $value) {
		if (!array_key_exists($value, $available_musicians_options)) {
			form_error($element, t('This field is faulty.'));
			form_set_error($element['#id'], t('One user does not exist.'));
		}
	}
	return $element;
}

function belive_registration_register_many_users_form_validate($form, &$form_state) {
	if (!user_access('registrate users to belive performance')) {
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

function belive_registration_register_many_users_form_submit($form, &$form_state) {

	if (isset($form_state['values']['users'])) {
		$registration_base = $form_state['registration_base'];
		$nid = $registration_base['entity_id'];
		$accounts = user_load_multiple( $form_state['values']['users'] );

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