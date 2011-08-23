<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function openstore_all_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-info:node/1
  $menu_links['menu-info:node/1'] = array(
    'menu_name' => 'menu-info',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'О магазине',
    'options' => array(
      'attributes' => array(
        'title' => 'Основная информация о магазине',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-info:node/2
  $menu_links['menu-info:node/2'] = array(
    'menu_name' => 'menu-info',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Гарантии',
    'options' => array(
      'attributes' => array(
        'title' => 'Гарантии магазина',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-info:node/3
  $menu_links['menu-info:node/3'] = array(
    'menu_name' => 'menu-info',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Оплата',
    'options' => array(
      'attributes' => array(
        'title' => 'Порядок и способы оплаты',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-info:node/4
  $menu_links['menu-info:node/4'] = array(
    'menu_name' => 'menu-info',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Доставка',
    'options' => array(
      'attributes' => array(
        'title' => 'Способы доставки',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Гарантии');
  t('Доставка');
  t('О магазине');
  t('Оплата');


  return $menu_links;
}
