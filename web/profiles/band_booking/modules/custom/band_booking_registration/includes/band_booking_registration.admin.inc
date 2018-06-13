<?php
/**
 * @file
 * Administrative pages for the Video.js module.
 */

/**
 * Menu callback; Provides the Video.js settings form.
 */
function band_booking_registration_settings_form($form, &$form_state) {
  $roles_list = array(
    '#type' => 'value',
    '#value' => user_roles(),
  );
  $form['roles'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#title' => t('Select roles'),
    '#description' => t('Select the users you want to add. Users already signed up wont appear.'),
    '#default_value' => variable_get('band_booking_registration_default_roles', array()),
    '#size' => 5,
    '#weight' => 0,
    '#options' => $roles_list['#value'],
  );

  $form = system_settings_form($form);
  // $form['#validate'][] = 'band_booking_registration_settings_form_validate';
  $form['#submit'][] = 'band_booking_registration_settings_form_submit';
  return $form;
}

/**
 * Validation function to validate the band_booking_registration_settings_form() form.
 */
// function band_booking_registration_settings_form_validate($form, &$form_state) {
//   dpm('validate my form !!!');
//   // @TODO

//   // $form_state['videojs_version'] = videojs_get_version($form_state['values']['videojs_directory']);
//   // $form_state['band_booking_registration_version'] = band_booking_registration_get_version($form_state['values']['band_booking_registration_directory']);
//   //$form_state['band_booking_registration_version'] = band_booking_registration_get_version($form_state['values']['band_booking_registration_directory']);
  
//   // $dir = base_path() . $form_state['values']['band_booking_registration_directory'];
//   // dpm($dir);
//   // dpm( is_dir($dir) );

//   // if (!$form_state['band_booking_registration_version']) {
//   //   form_error($form['band_booking_registration_directory'], t('The directory specified does not seem to contain the Multiselect.js library. Check to make sure that the video.js file is located within this directory.'));
//   // }
// }

/**
 * Submit handler for the band_booking_registration_settings_form() form.
 */
function band_booking_registration_settings_form_submit($form, &$form_state) {
  $default_roles = !empty($form_state['input']['roles']) ? $form_state['input']['roles'] : array();
  variable_set('band_booking_registration_default_roles', $default_roles);
  // TODO
  // drupal_set_message(t('The band_booking_registration.js library (version @version) successfully found in the %directory directory.', array('@version' => $form_state['band_booking_registration_version'], '%directory' => $form_state['values']['band_booking_registration_directory'])));
}