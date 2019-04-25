<?php
/**
 * @file
 * Administrative pages for the Video.js module.
 */

/**
 * Menu callback; Provides the Video.js settings form.
 */
function bootstrap_multiselect_settings_form() {
  $form = array();
  //bootstrap_multiselect_get_version();
  //dpm(bootstrap_multiselect_get_version($form_state['values']['bootstrap_multiselect_directory']));

  $form['bootstrap_multiselect_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Multiselect.js file directory'),
    '#default_value' => variable_get('bootstrap_multiselect_directory', 'sites/all/libraries/bootstrap-multiselect/dist'),
    '#description' => t('Specify the path that contains the Video.js library. The video.js file should be in the root of this directory.'),
  );

  // $form['options'] = array(
  //   '#type' => 'fieldset',
  //   '#title' => t('Video.js options'),
  //   '#collapsible' => FALSE,
  // );

  // $form['options']['videojs_autoplay'] = array(
  //   '#type' => 'checkbox',
  //   '#title' => t('Auto-play files on page load'),
  //   '#description' => t('Use caution when combining this option with multiple players on the same page.'),
  //   '#default_value' => variable_get('videojs_autoplay', ''),
  // );

  // $form['options']['videojs_width'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Player width'),
  //   '#default_value' => variable_get('videojs_width', 640),
  // );

  // $form['options']['videojs_height'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Player height'),
  //   '#default_value' => variable_get('videojs_height', 360),
  // );

  $form = system_settings_form($form);
  $form['#validate'][] = 'bootstrap_multiselect_settings_form_validate';
  $form['#submit'][] = 'bootstrap_multiselect_settings_form_submit';
  return $form;
}

/**
 * Validation function to validate the bootstrap_multiselect_settings_form() form.
 */
function bootstrap_multiselect_settings_form_validate($form, &$form_state) {
  //TODO

  // $form_state['videojs_version'] = videojs_get_version($form_state['values']['videojs_directory']);
  // $form_state['bootstrap_multiselect_version'] = bootstrap_multiselect_get_version($form_state['values']['bootstrap_multiselect_directory']);
  //$form_state['bootstrap_multiselect_version'] = bootstrap_multiselect_get_version($form_state['values']['bootstrap_multiselect_directory']);
  
  // $dir = base_path() . $form_state['values']['bootstrap_multiselect_directory'];
  // dpm($dir);
  // dpm( is_dir($dir) );

  // if (!$form_state['bootstrap_multiselect_version']) {
  //   form_error($form['bootstrap_multiselect_directory'], t('The directory specified does not seem to contain the Multiselect.js library. Check to make sure that the video.js file is located within this directory.'));
  // }
}

/**
 * Submit handler for the bootstrap_multiselect_settings_form() form.
 */
function bootstrap_multiselect_settings_form_submit($form, &$form_state) {
  //TODO
  // drupal_set_message(t('The bootstrap_multiselect.js library (version @version) successfully found in the %directory directory.', array('@version' => $form_state['bootstrap_multiselect_version'], '%directory' => $form_state['values']['bootstrap_multiselect_directory'])));
}