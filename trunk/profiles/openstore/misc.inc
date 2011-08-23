<?php

/**
 * Настройка флагов
 *
 */
function openstore_config_flag() {
  $flag_id = db_result(db_query("SELECT fid FROM {flags} WHERE name = '%s'", 'bookmarks'));
  $sql = "INSERT INTO {flag_types} (fid, type) VALUES (%d, '%s')";
  db_query("DELETE FROM {flag_types}");
  
  // Назначаем флаг для типов содержимого...
  db_query($sql, $flag_id, OPENSTORE_CONTENT_PRODUCT_ID);
  db_query($sql, $flag_id, OPENSTORE_CONTENT_PRODUCTKIT_ID);

  $flag_settings = array(
   'flag_short' => 'В закладки',
   'flag_long' => 'Добавить в закладки',
   'flag_message' => 'Товар был добавлен в ваши закладки',
   'flag_confirmation' => '',
   'unflag_short' => 'Удалить из закладок',
   'unflag_long' => 'Удалить товар из своих закладок',
   'unflag_message' => 'Товар был удалён из ваших закладок',
   'unflag_confirmation' => '',
   'link_type' => 'toggle',
   'show_on_page' => 1,
   'show_on_teaser' => 0,
   'show_on_form' => 0,
   'i18n' => 0,
  );

  $flag_settings = serialize($flag_settings);
   db_query("UPDATE {flags} SET options = '%s' WHERE name = '%s'", $flag_settings, 'bookmarks');  
  }

/**
 * Настройка видов. Мы отключаем ненужные нам виды.
 * 
 */
function openstore_config_views() {
  $disabled = variable_get('views_defaults', array());
  //$disabled['comments_recent'] = TRUE; // с этим видом проблема, пока отключаем 
  
  // Бага с созданием множества видов очередей, игнорируя настройки, запрещающие это. Отключаем их
  $disabled['nodequeue_1'] = TRUE;    
  $disabled['nodequeue_2'] = TRUE;
  $disabled['nodequeue_3'] = TRUE;
  $disabled['nodequeue_4'] = TRUE;
  $disabled['nodequeue_5'] = TRUE;
  $disabled['nodequeue_6'] = TRUE;
  $disabled['nodequeue_7'] = TRUE;
  $disabled['nodequeue_8'] = TRUE;
  $disabled['nodequeue_9'] = TRUE;
  $disabled['tweets'] = TRUE;
  variable_set('views_defaults', $disabled);
  views_invalidate_cache(); // Сбрасываем кеш видов 
  }
  
/*
 * Настройка тем оформления
 * 
 */
function openstore_config_theme() {
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", OPENSTORE_THEME); // Включаем тему "Frontend"
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", OPENSTORE_ADMIN_THEME); // Включаем тему "Administrator"
  db_query("UPDATE {system} SET status = 0 WHERE type = 'theme' and name = '%s'", 'garland'); // Отключаем дефолтный garland :) 
  variable_set('theme_default', OPENSTORE_THEME); // Устанавливаем для фронтенда тему Frontend 
  variable_set('admin_theme', OPENSTORE_ADMIN_THEME); // Устанавливаем для администратора тему Administrator  
  // Сбрасываем кэш
  list_themes(TRUE); 
  drupal_rebuild_theme_registry();
}


/**
 * Настройка языков
 *
 */
function openstore_config_language() {
  global $install_locale;
  
  // Удаляем английский с глаз долой, чтобы не смущать тех, кто с ним не дружит
  if (!empty($install_locale) && ($install_locale != 'en')) {
    db_query("DELETE FROM {languages} WHERE language = 'en'");
  }
  
  // Устанавливаем русский по умолчанию, иначе сразу после установки при загруженном переводе интерфейс будет оставаться на английском
  $sql = db_query("SELECT * FROM {languages} WHERE language = '%s'", $install_locale);
  while ($result = db_fetch_object($sql)) {
  variable_set('language_default', $result);
  }  
  //cache_clear_all('locale:', 'cache', TRUE); // Сбрасываем кэш локализации на всякий случай
  }

/**
 * Импорт адресной информации для Украины и России с одновременной очисткой ненужных стран
 *
 */
function openstore_config_countries() {
$files = _country_import_list();
    if (!empty($files[804]) && !empty($files[643])) {  
    db_query("DELETE FROM {uc_countries}");  // Очищаем таблицу от ненужного
    db_query("DELETE FROM {uc_zones}"); //...и ещё одну 
    uc_country_import($files[804]['file']); // Импорт Украины
    uc_country_import($files[643]['file']); // Импорт России
  }
}

/**
 * Базовая настройка метатегов
 *
 */
