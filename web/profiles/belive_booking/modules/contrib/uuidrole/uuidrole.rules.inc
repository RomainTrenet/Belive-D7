<?php
/**
 * @file
 * Rules actions/conditions for uuidrole
 */

/**
 * Implements hook_rules_action_info().
 */
function uuidrole_rules_action_info() {
  $items['uuidrole_user_add_role'] = array(
    'label' => t('Add user role UUID'),
    'base' => 'uuidrole_rules_action_user_add_role',
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user whose roles should be changed.'),
        'save' => TRUE,
      ),
      'roles' => array(
        'type' => 'list<text>',
        'label' => t('Roles'),
        'options list' => 'uuidrole_add_roles_options',
      ),
    ),
    'group' => t('User'),
    'access callback' => 'rules_user_role_change_access',
  );

  return $items;
}

/**
 * Implements hook_rules_condition_info().
 */
function uuidrole_rules_condition_info() {
  return array(
    'user_has_roleuuid' => array(
      'label' => t('User has role(s) UUID'),
      'parameter' => array(
        'account' => array('type' => 'user', 'label' => t('User')),
        'roles' => array(
          'type' => 'list<text>',
          'label' => t('Roles'),
          'options list' => 'uuidrole_roles_options',
        ),
        'operation' => array(
          'type' => 'text',
          'label' => t('Match roles'),
          'options list' => 'rules_user_condition_operations',
          'restriction' => 'input',
          'optional' => TRUE,
          'default value' => 'AND',
          'description' => t('If matching against all selected roles, the user must have <em>all</em> the roles selected.'),
        ),
      ),
      'group' => t('User'),
      'access callback' => 'rules_user_integration_access',
      'base' => 'uuidroles_rules_condition_user_has_roleuuid',
    ),
  );
}

/**
 * Options list callback for user roles uuid.
 */
function uuidrole_roles_options($element) {
  return uuidrole_roles();
}

/**
 * Options list callback for user roles uuid.
 */
function uuidrole_add_roles_options($element) {
  $roles = uuidrole_roles();

  if ($element instanceof RulesActionInterface) {
    unset($roles[UUIDROLE_ANONYMOUS]);
    unset($roles[UUIDROLE_AUTHENTICATED]);
  }

  return $roles;
}

/**
 * Condition user: condition to check whether user has particular roles
 */
function uuidroles_rules_condition_user_has_roleuuid($account, $roles, $operation = 'AND') {
  switch ($operation) {
    case 'OR':
      foreach ($roles as $uuid) {
        if (isset($account->uuidroles[$uuid])) {
          return TRUE;
        }
      }
      return FALSE;

    case 'AND':
      foreach ($roles as $uuid) {
        if (!isset($account->uuidroles[$uuid])) {
          return FALSE;
        }
      }
      return TRUE;
  }
}

/**
 * Action user: add role to user by its UUID.
 */
function uuidrole_rules_action_user_add_role($account, $roles) {
  if ($account->uid || !empty($account->is_new)) {
    // Get role list (minus the anonymous)
    $role_list = uuidrole_roles(TRUE);

    foreach ($roles as $ruuid) {
      $role = uuidrole__load($ruuid);
      $account->roles[$role->rid] = $role_list[$ruuid];
    }
    if (!empty($account->is_new) && $account->uid) {
      // user_save() inserts roles after invoking hook_user_insert() anyway, so
      // we skip saving to avoid errors due saving them twice.
      return FALSE;
    }
  }
  else {
    return FALSE;
  }
}
