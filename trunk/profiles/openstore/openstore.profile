<?php

// Словари таксономии
define('OPENSTORE_CATALOG_ID', 1);
define('OPENSTORE_CATALOG_NAME', 'Catalog');
define('OPENSTORE_SIMPLENEWS_ID', 2);
define('OPENSTORE_SIMPLENEWS_NAME', 'Newsletters');
define('OPENSTORE_TRADEMARK_ID', 3);
define('OPENSTORE_TRADEMARK_NAME', 'Manufacturer');
define('OPENSTORE_COMMONTERMS_ID', 4);
define('OPENSTORE_COMMONTERMS_NAME', 'Common');
define('OPENSTORE_TAGS_ID', 5);
define('OPENSTORE_TAGS_NAME', 'Tags');
define('OPENSTORE_PROMO_ID', 6);
define('OPENSTORE_PROMO_NAME', 'Promo');

 // Типы документов
define('OPENSTORE_CONTENT_BANNER_ID', 'banner');
define('OPENSTORE_CONTENT_BANNER_NAME', 'banner');
define('OPENSTORE_CONTENT_POLL_ID', 'poll');
define('OPENSTORE_CONTENT_POLL_NAME', 'Poll');
define('OPENSTORE_CONTENT_PRODUCTKIT_ID', 'product_kit');
define('OPENSTORE_CONTENT_PRODUCTKIT_NAME', 'Product Kit');
define('OPENSTORE_CONTENT_SIMPLENEWS_ID', 'simplenews');
define('OPENSTORE_CONTENT_SIMPLENEWS_NAME', 'simplenews');
define('OPENSTORE_CONTENT_PAGE_ID', 'page');
define('OPENSTORE_CONTENT_PAGE_NAME', 'page');
define('OPENSTORE_CONTENT_PRODUCT_ID', 'product');
define('OPENSTORE_CONTENT_PRODUCT_NAME', 'product');

// Очереди
define('OPENSTORE_QUEUE_LARGE_ID', 1);
define('OPENSTORE_QUEUE_LARGE_NAME', 'Large carousel');
define('OPENSTORE_QUEUE_FEATURED_ID', 2);
define('OPENSTORE_QUEUE_FEATURED_NAME', 'Featured products');
define('OPENSTORE_QUEUE_SEO_ID', 3);
define('OPENSTORE_QUEUE_SEO_NAME', 'SEO category articles');
define('OPENSTORE_QUEUE_ARTICLE_ID', 4);
define('OPENSTORE_QUEUE_ARTICLE_NAME', 'Articles in category');
define('OPENSTORE_QUEUE_BANNER_ID', 5);
define('OPENSTORE_QUEUE_BANNER_NAME', 'Banner in category');
define('OPENSTORE_QUEUE_HOT_ID', 6);
define('OPENSTORE_QUEUE_HOT_NAME', 'Hot offers');
define('OPENSTORE_QUEUE_NEWS_ID', 7);
define('OPENSTORE_QUEUE_NEWS_NAME', 'Store news');
define('OPENSTORE_QUEUE_POLL_ID', 8);
define('OPENSTORE_QUEUE_POLL_NAME', 'Poll in block');
define('OPENSTORE_QUEUE_REVIEW_ID', 9);
define('OPENSTORE_QUEUE_REVIEW_NAME', 'Customer reviews');

// Роли (название)
define('OPENSTORE_ROLE_DIRECTOR', 'director');
define('OPENSTORE_ROLE_MANAGER', 'manager');
define('OPENSTORE_ROLE_CONTENTMANAGER', 'content manager');
define('OPENSTORE_ROLE_AFFILIATE', 'affiliate');

// Роли (rid)
define('OPENSTORE_ROLEID_DIRECTOR', 3);
define('OPENSTORE_ROLEID_MANAGER', 4);
define('OPENSTORE_ROLEID_CONTENTMANAGER', 5);
define('OPENSTORE_ROLEID_AFFILIATE', 6);

// Пользователи (логины)
define('OPENSTORE_USER_DIRECTOR', 'director');
define('OPENSTORE_USER_MANAGER', 'manager');
define('OPENSTORE_USER_CONTENTMANAGER', 'contentmanager');
define('OPENSTORE_USER_AFFILIATE', 'affiliate');

