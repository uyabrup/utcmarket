<?php

function administrator_settings($saved_settings, $subtheme_defaults = array()) {

  $themes = list_themes();
  $defaults = $themes['administrator']->info['settings'];
  $defaults = array_merge($defaults, $subtheme_defaults);
  $settings = array_merge($defaults, $saved_settings);

  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['header']['administrator_header_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable header'),
    '#default_value' => $settings['administrator_header_display'],
  );
  
  $form['header']['administrator_hide_panel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable sliding panel'),
    '#default_value' => $settings['administrator_hide_panel'],
  );
  
  $form['dashboard'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dashboard'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['dashboard']['administrator_dashboard_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable dashboard regions'),
    '#default_value' => $settings['administrator_dashboard_display'],
  );

    $form['dashboard']['administrator_dashboard_tabs'] = array(
    '#type' => 'select',
    '#options' => array('collapsed' => t('Fieldset collapsed by default'), 'tabs' => t('Tabbed blocks')),
    '#title' => t('How to display dashboard content blocks'),
    '#default_value' => $settings['administrator_dashboard_tabs'],
  );
  
  $form['dashboard']['administrator_dashboard_display_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable messages on dashboard'),
    '#default_value' => $settings['administrator_dashboard_display_message'],
  );  
  
  $form['dashboard']['administrator_dashboard_content_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable content on a dashboard'),
    '#default_value' => $settings['administrator_dashboard_content_display'],
  );

  $form['navigation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navigation'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $menu_options = array_merge(array('_administrator_default_navigation' => t('default navigation')), menu_get_menus());
  if (!isset($settings['administrator_navigation_source_admin'])) {
    $settings['administrator_navigation_source_admin'] = '_administrator_default_navigation';
  }

  $form['navigation']['administrator_superuser_menu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Super user (uid 1) menu'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['navigation']['administrator_superuser_menu']['administrator_navigation_source_admin'] = array(
    '#type' => 'select',
    '#default_value' => $settings['administrator_navigation_source_admin'],
    '#options' => $menu_options,
    '#tree' => FALSE,
  );

  $primary_options = array(
    NULL => t('None'),
  );

  $primary_options = array_merge($primary_options, $menu_options);

  $form['navigation']['role-weights'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu by role and weights'),
    '#weight' => 2,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $roles = user_roles(FALSE);
  $max_weight = 0;
  foreach ($roles as $rid => $role) {
    if (empty($settings['administrator_navigation_source_'. $rid])) $settings['administrator_navigation_source_'. $rid] = '';

    $form['navigation']['nav-by-role']['administrator_navigation_source_'. $rid] = array(
      '#type' => 'select',
      '#default_value' => $settings['administrator_navigation_source_'. $rid],
      '#options' => $primary_options,
      '#tree' => FALSE,
    );

    if (isset($settings['role-weight-'. $rid])) {
      if ($max_weight < $settings['role-weight-'. $rid]) {
        $max_weight = $settings['role-weight-'. $rid];
      }
    }
  }

  $form['Misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Misc'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['Misc']['administrator_help_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable help'),
    '#default_value' => $settings['administrator_help_display'],
  );

  $max_weight = (isset($max_weight)) ? $max_weight : 100;
  foreach ($roles as $rid => $role) {
    if (empty($settings['role-weight-'. $rid])) $settings['role-weight-'. $rid] = '';
    if (!$weight = $settings['role-weight-'. $rid]) {
      $weight = ++$max_weight;
    }
    $data = array($role);
    $form['rows'][$rid]['data'] = array('#type' => 'value', '#value' => $data);
    $form['rows'][$rid]['role-weight-'. $rid] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#default_value' => $weight,
      '#attributes' => array('class' => 'weight'),
    );
  }
  return $form;
}