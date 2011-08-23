<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function openstore_all_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function openstore_all_features_node_info() {
  $items = array(
    'banner' => array(
      'name' => t('Баннер'),
      'module' => 'features',
      'description' => t('Тип документа <em>Баннер</em> - это документ, который главным образом используется как баннер в каруселях, категорих и тд.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'page' => array(
      'name' => t('Страница'),
      'module' => 'features',
      'description' => t('Тип документа <em>Страница</em> используется для создания страниц с обычным текстом, например справка, "О магазине" и т.д.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'has_body' => '1',
      'body_label' => t('Основной текст'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'simplenews' => array(
      'name' => t('Рассылка'),
      'module' => 'features',
      'description' => t('Тип документа <em>Рассылка</em> предназначен для создания выпуском рассылок, которые отправляются подписчикам сайта.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'has_body' => '1',
      'body_label' => t('Основной текст'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function openstore_all_features_views_api() {
  return array(
    'api' => '2',
  );
}