// Пользователи (UID)
define('OPENSTORE_USERID_DIRECTOR', 3);
define('OPENSTORE_USERID_MANAGER', 4);
define('OPENSTORE_USERID_CONTENTMANAGER', 5);
define('OPENSTORE_USERID_AFFILIATE', 6);

// Темы оформления
define('OPENSTORE_THEME', 'frontend');
define('OPENSTORE_ADMIN_THEME', 'administrator');

// CKeditor
define('OPENSTORE_CKEDITOR_DEF_NAME', 'Default');
define('OPENSTORE_CKEDITOR_ADV_NAME', 'Advanced');
define('OPENSTORE_CKEDITOR_GLOBAL_NAME', 'CKEditor Global Profile');

// Меню
define('OPENSTORE_MEGAMENU', 'menu-drop');

// Функции настройки для удобства вынесены во внешние файлы, подключим их.
include_once 'blocks.inc';
include_once 'misc.inc';
include_once 'nodequeue.inc';
include_once 'nodes.inc';
include_once 'taxonomy.inc';
include_once 'users.inc';
include_once 'editor.inc';
include_once 'imagecache.inc';
include_once 'cck.inc';

// Информация по этому профилю
function openstore_profile_details() {
  return array(
    'name' => 'Open Store',
    'description' => st('Free e-commerce solution based on Drupal and Ubercart module'),
  );
}

function openstore_profile_modules() {
  return array(
    'locale', 
	'l10n_update',
	'general',
	'comment', 
	'menu', 
	'taxonomy', 
	
	);
 }
 
function openstore_modules_1() {
  return array(
    'dblog', 
    'upload',
	'poll',
	'php',
	'path',
	'contact',
	'profile',	
	'statistics',	   
	'translation',
	'transliteration',	
	'token',	
	'content', 
	'fieldgroup',
	'nodereference',
	'number',
	'optionwidgets',
	'text',
	'computed_field',
	'filefield',
	'imagefield',		
	'imageapi', 
	'imageapi_gd', 
	'imagecache',
	'imagecache_ui',
    'imagecache_canvasactions',	
	'ckeditor', 
    'ckeditor_link', 	
	'imce', 			
	'imce_mkdir',	 	 
	'taxonomy_menu',
	'taxonomy_menu_path_custom',
	'megamenu',
	'superfish',	 	 
	'votingapi',
	'fivestar',			 
	'mimemail',  
	'mimemail_compress',	
	'nodewords', 
	'nodewords_basic',
	'nodewords_custom_pages',
	'nodewords_admin',
	'nodewords_tokens',
	'nodewords_ui',
	'nodewords_verification_tags',	
	'nodequeue',    
    'tagadelic', 		
	'service_links',
	'general_services',
	'russian_services',			
	'xmlsitemap', 
	'xmlsitemap_engines', 
	'xmlsitemap_menu', 
	'xmlsitemap_node', 			
	'views',
    'views_ui', 	
	'views_bonus_export', 
	'views_bulk_operations', 
	'views_showcase',
    'translation_helpers',
    'flag',
    'pathauto',	    
	'admin_theme',  
    'ajax_search', 
    'backup_migrate', 	
    'advcontact',
    'globalredirect', 
    'googleanalytics',
    'javascript_aggregator', 
	'module_filter',	
    'submitagain',	
    'r4032login',    
	'login_destination',
    'poormanscron',
    'jquery_update',
	'chart',	
    'userpoints', 
    'uc_userpoints_award', 
    'uc_userpoints_discount',	

	);
 }
 
 
 function openstore_modules_2() {
 return array(
	// Ubercart   
	'ca',
    'uc_store', 
    'uc_product',
    'uc_product_kit',
    'uc_order',
    'uc_cart',
    'uc_attribute',
    'uc_catalog',
    'uc_payment',
    'uc_file',
    'uc_reports',
    'uc_roles',
    'uc_taxes',
    'uc_tax_report',
    'uc_quote',
    'uc_shipping',
    'uc_affiliate2',
    'uc_cart_links',
    'uc_googleanalytics',
	'uc_product_power_tools',
	'uc_recent_products',
	'uc_stock',
	'uc_stock_update',
	'uc_addresses',
	'uc_followup',
	'uc_flatrate',
	'uc_weightquote',
	'uc_payment_pack',
    'uc_paymentgate', 	  
    'uc_interkassa',
    'uc_liqpay', 
    'uc_receipt',
    'uc_webmoneygate',
    'uc_views',
    'uc_views_attribute',
    'uc_views_marketing',
    'uc_advanced_catalog',
	'simplenews',
	'google_analytics_api',
	'tagging',
    'tagging_vocab_suggest',
  	
	// Фичи	
	'ctools',
	'strongarm', 
	'features', 
    'openstore_all_features',
   );
 }
  
