<?php

/**
 * Formats child form elements as inline elements.
 */
function theme_multiple_select_inline_form_element($variables) {
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

  // Prepare HTML values.
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';
  $label = theme('form_element_label', $variables);
  $children = empty($element['#options']) ? t('No available option.') : $element['#children'];

  switch ($element['#title_display']) {
    case 'before':
      $output .= $label . ' ' . $prefix . $children . $suffix;
      break;

    case 'invisible':
    case 'after':
      $output .= ' ' . $prefix . $children . $suffix . ' ' . $label . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $children . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}
