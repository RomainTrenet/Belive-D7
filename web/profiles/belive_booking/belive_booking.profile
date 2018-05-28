<?php

/**
 * @file
 * Module that activates all necessary modules to Intranet Market D8.
 */

// The Belive Booking default site informations
define('BLV_SITE_NAME', 'Belive Booking');
define('BLV_SITE_MAIL', 'booking.belive@gmail.com');
define('BLV_SITE_ADMIN_NAME', 'Admin');
define('BLV_SITE_ADMIN_MAIL', 'romain.trenet@gmail.com');
define('BLV_SITE_DEFAULT_COUNTRY', 'FR');
define('BLV_SITE_DEFAULT_TZ', 'Europe/Paris');

// Call at the beginning, but is it used ?
function belive_booking_profile_details(){
  $details['language'] = "fr";
  return $details;
}

/**
 * Removing database entry for a list of modules.
 */
function belive_booking_erase_modules_entry(array $modules) {
  db_delete('system')
    ->condition('name', $modules, 'IN')
    ->condition('type', 'module')
    ->execute();
}

/**
 * Implements hook_install_tasks().
 *
 * Displays help and module information.
 *
 * @param $install_state
 */
function belive_booking_install_tasks(&$install_state) {
  return array (
    'apply_default_features' => array(
      'display_name' => t('Apply default features'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => 'INSTALL_TASK_RUN_IF_REACHED',
      'function' => 'belive_booking_apply_default_features',
    )
    // @Todo : delete or make it work.
  /*,
    'refresh_default_translations' => array(
      'display_name' => t('Refresh default translations'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => 'INSTALL_TASK_RUN_IF_REACHED',
      'function' => 'belive_booking_refresh_default_translations',
    ),
    'apply_default_translations' => array(
      'display_name' => t('Apply default translations'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => 'INSTALL_TASK_RUN_IF_REACHED',
      'function' => 'belive_booking_apply_default_translations',
    )
  */
  );
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function belive_booking_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name and mail.
  $form['site_information']['site_name']['#default_value'] = BLV_SITE_NAME;
  $form['site_information']['site_mail']['#default_value'] = BLV_SITE_MAIL;

  // Pre-populate admin account name and mail.
  $form['admin_account']['account']['name']['#default_value'] = BLV_SITE_ADMIN_NAME;
  $form['admin_account']['account']['mail']['#default_value'] = BLV_SITE_ADMIN_MAIL;

  // Pre-populate server location..
  $form['server_settings']['site_default_country']['#default_value'] = BLV_SITE_DEFAULT_COUNTRY;
  $form['server_settings']['date_default_timezone']['#default_value'] = BLV_SITE_DEFAULT_TZ;
  //unset($form['server_settings']['date_default_timezone']['#attributes']);

  // Uncheck site notifications for update.
  unset($form['update_notifications']['update_status_module']['#default_value']);

}

/**
 * Custom function to automatically manage themes.
 */
function belive_booking_apply_default_features() {
  // Revert features to ensure they are all installed
  $features = array(
    'artists_position',
    'belive_base',
    'belive_user'
  );
  features_revert($features);
}

/**
 * Custom function to automatically manage themes.
 */
// @todo : delete or make it work.
/*
function belive_booking_refresh_default_translations() {
  module_load_include('admin.inc', 'l10n_update');

  // Force refreshing.
  $form_state = array(
    'values' => array('op' => t('Refresh information'))
  );
  l10n_update_admin_import_form_submit(NULL, $form_state);
}

function belive_booking_apply_default_translations() {
  module_load_include('admin.inc', 'l10n_update');

  //$projects = l10n_update_get_projects();
  $languages = l10n_update_language_list('name');
  dpm('romain !!!');
  dpm($languages);

  //$build = array();
  if ($languages) {
    $history = l10n_update_get_history();
    $available = l10n_update_available_releases();
    $updates = l10n_update_build_updates($history, $available);
    /*$build['project_status'] = array(
      '#theme' => 'l10n_update_project_status',
      '#projects' => $projects,
      '#languages' => $languages,
      '#history' => $history,
      '#available' => $available,
      '#updates' => $updates,
    );
    * /
    //$build['admin_import_form'] = drupal_get_form('l10n_update_admin_import_form', $projects, $updates);
    // Force importing.
    $form_state = array(
      'values' => array(
        'op' => t('Update translations'),
        'languages' => $languages,
        'updates' => $updates,
      )
    );
    dpm($form_state);

    //$form_state['values']['languages'] = $languages;
    //$form_state['values']['updates'] = $updates;
    l10n_update_admin_import_form_submit(NULL, $form_state);
  }
  else {
    //$build['no_languages'] = array('#markup' => t('No translatable language defined. <a href="/admin/config/regional/language">Add a language</a>.'));
  }
  //return $build;
}
*/
