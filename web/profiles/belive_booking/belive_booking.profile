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
    'manage_themes' => array(
      'display_name' => t('Manage Themes'),
      'display' => TRUE,
      'type' => 'normal',
      'run' => 'INSTALL_TASK_RUN_IF_REACHED',
      'function' => 'belive_booking_manage_themes',
    ),
    'apply_default_features' => array(
      'display_name' => t('Apply default features'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => 'INSTALL_TASK_RUN_IF_REACHED',
      'function' => 'belive_booking_apply_default_features',
    )
  );
}

/**
 * Implements hook_install_tasks_alter().
 *
 * Displays help and module information.
 *
 * @param $install_state
 */
function belive_booking_install_tasks_alter (&$tasks, $install_state) {
  $tasks['install_select_locale']['function'] = '_belive_booking_locale_selection';
}

// Local callback function.
function _belive_booking_locale_selection (&$install_state) {
  $install_state['parameters']['locale'] = 'fr';
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
function belive_booking_manage_themes() {
  // Enable usefull theme.
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', array('adminimal', 'omega', 'belive_global', 'belive_booking_admin', 'belive_booking_front'), 'IN')
    ->execute();
  variable_set('admin_theme', 'belive_booking_admin');
  variable_set('node_admin_theme', '1');
  variable_set('theme_default', 'belive_booking_front');

  // Disable unusefull theme.
  db_update('system')
    ->fields(array('status' => 0))
    ->condition('type', 'theme')
    ->condition('name', array('bartik'), 'IN')
    ->execute();
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
