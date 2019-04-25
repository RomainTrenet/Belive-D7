<?php

/**
 * Custom function to get default state for a given registation type
 */
function belive_registration_get_registration_type_default_state($registration_type) {
    $query = db_select('registration_type', 'r')
      ->condition('r.name', $registration_type, '=')
      ->fields('r', array('default_state'))
      ->execute()
      ->fetchField();

    return $query;
}

/**
 * Custom function to get corrects combinations
 */
function belive_registration_get_status_combinations() {
	return array(
    'waiting' => t('Waiting'),
    'postponed' => t('Postponed'),
    'accepted' => t('Accepted'),
    'refused' => t('Refused'),
  );
}

//belive_registration_handler_field_registration_state_past_tense_conjugation
function _get_registration_states_past_tense_conjugation($state) {
  $state_past_tense_conjugation = array(
    'waiting' => t('a mis en attente de décision'),
    'postponed' => t('a reporté'),
    'accepted' => t('a accepté'),
    'refused' => t('a refusé'),
  );
  return $state_past_tense_conjugation[$state];
}

/**
 * Custom function to get corrects combinations
 */
function belive_registration_get_actions_combinations() {
	return array(
      'wait' => t('Wait'),
      'postpone' => t('Postpone'),
      'accept' => t('Accept'),
      'refuse' => t('Refuse'),
    );
}

function _get_node_registrations_id_for_users($nid, $users_id) {
    $ids = array();

    $query = db_select('registration', 'r')
        ->condition('r.entity_id', $nid, '=')
        ->condition('r.user_uid', $users_id, 'IN')
        ->fields('r', array('registration_id'))
        ->execute();

    while($registration = $query->fetchAssoc()) {
        $ids[] = $registration['registration_id'];
    }
    return $ids;
}

function _get_node_registered_users($nid) {
    if ( is_numeric($nid) ) {
        $ids = array();

        $query = db_select('registration', 'e')
            ->condition('e.entity_id', $nid, '=')
            ->fields('e', array('user_uid'))
            ->execute();

        while($user = $query->fetchAssoc()) {
            $ids[] = $user['user_uid'];
        }

        return user_load_multiple($ids);
    }
}

/**
 * Get users id from users list, excepted users already selected
 * @param $excepted_users
 * @param $positions
 * @return mixed
 */
