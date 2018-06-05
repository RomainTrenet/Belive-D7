<?php
/**
 * @file
 * belive_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function belive_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_account-settings:admin/config/people/accounts.
  $menu_links['management_account-settings:admin/config/people/accounts'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/accounts',
    'router_path' => 'admin/config/people/accounts',
    'link_title' => 'Account settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure default behavior of users, including registration requirements, e-mails, fields, and user pictures.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_account-settings:admin/config/people/accounts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_personnes:admin/config/people',
  );
  // Exported menu link: management_actions:admin/config/system/actions.
  $menu_links['management_actions:admin/config/system/actions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/actions',
    'router_path' => 'admin/config/system/actions',
    'link_title' => 'Actions',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage the actions defined for your site.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_actions:admin/config/system/actions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_systme:admin/config/system',
  );
  // Exported menu link: management_adminimal-menu:admin/config/administration/adminimal_menu.
  $menu_links['management_adminimal-menu:admin/config/administration/adminimal_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/adminimal_menu',
    'router_path' => 'admin/config/administration/adminimal_menu',
    'link_title' => 'Adminimal menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust adminimal menu settings.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_adminimal-menu:admin/config/administration/adminimal_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin/config/administration',
  );
  // Exported menu link: management_administration:admin.
  $menu_links['management_administration:admin'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin',
    'router_path' => 'admin',
    'link_title' => 'Administration',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_administration:admin',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
  );
  // Exported menu link: management_administration:admin/config/administration.
  $menu_links['management_administration:admin/config/administration'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration',
    'router_path' => 'admin/config/administration',
    'link_title' => 'Administration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administration tools.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_administration:admin/config/administration',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_ajouter-une-prestation:node/add/performance.
  $menu_links['management_ajouter-une-prestation:node/add/performance'] = array(
    'menu_name' => 'management',
    'link_path' => 'node/add/performance',
    'router_path' => 'node/add/performance',
    'link_title' => 'Ajouter une prestation',
    'options' => array(
      'attributes' => array(
        'title' => 'Ajouter une prestation',
      ),
      'identifier' => 'management_ajouter-une-prestation:node/add/performance',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_appearance:admin/appearance.
  $menu_links['management_appearance:admin/appearance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/appearance',
    'router_path' => 'admin/appearance',
    'link_title' => 'Appearance',
    'options' => array(
      'attributes' => array(
        'title' => 'Select and configure your themes.',
      ),
      'identifier' => 'management_appearance:admin/appearance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_arrange:admin/config/front/arrange.
  $menu_links['management_arrange:admin/config/front/arrange'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/front/arrange',
    'router_path' => 'admin/config/front/arrange',
    'link_title' => 'Arrange',
    'options' => array(
      'attributes' => array(
        'title' => 'Ability to re-arrange what order front page roles are processed.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_arrange:admin/config/front/arrange',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 0,
    'parent_identifier' => 'management_front-page:admin/config/front',
  );
  // Exported menu link: management_artistes:admin/people.
  $menu_links['management_artistes:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Artistes',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage user accounts, roles, and permissions.',
      ),
      'identifier' => 'management_artistes:admin/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_artists:admin/artists.
  $menu_links['management_artists:admin/artists'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/artists',
    'router_path' => 'admin/artists',
    'link_title' => 'Artists',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_artists:admin/artists',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_available-updates:admin/reports/updates.
  $menu_links['management_available-updates:admin/reports/updates'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/updates',
    'router_path' => 'admin/reports/updates',
    'link_title' => 'Available updates',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about available updates for your installed modules and themes.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_available-updates:admin/reports/updates',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_backup-and-migrate:admin/config/system/backup_migrate.
  $menu_links['management_backup-and-migrate:admin/config/system/backup_migrate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/backup_migrate',
    'router_path' => 'admin/config/system/backup_migrate',
    'link_title' => 'Backup and Migrate',
    'options' => array(
      'attributes' => array(
        'title' => 'Backup/restore your database and files or migrate data to or from another Drupal site.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_backup-and-migrate:admin/config/system/backup_migrate',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_systme:admin/config/system',
  );
  // Exported menu link: management_belive-registration-roles:admin/structure/registration/belive-registration/roles.
  $menu_links['management_belive-registration-roles:admin/structure/registration/belive-registration/roles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/registration/belive-registration/roles',
    'router_path' => 'admin/structure/registration/belive-registration/roles',
    'link_title' => 'Belive Registration roles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the roles for Belive Registration',
      ),
      'alter' => TRUE,
      'identifier' => 'management_belive-registration-roles:admin/structure/registration/belive-registration/roles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_inscription:admin/structure/registration',
  );
  // Exported menu link: management_blocks:admin/structure/block.
  $menu_links['management_blocks:admin/structure/block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure what block content appears in your site\'s sidebars and other regions.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_blocks:admin/structure/block',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_bootstrapmultiselectjs:admin/config/media/bootstrap-multiselect.
  $menu_links['management_bootstrapmultiselectjs:admin/config/media/bootstrap-multiselect'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/bootstrap-multiselect',
    'router_path' => 'admin/config/media/bootstrap-multiselect',
    'link_title' => 'BootstrapMultiselect.js',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the settings for the bootstrap_multiselect.js module.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_bootstrapmultiselectjs:admin/config/media/bootstrap-multiselect',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_mdia:admin/config/media',
  );
  // Exported menu link: management_calendar:admin/config/date/calendar.
  $menu_links['management_calendar:admin/config/date/calendar'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date/calendar',
    'router_path' => 'admin/config/date/calendar',
    'link_title' => 'Calendar',
    'options' => array(
      'attributes' => array(
        'title' => 'Calendar administration.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_calendar:admin/config/date/calendar',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_date-api:admin/config/date',
  );
  // Exported menu link: management_clean-urls:admin/config/search/clean-urls.
  $menu_links['management_clean-urls:admin/config/search/clean-urls'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/clean-urls',
    'router_path' => 'admin/config/search/clean-urls',
    'link_title' => 'Clean URLs',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable clean URLs for your site.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_clean-urls:admin/config/search/clean-urls',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_recherche-et-metadonnes:admin/config/search',
  );
  // Exported menu link: management_configuration:admin/config.
  $menu_links['management_configuration:admin/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config',
    'router_path' => 'admin/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer settings.',
      ),
      'identifier' => 'management_configuration:admin/config',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_content-authoring:admin/config/content.
  $menu_links['management_content-authoring:admin/config/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content',
    'router_path' => 'admin/config/content',
    'link_title' => 'Content authoring',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings related to formatting and authoring content.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_content-authoring:admin/config/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_content-types:admin/structure/types.
  $menu_links['management_content-types:admin/structure/types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/types',
    'router_path' => 'admin/structure/types',
    'link_title' => 'Content types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage content types, including default status, front page promotion, comment settings, etc.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_content-types:admin/structure/types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_content:admin/content.
  $menu_links['management_content:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer content and comments.',
      ),
      'identifier' => 'management_content:admin/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_cron:admin/config/system/cron.
  $menu_links['management_cron:admin/config/system/cron'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/cron',
    'router_path' => 'admin/config/system/cron',
    'link_title' => 'Cron',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage automatic site maintenance tasks.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_cron:admin/config/system/cron',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_systme:admin/config/system',
  );
  // Exported menu link: management_dashboard:admin/dashboard.
  $menu_links['management_dashboard:admin/dashboard'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => 'View and customize your dashboard.',
      ),
      'identifier' => 'management_dashboard:admin/dashboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_date-and-time:admin/config/regional/date-time.
  $menu_links['management_date-and-time:admin/config/regional/date-time'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/date-time',
    'router_path' => 'admin/config/regional/date-time',
    'link_title' => 'Date and time',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure display formats for date and time.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_date-and-time:admin/config/regional/date-time',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_rgionalisation-et-langue:admin/config/regional',
  );
  // Exported menu link: management_date-api:admin/config/date.
  $menu_links['management_date-api:admin/config/date'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date',
    'router_path' => 'admin/config/date',
    'link_title' => 'Date API',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for modules the use the Date API.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_date-api:admin/config/date',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_date-popup:admin/config/date/date_popup.
  $menu_links['management_date-popup:admin/config/date/date_popup'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date/date_popup',
    'router_path' => 'admin/config/date/date_popup',
    'link_title' => 'Date Popup',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the Date Popup settings.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_date-popup:admin/config/date/date_popup',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_date-api:admin/config/date',
  );
  // Exported menu link: management_devel-settings:admin/config/development/devel.
  $menu_links['management_devel-settings:admin/config/development/devel'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/devel',
    'router_path' => 'admin/config/development/devel',
    'link_title' => 'Devel settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Helper functions, pages, and blocks to assist Drupal developers. The devel blocks can be managed via the <a href="/admin/structure/block">block administration</a> page.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_devel-settings:admin/config/development/devel',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_development:admin/config/development.
  $menu_links['management_development:admin/config/development'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development',
    'router_path' => 'admin/config/development',
    'link_title' => 'Development',
    'options' => array(
      'attributes' => array(
        'title' => 'Development tools.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_development:admin/config/development',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_example-help:admin/help_example.
  $menu_links['management_example-help:admin/help_example'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/help_example',
    'router_path' => 'admin',
    'link_title' => 'Example help',
    'options' => array(
      'identifier' => 'management_example-help:admin/help_example',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_exemples-prestations:admin/structure/menu/manage/menu-exemples-prestations.
  $menu_links['management_exemples-prestations:admin/structure/menu/manage/menu-exemples-prestations'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-exemples-prestations',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Exemples prestations',
    'options' => array(
      'identifier' => 'management_exemples-prestations:admin/structure/menu/manage/menu-exemples-prestations',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_features:admin/structure/features.
  $menu_links['management_features:admin/structure/features'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage features.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_features:admin/structure/features',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_field-list:admin/reports/fields.
  $menu_links['management_field-list:admin/reports/fields'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/fields',
    'router_path' => 'admin/reports/fields',
    'link_title' => 'Field list',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of fields on all entity types.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_field-list:admin/reports/fields',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_file-system:admin/config/media/file-system.
  $menu_links['management_file-system:admin/config/media/file-system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-system',
    'router_path' => 'admin/config/media/file-system',
    'link_title' => 'File system',
    'options' => array(
      'attributes' => array(
        'title' => 'Tell Drupal where to store uploaded files and how they are accessed.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_file-system:admin/config/media/file-system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_mdia:admin/config/media',
  );
  // Exported menu link: management_front-page:admin/config/front.
  $menu_links['management_front-page:admin/config/front'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/front',
    'router_path' => 'admin/config/front',
    'link_title' => 'Front Page',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure front page.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_front-page:admin/config/front',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_help:admin/help.
  $menu_links['management_help:admin/help'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/help',
    'router_path' => 'admin/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => 'Reference for usage, configuration, and modules.',
      ),
      'identifier' => 'management_help:admin/help',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_home-links:admin/config/front/home-links.
  $menu_links['management_home-links:admin/config/front/home-links'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/front/home-links',
    'router_path' => 'admin/config/front/home-links',
    'link_title' => 'Home links',
    'options' => array(
      'attributes' => array(
        'title' => 'Allows you to change the location of the &lt;front&gt; placeholder.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_home-links:admin/config/front/home-links',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 0,
    'parent_identifier' => 'management_front-page:admin/config/front',
  );
  // Exported menu link: management_image-styles:admin/config/media/image-styles.
  $menu_links['management_image-styles:admin/config/media/image-styles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-styles',
    'router_path' => 'admin/config/media/image-styles',
    'link_title' => 'Image styles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure styles that can be used for resizing or adjusting images on display.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_image-styles:admin/config/media/image-styles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_mdia:admin/config/media',
  );
  // Exported menu link: management_image-toolkit:admin/config/media/image-toolkit.
  $menu_links['management_image-toolkit:admin/config/media/image-toolkit'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-toolkit',
    'router_path' => 'admin/config/media/image-toolkit',
    'link_title' => 'Image toolkit',
    'options' => array(
      'attributes' => array(
        'title' => 'Choose which image toolkit to use if you have installed optional toolkits.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_image-toolkit:admin/config/media/image-toolkit',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_mdia:admin/config/media',
  );
  // Exported menu link: management_ip-address-blocking:admin/config/people/ip-blocking.
  $menu_links['management_ip-address-blocking:admin/config/people/ip-blocking'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/ip-blocking',
    'router_path' => 'admin/config/people/ip-blocking',
    'link_title' => 'IP address blocking',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage blocked IP addresses.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_ip-address-blocking:admin/config/people/ip-blocking',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_personnes:admin/config/people',
  );
  // Exported menu link: management_jquery-update:admin/config/development/jquery_update.
  $menu_links['management_jquery-update:admin/config/development/jquery_update'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/jquery_update',
    'router_path' => 'admin/config/development/jquery_update',
    'link_title' => 'jQuery update',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure settings related to the jQuery upgrade, the library path and compression.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_jquery-update:admin/config/development/jquery_update',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_languages:admin/config/regional/language.
  $menu_links['management_languages:admin/config/regional/language'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/language',
    'router_path' => 'admin/config/regional/language',
    'link_title' => 'Languages',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure languages for content and the user interface.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_languages:admin/config/regional/language',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_rgionalisation-et-langue:admin/config/regional',
  );
  // Exported menu link: management_les-inscriptions:admin/registrations.
  $menu_links['management_les-inscriptions:admin/registrations'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/registrations',
    'router_path' => 'admin/registrations',
    'link_title' => 'Les inscriptions',
    'options' => array(
      'identifier' => 'management_les-inscriptions:admin/registrations',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -37,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_les-prestations:admin/performances.
  $menu_links['management_les-prestations:admin/performances'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/performances',
    'router_path' => 'admin/performances',
    'link_title' => 'Les prestations',
    'options' => array(
      'attributes' => array(
        'title' => 'Les prestations',
      ),
      'identifier' => 'management_les-prestations:admin/performances',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_libraries:admin/reports/libraries.
  $menu_links['management_libraries:admin/reports/libraries'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/libraries',
    'router_path' => 'admin/reports/libraries',
    'link_title' => 'Libraries',
    'options' => array(
      'attributes' => array(
        'title' => 'An overview of libraries installed on this site.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_libraries:admin/reports/libraries',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_logging-and-errors:admin/config/development/logging.
  $menu_links['management_logging-and-errors:admin/config/development/logging'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/logging',
    'router_path' => 'admin/config/development/logging',
    'link_title' => 'Logging and errors',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for logging and alerts modules. Various modules can route Drupal\'s system events to different destinations, such as syslog, database, email, etc.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_logging-and-errors:admin/config/development/logging',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_maintenance-mode:admin/config/development/maintenance.
  $menu_links['management_maintenance-mode:admin/config/development/maintenance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/maintenance',
    'router_path' => 'admin/config/development/maintenance',
    'link_title' => 'Maintenance mode',
    'options' => array(
      'attributes' => array(
        'title' => 'Take the site offline for maintenance or bring it back online.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_maintenance-mode:admin/config/development/maintenance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_management:admin/structure/menu/manage/management.
  $menu_links['management_management:admin/structure/menu/manage/management'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/management',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Management',
    'options' => array(
      'identifier' => 'management_management:admin/structure/menu/manage/management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_masquerade:admin/config/people/masquerade.
  $menu_links['management_masquerade:admin/config/people/masquerade'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/masquerade',
    'router_path' => 'admin/config/people/masquerade',
    'link_title' => 'Masquerade',
    'options' => array(
      'attributes' => array(
        'title' => 'Masquerade module allows administrators to masquerade as other users.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_masquerade:admin/config/people/masquerade',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_personnes:admin/config/people',
  );
  // Exported menu link: management_media:admin/config/media.
  $menu_links['management_media:admin/config/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media',
    'router_path' => 'admin/config/media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Media tools.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_media:admin/config/media',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_menu-principal:admin/structure/menu/manage/main-menu.
  $menu_links['management_menu-principal:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Menu principal',
    'options' => array(
      'identifier' => 'management_menu-principal:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_menus:admin/structure/menu.
  $menu_links['management_menus:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_menus:admin/structure/menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_messaging--notifications:admin/config/messaging.
  $menu_links['management_messaging--notifications:admin/config/messaging'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/messaging',
    'router_path' => 'admin/config/messaging',
    'link_title' => 'Messaging & Notifications',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer and configure messaging',
      ),
      'alter' => TRUE,
      'identifier' => 'management_messaging--notifications:admin/config/messaging',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_messaging-settings:admin/config/messaging/settings.
  $menu_links['management_messaging-settings:admin/config/messaging/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/messaging/settings',
    'router_path' => 'admin/config/messaging/settings',
    'link_title' => 'Messaging settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configuration of messaging framework',
      ),
      'alter' => TRUE,
      'identifier' => 'management_messaging-settings:admin/config/messaging/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_envois--notifications:admin/config/messaging',
  );
  // Exported menu link: management_metatag:admin/config/search/metatags.
  $menu_links['management_metatag:admin/config/search/metatags'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/metatags',
    'router_path' => 'admin/config/search/metatags',
    'link_title' => 'Metatag',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure Metatag defaults.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_metatag:admin/config/search/metatags',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_recherche-et-metadonnes:admin/config/search',
  );
  // Exported menu link: management_module-filter:admin/config/user-interface/modulefilter.
  $menu_links['management_module-filter:admin/config/user-interface/modulefilter'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/modulefilter',
    'router_path' => 'admin/config/user-interface/modulefilter',
    'link_title' => 'Module filter',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how the modules page looks and acts.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_module-filter:admin/config/user-interface/modulefilter',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_interface-utilisateur:admin/config/user-interface',
  );
  // Exported menu link: management_modules:admin/modules.
  $menu_links['management_modules:admin/modules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/modules',
    'router_path' => 'admin/modules',
    'link_title' => 'Modules',
    'options' => array(
      'attributes' => array(
        'title' => 'Extend site functionality.',
      ),
      'identifier' => 'management_modules:admin/modules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_multilingual-settings:admin/config/regional/i18n.
  $menu_links['management_multilingual-settings:admin/config/regional/i18n'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/i18n',
    'router_path' => 'admin/config/regional/i18n',
    'link_title' => 'Multilingual settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure extended options for multilingual content and translations.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_multilingual-settings:admin/config/regional/i18n',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_rgionalisation-et-langue:admin/config/regional',
  );
  // Exported menu link: management_navigation:admin/structure/menu/manage/navigation.
  $menu_links['management_navigation:admin/structure/menu/manage/navigation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/navigation',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Navigation',
    'options' => array(
      'identifier' => 'management_navigation:admin/structure/menu/manage/navigation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_notifications-settings:admin/config/messaging/notifications.
  $menu_links['management_notifications-settings:admin/config/messaging/notifications'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/messaging/notifications',
    'router_path' => 'admin/config/messaging/notifications',
    'link_title' => 'Notifications settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure notifications.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_notifications-settings:admin/config/messaging/notifications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_envois--notifications:admin/config/messaging',
  );
  // Exported menu link: management_people:admin/config/people.
  $menu_links['management_people:admin/config/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people',
    'router_path' => 'admin/config/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure user accounts.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_people:admin/config/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_performance:admin/config/development/performance.
  $menu_links['management_performance:admin/config/development/performance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/performance',
    'router_path' => 'admin/config/development/performance',
    'link_title' => 'Performance',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable page caching for anonymous users and set CSS and JS bandwidth optimization options.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_performance:admin/config/development/performance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_postes-des-artistes:admin/structure/taxonomy/position.
  $menu_links['management_postes-des-artistes:admin/structure/taxonomy/position'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy/position',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Postes des artistes',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'management_postes-des-artistes:admin/structure/taxonomy/position',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_processus-workflows:admin/config/workflow/workflow.
  $menu_links['management_processus-workflows:admin/config/workflow/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/workflow',
    'router_path' => 'admin/config/workflow/workflow',
    'link_title' => 'Processus (workflows)',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Processus (workflows).',
      ),
      'alter' => TRUE,
      'identifier' => 'management_processus-workflows:admin/config/workflow/workflow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_processus:admin/config/workflow',
  );
  // Exported menu link: management_recent-log-messages:admin/reports/dblog.
  $menu_links['management_recent-log-messages:admin/reports/dblog'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/dblog',
    'router_path' => 'admin/reports/dblog',
    'link_title' => 'Recent log messages',
    'options' => array(
      'attributes' => array(
        'title' => 'View events that have recently been logged.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_recent-log-messages:admin/reports/dblog',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_regional-and-language:admin/config/regional.
  $menu_links['management_regional-and-language:admin/config/regional'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional',
    'router_path' => 'admin/config/regional',
    'link_title' => 'Regional and language',
    'options' => array(
      'attributes' => array(
        'title' => 'Regional settings, localization and translation.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_regional-and-language:admin/config/regional',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_regional-settings:admin/config/regional/settings.
  $menu_links['management_regional-settings:admin/config/regional/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/settings',
    'router_path' => 'admin/config/regional/settings',
    'link_title' => 'Regional settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for the site\'s default time zone and country.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_regional-settings:admin/config/regional/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_rgionalisation-et-langue:admin/config/regional',
  );
  // Exported menu link: management_registration-role:admin/config/people/registration_role.
  $menu_links['management_registration-role:admin/config/people/registration_role'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/registration_role',
    'router_path' => 'admin/config/people/registration_role',
    'link_title' => 'Registration role',
    'options' => array(
      'attributes' => array(
        'title' => 'Auto-assign a role upon registration.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_registration-role:admin/config/people/registration_role',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_personnes:admin/config/people',
  );
  // Exported menu link: management_registration-states:admin/structure/registration/registration_states.
  $menu_links['management_registration-states:admin/structure/registration/registration_states'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/registration/registration_states',
    'router_path' => 'admin/structure/registration/registration_states',
    'link_title' => 'Registration states',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Registration states.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_registration-states:admin/structure/registration/registration_states',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_inscription:admin/structure/registration',
  );
  // Exported menu link: management_registration-types:admin/structure/registration/registration_types.
  $menu_links['management_registration-types:admin/structure/registration/registration_types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/registration/registration_types',
    'router_path' => 'admin/structure/registration/registration_types',
    'link_title' => 'Registration types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage registration entity types, including adding and removing fields and the display of fields.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_registration-types:admin/structure/registration/registration_types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_inscription:admin/structure/registration',
  );
  // Exported menu link: management_registration:admin/structure/registration.
  $menu_links['management_registration:admin/structure/registration'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/registration',
    'router_path' => 'admin/structure/registration',
    'link_title' => 'Registration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer Registration items, such as types, states, etc.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_registration:admin/structure/registration',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_reports:admin/reports.
  $menu_links['management_reports:admin/reports'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'View reports, updates, and errors.',
      ),
      'identifier' => 'management_reports:admin/reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_rss-publishing:admin/config/services/rss-publishing.
  $menu_links['management_rss-publishing:admin/config/services/rss-publishing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/rss-publishing',
    'router_path' => 'admin/config/services/rss-publishing',
    'link_title' => 'RSS publishing',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the site description, the number of items per feed and whether feeds should be titles/teasers/full-text.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_rss-publishing:admin/config/services/rss-publishing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_services-web:admin/config/services',
  );
  // Exported menu link: management_rules:admin/config/workflow/rules.
  $menu_links['management_rules:admin/config/workflow/rules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/rules',
    'router_path' => 'admin/config/workflow/rules',
    'link_title' => 'Rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage reaction rules and rule components.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_rules:admin/config/workflow/rules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_processus:admin/config/workflow',
  );
  // Exported menu link: management_search-and-metadata:admin/config/search.
  $menu_links['management_search-and-metadata:admin/config/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search',
    'router_path' => 'admin/config/search',
    'link_title' => 'Search and metadata',
    'options' => array(
      'attributes' => array(
        'title' => 'Local site search, metadata and SEO.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_search-and-metadata:admin/config/search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_search-settings:admin/config/search/settings.
  $menu_links['management_search-settings:admin/config/search/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/settings',
    'router_path' => 'admin/config/search/settings',
    'link_title' => 'Search settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure relevance settings for search and other indexing options.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_search-settings:admin/config/search/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_recherche-et-metadonnes:admin/config/search',
  );
  // Exported menu link: management_send-methods:admin/config/messaging/method.
  $menu_links['management_send-methods:admin/config/messaging/method'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/messaging/method',
    'router_path' => 'admin/config/messaging/method',
    'link_title' => 'Send methods',
    'options' => array(
      'attributes' => array(
        'title' => 'Configuration of sending methods',
      ),
      'alter' => TRUE,
      'identifier' => 'management_send-methods:admin/config/messaging/method',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_envois--notifications:admin/config/messaging',
  );
  // Exported menu link: management_settings:admin/config/front/settings.
  $menu_links['management_settings:admin/config/front/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/front/settings',
    'router_path' => 'admin/config/front/settings',
    'link_title' => 'Settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer custom front page settings.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_settings:admin/config/front/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_front-page:admin/config/front',
  );
  // Exported menu link: management_shortcuts:admin/config/user-interface/shortcut.
  $menu_links['management_shortcuts:admin/config/user-interface/shortcut'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/shortcut',
    'router_path' => 'admin/config/user-interface/shortcut',
    'link_title' => 'Shortcuts',
    'options' => array(
      'attributes' => array(
        'title' => 'Add and modify shortcut sets.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_shortcuts:admin/config/user-interface/shortcut',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_interface-utilisateur:admin/config/user-interface',
  );
  // Exported menu link: management_site-information:admin/config/system/site-information.
  $menu_links['management_site-information:admin/config/system/site-information'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/site-information',
    'router_path' => 'admin/config/system/site-information',
    'link_title' => 'Site information',
    'options' => array(
      'attributes' => array(
        'title' => 'Change site name, e-mail address, slogan, default front page, and number of posts per page, error pages.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_site-information:admin/config/system/site-information',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_systme:admin/config/system',
  );
  // Exported menu link: management_status-report:admin/reports/status.
  $menu_links['management_status-report:admin/reports/status'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/status',
    'router_path' => 'admin/reports/status',
    'link_title' => 'Status report',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about your site\'s operation and any detected problems.',
      ),
      'identifier' => 'management_status-report:admin/reports/status',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_strongarm:admin/config/development/strongarm.
  $menu_links['management_strongarm:admin/config/development/strongarm'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/strongarm',
    'router_path' => 'admin/config/development/strongarm',
    'link_title' => 'Strongarm',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Drupal variable settings that have been strongarmed.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_strongarm:admin/config/development/strongarm',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_dveloppement:admin/config/development',
  );
  // Exported menu link: management_structure:admin/structure.
  $menu_links['management_structure:admin/structure'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer blocks, content types, menus, etc.',
      ),
      'identifier' => 'management_structure:admin/structure',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_subscriptions-settings:admin/config/messaging/subscriptions.
  $menu_links['management_subscriptions-settings:admin/config/messaging/subscriptions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/messaging/subscriptions',
    'router_path' => 'admin/config/messaging/subscriptions',
    'link_title' => 'Subscriptions settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure subscription types and options.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_subscriptions-settings:admin/config/messaging/subscriptions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_envois--notifications:admin/config/messaging',
  );
  // Exported menu link: management_subscriptions:admin/notifications.
  $menu_links['management_subscriptions:admin/notifications'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/notifications',
    'router_path' => 'admin/notifications',
    'link_title' => 'Subscriptions',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage existing subscriptions.',
      ),
      'identifier' => 'management_subscriptions:admin/notifications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_system:admin/config/system.
  $menu_links['management_system:admin/config/system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system',
    'router_path' => 'admin/config/system',
    'link_title' => 'System',
    'options' => array(
      'attributes' => array(
        'title' => 'General system related configuration.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_system:admin/config/system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_taxonomy:admin/structure/taxonomy.
  $menu_links['management_taxonomy:admin/structure/taxonomy'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'Taxonomy',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage tagging, categorization, and classification of your content.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_taxonomy:admin/structure/taxonomy',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_text-formats:admin/config/content/formats.
  $menu_links['management_text-formats:admin/config/content/formats'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/formats',
    'router_path' => 'admin/config/content/formats',
    'link_title' => 'Text formats',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how content input by users is filtered, including allowed HTML tags. Also allows enabling of module-provided filters.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_text-formats:admin/config/content/formats',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rdaction-de-contenu:admin/config/content',
  );
  // Exported menu link: management_top-access-denied-errors:admin/reports/access-denied.
  $menu_links['management_top-access-denied-errors:admin/reports/access-denied'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/access-denied',
    'router_path' => 'admin/reports/access-denied',
    'link_title' => 'Top \'access denied\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'access denied\' errors (403s).',
      ),
      'alter' => TRUE,
      'identifier' => 'management_top-access-denied-errors:admin/reports/access-denied',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_top-page-not-found-errors:admin/reports/page-not-found.
  $menu_links['management_top-page-not-found-errors:admin/reports/page-not-found'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/page-not-found',
    'router_path' => 'admin/reports/page-not-found',
    'link_title' => 'Top \'page not found\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'page not found\' errors (404s).',
      ),
      'alter' => TRUE,
      'identifier' => 'management_top-page-not-found-errors:admin/reports/page-not-found',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_top-search-phrases:admin/reports/search.
  $menu_links['management_top-search-phrases:admin/reports/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/search',
    'router_path' => 'admin/reports/search',
    'link_title' => 'Top search phrases',
    'options' => array(
      'attributes' => array(
        'title' => 'View most popular search phrases.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_top-search-phrases:admin/reports/search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_translate-interface:admin/config/regional/translate.
  $menu_links['management_translate-interface:admin/config/regional/translate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/translate',
    'router_path' => 'admin/config/regional/translate',
    'link_title' => 'Translate interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Translate the built in interface and optionally other text.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_translate-interface:admin/config/regional/translate',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_rgionalisation-et-langue:admin/config/regional',
  );
  // Exported menu link: management_triggers:admin/structure/trigger.
  $menu_links['management_triggers:admin/structure/trigger'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/trigger',
    'router_path' => 'admin/structure/trigger',
    'link_title' => 'Triggers',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure when to execute actions.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_triggers:admin/structure/trigger',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_url-aliases:admin/config/search/path.
  $menu_links['management_url-aliases:admin/config/search/path'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/path',
    'router_path' => 'admin/config/search/path',
    'link_title' => 'URL aliases',
    'options' => array(
      'attributes' => array(
        'title' => 'Change your site\'s URL paths by aliasing them.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_url-aliases:admin/config/search/path',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_recherche-et-metadonnes:admin/config/search',
  );
  // Exported menu link: management_user-interface:admin/config/user-interface.
  $menu_links['management_user-interface:admin/config/user-interface'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface',
    'router_path' => 'admin/config/user-interface',
    'link_title' => 'User interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools that enhance the user interface.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_user-interface:admin/config/user-interface',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_user-menu:admin/structure/menu/manage/user-menu.
  $menu_links['management_user-menu:admin/structure/menu/manage/user-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/user-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'User menu',
    'options' => array(
      'identifier' => 'management_user-menu:admin/structure/menu/manage/user-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_views-plugins:admin/reports/views-plugins.
  $menu_links['management_views-plugins:admin/reports/views-plugins'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/views-plugins',
    'router_path' => 'admin/reports/views-plugins',
    'link_title' => 'Views plugins',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of plugins used in all views.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_views-plugins:admin/reports/views-plugins',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_rapports:admin/reports',
  );
  // Exported menu link: management_views:admin/structure/views.
  $menu_links['management_views:admin/structure/views'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customized lists of content.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_views:admin/structure/views',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_web-services:admin/config/services.
  $menu_links['management_web-services:admin/config/services'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services',
    'router_path' => 'admin/config/services',
    'link_title' => 'Web services',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools related to web services.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_web-services:admin/config/services',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_workflow:admin/config/workflow.
  $menu_links['management_workflow:admin/config/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow',
    'router_path' => 'admin/config/workflow',
    'link_title' => 'Workflow',
    'options' => array(
      'attributes' => array(
        'title' => 'Content workflow, editorial workflow tools.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_workflow:admin/config/workflow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Account settings');
  t('Actions');
  t('Adminimal menu');
  t('Administration');
  t('Ajouter une prestation');
  t('Appearance');
  t('Arrange');
  t('Artistes');
  t('Artists');
  t('Available updates');
  t('Backup and Migrate');
  t('Belive Registration roles');
  t('Blocks');
  t('BootstrapMultiselect.js');
  t('Calendar');
  t('Clean URLs');
  t('Configuration');
  t('Content');
  t('Content authoring');
  t('Content types');
  t('Cron');
  t('Dashboard');
  t('Date API');
  t('Date Popup');
  t('Date and time');
  t('Devel settings');
  t('Development');
  t('Example help');
  t('Exemples prestations');
  t('Features');
  t('Field list');
  t('File system');
  t('Front Page');
  t('Help');
  t('Home links');
  t('IP address blocking');
  t('Image styles');
  t('Image toolkit');
  t('Languages');
  t('Les inscriptions');
  t('Les prestations');
  t('Libraries');
  t('Logging and errors');
  t('Maintenance mode');
  t('Management');
  t('Masquerade');
  t('Media');
  t('Menu principal');
  t('Menus');
  t('Messaging & Notifications');
  t('Messaging settings');
  t('Metatag');
  t('Module filter');
  t('Modules');
  t('Multilingual settings');
  t('Navigation');
  t('Notifications settings');
  t('People');
  t('Performance');
  t('Postes des artistes');
  t('Processus (workflows)');
  t('RSS publishing');
  t('Recent log messages');
  t('Regional and language');
  t('Regional settings');
  t('Registration');
  t('Registration role');
  t('Registration states');
  t('Registration types');
  t('Reports');
  t('Rules');
  t('Search and metadata');
  t('Search settings');
  t('Send methods');
  t('Settings');
  t('Shortcuts');
  t('Site information');
  t('Status report');
  t('Strongarm');
  t('Structure');
  t('Subscriptions');
  t('Subscriptions settings');
  t('System');
  t('Taxonomy');
  t('Text formats');
  t('Top \'access denied\' errors');
  t('Top \'page not found\' errors');
  t('Top search phrases');
  t('Translate interface');
  t('Triggers');
  t('URL aliases');
  t('User interface');
  t('User menu');
  t('Views');
  t('Views plugins');
  t('Web services');
  t('Workflow');
  t('jQuery update');

  return $menu_links;
}
