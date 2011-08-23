<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function openstore_all_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-common
  $menus['menu-common'] = array(
    'menu_name' => 'menu-common',
    'title' => 'Общее меню',
    'description' => 'Это меню содержит разные ссылки, главным образом на справочные страницы и статьи, которые генерируются из терминов словаря "Общие категории" (№5) модулем "Меню таксономии" или образуются при добавлении документов.',
  );
  // Exported menu: menu-drop
  $menus['menu-drop'] = array(
    'menu_name' => 'menu-drop',
    'title' => 'Каталог магазина',
    'description' => 'Это меню содержит ссылки главного каталога товаров, которые генерируются из терминов словаря №1 модулем "Меню таксономии".',
  );
  // Exported menu: menu-info
  $menus['menu-info'] = array(
    'menu_name' => 'menu-info',
    'title' => 'Справка',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Каталог магазина');
  t('Общее меню');
  t('Это меню содержит разные ссылки, главным образом на справочные страницы и статьи, которые генерируются из терминов словаря "Общие категории" (№5) модулем "Меню таксономии" или образуются при добавлении документов.');
  t('Это меню содержит ссылки главного каталога товаров, которые генерируются из терминов словаря №1 модулем "Меню таксономии".');
  t('Справка');

  return $menus;
}
