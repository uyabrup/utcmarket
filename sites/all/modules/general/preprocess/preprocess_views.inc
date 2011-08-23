<?php


/**
 * Функция препроцесса общего вида модуля "Views"
 */
function general_preprocess_views_view(&$vars) {
  global $user;
  
  if ($user->uid == 1) {
    $items = array();
    if ($vars['name'] == 'queues' && $vars['display_id'] == 'block_3' && $vars['empty']) {
	  //krumo($vars);
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
      $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new document'), 'node/add',
                  array(
                 'attributes' => array(
                 'title' => t('Create new document'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );

      $items[] = t(' - AND / OR - ');
      $items[] = l(t('Add existing document to block queue'), 'admin/content/nodequeue/1/view',
            array(
              'attributes' => array(
              'title' => t('Add existing document to block queue'),
              'class' => 'empty-block-action',),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
          );
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/319');
    }

    if ($vars['name'] == 'queues' && $vars['display_id'] == 'block_2' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new document'), 'node/add',
                  array(
                 'attributes' => array(
                 'title' => t('Create new document'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );

      $items[] = t(' - AND / OR - ');
      $items[] = l(t('Add existing document to block queue'), 'admin/content/nodequeue/6/view',
            array(
              'attributes' => array(
              'title' => t('Add existing document to block queue'),
              'class' => 'empty-block-action',),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
          );


      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/320');
    }

    if ($vars['name'] == 'queues' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new document'), 'node/add',
                  array(
                 'attributes' => array(
                 'title' => t('Create new document'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );
      $items[] = t(' - AND / OR - ');
      $items[] = l(t('Add existing document to block queue'), 'admin/content/nodequeue/2/view',
            array(
              'attributes' => array(
              'title' => t('Add existing document to block queue'),
              'class' => 'empty-block-action',),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
          );
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/321');
    }

    if ($vars['name'] == 'new_products' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new document'), 'node/add/product',
                  array(
                 'attributes' => array(
                 'title' => t('Create new document'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/322');
    }

    if ($vars['name'] == 'top_content' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = t('You or someone else has to rate any product') . '<br />';
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/323');
    }

    if ($vars['name'] == 'uc_products' && $vars['display_id'] == 'block_2' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = t('You or someone else has to order a product in this shop') . '<br />';
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/324');
    }

    if ($vars['name'] == 'uc_products' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = t('You or someone else has to write a comment to any product') . '<br />';
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/325');
    }

    if ($vars['name'] == 'news' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new document'), 'node/add',
                  array(
                 'attributes' => array(
                 'title' => t('Create new document'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );

      $items[] = t(' - AND / OR - ');
      $items[] = l(t('Add existing document to block queue'), 'admin/content/nodequeue/7/view',
            array(
              'attributes' => array(
              'title' => t('Add existing document to block queue'),
              'class' => 'empty-block-action',),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
          );
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/326');
    }

    if ($vars['name'] == 'discounts' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = t('Set list price of the product greater than its sell price') . '<br />';
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/327');
    }

    if ($vars['name'] == 'poll' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = l(t('Create new poll'), 'node/add/poll',
                  array(
                 'attributes' => array(
                 'title' => t('Create new poll'),
                 'class' => 'empty-block-action',),
                 'query' => drupal_get_destination(),
                 'html' => TRUE,
                )
     );
      $items[] = t(' - AND / OR - ');
      $items[] = l(t('Add existing document to block queue'), 'admin/content/nodequeue/8/view',
            array(
              'attributes' => array(
              'title' => t('Add existing document to block queue'),
              'class' => 'empty-block-action',),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
          );
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/328');
    }
    if ($vars['name'] == 'popular_products' && $vars['display_id'] == 'block_1' && $vars['empty']) {
	  $display_id = $vars['display_id'];
	  $items[] = '<h3>' . $vars['view']->display[$display_id]->display_title . '</h3>';
	  $items[] = t('No content in this block yet') . '<br />';
      $items[] = t('To show something in this block you have to do the following:') . '<br />';
      $items[] = t('You or someone else has to order at least two similar products in this shop') . '<br />';
      $items[] = l(t('Block information can be found here'), 'http://openstore.org.ua/node/329');
    }
  }
  $vars['empty'] = '<div class="empty-inner">' . theme_item_list($items, NULL, 'ul', array('class' => 'empty-block-action')) . '</div>';
  if ($vars['more'] || $vars['feed_icon']) {
    $vars['more'] = '<div class="footer-links-wrapper">' . $vars['more'] . $vars['feed_icon'] . '</div>';
    unset($vars['feed_icon']);
  }

  // Убираем ссылки администратора для блоков видов, если включены всплывающие ссылки администрирования в теме оформления.
  if (!variable_get('views_no_hover_links', FALSE)) {
    $def_theme = variable_get('theme_default', FALSE);
    if (theme_get_setting($def_theme . '_block_editing')) {
      $display_id = explode('_', $vars['display_id']);
      $display_id = $display_id[0];
      if ($display_id == 'block') {
        unset($vars['admin_links']);
      }
    }
  }
}

/**
 * Функция препроцесса полей видов
 */
function general_preprocess_views_view_fields(&$vars) {
  if ($vars['fields']['edit_node']->content && $vars['fields']['nodequeue_links']->content) { // dont touch this statement
    $vars['fields']['edit_node']->content = $vars['fields']['edit_node']->content . $vars['fields']['nodequeue_links']->content;
    unset($vars['fields']['nodequeue_links']->content);
  }

  /**
   * На страницах  taxonomy/term/id у нас выводятся документы разного типа, в.т числе не товары.
   * В видах у нас определены поля с   ценами, которые даже при нулевом значении будут выведены,
   * так как содержат ноль и название валюты, т.е это не будет ноль.
   * Мы выделяем число из строки, сравниваем, и если это ноль, убираем поле с ценой
   */

  $price_sell = strip_tags($vars['fields']['sell_price']->content);
  $res = ereg_replace("[^0-9]", "", $price_sell); // убираем всё, кроме цифр
  if ($res == 0) {
    unset($vars['fields']['sell_price']); // если ноль, удаляем поле
  }
}