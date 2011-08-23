<?php

function frontend_settings($saved_settings, $subtheme_defaults = array()) {
  $defaults = frontend_theme_get_default_settings('frontend');
  $settings = array_merge($defaults, $saved_settings);
  $form['frontend_block_editing'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show block editing on hover'),
    '#description'   => t('When hovering over a block, privileged users will see block editing links.'),
    '#default_value' => $settings['frontend_block_editing'],
    '#prefix'        => '<strong>' . t('Block Edit Links:') . '</strong>',
  );
  
    $form['themedev']['frontend_hashgrid'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Display a grid overlay'),
    '#default_value' => $settings['frontend_hashgrid'],
    '#description'   => t('During theme development, it can be useful to display a grid system for reference.'),
    '#prefix'        => '<div id="div-grid"><strong>' . t('# Grid:') . '</strong>',
    '#suffix'        => '</div>',
  );
  return $form;
}

function _frontend_theme(&$existing, $type, $theme, $path) {
  $functions[0] = $theme . '_preprocess';
  foreach (array_keys($existing) AS $hook) {
    $functions[1] = $theme . '_preprocess_' . $hook;
    foreach ($functions AS $key => $function) {
      if (function_exists($function) && !in_array($function, $existing[$hook]['preprocess functions'])) {
        $existing[$hook]['preprocess functions'][] = $function;
      }
    }
  }

  frontend_theme_get_default_settings($theme);
  return array();
}


function frontend_theme_get_default_settings($theme) {
  $themes = list_themes();
  $defaults = !empty($themes[$theme]->info['settings']) ? $themes[$theme]->info['settings'] : array();
  if (!empty($defaults)) {
    $settings = theme_get_settings($theme);
    if (module_exists('node')) {
      foreach (node_get_types() as $type => $name) {
        unset($settings['toggle_node_info_' . $type]);
      }
    }
    variable_set(
      str_replace('/', '_', 'theme_' . $theme . '_settings'),
      array_merge($defaults, $settings)
    );
    if (!empty($GLOBALS['theme_key'])) {
      theme_get_setting('', TRUE);
    }
  }
  return $defaults;
}