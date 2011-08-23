<?php


/**
 * Коррекция типов документров. Мы изменяем/добавляем некоторые элементы, так как модуль Свойства не всегда делает всю эту работу
 *
 */
function openstore_config_content() {

// По некоторым причинам у иногда нас не создаются группы для полей при помощи свойств, мы это сделаем вручную.
$settings = array ('form' => array ('style' => 'fieldset_collapsed', 'description' => '',),
                   'display' => array ('description' => '', 'teaser' => array ('format' => 'fieldset','exclude' => 0,),
                   'full' => array ('format' => 'fieldset', 'exclude' => 0,),
                   4 => array ('format' => 'fieldset','exclude' => 0,),
                   'email_plain' => array ('format' => 'fieldset','exclude' => 0,),
                   'email_html' => array ('format' => 'fieldset','exclude' => 0,),
				   'token' => array ('format' => 'fieldset', 'exclude' => 0,),
                   'label' => 'above',),
                  );

openstore_create_field_group('product', 'group_specs', t('Product specs'), $settings, 1);   				
openstore_create_field_group('product', 'group_media', t('Product media'), $settings, 2);
openstore_create_field_group('product', 'group_additional', t('Product additional'), $settings, 3);


// Теперь мы влаживаем поля в созданные выше группы.
$fields = array('field_specs');
openstore_fields_in_group('product', 'group_specs', $fields);

$fields = array('field_media');
openstore_fields_in_group('product', 'group_media', $fields);

$fields = array('field_notes', 'field_warranty', 'field_warranty_add');
openstore_fields_in_group('product', 'group_additional', $fields);

}

/**
 * Функция создания групп полей в типе документа
 *
 * @param $content_type       Обязательно. Существующий тип документа
 * @param $group_name         Название группы полей
 * @param $label              Обязательно. Человеческое название поля
 * @param $settings           Массив с настройками группы полей
 * @param $weight             Вес группы. Влияет на положение группы в интерфейсе
 *
 */
 
function openstore_create_field_group($content_type, $group_name, $label, $settings = array(), $weight = 0) {  
  if (!is_array($settings)) {
    $settings = array(
      'form' => array('style' => 'fieldset', 'description' => ''),
      'display' => array('description' => '', 'teaser' => NULL, 'label' => NULL),
    );
  }
  db_query("INSERT INTO {content_group} (type_name, group_name, label, settings, weight)
    VALUES ('%s', '%s', '%s', '%s', %d)",
    $content_type, $group_name, $label, serialize($settings), $weight);
}

/**
 * Функция назначения полей к группам
 *
 * @param $content_type   Обязательно. Существующий тип документа
 * @param $group_name     Обязательно. Название существующей группы
 * @param $fields         Обязательно. Массив с названиями полей
 */
function openstore_fields_in_group($content_type, $group_name, $fields) {
  if (!is_array($fields)) {
    $fields = array($fields);
  }
  foreach ($fields AS $field_name) {
    db_query("INSERT INTO {content_group_fields} (type_name, group_name, field_name)
      VALUES ('%s', '%s', '%s')",
      $content_type, $group_name, $field_name);
  }
}