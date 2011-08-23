<?php


/**
 * Функция темизации форм hook_form_alter. Здесь мы уточняем расположение полей, убираем ненужные, добавляем нужные.
 */
function general_form_alter(&$form, $form_state, $form_id) {
  global $base_path;
  
  if (variable_get('uc_advanced_catalog_sticky', FALSE)) {
    variable_set('uc_advanced_catalog_sticky', 0); //если каким-то образом у нас включено отображение прилепленных товаров в каталоге, мы отключаем это
  }
  
  /// Сворачиваем малозначительные fieldsets на всех страницах
  $form['domain_settings']['#collapsed'] = TRUE;
  $form['domain']['#collapsed'] = TRUE;
  $form['shipping']['#collapsed'] = TRUE;
  $form['path']['#collapsed'] = TRUE;
  $form['taxonomy']['#type'] = 'markup';

  if ($form_state['view']->name == 'uc_products') {
    $form['submit']['#value'] = t('Show products');
    $form['tid']['#options']['All'] = t('All categories');
    $form['tid_1']['#options']['All'] = t('All manufacturers');
    $form['sell_price']['min']['#title'] = t('Price from');
    $form['sell_price']['max']['#title'] = t('Price to');
  }

  if ($form_state['view']->name == 'discounts') {
    $form['submit']['#value'] = t('Show discounts');
    $form['term_node_tid_depth']['#options']['All'] = t('All categories');
    $form['tid']['#options']['All'] = t('All manufacturers');
    $form['field_discount_value_1']['min']['#title'] = t('Price from');
    $form['field_discount_value_1']['max']['#title'] = t('Price to');
  }
  
  if ($form_id == 'system_site_maintenance_settings') {
    
	$form['openstore_add_contact_info'] = array(
     '#type' => 'checkbox',
	 '#weight' => 0,
     '#title' => t('Add contact information'),
     '#default_value' => variable_get('openstore_add_contact_info', TRUE),
	 '#description' => t('Show contact information on maintain page in additional to text set below. The info will be taken from <em>admin/store/settings/store/edit</em>.'),
	);
  
  } 
  
    if ($form_id == 'system_themes_form') { 
     unset($form['status']['#options']['garland']);
     unset($form['status']['#options']['minnelli']);	 
     unset($form['status']['#options']['bluemarine']);
     unset($form['status']['#options']['chameleon']);
     unset($form['status']['#options']['marvin']);
     unset($form['status']['#options']['pushbutton']);	 	 
     unset($form['theme_default']['#options']['garland']);
     unset($form['theme_default']['#options']['minnelli']); 
     unset($form['theme_default']['#options']['bluemarine']);
     unset($form['theme_default']['#options']['chameleon']);
     unset($form['theme_default']['#options']['marvin']);
     unset($form['theme_default']['#options']['pushbutton']);		 
     unset($form['garland']);
     unset($form['minnelli']); 
     unset($form['bluemarine']);
     unset($form['chameleon']); 
     unset($form['marvin']);
     unset($form['pushbutton']); 	 
  }

  if ($form_id == 'uc_product_settings_form') {
     unset($form['uc_product_image_widget']);	
    $form['uc_add_to_cart_text']['#collapsed'] = TRUE;
    $form['uc_add_to_cart_text']['#collapsible'] = TRUE;
	
    $form['uc_image_display_settings'] = array(
     '#type' => 'fieldset',
     '#title' => t('Product image display settings'),
     '#weight' => -10,
     '#collapsible' => TRUE,
     '#collapsed' => TRUE,
	 '#summary callback' => 'summarize_form',
     );
	 
    $form['openstore_empty_text'] = array(
     '#type' => 'fieldset',
     '#title' => t('Empty image placeholder'),
     '#weight' => -1,
     '#collapsible' => TRUE,
     '#collapsed' => TRUE,
     );
	 
	 $form['openstore_empty_text']['openstore_empty_image_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Placeholder text'),
      '#default_value' => variable_get('openstore_empty_image_text', FALSE),
	  '#description' => t('Enter a text that will be show if product images are not provided.'),
    ); 

    $form['uc_image_display_settings']['uc_image_display_plugin'] = array(
     '#type' => 'select',
     '#options' => array('fancybox' => t('Fancybox'), 'slimbox' => t('Slimbox')),
     '#title' => t('Choose JavaScript plugin'),
     '#default_value' => variable_get('uc_image_display_plugin', 'slimbox'),
	 '#weight' => -9,
	 '#description' => t('Choose which JavaScript plugin will used for displaying big product images on a product page. Plugins stored in libraries directory'),

	 );

    $small_image_preset = array();
    $product_image_preset = array();
    $big_image_preset = array();
    $adjust_image_preset = array(0 => t('Do not adjust image size'));
    $presets = imagecache_presets();

    foreach ($presets as $preset_id => $preset) {
      $small_image_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
      $product_image_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
      $big_image_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
      $adjust_image_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
	
	}

    $form['uc_image_display_settings']['uc_small_image_preset'] = array(
      '#type' => 'select',
      '#title' => t('Small image'),
      '#default_value' => variable_get('uc_small_image_preset', 2),
      '#options' => $small_image_preset,
      '#weight' => -9,
	  '#description' => t('Choose a preset name to use as small additional product images.'),
    );

    $form['uc_image_display_settings']['uc_product_image_adjust'] = array(
      '#type' => 'select',
      '#title' => t('Adjusted image preset'),
      '#default_value' => variable_get('uc_product_image_adjust', 0),
      '#options' => $adjust_image_preset,
      '#weight' => -8,
	  '#description' => t('Choose a preset name to use depending on left/right sidebar position.'),
    );

    $form['uc_image_display_settings']['uc_product_image_preset'] = array(
      '#type' => 'select',
      '#title' => t('Product image'),
      '#default_value' => variable_get('uc_product_image_preset', 1),
      '#options' => $product_image_preset,
      '#weight' => -7,
	  '#description' => t('Choose a preset name to use as main product image.'),
    );

    $form['uc_image_display_settings']['uc_big_image_preset'] = array(
      '#type' => 'select',
      '#title' => t('Big image'),
      '#default_value' => variable_get('uc_big_image_preset', 3),
      '#options' => $big_image_preset,
      '#weight' => -6,
	  '#description' => t('Choose a preset name to use as original product images (popup).'),
    );

    $form['uc_zoom_settings'] = array(
     '#type' => 'fieldset',
     '#title' => t('Zoom settings'),
     '#weight' => -10,
     '#collapsible' => TRUE,
     '#collapsed' => TRUE,
	 '#summary callback' => 'summarize_form',
     );

    $form['uc_zoom_settings']['uc_big_zoom_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Zoom height'),
      '#default_value' => variable_get('uc_big_zoom_height', 1000),
      '#weight' => -5,
	  '#size' => 20,
	  '#description' => t('Enter the image height value (in px). Images with greater height will be displayed via zoom.'),
    );

    $form['uc_zoom_settings']['uc_big_zoom_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Zoom width'),
      '#default_value' => variable_get('uc_big_zoom_width', 1000),
      '#weight' => -4,
	  '#size' => 20,
	  '#description' => t('Enter the image width value (in px). Images with greater width will be displayed via zoom.'),
    );

    $form['uc_zoom_settings']['uc_zoom_plugin'] = array(
     '#type' => 'select',
     '#options' => array('jqzoom' => t('Jqzoom'), 'cloudzoom' => t('Cloud Zoom')),
     '#title' => t('Choose zoom plugin'),
     '#default_value' => variable_get('uc_zoom_plugin', 'jqzoom'),
	 '#weight' => -8,
	 '#description' => t('Choose which JavaScript plugin will used for zoom effect.'),
    );

    $form['uc_product_tab_style'] = array(
     '#type' => 'fieldset',
     '#title' => t('Tab style'),
     '#weight' => -8,
     '#collapsible' => TRUE,
     '#collapsed' => TRUE,
	 '#summary callback' => 'summarize_form',
     );

    $form['uc_product_tab_style']['uc_product_tab_style_op'] = array(
     '#type' => 'select',
     '#options' => array('accordion' => t('Accordion'), 'cookie' => t('Collapsed with cookie')),
     '#title' => t('Tab style'),
     '#default_value' => variable_get('uc_product_tab_style', 'accordion'),
	 '#weight' => -3,
	 '#description' => t('Choose how to display main tabs on product page.'),
	);

    $form['uc_image_display_settings']['uc_images_scroll_threshold'] = array(
     '#type' => 'textfield',
     '#title' => t('Scroll threshold'),
     '#default_value' => variable_get('uc_images_scroll_threshold', 3),
     '#weight' => -2,
	 '#size' => 10,
	 '#maxlength' => 2,
	 '#description' => t('If a product has more additional images then set here, these images will have scrolling effect.'),
    );
  }
  if ($form_id == 'userpoints_admin_settings') {
    unset($form['renaming']);
  }

  if ($form_id == 'user_profile_form') {
    $form['account']['#weight'] = -10;
    $form['block']['#weight'] = -9;
    $form['locale']['#weight'] = -8;
    $form['timezone']['#weight'] = -7;
    $form['contact']['#weight'] = -6;
    $form['mimemail']['#weight'] = -5;
    $form['file']['#weight'] = -4;
    $form['account']['#attributes'] = array('class' => 'account-settings');
    $form['block']['#attributes'] = array('class' => 'block-settings');
    $form['locale']['#attributes'] = array('class' => 'locale-settings');
    $form['timezone']['#attributes'] = array('class' => 'timezone-settings');
    $form['contact']['#attributes'] = array('class' => 'contact-settings');
    $form['mimemail']['#attributes'] = array('class' => 'mimemail-settings');
    $form['file']['#attributes'] = array('class' => 'file-settings');
    $form['subscriptions']['#attributes'] = array('class' => 'subscriptions-settings');
    $form['account']['#title'] = '';
    $form['locale']['#title'] = '';
    $form['mimemail']['#title'] = '';
    $form['block']['#title'] = '';
    $form['contact']['#title'] = '';
    $form['timezone']['#title'] = '';
    $form['file']['#title'] = '';
    $form['subscriptions']['#title'] = '';
    $form['theme_select']['themes']['#collapsed'] = TRUE;
    $form['domain_user']['#collapsed'] = TRUE;
    $form['masquerade']['#collapsible'] = TRUE;
    $form['masquerade']['#collapsed'] = TRUE;
    $form['block']['#collapsible'] = FALSE;
    $form['contact']['#collapsible'] = FALSE;
    $form['timezone']['#collapsible'] = FALSE;
    $form['commission_settings']['#collapsed'] = TRUE;
    $form['file']['#collapsed'] = FALSE;
    $form['file']['#collapsible'] = FALSE;
    $form['uc_roles']['expirations']['#type'] = 'markup';
  }

  if ($form_id == 'uc_store_store_settings_form') {
    $form['uc_store_main_settings']['uc_store_start_date'] = array(
     '#type' => 'textfield',
     '#title' => t('Start copyright date'),
	 '#size' => 20,
	 '#maxlength' => 4,
     '#default_value' => variable_get('uc_store_start_date', 2010),
	 '#description' => t('The date, when your business was started. Used for copyright'),
     );

    $form['uc_store_main_settings']['uc_store_yandex_map'] = array(
     '#type' => 'textarea',
     '#title' => t('Location on Yandex Map'),
	 '#rows' => 2,
     '#default_value' => variable_get('uc_store_yandex_map', FALSE),
	 '#description' => t('Office/store location shown on <a href="http://maps.yandex.ru">Yandex Maps</a>'),
     );

    $form['uc_store_main_settings']['uc_store_google_map'] = array(
     '#type' => 'textarea',
     '#title' => t('Location on Google Map'),
	 '#rows' => 2,
     '#default_value' => variable_get('uc_store_google_map', FALSE),
	 '#description' => t('Office/store location shown on <a href="http://maps.google.com">Google Maps</a>'),
     );

  }

  if ($form_id == 'user_login') {
    $form['fb_user']['#weight'] = 1;
    $form['twitter_signin']['#weight'] = 3;
    $form['vk_openapi_button']['#weight'] = 2;
    $form['name']['#weight'] = 4;
    $form['pass']['#weight'] = 5;
    $form['submit']['#weight'] = 6;
    $form['openid_links']['#weight'] = 8;
    $form['openid_identifier']['#weight'] = 7;
    $form['openid.return_to']['#weight'] = 9;
    $form['submit']['#weight'] = 10;

  }
  if ($form_id == 'nodequeue_edit_queue_form') {
    unset($form['description']['#title']);
  }

  if ($form_id == 'product_node_form') {
    $form['base']['pkg_qty']['#size'] = 20;
    $form['base']['model']['#size'] = 20;
  }

  if ($form_id == 'uc_catalog_settings_form') {
    $form['catalog-top-level']['uc_cat_auto_pic'] = array(
     '#type' => 'checkbox',
     '#title' => t('Catalog auto pictures'),
     '#default_value' => variable_get('uc_cat_auto_pic', FALSE),
	 '#description' => t('If selected, category pictures will be filled automatically from associated nodes imagefields'),
	);

    $form['catalog-top-level']['uc_category_image'] = array(
     '#type' => 'checkbox',
     '#title' => t('Enable category image'),
     '#default_value' => variable_get('uc_category_image', TRUE),
	 '#description' => t('If selected, parent category picture will be shown on nested pages'),
	);

    $autopictures_preset = array();
    $category_image_preset = array();
    $presets = imagecache_presets();
    foreach ($presets as $preset_id => $preset) {
      $autopictures_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
      $category_image_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
    }

    $form['catalog-top-level']['uc_cat_auto_pic_preset'] = array(
      '#type' => 'select',
      '#title' => t('Catalog picture preset'),
      '#default_value' => variable_get('uc_cat_auto_pic_preset', 10),
      '#options' => $autopictures_preset,
	  '#description' => t('Choose the preset name used for catalog image output'),
    );

    $form['catalog-top-level']['uc_category_image_preset'] = array(
      '#type' => 'select',
      '#title' => t('Category picture preset'),
      '#default_value' => variable_get('uc_category_image_preset', 10),
      '#options' => $category_image_preset,
	  '#description' => t('Choose a preset name used for category image output'),
    );
  }
  if ($form_id == 'uc_addresses_settings_form') {
    $form['user']['#title'] = '';
    $form['user']['#type'] = 'markup';
  }
  if ($form_id == 'uc_cart_cart_settings_form') {
    $form['openstore'] = array(
	'#type' => 'fieldset',
	'#collapsed' => FALSE,
	'#collapsible' => FALSE,
	'#title' => t('Cart message'),
	'#weight' => -10,	
	);
    $form['openstore']['openstore_cart_text'] = array(
     '#type' => 'textarea',
     '#title' => t('Message'),
	 '#rows' => 2,
     '#default_value' => variable_get('openstore_cart_text', FALSE),
	 '#description' => t('Enter a help message that will shown on cart page.'),
     );
  }
  if ($form_id == 'uc_cart_checkout_form' && !variable_get('uc_use_next_buttons', FALSE) && !variable_get('uc_collapse_current_pane', FALSE)) {
    foreach ($form['panes'] as $key => $value) {
      if ($form['panes'][$key]['#type'] == 'fieldset') {
        $form['panes'][$key]['#title'] = '';
      }
    }
  }
  if ($form_id == 'user_login') {
    $form['forgot_pass'] = array(
	'#type' => 'markup',
	'#value' => l(t('Request new password'), 'user/password', array('attributes' => array('rel' => 'nofollow', 'class' => 'forgot-pass'))),
	'#weight' => 20,
	);     
	
    $form['name']['#weight'] = 5;
    $form['pass']['#weight'] = 6;   
    $form['submit']['#weight'] = 8;
    $form['forgot_pass']['#weight'] = 9;   	
    
	if (module_exists('fbconnect')) {
    unset($form['fbconnect_button']['#description']);
    $form['fbconnect_button']['#weight'] = 3;
	$form['fbconnect_button']['#value'] = '<div class="fb-button">' . $form['fbconnect_button']['#value'] . '</div>';
	$form['fbconnect_button']['#type'] = 'markup';
	}   
	
	if (module_exists('openid')) {
	unset($form['openid_links']);
	unset($form['openid_identifier']['#description']);
	$form['openid_button']['#value'] = '<div class="openid-button">' . theme_image(drupal_get_path('module', 'general') . '/images/openid_icon.png', t('OpenID'), t('Click to login via OpenID'), NULL, FALSE) . ' ' . t('OpenID') . '</div>';	
	$form['openid_identifier']['#weight'] = 7;
	$form['openid_button']['#weight'] = 1;
	$form['openid_button']['#type'] = 'markup';
	}	
	
	if (module_exists('vk_openapi')) {
	$form['vk_openapi_button']['#value'] = '<div class="vk-button">' . $form['vk_openapi_button']['#value'] . '</div>';
	$form['vk_openapi_button']['#weight'] = 4;
	}
	
	if (module_exists('twitter')) {
	$form['twitter_signin']['#value'] = '<div class="twitter-button">';
	$form['twitter_signin']['#weight'] = 2;   
	$form['twitter_signin']['#value'] .= theme_image(drupal_get_path('module', 'general') . '/images/twitter_button.jpg', t('Twitter'), t('Sign in with Twitter'), NULL, FALSE);	
	$form['twitter_signin']['#value'] .= l('Twitter', 'twitter/redirect');
    $form['twitter_signin']['#value'] .= '</div>';
	}
  }

  if ($form_id == 'user_register') {
    if (!empty($form['simplenews']['newsletters']['#options'])) {

      $form['simplenews']['newsletters']['openstore_text_top'] = array(
	'#type' => 'markup',
	'#value' => '<div class="text-top">' . t('Subscribe to store newsletters') . '</div>',
	'#weight' => -10,
	);

      $form['simplenews']['newsletters']['openstore_text_bottom'] = array(
	'#type' => 'markup',
	'#value' => '<div class="text-bottom">' . t('NOTE: we DO NOT spam!') . '</div>',
	'#weight' => 10,
	);
    }
    $form['account']['#type'] = 'markup';
    $form['account']['delimeter'] = array(
	'#type' => 'markup',
	'#value' => '<hr/>',
	'#weight' => 20,
	);
    foreach ($form as $key => $value) {
      if ($value['#type'] == 'fieldset') {
        $form[$key]['#type'] = 'markup';
      }
      if (!empty($value['first_name']) && !empty($value['first_name']) && !empty($value['city'])) { // Справка-пояснение, если есть форма с данными адреса	
        $form[0]['explanation'] = array(
	'#type' => 'markup',
	'#value' => '<div class="register-address-text">' . t('Please provide your address information below. It will used for delivery and payment address') . '</div>',
	'#weight' => -20,
	);
      }
    }
  }
  if ($form_id == 'user_pass') {
    $form['forgot_pass'] = array(
	'#type' => 'markup',
	'#value' => l(t('Return to login/register'), 'user', array('attributes' => array('rel' => 'nofollow', 'class' => 'to-user-page'))),
	'#weight' => 20,
	);
  }
  if ($form_id == 'twitter_signin_admin_settings') {
    unset($form['twitter_signin_button']); // Убираем форму выбора стиля кнопок, так как они нам не нравятся и мы определили выше свою в форме входа	
  }
  if ($form_id == 'comment_form') {
    if (arg(0) == 'comment' && is_numeric(arg(2))) {
      $prev_page = 'node/' . $form['nid']['#value'];
      $form['openstore_return_link'] = array(
	'#type' => 'markup',
	'#value' => l(t('Return to previous page'), $prev_page, array('attributes' => array('class' => 'to-prev-page'))),
	'#weight' => 20,
	);
    }
    $form['admin']['#type'] = 'markup';
  }
  if (module_exists('uc_addresses')) {
    if ($form_id == 'uc_addresses_get_address_form') {
      $form['panes']['address']['#type'] = 'markup';
      $form['panes']['address']['save']['#title'] = '';
    }
  }
  if ($form_id == 'uc_advanced_catalog_settings_form') {
    unset($form['uc_advanced_catalog_sticky']); // скрываем чекбокс "отображать прилепленные товары в каталоге"
  }

  if (module_exists('uc_product_kit')) {
    if ($form_id == 'uc_product_kit_settings_form') {
      $product_kit_preset = array();
      $product_kit_main_preset = array(0 => t('Do not adjust image size'));
      $presets = imagecache_presets();

      foreach ($presets as $preset_id => $preset) {
        $product_kit_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));
        $product_kit_main_preset[$preset_id] = t('Display via imagecache preset !preset', array('!preset' => $preset['presetname']));

        $form['openstore_kit_preset'] = array(
      '#type' => 'select',
      '#title' => t('Product kit preset'),
      '#default_value' => variable_get('openstore_kit_preset', 13),
      '#options' => $product_kit_preset,
	  '#description' => t('Choose a preset name to use as product kit items image.'),
    );

        $form['openstore_kit_main_preset'] = array(
      '#type' => 'select',
      '#title' => t('Product kit main image preset'),
      '#default_value' => variable_get('openstore_kit_main_preset', 0),
      '#options' => $product_kit_main_preset,
	  '#description' => t('Choose a preset name to use as product kit main image.'),
    );

        $form['openstore_kit_column'] = array(
      '#type' => 'select',
      '#title' => t('Column count'),
      '#default_value' => variable_get('openstore_kit_column', 2),
      '#options' => array(1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5),
	  '#description' => t('Choose how many columns will have the table which presents product kit items'),
    );
      }
    }
  }

  if (module_exists('advcontact')) {
    if ($form_id == 'contact_mail_page') {
      unset($form['contact_information']);
    }
  }
}