function openstore_config_metatags() {
db_query("DELETE FROM {nodewords_custom}");
$sql = "INSERT INTO {nodewords_custom} (pid, name, path, weight, enabled) VALUES (%d, '%s', '%s', %d, %d)";
db_query($sql, 1, t('Home'), '<front>', 0, 1);
}

/**
 * Создаём профиль и расписание автоматического резервирования
 *
 */
function openstore_config_backup() {
$filter = array(
'compression' => 'gzip',
'notify_success_enable' => 0,
'notify_success_email' => '',
'notify_failure_enable' => 0,
'notify_failure_email' => '',
'utils_site_offline' => 0,
'utils_site_offline_message' => '',
'exclude_tables' => '',
// Массив с таблицами, содержание которых не будет включено в резервную копию (кэш, сессии и тд.)
'nodata_tables' => array ('accesslog' => 'accesslog',
                          'cache' => 'cache',
                          'cache_block' => 'cache_block',
                          'cache_filter' => 'cache_filter',
                          'cache_form' => 'cache_form',
                          'cache_menu' => 'cache_menu',
                          'cache_page' => 'cache_page',
                          'cache_views' => 'cache_views',
                          'devel_queries' => 'devel_queries',
                          'devel_times' => 'devel_times',
                          'sessions' => 'sessions',
                          'watchdog' => 'watchdog',
                          ),
                          'utils_lock_tables' => 0,
);

// Создаём расписание резервирования
$schedule_id = '1autoinstalledschedule';
$profile_id = '1autoinstalledprofile';
$name = 'Автоматическое резервирование';
$filename = '[site-name]_auto';
$append_timestamp = 1;
$timestamp_format = 'Y-m-d\TH-i-s';
$filters = serialize($filter);

$sql = "INSERT INTO {backup_migrate_profiles} (profile_id, name, filename, append_timestamp, timestamp_format, filters) VALUES ('%s', '%s', '%s', %d, '%s', '%s')";
db_query($sql, $profile_id, $name, $filename, $append_timestamp, $timestamp_format, $filters);

$sql = "INSERT INTO {backup_migrate_schedules} (schedule_id, name, source_id, destination_id, profile_id, keep, period, last_run, enabled, cron) 
        VALUES ('%s', '%s', '%s', '%s', '%s', %d, %d, %d, %d, %d)";
db_query($sql, $schedule_id, 'Ежедневное резервирование', 'db', 'scheduled', $profile_id, 30, 86400, '', 1, 0); // Хранить одновременно 30 копий и резервировать раз в день
}

/**
 * Создаём категории для контактной формы
 *
 */
function openstore_config_contact() {
$site_mail = variable_get('site_mail', 'mail@domain.com');
$sql = "INSERT INTO {contact} (cid, category, recipients, reply, weight, selected) VALUES (%d, '%s', '%s', '%s', %d, %d)";
db_query($sql, 1, 'Общие вопросы', $site_mail, '', 0, 1);
db_query($sql, 2, 'Цена товара у конкурентов', $site_mail, '', 1, 0);
db_query($sql, 3, 'Сотрудничество', $site_mail, '', 2, 0);
db_query($sql, 4, 'Вопрос по товару', $site_mail, '', 3, 0);
db_query($sql, 5, 'Неточность в описании', $site_mail, '', 4, 0);
}

/**
 * Настройка MegaMenu
 *
 */
function openstore_config_megamenu() {
   
   db_query("DELETE FROM {megamenu}"); // Удаляем всё ранее записанное в таблице megamenu    
   $result = db_query("SELECT menu_name FROM {menu_custom}"); // Смотрим, какие меню у нас уже имеются в системе
   $names = array();
     while ($menus = db_fetch_array($result)) {
        $names[] = $menus['menu_name'];
    }
   
    foreach ($names as $name) {
	// Копируем найденные меню в таблицу megamenu
    $sql = "INSERT INTO {megamenu} (menu_name, enabled, skin, menu_orientation, slot_orientation, slot_attributes) 
          VALUES ('%s', %d, '%s', '%s', '%s', '%s')";
    db_query($sql, $name, 0, 'friendly', 'horizontal', 'columnar', ''); // Вводим заново данные для всех меню
      }
	
    // наконец устанавливаем меню, которое у нас будет выпадающим	
    db_query("UPDATE {megamenu} SET enabled = %d WHERE menu_name = '%s'", 1, OPENSTORE_MEGAMENU);
    db_query("UPDATE {megamenu} SET skin = '%s' WHERE menu_name = '%s'", 'catalog', OPENSTORE_MEGAMENU);
    db_query("UPDATE {megamenu} SET menu_orientation = '%s' WHERE menu_name = '%s'", 'vertical', OPENSTORE_MEGAMENU);

}