// Задания профиля  
function openstore_profile_task_list() {
     $tasks = array(); 
	 $tasks['openstore-modules-batch'] = st('Additional modules');
	 if (openstore_language_selected() && variable_get('openstore_install_translations', TRUE)) {
          $tasks['openstore-translate-batch'] = st('Download and import translations');
     }  	 	 
	 $tasks['openstore-configure-batch'] = st('Final configuration'); 
	
	return $tasks;
  } 

function openstore_profile_tasks(&$task, $url) {
    global $profile, $install_locale;  	
	$output = '';
	
    if ($task == 'profile') {		
	$modules = openstore_modules_1();
    $files = module_rebuild_cache();
    foreach ($modules as $module) {
      $batch['operations'][] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }    
    $batch['finished'] = 'openstore_modules1_batch_finished';
    $batch['title'] = st('Installing additional modules. Stage 1', array('@drupal' => drupal_install_profile_name()));
    $batch['error_message'] = st('The installation has encountered an error.');
    variable_set('install_task', 'openstore-modules-batch');
    batch_set($batch);
    batch_process($url, $url);
    return;
    }
	
    if ($task == 'openstore-modules-2') {		
	$modules = openstore_modules_2();
    $files = module_rebuild_cache();
    foreach ($modules as $module) {
      $batch['operations'][] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }    
    $batch['finished'] = 'openstore_modules2_batch_finished';
    $batch['title'] = st('Installing additional modules. Stage 2', array('@drupal' => drupal_install_profile_name()));
    $batch['error_message'] = st('The installation has encountered an error.');
    variable_set('install_task', 'openstore-modules-batch');
    batch_set($batch);
    batch_process($url, $url);
    return;
    }		
	
	// Подключаем BatchAPI
    if (in_array($task, array('openstore-configure-batch', 'openstore-modules-batch', 'openstore-translate-batch'))) {
    include_once 'includes/batch.inc';
    $output = _batch_page();
    } 
	
	
	if ($task == 'translate-batch') { 			
    if (openstore_language_selected() && variable_get('openstore_install_translations', TRUE)) {
      $history = l10n_update_get_history();
      module_load_include('check.inc', 'l10n_update');
      $available = l10n_update_available_releases();
      $updates = l10n_update_build_updates($history, $available);
      module_load_include('batch.inc', 'l10n_update');
      $updates = _l10n_update_prepare_updates($updates, NULL, array());
      $batch = l10n_update_batch_multiple($updates, LOCALE_IMPORT_KEEP);
      $batch['finished'] = 'openstore_batch_finished';
      variable_set('install_task', 'openstore-translate-batch');
      batch_set($batch);
      batch_process($url, $url);
      }
	}	
	
	if($task == 'configure-batch') {
	$batch['title'] = st('Final configuration');   	
    $batch['operations'][] = array('openstore_config_directories', array());
	$batch['operations'][] = array('openstore_config_roles', array());
	$batch['operations'][] = array('openstore_config_perms', array());
	$batch['operations'][] = array('openstore_config_users', array());
	$batch['operations'][] = array('openstore_config_taxonomy', array());
	$batch['operations'][] = array('openstore_config_nodes', array());
	$batch['operations'][] = array('openstore_config_nodequeues', array());
	$batch['operations'][] = array('openstore_config_countries', array());
	$batch['operations'][] = array('openstore_config_megamenu', array());
	$batch['operations'][] = array('openstore_config_editor', array());
	$batch['operations'][] = array('openstore_config_flag', array());
	$batch['operations'][] = array('openstore_config_metatags', array());
	$batch['operations'][] = array('openstore_config_backup', array());
	$batch['operations'][] = array('openstore_config_contact', array());
	$batch['operations'][] = array('openstore_config_statuses', array());
	$batch['operations'][] = array('openstore_config_imagecache', array());
	$batch['operations'][] = array('openstore_config_content', array());
	$batch['operations'][] = array('openstore_config_views', array());
	$batch['operations'][] = array('openstore_config_blocks', array());
	$batch['operations'][] = array('openstore_config_ptools', array());
	$batch['finished'] = 'openstore_configure_batch_finished';    
	variable_set('install_task', 'openstore-configure-batch');
    batch_set($batch);
    batch_process($url, $url);
    return;		
    } 
	
  return $output;
}

