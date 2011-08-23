<?php
// $Id $

function cmlservice_admin_settings() {
/*  
  $form['general']['cmlservice_verbose'] = array(
    '#type' => 'checkbox',
    '#title' => t('Verbose'),
    '#default_value' =>  FALSE,
    '#description' => t('Display alias changes (except during bulk updates).'),
  );
  return system_settings_form($form);
  */
}

function cmlservice_form($form_state){
    $abort = FALSE;
    $processing = '';
    $system_path = variable_get('cml_data_path', drupal_get_path('module', 'cmlservice'));
    if(!is_dir("$system_path")){ $processing.='Can`t find the cml directory. Please select it '.l('here', 'admin/store/settings/cml'); $abort = TRUE;}
    if($abort) return;
    $options = array(); $options_set = array();
    $flags = cmlservice_get_flags();
    
    $options['delete_all'] = t('Delete all.');
    $options['update_all'] = t('Updated all.');
    $options['update_price'] = t('Updated price.');
       
    $options['force_replace'] = t('Product force replace.');
    $options['product_enabled'] = t('Product enabled.');
    //$options['force_batch'] = t('Batch process on.');
    //$options['product_shippible'] = t('Product enabled.');
    
    foreach($flags as $flag){
      switch($flag){
        case 'delete_all':
          $processing.= '<b style=color:red>Attention!!!</b> Will delete all products` data.<br>'; 
          $options_set[$flag] = TRUE;
        break;
        case '1c_attention':
          $processing.='Can`t run it because the 1c proceaa aren`t finish.<br>'; $abort = TRUE;
        break;
        case 'drupal_attention':
          $processing.='Can`t run it because another process are running.<br>'; $abort = TRUE;
        break;
        case 'update_all':
          $processing.= 'Will be updated all.<br>'; 
          $options_set[$flag] = TRUE;
        break;        
        case 'update_price':
          $processing.= 'Will be updated only price.<br>'; 
          $options_set[$flag] = TRUE;
        break;
        case 'update_title':
          $processing.= 'Will be updated only product title.<br>'; 
          $options['update_title'] = t('Updated title.'); $options_set[$flag] = TRUE;
        break;
        case 'update_description':
          $processing.= 'Will be updated only product description.<br>'; 
          $options['update_description'] = t('Updated description.'); $options_set[$flag] = TRUE;
        break;
        case 'update_picture':
          $processing.= 'Will be updated only product pictures.<br>'; 
          $options['update_picture'] = t('Updated pictures.'); $options_set[$flag] = TRUE;
        break;                                                
      }
    }
      
    $form['flags'] = array(
      '#type' => 'checkboxes',
      '#title' => t(''),
      '#default_value' => array_keys($options_set),
      '#options' => $options,
      //'#disabled' => TRUE,
    );
    $form['processing'] = array(
      '#type' => 'item',
      '#title' => 'ver: ' . CML_VER,
      '#value' => $processing ? t('Processing...') . $processing : '',
    );
    if(!$abort) 
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Послать',
    );
  return $form;
}

function cmlservice_form_submit($form, &$form_state) {
  cmlservice_add($form_state['values']);
}

function cmlservice_page() {
  $output = drupal_get_form('cmlservice_form');
  return $output;
}

function cml_settings(){
  $output = drupal_get_form('cml_settings_form');
  return $output;
}

function cml_settings_form($form_state){
  $form['cml_data_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to folder'),
    '#description' => t('Path must be without /import_files'),
    '#default_value' =>  variable_get('cml_data_path', drupal_get_path('module', 'cmlservice') . '/import_files'),
  );
  $form['cml_product_altered_price'] = array(
    '#type' => 'checkbox',
    '#title' => t('Altered price on/off'),
    '#default_value' => variable_get('cml_product_altered_price', FALSE),
    '#description' => t(''),
  ); 
  $form = system_settings_form($form);
  return $form;
}

function cml_settings_form_submit($form, &$form_state){
}