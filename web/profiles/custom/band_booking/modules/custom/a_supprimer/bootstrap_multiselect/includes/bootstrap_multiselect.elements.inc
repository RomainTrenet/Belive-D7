<?php
/**
 * Themes a custom select.
 *
 * This create a belive custom select with "multiple" option
 */
// function theme_bootstrap_multiselect_select($variables) {
//   $element = $variables['element'];
//   dpm($element);
//   element_set_attributes($element, array('id', 'name', 'size'));
//   dpm($element);
//   _form_set_class($element, array('form-select', 'testtest'));

//   return '<select' . drupal_attributes($element['#attributes']) . form_select_options($element) . '</select>';
//   //return '<select' . drupal_attributes($element['#attributes']) . ' multiple="multiple">' . form_select_options($element) . '</select>';
// }

/**
 * Formats child form elements as inline elements.
 */
function theme_bootstrap_multiselect_inline_form_element($variables) {
  //dpm('inline form bootstrap !');
  $element = $variables['element'];
  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'],
      array(
        ' ' => '-',
        '_' => '-',
        '[' => '-',
        ']' => '',
      )
    );
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . '<div class="container-users">' . $prefix . $element['#children'] . $suffix . "</div>\n";
      break;

    case 'invisible':
    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}