function openstore_language_selected() {
  global $install_locale;
  return !empty($install_locale) && ($install_locale != 'en');
}

function openstore_batch_finished($success, $results) {
  if ($success) {
    variable_set('install_task', 'configure-batch');
  } 
}

function openstore_modules1_batch_finished($success, $results) {
  variable_set('install_task', 'openstore-modules-2');
}

function openstore_modules2_batch_finished($success, $results) {
  if (variable_get('openstore_install_translations', TRUE) && openstore_language_selected()) {
  variable_set('install_task', 'translate-batch');
  } else {
	variable_set('install_task', 'configure-batch');
  }
}
 
function openstore_configure_batch_finished($success, $results) {		 
   	    openstore_cleanup(); // Прибираем за собой, сбрасываем кэш, перестраиваем права и тд.
	    variable_set('install_task', 'finished'); // Устанавливаем состояние профиля как "Установлен"	
  }
 
// Выбираем по умолчанию профиль установки "Openstore"
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'openstore'; 
	unset($form['profile']['Drupal']);
  }
}

// Удаляем ненужные элементы интерфейса, чтобы не утомлять ими пользователя
function system_form_install_configure_form_alter(&$form, $form_state) { 
$form['server_settings']['update_status_module']['#default_value'][0] = FALSE;
unset($form['server_settings']['update_status_module']);
unset($form['server_settings']['date_default_timezone']);
}

function openstore_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    $form['openstore'] = array(
      '#weight' => -10,
      '#type' => 'fieldset',
      '#title' => st('Install options'),
      '#collapsible' => false,
    );

    $form['openstore']['openstore_install_translations'] = array(
      '#type' => 'checkbox',
      '#title' => st('Download & install translates'),
	  '#description' => st('After all modules installed, they will be translated by downloading and importing .po files from openstore.org.ua. If you would like to use your own translates or have a problem with getting our translations, uncheck this option'),
    );
	
	if (openstore_language_selected()) {
    $form['openstore']['openstore_install_translations']['#disabled'] = FALSE;
	$form['openstore']['openstore_install_translations']['#default_value'] = TRUE;
	} else {
	$form['openstore']['openstore_install_translations']['#disabled'] = TRUE;
	$form['openstore']['openstore_install_translations']['#default_value'] = FALSE;
	}
	
	$time = ini_get('max_execution_time');
	$recommended = 60;
	$hosts = gethostbynamel('www.openstore.org.ua');
	
	if (empty($hosts)) {
	$requirements = '<span style = "color:red;">' . st('No connection to openstore.org.ua. You can not download and import translates from there. Check your internet connection or try later.') . '</span>';
	}
	if ($time < $recommended) {
	$requirements .= '<span style = "color:blue;">' . st('<p>Your <em>max_execution_time</em> value is @time, that may cause fatal error on the next steps, i.e preparing to import translations. Try to increase the value to at least <em>@recommended</em>', array('@time' => $time, '@recommended' => $recommended,)) . '<span></p>';
	}
    
	$form['openstore']['openstore_check_requirements'] = array(
      '#type' => 'markup',
      '#value' => $requirements,
    );   
    
    $form['#submit'] = array('openstore_config_submit', 'install_configure_form_submit');
  } 
}

//Изменяем форму выбора языков. Устанавливаем русский по умолчанию, убираем английский
function system_form_install_select_locale_form_alter(&$form, $form_state) {
  $form['locale']['ru']['#value'] = 'ru';
  unset($form['locale']['en']);
}

function openstore_config_submit($form, &$form_state) {
  variable_set('openstore_install_translations', $form_state['values']['openstore_install_translations']);
}