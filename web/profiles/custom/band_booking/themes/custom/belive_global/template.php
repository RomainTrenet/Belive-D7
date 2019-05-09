<?php

/**
 * Override or insert variables into the html template.
 */
function belive_global_preprocess_html(&$vars)
{
  // Get adminimal folder path.
  $belive_global_path = drupal_get_path('theme', 'belive_global');

  // Add default styles, to fight with Adminimal Theme, Had weight 1000
  drupal_add_css($belive_global_path . '/css/custom.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 1000));
}

// theme_select
function belive_global_select($variables) {
    $element = $variables['element'];
    element_set_attributes($element, array('id', 'name', 'size'));
    _form_set_class($element, array('form-select'));
    return '<select' . drupal_attributes($element['#attributes']) . '>' . belive_global_form_select_options($element) . '</select>';
}


function belive_global_form_select_options($element, $choices = NULL) {
    if (!isset($choices)) {
        $choices = $element['#options'];
    }
    //dpm($element);

    // array_key_exists() accommodates the rare event where $element['#value'] is NULL.
    // isset() fails in this situation.
    $value_valid = isset($element['#value']) || array_key_exists('#value', $element);

    // @vishal  so there I have declared the variable to accept the values.
    $vtitle = isset($element['#title']) || array_key_exists('#title', $element);

    $value_is_array = $value_valid && is_array($element['#value']);
    $options = '';
    foreach ($choices as $key => $choice) {
        if (is_array($choice)) {
            $options .= '<optgroup label="' . check_plain($key) . '">';
            $options .= form_select_options($element, $choice);
            $options .= '</optgroup>';
        }
        elseif (is_object($choice)) {
            $options .= form_select_options($element, $choice->option);
        }
        else {
            $key = (string) $key;
            if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
                $selected = ' selected="selected"';
            }
            else {
                $selected = '';
            }
//
            //$hidden = ($choice == 'Bassiste' || $choice == 'Untel') ? 'hidden="hidden"' : '';
            //$options .= '<option '.$hidden.' title="'.$vtitle.'" value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
            $options .= '<option title="'.$vtitle.'" value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
        }
    }
    return $options;
}