/**
 * Даём названия для состояний заказов
 *
 */
function openstore_config_statuses() {
$statuses = array ('canceled' => 'Заказ отменён',
                   'in_checkout' => 'В процессе оформления',
				   'pending' => 'Ожидает',
				   'processing' => 'Обрабатывается',
				   'completed' => 'Завершено',
				   'payment_received' => 'Оплата получена',
				   'paypal_pending' => 'Ожидание ответа от PayPal',
				   );

	foreach($statuses as $id => $name) {	
	db_query("UPDATE {uc_order_statuses} SET title = '%s' WHERE order_status_id = '%s'", $name, $id);
	}
}

/**
 * Финальная стадия в профиле установки.
 *
 */
function openstore_cleanup() {
	
    variable_del('openstore_install_translations');	// Удаляем переменную, которую мы выставили при установке	
	
	node_types_rebuild();
	node_access_rebuild(FALSE);
	menu_rebuild();	
    
	// Сбрасываем всю возможную закешированную информацию	
	drupal_flush_all_caches();	
    drupal_clear_css_cache();
    drupal_clear_js_cache();
    
    // Настройка темы. По некоторым причинам, настройки темы нужно делать после полного сброса кэш, не перед этим
	openstore_config_theme();
	
	if (function_exists('strongarm_init')) {
    strongarm_init();
    }
	
	// На всякий случай делаем реверт для наших фич
	$revert = array('openstore_all_features' => array('content', 
	                                                  'fieldgroup', 
													  'menu_custom', 
													  'node', 
													  'variable', 
													  'views',
													  ),
                                                    );	
	features_revert($revert);
   
   // На всякий случай сбрасываем кэш видов предотвращения возможных проблем с видами после реверта выше.
   $clear = array('cache_views', 'cache_views_data');
   $cache_tables = array_merge(module_invoke_all('flush_caches'), $clear);
   foreach ($cache_tables as $table) {
    cache_clear_all('*', $table, TRUE);
   }

    openstore_config_language(); // Настройка языков    	
	variable_set('site_offline', TRUE); //Сразу после установки сайт будет в режиме профилактики
    variable_set('maintenance_theme', OPENSTORE_THEME); // Тема, используемая в режиме профилактики сайта		
	variable_set('error_level', 0); // Записывать ошибки в журнал и не выводить на экран (чтобы не пугать народ)  
    drupal_get_messages('status', TRUE); // Стираем все возможные сообщения, установленные Друпалом ранее
    variable_set('openstore_welcome_message', TRUE); // Служебная переменная
    drupal_set_message(st('OpenStore installed. Thank you for using OpenStore!'), 'welcome-message', TRUE); // Приветственное сообщение 		
	db_query("DELETE FROM {watchdog}"); // Подчищаем все записанные ранее сообщения в системном журнале
    watchdog('openstore', t('Welcome to OpenStore!')); // Дать лапу собаке 
	drupal_goto('<front>'); // Переходим на главную страницу
   }

/**
 * Создаём директории. Эта функция не является жизненно необходимой, в большинстве случаев директории создаются по мере необходимости самими модулями
 * 
 */
function openstore_config_directories() {
  $dirs = array( 
                 /*
                 // Директории пресетов
				 
                'imagecache',
                'imagecache/cart',
                'imagecache/category_banner',
                'imagecache/hot_offer',
                'imagecache/pager',
                'imagecache/product',
                'imagecache/product_adjusted',
                'imagecache/product_full',
                'imagecache/product_kit',
                'imagecache/product_list',
                'imagecache/product_list_promo',
                'imagecache/uc_category',
                'imagecache/uc_thumbnail',

                // Директории для резервирования
				
				'backup_migrate',
				'backup_migrate/scheduled',
				
				// Карта сайта
				
				'xmlsitemap',
				
				// CCK поля
				
				'banner',
				'product',
				'product_kit',
				'showcase_pager',
				
				// Другое
				
				'css', 
				'js',
				'ctools', 
                'ctools/css',
				'languages',
                */				
				'downloads', // Директория для файлов, если мы продаём файлы. Не создаётся автоматически
				);
  
  foreach ($dirs as $dir) {
    $dir = file_directory_path() . '/' . $dir;
    file_check_directory($dir, TRUE); // Мы смотрим, есть ли директории, указанные в массиве выше и если нет, создаём их.
  }
}

function  openstore_config_ptools() {
db_query("UPDATE {uc_power_tools} SET enabled = %d, asku = %d WHERE pcid = '%s'", 1, 3, OPENSTORE_CONTENT_PRODUCT_ID);
}
