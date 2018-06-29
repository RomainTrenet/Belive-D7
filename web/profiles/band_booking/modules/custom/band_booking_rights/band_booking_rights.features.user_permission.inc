<?php
/**
 * @file
 * band_booking_rights.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function band_booking_rights_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Artiste' => 'Artiste',
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer band booking'.
  $permissions['administer band booking'] = array(
    'name' => 'administer band booking',
    'roles' => array(
      'Gérant' => 'Gérant',
    ),
    'module' => 'band_booking_admin',
  );

  // Exported permission: 'administer band booking registration'.
  $permissions['administer band booking registration'] = array(
    'name' => 'administer band booking registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'band_booking_registration',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer bootstrap multiselect'.
  $permissions['administer bootstrap multiselect'] = array(
    'name' => 'administer bootstrap multiselect',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'bootstrap_multiselect',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer front page'.
  $permissions['administer front page'] = array(
    'name' => 'administer front page',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'front_page',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer messaging'.
  $permissions['administer messaging'] = array(
    'name' => 'administer messaging',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'messaging',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer own performance registration'.
  $permissions['administer own performance registration'] = array(
    'name' => 'administer own performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer performance registration'.
  $permissions['administer performance registration'] = array(
    'name' => 'administer performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer position vocabulary terms'.
  $permissions['administer position vocabulary terms'] = array(
    'name' => 'administer position vocabulary terms',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profile2_regpath'.
  $permissions['administer profile2_regpath'] = array(
    'name' => 'administer profile2_regpath',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'profile2_regpath',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer registration'.
  $permissions['administer registration'] = array(
    'name' => 'administer registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration states'.
  $permissions['administer registration states'] = array(
    'name' => 'administer registration states',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration types'.
  $permissions['administer registration types'] = array(
    'name' => 'administer registration types',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer tags vocabulary terms'.
  $permissions['administer tags vocabulary terms'] = array(
    'name' => 'administer tags vocabulary terms',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workflow'.
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 4'.
  $permissions['cancel users with role 4'] = array(
    'name' => 'cancel users with role 4',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 5'.
  $permissions['cancel users with role 5'] = array(
    'name' => 'cancel users with role 5',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Artiste' => 'Artiste',
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create performance content'.
  $permissions['create performance content'] = array(
    'name' => 'create performance content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create performance registration'.
  $permissions['create performance registration'] = array(
    'name' => 'create performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create performance registration other anonymous'.
  $permissions['create performance registration other anonymous'] = array(
    'name' => 'create performance registration other anonymous',
    'roles' => array(
      'Gérant' => 'Gérant',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create performance registration other users'.
  $permissions['create performance registration other users'] = array(
    'name' => 'create performance registration other users',
    'roles' => array(
      'Gérant' => 'Gérant',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create performance registration self'.
  $permissions['create performance registration self'] = array(
    'name' => 'create performance registration self',
    'roles' => array(),
    'module' => 'registration',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any performance content'.
  $permissions['delete any performance content'] = array(
    'name' => 'delete any performance content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any performance registration'.
  $permissions['delete any performance registration'] = array(
    'name' => 'delete any performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own performance content'.
  $permissions['delete own performance content'] = array(
    'name' => 'delete own performance content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own performance registration'.
  $permissions['delete own performance registration'] = array(
    'name' => 'delete own performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in position'.
  $permissions['delete terms in position'] = array(
    'name' => 'delete terms in position',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any performance content'.
  $permissions['edit any performance content'] = array(
    'name' => 'edit any performance content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any performance registration status'.
  $permissions['edit any performance registration status'] = array(
    'name' => 'edit any performance registration status',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'band_booking_registration',
  );

  // Exported permission: 'edit any profil_musicien profile'.
  $permissions['edit any profil_musicien profile'] = array(
    'name' => 'edit any profil_musicien profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own performance content'.
  $permissions['edit own performance content'] = array(
    'name' => 'edit own performance content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own performance registration status'.
  $permissions['edit own performance registration status'] = array(
    'name' => 'edit own performance registration status',
    'roles' => array(
      'Artiste' => 'Artiste',
    ),
    'module' => 'band_booking_registration',
  );

  // Exported permission: 'edit own profil_musicien profile'.
  $permissions['edit own profil_musicien profile'] = array(
    'name' => 'edit own profil_musicien profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit performance registration state'.
  $permissions['edit performance registration state'] = array(
    'name' => 'edit performance registration state',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'edit terms in position'.
  $permissions['edit terms in position'] = array(
    'name' => 'edit terms in position',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 4'.
  $permissions['edit users with role 4'] = array(
    'name' => 'edit users with role 4',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 5'.
  $permissions['edit users with role 5'] = array(
    'name' => 'edit users with role 5',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit workflow comment'.
  $permissions['edit workflow comment'] = array(
    'name' => 'edit workflow comment',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'features',
  );

  // Exported permission: 'grant content access'.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'grant own content access'.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'participate in workflow'.
  $permissions['participate in workflow'] = array(
    'name' => 'participate in workflow',
    'roles' => array(
      'Artiste' => 'Artiste',
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'registrate users to performance registration'.
  $permissions['registrate users to performance registration'] = array(
    'name' => 'registrate users to performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'band_booking_registration',
  );

  // Exported permission: 'relaunch waiting users registration'.
  $permissions['relaunch waiting users registration'] = array(
    'name' => 'relaunch waiting users registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'belive_registration_relaunch',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule workflow transitions'.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show workflow state form'.
  $permissions['show workflow state form'] = array(
    'name' => 'show workflow state form',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'update any performance registration'.
  $permissions['update any performance registration'] = array(
    'name' => 'update any performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'update own performance registration'.
  $permissions['update own performance registration'] = array(
    'name' => 'update own performance registration',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any profil_musicien profile'.
  $permissions['view any profil_musicien profile'] = array(
    'name' => 'view any profil_musicien profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'view own performance registration'.
  $permissions['view own performance registration'] = array(
    'name' => 'view own performance registration',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view own profil_musicien profile'.
  $permissions['view own profil_musicien profile'] = array(
    'name' => 'view own profil_musicien profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view performance registration'.
  $permissions['view performance registration'] = array(
    'name' => 'view performance registration',
    'roles' => array(
      'Gérant' => 'Gérant',
      'administrateur' => 'administrateur',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrateur' => 'administrateur',
    ),
    'module' => 'system',
  );

  return $permissions;
}