function _get_node_available_users($excepted_users) {
    $excepted_users_ids = array();
    foreach ($excepted_users as $uid => $value) {
        $excepted_users_ids[] = $uid;
    }

    //Get authorized roles
    $rolesId = variable_get('belive_registration_default_roles', array());

    $query=db_select('users','u');
    $query->fields('u',array('uid', 'name'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->condition('u.status', 1, '=');
    !empty($rolesId) ? $query->condition('ur.rid', $rolesId, 'IN') : NULL;
    !empty($excepted_users_ids) ? $query->condition('u.uid', $excepted_users_ids, 'NOT IN') : NULL;
    $rep = $query->execute()->fetchAll();

    $users_id = array();
    foreach ($rep as $key => $value) {
        $users_id[] = $value->uid;
    }
    return user_load_multiple($users_id);
}

/**
 * Get users id from users list, excepted users already selected and filter by artist position
 * @param $excepted_users
 * @param $positions
 * @return mixed
 */
function _get_node_available_users_id_with_position($excepted_users, $positions) {
    $excepted_users_ids = array();
    foreach ($excepted_users as $uid => $value) {
        $excepted_users_ids[$uid] = $uid;
    }

    //Get authorized roles
    $rolesId = variable_get('belive_registration_default_roles', array());

    $query=db_select('users','u');
    $query->fields('u',array('uid', 'name'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->condition('u.status', 1, '=');
    !empty($rolesId) ? $query->condition('ur.rid', $rolesId, 'IN') : NULL;
    !empty($excepted_users_ids) ? $query->condition('u.uid', $excepted_users_ids, 'NOT IN') : NULL;

    if (!empty($positions)) {
        $query->join('field_data_field_poste_de_l_artiste', 'pa', 'pa.entity_id = u.uid');
        $query->condition('pa.field_poste_de_l_artiste_tid', $positions, 'IN');
    }

    return $query->execute()->fetchAllKeyed();
}


/**
 * Get registration id from nid and uid
 * @param $nid
 * @param $uid
 * @return mixed
 */
function _get_registration_id($nid, $uid) {
  $query = db_select('registration', 'r')
    ->condition('r.entity_id', $nid, '=')
    ->condition('r.user_uid', $uid, '=')
    ->fields('r', array('registration_id'))
    ->execute()
    ->fetchField();

  return $query;
}

function _get_workflow_status_id_from_machine_name($states, $registration_state) {
  foreach ($states as $key => $state ) {
    if($state->name == $registration_state) {
      return $state->sid;
    }
  }
}

/**
 * Get a list of possible status (id => name)
 * @param $workflow_transitions
 * @param $registration_state_id
 * @param $roles
 * @return array
 */
function _get_belive_registration_worklflow_possible_statuses($workflow_transitions, $registration_state_id, $roles)
{
  $statuses = array();
  $transitions = _get_list_transitions_for_roles_and_state_id($workflow_transitions, $registration_state_id, $roles);
  foreach ($transitions as $key => $transition) {
    $state = workflow_state_load($transition->target_sid);
    $statuses[$state->name] = t($state->state);
  }
  return $statuses;
}

/**
 * Get a list of transition for a list of roles and a starting state id
 * @param $workflow_transitions
 * @param $roles
 * @param $registration_state_id
 * @return array
 */
function _get_list_transitions_for_roles_and_state_id($workflow_transitions, $registration_state_id, $roles) {
  $transitions = array();
  foreach($workflow_transitions as $key => $transition) {
    if ($transition->sid == $registration_state_id && $transition->sid != $transition->target_sid) {
      //Check roles
      foreach ($transition->roles as $role_key => $role) {
        if (array_key_exists($role, $roles)) {
          $transitions[$key] = $transition;
          break;
        }
      }
    }
  }
  return($transitions);
}

/**
 * Get states (like in registration_state table)
 * @return array
 */
function _get_belive_registration_states() {
  return array(
    0 => array(
      'name' => 'waiting',
      'label' => 'Waiting',
      'description' => 'Default registration state',
      'default_state' => 1,
      'active' => 1,
      'held' => 0,
      'show_on_form' => 1,
      'weight' => -15,
      'status' => 1,
      'module' => NULL,
    ),
    1 => array(
      'name' => 'postponed',
      'label' => 'Postponed',
      'description' => 'Registration is postponed.',
      'default_state' => 0,
      'active' => 1,
      'held' => 0,
      'show_on_form' => 0,
      'weight' => -14,
      'status' => 1,
      'module' => NULL,
    ),
    2 => array(
      'name' => 'accepted',
      'label' => 'Accepted',
      'description' => 'Registration is accepted.',
      'default_state' => 0,
      'active' => 1,
      'held' => 0,
      'show_on_form' => 0,
      'weight' => -13,
      'status' => 1,
      'module' => NULL,
    ),
    3 => array(
      'name' => 'refused',
      'label' => 'Refused',
      'description' => 'Registration is refused.',
      'default_state' => 0,
      'active' => 1,
      'held' => 0,
      'show_on_form' => 0,
      'weight' => -12,
      'status' => 1,
      'module' => NULL,
    ),
  );
}

/**
 * @param $nid
 * @param $users_id
 * @return array
 */
function _get_taxonomy_terms_options_formatted($vid) {
    $terms = db_select('taxonomy_term_data', 't')
        ->condition('t.vid', $vid, '=')
        ->fields('t', array('tid', 'name'))
        ->execute()
        ->fetchAllKeyed();
    return $terms;
}