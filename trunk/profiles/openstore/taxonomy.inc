<?php

/*
 * Добавление и настройка таксономии (словари и термины)
 * 
 */
function openstore_config_taxonomy() { 
 $vocabularies = array (  
    // Словарь с терминами торговых марок
    $vocab1 = array(
    'name' => t(OPENSTORE_TRADEMARK_NAME),
    'description' => t('Trademarks of manufacturers'),
    'multiple' => '0',
    'required' => '0',
    'hierarchy' => '0',
    'relations' => '0',
    'module' => 'taxonomy',
   ), 
    
	// Общий словарь
    $vocab2 = array(
    'name' => t(OPENSTORE_COMMONTERMS_NAME),
    'description' => t('Different categories for common usage'),
    'multiple' => '1',
    'required' => '0',
    'hierarchy' => '0',
    'relations' => '0',
    'module' => 'taxonomy',
   ),
    
	// Словарь для тегов
    $vocab3 = array(
    'name' => t(OPENSTORE_TAGS_NAME),
    'description' => t('Tags for content tagging'),
    'multiple' => '0',
    'required' => '0',
    'hierarchy' => '0',
    'relations' => '0',
	  'tags' => '1',
    'module' => 'taxonomy',
   ),
	
    // Словарь для промо-акций, скидок, распродаж	
	$vocab4 = array(
    'name' => t(OPENSTORE_PROMO_NAME),
    'description' => t('Promo actions, hot offers...'),
    'multiple' => '1',
    'required' => '0',
    'hierarchy' => '0',
    'relations' => '0',
    'module' => 'taxonomy',
    ),
  );

   foreach ($vocabularies as $vocabulary) {
     taxonomy_save_vocabulary($vocabulary); 
    }
  
  // После того, как словари созданы, мы назначаем им нужные ID, так как от них зависят виды
  db_query("UPDATE {vocabulary} SET vid = %d WHERE name = '%s'", OPENSTORE_TRADEMARK_ID, OPENSTORE_TRADEMARK_NAME);    
  db_query("UPDATE {vocabulary} SET vid = %d WHERE name = '%s'", OPENSTORE_COMMONTERMS_ID, OPENSTORE_COMMONTERMS_NAME);  
  db_query("UPDATE {vocabulary} SET vid = %d WHERE name = '%s'", OPENSTORE_TAGS_ID, OPENSTORE_TAGS_NAME);  
  db_query("UPDATE {vocabulary} SET vid = %d WHERE name = '%s'", OPENSTORE_PROMO_ID, OPENSTORE_PROMO_NAME);  
  
  // Очищаем таблицу vocabulary_node_types перед последующим определением полей нашими значениями    
  $sql = db_query("SELECT vid FROM {vocabulary_node_types}");
   while ($vid = db_fetch_array($sql)) {     
     if ($vid['vid'] == OPENSTORE_CATALOG_ID || $vid['vid'] == OPENSTORE_SIMPLENEWS_ID) {     
     unset($vid['vid']);     
     }                
     db_query("DELETE FROM {vocabulary_node_types} WHERE vid = %d", $vid['vid']);     
  } 
  
  // Назначаем созданные словари к нужным типам документов
  $sql = "INSERT INTO {vocabulary_node_types} (vid, type) VALUES (%d, '%s')"; 
  db_query($sql, OPENSTORE_CATALOG_ID, OPENSTORE_CONTENT_BANNER_ID);
  db_query($sql, OPENSTORE_CATALOG_ID, OPENSTORE_CONTENT_PAGE_ID);  
  db_query($sql, OPENSTORE_TRADEMARK_ID, OPENSTORE_CONTENT_BANNER_ID);
  db_query($sql, OPENSTORE_TRADEMARK_ID, OPENSTORE_CONTENT_PAGE_ID);
  db_query($sql, OPENSTORE_TRADEMARK_ID, OPENSTORE_CONTENT_PRODUCT_ID);  
  db_query($sql, OPENSTORE_COMMONTERMS_ID, OPENSTORE_CONTENT_BANNER_ID);
  db_query($sql, OPENSTORE_COMMONTERMS_ID, OPENSTORE_CONTENT_PAGE_ID);  
  db_query($sql, OPENSTORE_TAGS_ID, OPENSTORE_CONTENT_PAGE_ID); 
  db_query($sql, OPENSTORE_TAGS_ID, OPENSTORE_CONTENT_PRODUCT_ID);
  db_query($sql, OPENSTORE_TAGS_ID, OPENSTORE_CONTENT_PRODUCTKIT_ID);  
  db_query($sql, OPENSTORE_PROMO_ID, OPENSTORE_CONTENT_BANNER_ID);
  db_query($sql, OPENSTORE_PROMO_ID, OPENSTORE_CONTENT_PAGE_ID);
  db_query($sql, OPENSTORE_PROMO_ID, OPENSTORE_CONTENT_PRODUCT_ID);
  db_query($sql, OPENSTORE_PROMO_ID, OPENSTORE_CONTENT_PRODUCTKIT_ID);
  
  // Небольшая корректировка словарей, которые созданы автоматически при включении модулей
  db_query("UPDATE {vocabulary} SET name = '%s' WHERE module = '%s'", 'Каталог', 'uc_catalog');
  db_query("UPDATE {vocabulary} SET name = '%s' WHERE module = '%s'", 'Рассылки', 'simplenews'); 
  db_query("UPDATE {vocabulary} SET description = '%s' WHERE module = '%s'", 'Главный каталог мазазина с категориями товаров', 'uc_catalog');
  db_query("UPDATE {vocabulary} SET description = '%s' WHERE module = '%s'", 'Категории рассылки', 'simplenews');  
  db_query("UPDATE {vocabulary} SET help = '%s' WHERE module = '%s'", '', 'uc_catalog');
}
