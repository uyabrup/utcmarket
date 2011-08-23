<?php


function general_preprocess(&$vars, $hook) {

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $is_product = uc_product_is_product($vars['node']);
  }

  global $base_path;
    $path_to_lib = drupal_get_path('module', 'general') . '/lib';

  $path_to_theme = drupal_get_path('theme', variable_get('theme_default', 'frontend'));
  $file_directory = file_directory_path();

  /*
   $path_arg = drupal_get_path_alias($_GET['q'], NULL); // Аргументы из алиасов страниц, которые нам могут понадобиться в будущем, аналог arg(), но для алиасов
   $alias_arg = explode('/', $path_arg);
   $alias_arg[0]; //первая часть УРЛ
   $alias_arg[1]; //вторая часть УРЛ
   $alias_arg[2]; //третья часть УРЛ и так далее...
   */

  // Переменные для шаблонов page.tpl.php
  if ($hook == 'page') {
  
     if ($vars['is_front']) {
	 
	 $vars['content_top'] = $vars['messages'] . $vars['content_top'];
	 unset($vars['messages']);
	 
	 }

    if (arg(0) == 'admin' && arg(1) == 'build' && arg(2) == 'block') {
      unset($vars['breadcrumb']);
      unset($vars['help']);
      unset($vars['title']);
    }

    if (arg(0) != 'cart') {

      $vars['show_product_cart_summary'] .= '<div class="cart-summary product-string">';
      $items = 0;
      $subtotal = 0;
	  if(function_exists('uc_cart_get_contents')) {
      foreach (uc_cart_get_contents() as $item) {
        $items += $item->qty;
        $subtotal += $item->price * $item->qty;
      }
	 }
      if ($items == 0) {
        $vars['show_product_cart_summary'] .= t('Your basket is empty');
      }
      else {
        $vars['show_product_cart_summary'] .= t('In your') . '&nbsp;<a href="' . $base_path . 'cart" title="' . t('Go to cart') . '" rel="nofollow">' . t('basket') . '</a>&nbsp;<label>' . format_plural($items, '1 basket item', '@count basket items') . '</label>&nbsp;' . t('totaling') . '&nbsp;<label>' . uc_currency_format($subtotal) . '</label>';
        $cart_filled = TRUE;

      }
      $vars['show_product_cart_summary'] .= '</div>';

    }

    // Если включено в настройках темы, показываем сетку, позволяющую выявлять кривости вёрстки
    if (variable_get('openstore_grid', NULL)) {
      $gridder_path = $base_path . $path_to_lib . '/gridder/960.gridder.js';
      $gridder_conf = "
createGridder = function() {
document.body.appendChild(
document.createElement('script')).src='$gridder_path';
}
";

      drupal_add_js($gridder_conf, 'inline');
      $vars['gridder'] = ' onload="createGridder()"';
    }

    if (arg(0) == 'cart' && arg(1) == NULL) {

      $check_empty = uc_cart_get_contents();

      if (variable_get('openstore_cart_text', FALSE) && !empty($check_empty)) {
        $vars['content'] = '<div class="cart-message">' . variable_get('openstore_cart_text', FALSE) . '</div>' . $vars['content'];
      }
    }

    if (arg(0) != 'admin') {
      drupal_add_js('
Drupal.behaviors.clicktxtBehavior = function(context) {
$(\'#ajax-search-field\').click(
function() {
if (this.value == this.defaultValue) {
this.value = \'\';
}
}
);
$(\'#ajax-search-field\').blur(
function() {
if (this.value == \'\') {
this.value = this.defaultValue;
}
}
);
};
', 'inline');

      $vars['show_search_form'] = '<div id="search-field" class="container-inline">
                                 <form action="' . $base_path . 'product" method="get"><div>
								 <input id="ajax-search-field" size="25" type="text" name="title" value="' . t('Enter search key') . '"  />
								 </div><div>';

      $vars['show_search_form'] .= '</div></form></div>';

    }

    if (arg(1) == 'reply' && is_numeric(arg(2))) {
      $node = node_load(arg(2));
      if (uc_product_is_product($node)) {
        $comment_rating_dinamic = '<div class="rating-widget dinamic product-string"><div class="rating-title">' . t('How would you rate this product?') . '</div>' . fivestar_widget_form($node) . '</div>';

        if (module_exists('contact')) {
          $comment_contact_link = t('To contact site administration please use') . '&nbsp;' . l(t('this contact form'), 'contact');
        }
        $vars['title'] = t('Your review about') . ' &#8220;' . $node->title . '&#8221;';
        $vars['content'] = '<div class="comment-warn">' . t('Please, DO NOT use the form to ask about this product! The form is intended to share your opinion about this product.') . '<br />' . $comment_contact_link . '</div>' . $comment_rating_dinamic . $vars['content'];
      }
    }

    // Ссылка входа/региcтрации для анонимов, логин и коргина - для авторизированных
	if (!in_array(arg(0), array('admin', 'user'))) {
      $items = array();
      if ($GLOBALS['user']->uid) {
        $items[] = l(t('My account'), 'user', array('attributes' => array('class' => 'admin-login', 'rel' => 'nofollow')));
        if (arg(0) != 'cart' && $vars['show_product_cart_summary'] && $cart_filled) {
          $items[] = $vars['show_product_cart_summary'];
        }
        $items[] = l(t('Log out'), 'logout', array('attributes' => array('rel' => 'nofollow')));
      }
      else {

             $items[] = l(t('Log in/Register'), 'user', array('attributes' => array('rel' => 'nofollow')));
             $items[] = $vars['show_product_cart_summary'];		     

      }
      $vars['show_login_links'] = '<div class="login-links">' . theme_item_list($items, NULL, 'ul', NULL) . '</div>';
    }

    // Индикатор шагов чекаута
    if (arg(0) == 'cart') {
      $vars['show_checkout_steps'] = '<div class="checkout-steps">';
      $vars['show_checkout_steps'] .= '<ul>';
      $vars['show_checkout_steps'] .= '<li class = "cart-step">' . t('Cart') . '</li>';
      $vars['show_checkout_steps'] .= '<li class = "checkout">' . t('Order info entry') . '</li>';
      $vars['show_checkout_steps'] .= '<li class = "checkout-review">' . t('Review') . '</li>';
      $vars['show_checkout_steps'] .= '<li class = "checkout-payment">' . t('Payment or submit order') . '</li>';
      $vars['show_checkout_steps'] .= '</ul>';
      $vars['show_checkout_steps'] .= '<br style="clear:both;" />';
      $vars['show_checkout_steps'] .= '</div>';
    }

    $store_name = variable_get('uc_store_name', FALSE);
    $store_owner = variable_get('uc_store_owner', FALSE);
    $store_email = variable_get('uc_store_email', FALSE);
    $store_phone = variable_get('uc_store_phone', FALSE);
    $store_fax = variable_get('uc_store_fax', FALSE);
    $store_city = variable_get('uc_store_city', FALSE);
    $store_street1 = variable_get('uc_store_street1', FALSE);
    $postal_code = variable_get('uc_store_postal_code', FALSE);
	if(function_exists('uc_country_get_by_id')) {
    $store_country = uc_country_get_by_id(variable_get('uc_store_country', FALSE));
	}

    if (module_exists('contact') && user_access('access site-wide contact form') && arg(0) != 'contact') {
      $contact_us = l(t('Contact us'), 'contact', array('attributes' => array('rel' => 'nofollow')));
    }

    $items = array();
    if ($store_name) {
      $items[] = t('Store name:') . ' ' . $store_name;
    }
    if ($store_owner) {
      $items[] = t('Store owner:') . ' ' . $store_owner;
    }
    if ($store_email) {
      $items[] = t('Store e-mail:') . ' ' . $store_email;
    }
    if ($store_phone) {
      $items[] = t('Store phone:') . ' ' . $store_phone;
    }
    if ($store_fax) {
      $items[] = t('Store fax:') . ' ' . $store_fax;
    }
    if ($store_city) {
      $items[] = t('Store city:') . ' ' . $store_city;
    }
    if ($store_street1) {
      $items[] = t('Store street 1:') . ' ' . $store_street1;
    }
    if ($postal_code) {
      $items[] = t('Store postal code:') . '&nbsp;' . $postal_code;
    }
    if ($contact_us) {
      $items[] = $contact_us;
    }
    $vars['show_store_contacts'] = '<div class="shop-contacts">' . theme_item_list($items, NULL, 'ul', NULL) . '</div>';
    $items = array();
    $items[] = $store_country;
    $items[] = $store_city;
    $items[] = $postal_code;
    $items[] = $store_street1;
    $items[] = '&#124;';
    $items[] = $store_phone;
    $items[] = $store_email;
    if ($contact_us) {
      $items[] = $contact_us;
    }

    // Копирайт с годами
    if (arg(0) != 'admin') {
      $vars['show_store_short_contacts'] = '<div class="shop-short-contacts">' . theme_item_list($items, NULL, 'ul', NULL) . '</div>';

      $start_year = variable_get('uc_store_start_date', 2010);
      $current_year = date('Y');
      if ($start_year < $current_year) {
        $year = $start_year . ' &#8211; ' . $current_year;
      }
      else {
        $year = $current_year;
      }
      $vars['show_copyright'] = '<div class="copyright">&copy;&nbsp;' . $year . '&nbsp;' . variable_get('uc_store_name', FALSE) . '&nbsp;' . t('All rights reserved') . '</div>';
    }

    if (arg(0) != 'admin') {
      $vars['footer'] .= '<div class="copyright" style="font-size:10px;text-align:center;">' . l(t('OpenStore - The OpenSource e-commerce solution'), 'http://openstore.org.ua') . '</div>';
    }
    if (arg(0) == 'admin') {
      $vars['footer'] .= '<div class="copyright" style="font-size:10px;text-align:center;">' . t('The Administrator theme developed specially for OpenStore e-commerce software by Iurii Makukh. If you have some questions or suggestions, please visit the <a href="http://openstore.org.ua">official site</a>') . '</div>';
      }

    if (theme('blocks', 'primary_menu')) {
      unset($vars['primary_links']);
      unset($vars['secondary_links']);
    }

    if (arg(1) == 'checkout' || (arg(1) == 'checkout' && arg(2) == 'review')) {
      unset($vars['primary_menu']);
      unset($vars['secondary_menu']);
      unset($vars['primary_links']);
      unset($vars['secondary_links']);
      unset($vars['secondary_links']);

    }

    if ((arg(0) == 'node' && is_numeric(arg(1)) && !arg(2)) || arg(0) == 'discounts') {
      unset($vars['title']);
    }


    $double_form_path = arg(0) . arg(1);

    if (($double_form_path == 'user' || $double_form_path == 'userregister' || $double_form_path == 'userlogin') && !$GLOBALS['user']->uid) {

      $vars['content'] = '<div class="register-form">
                        <h3>' .	 t('New user? Create an account here') . '</h3><div class="register-form-content">'
	                    . drupal_get_form('user_register') . '</div></div>';
      $vars['content'] .= '<div class="login-form">
                        <h3>' .	 t('Have you already registered an account? Log in here') . '</h3><div class="login-form-content">'	
	                    . drupal_get_form('user_login') . '</div></div>';
      unset($vars['tabs']);


      drupal_add_js('Drupal.behaviors.openidtoggleBehavior = function(context) { // Добавляем свой переключатель для OpenId

	 $("div.openid-button").click(function () {
     $(".login-form .form-item").toggle();
     });
	 };', 'inline');

    }

    if (arg(0) == 'user' && arg(1) == 'password' && !$GLOBALS['user']->uid) {
      unset($vars['tabs']);
    }



    if (arg(0) == 'user' && is_numeric(arg(1)) && !arg(2)) {
      $vars['title'] = t('Profile of ');
      drupal_add_js($path_to_lib . '/cookie/jquery.cookie.js', 'theme', 'header', FALSE, TRUE, FALSE);
      drupal_add_js($path_to_lib . '/collapse/jquery.collapse.js', 'theme', 'header', FALSE, TRUE, FALSE);
      drupal_add_js('Drupal.behaviors.profilecollapseBehavior = function(context) {$("#profile-blocks").collapse({open : true, head : "h3", group : "div", cookie : "profilecollapse"});};', 'inline');
    }

    if (arg(0) == 'user' && !$GLOBALS['user']->uid) {
      unset($vars['title']);
    }


    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'edit') {
      $vars['title'] = t('Edit profile');
    }

    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'addresses') {
      $vars['title'] = t('My address book');
    }

    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'openid') {
      $vars['title'] = t('My OpenId accounts');
    }

    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'edit' && arg(3) == 'newsletter') {
      $vars['title'] = t('Edit newsletters');
    }

    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'purchased-files') {
      $vars['title'] = t('My purchased files');
    }

    if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'contact') {
      $vars['title'] = t('My contact form');
    }

    if ($vars['is_front']) {
      unset($vars['content']);
    }


    if (arg(0) == 'user' && arg(1) == $GLOBALS['user']->uid && arg(2) == 'addresses' && !arg(3)) {
      $vars['content'] = '<div class="addresses-help">' . t('Profile addresses help text') . '</div>' . $vars['content'];
    }

    if (arg(0) == 'node' && is_numeric(arg(1)) && !empty($vars['tabs'])) {

      $vars['admin_tabs'] .= '<div id="toppanel"><div id="panel">';
      $vars['admin_tabs'] .= $vars['tabs'];
      $vars['admin_tabs'] .= '</div>';
      $vars['admin_tabs'] .= '<div id="toppanel-head"><div id="header-title" class="clearfix"><ul id="toggle"><li><a id="open" class="open" href="#"><span class="panel-open">' . t('Open toolbar to edit') . '</span></a>
<a id="close" style="display: none;" class="close" href="#"><span class="panel-close">' . t('Close settings toolbar') . '</span></a></li></ul>';
      $vars['admin_tabs'] .= '</div></div></div>';
      unset($vars['tabs']);
      drupal_add_js($path_to_lib . '/slide/slide.js', 'theme', 'header', FALSE, TRUE, FALSE);
    }

    if ($vars['help'] == "<div class=\"help\"><p></p>\n</div>") {
      $vars['help'] = '';
    }

    drupal_add_js('Drupal.behaviors.checkjsBehavior = function(context) {$(\'body\').removeClass(\'nojs\').addClass(\'withjs\');};', 'inline');


    // Формируем массив классов для тега <body>
    $body_classes = array($vars['body_classes']);

    if ($vars['site_slogan']) {
      $body_classes[] = 'slogan';
    }

    $body_classes[] = 'nojs';

    if (arg(0) == 'cart' && !arg(1)) {
      $body_classes[] = 'cart-page';
    }


    if (arg(0) != 'admin') {
      $block_region = 'wide_blocks';
      $in_region = block_list($block_region);
      $big_bl = $in_region['views_queues-block_3']->delta;
      $small_bl = $in_region['views_queues-block_2']->delta;
      if ($big_bl && !$small_bl) {
        $body_classes[] = 'wide-block-1';
      }
      if (!$big_bl && $small_bl) {
        $body_classes[] = 'wide-block-2';
      }
      if ($big_bl && $small_bl) {
        $body_classes[] = 'two-wide-blocks';
      }
    }


    if (user_access('administer blocks')) {
      $body_classes[] = 'admin';
    }

    if ($vars['primary_links'] || $vars['secondary_links']) {
      $body_classes[] = 'with-navigation';
    }


    if (!$vars['primary_links'] && !$vars['secondary_links'] && theme('blocks', 'primary_menu')) {
      $body_classes[] = 'with-navigation-block';
    }


    if (!empty($vars['secondary_links'])) {
      $body_classes[] = 'with-secondary';
    }

    $body_classes[] = ($vars['language']->language) ? '' . $vars['language']->language : '';

    if (arg(0) && arg(1) && is_numeric(arg(2))) {
      $body_classes[] = 'path-' . arg(0) . '-' . arg(1);
    }

    if (!$vars['is_front']) {

      $path = drupal_get_path_alias($_GET['q']);
      list($section) = explode('/', $path, 2);
      $body_classes[] = general_id_safe('page-' . $path);
      $body_classes[] = general_id_safe('section-' . $section);

      if (arg(0) == 'node') {
        if (arg(1) == 'add') {
          if ($section == 'node') {
            array_pop($body_classes);
          }
          $body_classes[] = 'section-node-add';
        }
        elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
          if ($section == 'node') {
            array_pop($body_classes);
          }
          $body_classes[] = 'section-node-' . arg(2);
        }
      }
    }


    $vars['body_classes'] = implode(' ', $body_classes);


    // Добавляем для удобства дополнительные варианты шаблона page.tpl.php для страниц в виде page-type-ТИПДОКУМЕНТА.tpl.php или page-node-IDдокумента.tpl.php
    if ($vars['node']->type != "") {
      $vars['template_files'][] = "page-type-" . $vars['node']->type;
    }
    if ($vars['node']->nid != "") {
      $vars['template_files'][] = "page-node-" . $vars['node']->nid;
    }

    if ($is_product && arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == NULL) {
      unset($vars['title']);
    }

    // Переменная, которая выводит надпись об отключённом в браузере пользователя JavaScript.
    $vars['noscript_warning'] = '<noscript><div id="noscript-warning">' . t('The site works better if <a href="http://google.com/support/websearch/bin/answer.py?hl=ru&amp;answer=23852" target="_blank" rel="nofollow">JavaScript enabled</a>') . '</div></noscript>';

  } // Конец препроцесса для шаблона страницы

  
  // Препроцесс для node.tpl.php
  if ($hook == 'node') {

    $node = node_build_content(node_load($vars['nid']));

    if (theme('blocks', 'left') && $is_product) { // Если есть блок в левом сайдбаре, то	
      $vars['template_files'][] = 'node-product-left'; // подключаем шаблон node-product-left.tpl.php	
    }
    if (theme('blocks', 'right') && $is_product) { // Если есть блок в правом сайдбаре, то
      $vars['template_files'][] = 'node-product-right'; // подключаем шаблон node-product-right.tpl.php	
    }
    if (theme('blocks', 'right') && theme('blocks', 'left') && $is_product) { // Если есть блок в правом и левом сайдбаре, то
      $vars['template_files'][] = 'node-product-left-right'; // подключаем шаблон node-product-left-right.tpl.php
    }

    if (module_exists('service_links')) {
      if (user_access('access service links') && (!empty($node->service_links) || $node->type == 'product_kit')) {
        $service_links = service_links_render($node, TRUE);
        $vars['show_share_widget'] = '<div class="share-widget">' . theme('links', $service_links) . '</div>';
        $vars['show_share_widget_text'] = '<div class="share-widget"><label>' . t('Add to your bookmarks') . '</label>' . theme('links', $service_links) . '</div>';
      }
    }
	
      $vars['show_title'] = '<h2 class="title">' . $node->title . '</h2>';
      $vars['node_creator'] = '<span class="node-creator">' . t('Submitted by ') . theme('username', $node) . '</span>';
      $vars['node_created_date'] = '<span class="node-created-date">' . t('Created on ') . format_date($node->created, 'custom', "d/m/Y") . '</span>'; // Время создания документа в формате "день/месяц/год". Используется стандартный PHP формат времени для функции date()	
      unset($vars['node_creator']);
      unset($vars['submitted']);


      if (user_access('edit own banner content') || user_access('edit own page content') || user_access('edit own simplenews content') || user_access('edit own products') || user_access('edit own product kits')) {
        if ($vars['node']->status) {
          $vars['show_document_status'] = '<div class="document-status document-published">' . t('This document is published') . ' ' . l(t('Unpublish document'), 'node/' . $vars['node']->nid . '/edit', array('fragment' => 'options-form', 'attributes' => array('class' => 'document-status-link'), 'query' => drupal_get_destination(), 'html' => TRUE)) . '</div>';
        }
        else {
          $vars['show_document_status'] = '<div class="document-status document-unpublished">' . t('This document is unpublished') . ' ' . l(t('Publish document'), 'node/' . $vars['node']->nid . '/edit', array('fragment' => 'options-form', 'attributes' => array('class' => 'document-status-link'), 'query' => drupal_get_destination(), 'html' => TRUE)) . '</div>';
        }
      }

      if ($node->type == 'page' || $node->type == 'banner' || $node->type == 'poll' || $node->type == 'simplenews' || $node->type == 'product_kit') {

        //Термины словаря "Главная категория"
        $terms_from_1 = vocab_terms($node, 1);
        if (!empty($terms_from_1)) {
          $term_links = array();
          foreach ($terms_from_1 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
          }
          $vars['show_terms_catalog'] = '<div class="vocab-terms catalog-terms string">' . theme_item_list($term_links, t('Catalog category:'), 'ul', array('class' => 'catalog-terms')) . '</div>';
        }
        
        //Термины словаря "Производители"
        $terms_from_3 = vocab_terms($node, 3);
        if (!empty($terms_from_3)) {
          $term_links = array();
          foreach ($terms_from_3 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
          }
          $vars['show_terms_trademark'] = '<div class="vocab-terms trademark-terms string">' . theme_item_list($term_links, t('Manufacturer:'), 'ul', array('class' => 'trademark-terms')) . '</div>';
        }

        //Термины словаря "Общие категории"
        $terms_from_4 = vocab_terms($node, 4);
        if (!empty($terms_from_4)) {
          $term_links = array();
          foreach ($terms_from_4 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
          }
          $vars['show_terms_common'] = '<div class="vocab-terms common-terms string">' . theme_item_list($term_links, t('Categories:'), 'ul', array('class' => 'categories-terms')) . '</div>';
        }

        //Термины словаря "Теги"
        $terms_from_5 = vocab_terms($node, 5);
        if (!empty($terms_from_5)) {
          $term_links = array();
          foreach ($terms_from_5 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
          }
          $vars['show_terms_tags'] = '<div class="vocab-terms tags-terms string">' . theme_item_list($term_links, t('Tags:'), 'ul', array('class' => 'tags-terms')) . '</div>';
        }

        //Термины словаря "Акции"
        $terms_from_6 = vocab_terms($node, 6);
        if (!empty($terms_from_6)) {
          $term_links = array();
          foreach ($terms_from_6 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
          }
          $vars['show_terms_promo'] = '<div class="vocab-terms promo-terms string">' . theme_item_list($term_links, t('Promo:'), 'ul', array('class' => 'promo-terms')) . '</div>';
        }

        if (module_exists('comment') && user_access('post comments') && $node->comment == COMMENT_NODE_READ_WRITE) {
          if ($comment_count > 0) {
            $vars['show_comment_link'] = '<div class="add-comment string">' . l(t('Add comment') . ' (' . $comment_count . ')', 'comment/reply/' . $node->nid) . '</div>';
          }
          else {
            $vars['show_comment_link'] = '<div class="add-comment string">' . l(t('Add comment'), 'comment/reply/' . $node->nid) . '</div>';
          }
        }
        $vars['show_description'] = '<div class="page-desc page-block">' . $node->content['body']['#value'] . '</div>';

      }

      if ($node->type == 'page' || $node->type == 'banner') { // Переменные для шаблона с типом документа "page"
        $vars['show_banner'] = '<div class="image-banner page-block">' . $vars['node']->field_banner[0]['view'] . '</div>';
      }


      // Препроцесс для документов, которые являются классами товара
      if ($is_product) {

        if ($node->type == 'product_kit') {

          $product_kit_preset = imagecache_preset(variable_get('openstore_kit_preset', 11));
          $product_kit_preset = $product_kit_preset['presetname'];

          $product_kit_main_preset_id = variable_get('openstore_kit_main_preset', 13);
          $product_kit_main_preset = imagecache_preset($product_kit_main_preset_id);
          $product_kit_main_preset = $product_kit_main_preset['presetname'];

          $product_kit_items = array();
          $product_kit_price = array();
          $product_kit_discount = array();
          $count_item = 0;
          foreach ($node->products as $product) {
            $count_item++;
            $product_kit_filepath = $product->field_image_cache[0]['filepath'];
            $product_kit_price[] = $product->sell_price;
            $product_kit_discount[] = $product->discount;
            $product_kit_items[] = '<div class="item-' . $count_item . ' item-container">' .
	                       '<div class="product-kit-title">' . l($product->title, 'node/' . $product->nid) . '</div>' .
	                       '<div class="product-kit-image">' . theme('imagecache', $product_kit_preset, $product_kit_filepath, $product->title, $product->title, FALSE) . '</div>' .	
	                       '<div class="product-kit-model">' . t('Product SKU:') . ' ' . $product->model . '</div>' .
						   '<div class="product-kit-price">' . t('Usual price:') . ' ' . uc_currency_format($product->sell_price) . '</div>' .
						   '<div class="product-kit-discount">' . t('Product kit discount:') . ' ' . uc_currency_format(abs($product->discount)) . '</div>' .
						   '</div>';

          }

          if (!empty($product_kit_items)) {

            $column_count = variable_get('openstore_kit_column', 2); // количество колонок по умолчанию на странице полного вида product_kit
            $rows = array_chunk($product_kit_items, $column_count);

            $vars['show_kit_items'] = '<div class="product-kit-items">' . theme_table(NULL, $rows, NULL, NULL) . '</div>';
            $amount_items = count($product_kit_items);
            $vars['show_kit_amount_regular'] = '<div class="amount-regular-price">' . t('Product regular amount:') . ' ' . uc_currency_format(array_sum($product_kit_price)) . '</div>';
            $vars['show_kit_amount_discount'] = '<div class="amount-discount-price">' . t('Kit discount amount:') . ' ' . uc_currency_format(abs(array_sum($product_kit_discount))) . '</div>';
            $vars['show_kit_amount_discounted'] = '<div class="amount-discounted-price">' . uc_currency_format($vars['node']->sell_price) . '</div>';

            $vars['show_kit_text'] = '<div class="kit-text product-string">' . t('Buying these products separately you would pay') . ' ' . uc_currency_format(array_sum($product_kit_price)) . '. ' . t('You will save') . ' ' . uc_currency_format(abs(array_sum($product_kit_discount))) . ' ' . t('by buying these') . ' ' . format_plural($amount_items, '1 product kit item', '@count product kit items') . ' ' . t('_together') . '</div>';
          }

          $kit_main_image_filepath = $node->field_banner[0]['filepath'];
          if ($node->field_banner[0]['data']['alt']) {
            $kit_main_image_alt = $node->field_image_cache[0]['data']['alt'];
          }
          else {
            $kit_main_image_alt = $node->title;
          }
          if ($node->field_banner[0]['data']['title']) {
            $kit_main_image_title = $node->field_image_cache[0]['data']['title'];
          }
          else {
            $kit_main_image_title = $node->title;
          }

          if ($product_kit_main_preset_id == 0) {
            $vars['show_kit_main_image'] = '<div class="product-kit-main-image product-block">' . theme_image($kit_main_image_filepath, $kit_main_image_alt, $kit_main_image_title) . '</div>';
          }
          else {
            $vars['show_kit_main_image'] = '<div class="product-kit-main-image product-block">' . theme('imagecache', $product_kit_main_preset, $kit_main_image_filepath, $kit_main_image_alt, $kit_main_image_title, FALSE) . '</div>';
          }
        }

        if (!empty($node->attributes)) {
          $vars['show_cart_button'] = '<div class="add-to-cart-form product-block">' . drupal_render($node->content['add_to_cart']) . '</div>';
        }
        else {
          $vars['show_cart_button'] = '<div class="add-to-cart-button product-string">' . drupal_render($node->content['add_to_cart']) . '</div>';
        }

        if (module_exists('flag')) {
          $vars['show_bookmark_link'] = '<div id="bookmark">' . flag_create_link('bookmarks', $node->nid) . '</div>';
        }

        // Список доступных способов доставки
        if ($node->shippable) {
          $shipping_items = array();
          $ship_enabl = variable_get('uc_quote_enabled', FALSE);
          
          $ship_label = db_query('SELECT label FROM {uc_flatrate_methods}'); // выбираем дополнительным запросом к БД
          
		 $rows_enabl = array();
          while ($row = db_fetch_array($ship_label)) {
            $rows_enabl[] = $row['label'];
          }		  
		  if (!empty($rows_enabl)) {		  		  
		  $vars['show_shipping_methods'] = '<div class="shipping-methods product-block">';          
          reset($rows_enabl);
          foreach ($rows_enabl as $value) {
            if (current($ship_enabl)) {
              $shipping_items[] = $value;
            }
            next($ship_enabl);
          }
          $vars['show_shipping_methods'] .= theme_item_list($shipping_items, t('The product can be delivered via'), $type = 'ul', $attributes = array('class' => 'shipping-methods'));
          $vars['show_shipping_methods'] .= l(t('More about shipping'), 'node/4', array('attributes' => array('rel' => 'nofollow')));
          $vars['show_shipping_methods'] .= '</div>';
        }
		
		}
        else {
          $vars['show_shipping_methods'] = '<div class="shipping-methods product-string">' . t('This product is not shippable!') . '</div>';
        }

        // Список доступных способов оплаты	
        $vars['show_payment_methods'] = '<div class="payment-methods product-block">';
        $arr_payment_list = _payment_method_list();
        $payment_items = array();
        foreach ($arr_payment_list as $row) {
          if ($row['checkout']) {
            $show_product_pm = TRUE;
            $moneybooker = explode('_', $row['id']);
            if ($moneybooker[0] == 'moneybookers') {
              if (!empty($moneybooker[1]) && $moneybooker[1] != 'cc') { // Показывем только основные способы оплаты из многих в Moneybookers
                unset($row['name']);
              }
            }
            if ($row['name']) {
              $payment_items[] = strip_tags($row['name']);
            }
          }
        }
        $vars['show_payment_methods'] .= theme_item_list($payment_items, t('We accept the following payment methods:'), $type = 'ul', $attributes = array('class' => 'payment-methods'));
        $vars['show_payment_methods'] .= l(t('More about payment'), 'node/3', array('attributes' => array('rel' => 'nofollow')));
        if (!$show_product_pm) {
          unset($vars['show_payment_methods']);
        }
        $vars['show_payment_methods'] .= '</div>';

        // Термины словаря "Каталог товаров"	
        $terms_from_1 = vocab_terms($node, 1);
        if (!empty($terms_from_1)) {
          $term_links = array();
          $term_id = array();
          $term_name = array();
          foreach ($terms_from_1 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
            $term_id[] = $term->tid;
            $term_name[] = $term->name;
          }
          
          $vars['show_terms_catalog'] = '<div class="vocab-terms catalog-terms product-string">' . theme_item_list($term_links, t('Category:'), 'ul', array('class' => 'catalog-terms')) . '</div>';
 
          if (count($term_id) > 1) {
            $term_path = implode(',', $term_id);
            $term_names = implode(',', $term_name);
            $path_xls = 'export-xls/' . $term_path;
            $path_doc = 'export-doc/' . $term_path;

          }
          else {
            $path_xls = 'export-xls/' . $term_id[0];
            $path_doc = 'export-doc/' . $term_id[0];
            $term_names = $term_name[0];
          }
          $vars['show_download_xls_catalog'] = '<div class="download-link download-xls">' . l(t('Download .XLS price for') . ' ' . $term_names, $path_xls, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .XLS price for all similar products')))) . '</div>';
          $vars['show_download_doc_catalog'] = '<div class="download-link download-doc">' . l(t('Download .DOC price for') . ' ' . $term_names, $path_doc, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .DOC price for all similar products')))) . '</div>';
        }

        // Термины словаря "Производители"
        $terms_from_3 = vocab_terms($node, 3);
        if (!empty($terms_from_3)) {
          $term_links = array();
          $term_id = array();
          $term_name = array();
          foreach ($terms_from_3 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
            $term_id[] = $term->tid;
            $term_name[] = $term->name;
          }

          $vars['show_terms_trademark'] = '<div class="vocab-terms trademark-terms product-string">' . theme_item_list($term_links, t('Manufacturer:'), 'ul', array('class' => 'trademark-terms')) . '</div>';

          if (count($term_id) > 1) {
            $term_path = implode(',', $term_id);
            $term_names = implode(',', $term_name);
            $path_xls = 'export-xls/' . $term_path;
            $path_doc = 'export-doc/' . $term_path;

          }
          else {
            $path_xls = 'export-xls/' . $term_id[0];
            $path_doc = 'export-doc/' . $term_id[0];
            $term_names = $term_name[0];
          }
          $vars['show_download_xls_trademark'] = '<div class="download-link download-xls">' . l(t('Download .XLS price for') . ' ' . $term_names, $path_xls, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .XLS price for all similar products')))) . '</div>';
          $vars['show_download_doc_trademark'] = '<div class="download-link download-doc">' . l(t('Download .DOC price for') . ' ' . $term_names, $path_doc, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .DOC price for all similar products')))) . '</div>';
        }

        //Термины словаря "Теги"
        $terms_from_5 = vocab_terms($node, 5);
        if (!empty($terms_from_5)) {
          $term_links = array();
          $term_id = array();
          $term_name = array();
          foreach ($terms_from_5 as $term) {
            $term_links[] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('rel' => 'tag', 'title' => $term->name)));
            $term_id[] = $term->tid;
            $term_name[] = $term->name;
          }

          $vars['show_terms_tags'] = '<div class="vocab-terms tags-terms product-string">' . theme_item_list($term_links, t('Tags:'), 'ul', array('class' => 'tags-terms')) . '</div>';

          if (count($term_id) > 1) {
            $term_path = implode(',', $term_id);
            $term_names = implode(',', $term_name);
            $path_xls = 'export-xls/' . $term_path;
            $path_doc = 'export-doc/' . $term_path;

          }
          else {
            $path_xls = 'export-xls/' . $term_id[0];
            $path_doc = 'export-doc/' . $term_id[0];
            $term_names = $term_name[0];
          }
          $vars['show_download_xls_tags'] = '<div class="download-link download-xls">' . l(t('Download .XLS price for') . ' ' . $term_names, $path_xls, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .XLS price for all similar products')))) . '</div>';
          $vars['show_download_doc_tags'] = '<div class="download-link download-doc">' . l(t('Download .DOC price for') . ' ' . $term_names, $path_doc, array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .DOC price for all similar products')))) . '</div>';
        }


        $vars['comments'] = '';
        if (function_exists('comment_render') && !empty($vars['node']) && $vars['node']->comment) {
          $arg2 = arg(2);
          $vars['show_product_custom_comments'] = comment_render($vars['node'], ($arg2 && is_numeric($arg2) ? $arg2 : NULL));
        }
        unset($vars['node']->comment); // Убираем стандартную форму комментариев, так как мы определили свою.


        // Мы определяем дополнительные (прозапас) регионы прямо в теле шаблона документа. Имейте ввиду, чтобы переменные регионов, определённые здесь были доступны на странице управления блока, вы должны их указать в .info темы
        if (theme('blocks', 'product_right_region')) {
          $vars['show_product_right_region'] = theme('blocks', 'product_right_region'); // первый регион
        }

        if (theme('blocks', 'product_left_region')) {
          $vars['show_product_left_region'] = theme('blocks', 'product_left_region'); // второй регион
        }

        if (theme('blocks', 'product_collapsible')) {
          $vars['product_collapsible'] = theme('blocks', 'product_collapsible'); // третий регион
        }


        $vars['show_product_simple_image_block'] = '<div class="image-block product-block">' . drupal_render($node->content['image']) . '</div>';
        $vars['show_product_description'] = '<div class="product-desc product-block">' . $node->content['body']['#value'] . '</div>';
        $vars['show_product_price_cost'] = drupal_render($node->content['cost']);
        $vars['show_product_weight'] = (!empty($node->weight)) ? drupal_render($node->content['weight']) : '';
        if ($vars['show_product_weight'] == '') {
          unset($node->content['weight']);
        }
        $dimensions = !empty($node->height) && !empty($node->width) && !empty($node->length);
        $vars['show_product_dimensions'] = ($dimensions) ? drupal_render($node->content['dimensions']) : '';
        if ($vars['show_product_dimensions'] == '') {
          unset($node->content['dimensions']);
        }
        $list_price = !empty($node->list_price) && $node->list_price > 0;
        $vars['show_product_price_list'] = ($list_price) ? drupal_render($node->content['list_price']) : '';
        if ($vars['show_product_price_list'] == '') {
          unset($node->content['list_price']);
        }


        // Текст гарантийных обязательств	 	
        if ($vars['field_warranty'][0]['value'] || $vars['field_warranty_add'][0]['value']) {
          $items = array();
          $vars['show_product_warranty'] = '<div class="product-warranty product-block">';
          if ($vars['field_warranty'][0]['value']) {
            $items[] = $vars['field_warranty'][0]['value'] . t(' official manufacturers warranty');
          }
          if ($vars['field_warranty_add'][0]['value']) {
            $items[] = $vars['field_warranty_add'][0]['value'];
          }
          $vars['show_product_warranty'] .= theme_item_list($items, t('Our warranty:'), $type = 'ul', $attributes = array('class' => 'product-warranty'));
          $vars['show_product_warranty'] .= l(t('More about warranty'), 'node/2', array('attributes' => array('rel' => 'nofollow')));
          $vars['show_product_warranty'] .= '</div>';
        }

        if (module_exists('fivestar') && user_access('rate content')) {
          $vars['show_product_fivestar_widget_dinamic'] = '<div class="rating-widget dinamic product-string"><label>' . t('Rate this product') . '</label>' . fivestar_widget_form($node) . '</div>';
        }

        if (module_exists('fivestar')) {
          $votingapi_rating = votingapi_select_results(array('content_id' => $node->nid, 'function' => 'average'));
          $current_product_rating = $votingapi_rating[0]['value'];
          if ($current_product_rating != NULL) {
            $vars['show_product_fivestar_widget_static'] = '<div class="rating-widget static product-string">' . fivestar_static('node', $nid) . '</div>';
          }
        }


        if (isset($node->files) && user_access('view uploaded files')) {
          $vars['show_product_files'] = '<div class="product-files product-block">' . theme('upload_attachments', $node->files) . '</div>';
        }
        $vars['show_product_breadcrumb'] = theme('breadcrumb', drupal_get_breadcrumb());

        if (!empty($node->field_media[0]['value'])) {
          $vars['show_product_media'] = '<div class="product-media product-block">' . $vars['field_media'][0]['value'] . '</div>';
        }

        $vars['show_product_notes'] .= '<div class="product-notices">';
        $vars['show_product_notes'] .= t('*Specifications and packaging of the product can be changed without notice');
        if (!empty($node->field_notes[0]['value'])) {
          $vars['show_product_notes'] .= $vars['field_notes'][0]['value'];
        }
        $vars['show_product_notes'] .= '</div>';



        if (!empty($node->field_specs[0]['value'])) {
          $vars['show_product_specs'] = '<div class="product-specs product-block">' . $vars['field_specs'][0]['value'] . '</div>';
        }

        $vars['show_product_sku'] = '<div class="product-page-sku product-string"><span class="sku-label">' . t('Product SKU:') . '</span>&nbsp;<span   class="sku-value">' . $node->model . '</span></div>';

        if (module_exists('userpoints') && userpoints_get_current_points($account->uid)) {
          $vars['show_product_userpoints'] = '<div class="userpoints-txt-value product-string">' . t('Your current points:') . '&nbsp;' . userpoints_get_current_points($account->uid) . '</div>';
          $vars['show_product_userpoints_value'] = '<span class="userpoints-value">' . userpoints_get_current_points($account->uid) . '</span>';
        }

        if (module_exists('uc_stock')) {
          $active_state = db_result(db_query("SELECT active FROM {uc_product_stock} WHERE sku = '%s'", $node->model));
          if (!$active_state) {
            $vars['show_product_state_text'] = '<div class="product-state-text out-of-stock-text product-block">' . t('This product is sold under the order. It means that we check availability of the product after you place an order for this product. We can not guarantee 100% availability of the product') . '</div>';
          }
          else {
            $vars['show_product_state_text'] = '<div class="product-state-text in-stock-text product-string">' . t('This product in stock') . '</div>';
          }
        }
        if (module_exists('advcontact') && user_access('access site-wide contact form')) {
          $vars['show_product_contact_bargain'] = '<div class="contact-link-bargain product-string"><a rel ="nofollow" href="' . $base_path . 'contact&amp;category=' . t('Contact category - bargain') . '&amp;subject=' . $node->title . '&amp;message=' . t('Contact message - bargain') . '">' . t('I know where is cheaper!') . '</a></div>';

          $vars['show_product_contact_error'] = '<div class="contact-link-error product-string"><a rel ="nofollow" href="' . $base_path . 'contact&amp;category=' . t('Contact category - error') . '&amp;subject=' . t('Wrong description') . '&amp;message=' . t('Contact message - error') . 'www.' . $_SERVER['SERVER_NAME'] . $_SERVER['REQUEST_URI'] . t('Contact message - error2') . '">' . t('The description contains errors!') . '</a></div>';


          $vars['show_product_contact_common'] = '<div class="contact-link-common product-string"><a rel ="nofollow" href="' . $base_path . 'contact&amp;category=' . t('Contact category - common') . '&amp;subject=' . $node->title . '&amp;message=' . t('Contact message - common') . '">' . t('Contact general questions') . '</a></div>';
          $vars['show_product_contact_partnership'] = '<div class="contact-link-partnership product-string"><a rel ="nofollow" href="' . $base_path . 'contact&amp;category=' . t('Contact category - partnership') . '&amp;subject=' . $node->title . '&amp;message=' . t('Contact message - partnership') . '">' . t('Contact partnership questions') . '</a></div>';
          $vars['show_product_contact_product'] = '<div class="contact-link-product product-string"><a rel ="nofollow" href="' . $base_path . 'contact&amp;category=' . t('Contact category - product') . '&amp;subject=' . $node->title . '&amp;message=' . t('Contact message - product') . '">' . t('Contact product questions') . '</a></div>';
        }

        if ($node->list_price != 0) {
          $pr_list_value = $node->list_price;
        }
        $pr_sell_value = $node->sell_price;
        if ($pr_sell_value < $pr_list_value) {
          $discount = $pr_list_value - $pr_sell_value;
          $vars['discount_percent'] = '<div class="discount-percent product-string">' . round(($discount / $pr_list_value) * 100, 0) . '%</div>';

          $vars['show_product_price_sell'] = '<div class="pricesell product-string">' . t('Our price') . '&nbsp;<span class="price-value">' . uc_currency_format($pr_sell_value) . '</span></div>';
          $vars['show_product_price_discount'] = '<div class="discount product-string">&nbsp;(' . t('You save') . '&nbsp;<span class="discount-value">' . uc_currency_format($discount ) . '</span>)</div>';

          $pr_sell_value_uc = $pr_sell_value;
          $vars['show_product_price_full'] = '<div class="price-full product-block"><span class="price-value">' . uc_currency_format(round($pr_sell_value_uc)) . '</span></div>
<div class="discount">

' . t('Old price was') . '&nbsp;<span class="old-price">' . uc_currency_format($pr_list_value) . '</span><br />

' . t('You save') . '&nbsp;<span class="discount-value">' . uc_currency_format($discount ) . '</span></div>';


        }
        else {
          $vars['show_product_price_sell'] = '<div class="pricesell product-string">' . t('Our price') . '&nbsp;<span class="price-value">' . uc_currency_format(round($pr_sell_value_uc)) . '</span></div>';
          $vars['show_product_price_full'] = '<div class="price-full product-block"><span class="price-value">' . uc_currency_format($pr_sell_value) . '</span></div>';

        }

        $vars['show_product_list_value'] = $pr_list_value;
        $vars['show_product_sell_value'] = $pr_sell_value;

        // Изображения товара
        $width_zoom_on = variable_get('uc_big_zoom_width', 1000);
        $height_zoom_on = variable_get('uc_big_zoom_height', 1000);
        $scroll_on = variable_get('uc_images_scroll_threshold', 3);

        $preset_thumb_id = variable_get('uc_small_image_preset', 2);
        $preset_thumb_image = imagecache_preset($preset_thumb_id);
        $preset_thumb_image = $preset_thumb_image['presetname'];


        $left = theme('blocks', 'left');
        $right = theme('blocks', 'right');
        $id_preset = variable_get('uc_product_image_adjust', FALSE);

        if ($left && $right) { // Уточнение размера картинки товара (пресета) в зависимости от наличия боковых блоков
          $preset_product_id = variable_get('uc_product_image_preset', 1);
        }
        else {
          if ($id_preset) {
            $preset_product_id = variable_get('uc_product_image_adjust', 10);
			$PRODUCT_IMAGE_ADJUSTED = TRUE;			
          }
          else {
            $preset_product_id = variable_get('uc_product_image_preset', 1);
          }
        }
		
		if($PRODUCT_IMAGE_ADJUSTED) {
		$image_ajusted_class = ' image-ajusted';
		} else {
		$image_ajusted_class = ' image-not-ajusted';
		}

        $preset_product_image = imagecache_preset($preset_product_id);
        $preset_product_image = $preset_product_image['presetname'];

        $preset_big_id = variable_get('uc_big_image_preset', 3);
        $preset_big_image = imagecache_preset($preset_big_id);
        $preset_big_image = $preset_big_image['presetname'];


        $plugin = variable_get('uc_image_display_plugin', 'slimbox');
        $zoom_type = variable_get('uc_zoom_plugin', 'jqzoom');

        if ($plugin == 'fancybox') {
          drupal_add_css($path_to_lib . '/fancybox/fancybox.css');
          drupal_add_js($path_to_lib . '/mousewheel/mousewheel.js');
          drupal_add_js($path_to_lib . '/fancybox/fancybox.js');
          drupal_add_js($path_to_theme . '/js/fancybox.config.js');
        }

        if ($plugin == 'slimbox') {
          drupal_add_css($path_to_lib . '/slimbox/slimbox.css');
          drupal_add_js($path_to_lib . '/slimbox/slimbox.js');
        }

        $img_items = array();
        $index = 0;
        foreach ($node->field_image_cache as $image) {
          $index++;
		  if (!empty($image)) {
		  $PRODUCT_IMAGE_SET = TRUE;
		  }
          $filepath = $image['filepath'];
          $filename = $image['filename'];
          if ($image['data']['alt']) {
            $alt = $image['data']['alt'];
          }
          else {
            $alt = $node->title;
          }
          if ($image['data']['title']) {
            $title = $image['data']['title'];
          }
          else {
            $title = $node->title;
          }

          if ($index == 1) {
            $zoom_href = $base_path . $filepath;
            $big_image = theme('imagecache', $preset_product_image, $filepath, $alt, $title, FALSE);
          }

          if ($zoom_type == 'jqzoom' && $index > 1) {

            $img_items[] = '<a href="' . $base_path . $file_directory . '/imagecache/' . $preset_big_image . '/product/' . $filename . '" rel="lightbox-thumbs" alt="' . $alt . '"  title="' . $title . '" target="_blank">' . theme('imagecache', $preset_thumb_image, $filepath, $alt, $title) . '</a>';

            $vars['show_product_small_images'] = '<div class="image-thumb product-block">' . theme_item_list($img_items, NULL, $type = 'ul', $attributes = array('class' => 'image-thumb')) . '</div>';

          }

          if ($zoom_type == 'cloudzoom' && $index > 0) { // Настройки для Cloud Zoom


            $product_image_url = $base_path . $file_directory . '/imagecache/' . $preset_product_image . '/product/' . $filename;

            $img_items[] = '<a class="cloud-zoom-gallery" href="' . $base_path . $filepath . '" rel="useZoom: \'zoom1\', smallImage: \'' .  $product_image_url . '\'" alt="' . $alt . '"  title="' . $title . '" target="_blank">' . theme('imagecache', $preset_thumb_image, $filepath, $alt, $title) . '</a>';

          }
        }


        if ($index > 1) {

          $img_items = $img_items;

        }
        else {

          $img_items = array_shift($img_items);
        }


        if (is_array($img_items)) {
          $vars['show_product_small_images'] = '<div class="image-thumb product-block">' . theme_item_list($img_items, NULL, $type = 'ul', $attributes = array('class' => 'image-thumb')) . '</div>';
        }

        if ($index > $scroll_on) {
          drupal_add_js($path_to_lib . '/scrollthumbs/scrollthumbs.js', 'theme', 'header', FALSE, TRUE, FALSE);
          drupal_add_css($path_to_lib . '/scrollthumbs/scrollthumbs.css', 'theme', 'all', FALSE);
        }

        if ($zoom_type == 'cloudzoom' && arg(0) == 'node' && is_numeric(arg(1)) && $PRODUCT_IMAGE_SET) {
          drupal_add_js($path_to_lib . '/cloud-zoom/cloud-zoom.js', 'theme', 'header', FALSE, TRUE, FALSE);
          drupal_add_css($path_to_lib . '/cloud-zoom/cloud-zoom.css', 'theme', 'all', FALSE);

        }

        list($width, $height) = @getimagesize($node->field_image_cache[0]['filepath']);

        if (($width > $width_zoom_on || $height > $height_zoom_on) && $zoom_type == 'jqzoom') {
          
		  if ($PRODUCT_IMAGE_SET) {
          drupal_add_js($path_to_lib . '/jqzoom/js/jqzoom.js', 'theme', 'header', FALSE, TRUE, FALSE);
          drupal_add_js($path_to_theme . '/js/jqzoom.config.js', 'theme', 'header', FALSE, TRUE, FALSE);
          drupal_add_css($path_to_lib . '/jqzoom/css/jqzoom.css', 'theme', 'all', FALSE);
          $big_img_id = 'zoom-link';

          $vars['show_product_image'] = '<div id="big-product-image" class="product-block' . $image_ajusted_class .'">
<div class="big-image-zoom"><a id="' . $big_img_id . '" href="' . $zoom_href . '" target="_blank">' . $big_image . '</a></div></div>';
        } else {
		$vars['show_product_image'] = '<div id="product-image-placeholder" class="product-block">' . variable_get('openstore_empty_image_text', 'Sorry, image is not available') .'</div>';
		}
		
		}

        else if (($width > $width_zoom_on || $height > $height_zoom_on) && $zoom_type == 'cloudzoom') {
          $big_img_class = 'cloud-zoom';
          $big_img_rel = "position: 'inside' , showTitle: false, adjustX:-4, adjustY:-4";

    // "rel" тег содержит конфигурацию плагина cloudzoom. Подробнее об доступных настройках на сайте плагина http://www.professorcloud.com/mainsite/cloud-zoom-integration.htm

          $big_img_id = 'zoom1';
          
		  if ($PRODUCT_IMAGE_SET) {
          $vars['show_product_image'] = '<div id="big-product-image" class="product-block' .  $image_ajusted_class .'">
<div class="big-image-zoom"><a class="' . $big_img_class . '" rel="' . $big_img_rel . '" id="' . $big_img_id . '" href="' . $zoom_href . '" target="_blank">' . $big_image . '</a></div></div>';
         } else {
		  $vars['show_product_image'] = '<div id="product-image-placeholder" class="product-block">' . variable_get('openstore_empty_image_text', 'Sorry, image is not available') .'</div>';
		 }
	}

        else {

          $big_img_class = 'cloud-zoom';
          $big_img_rel = 'zoomWidth: 0, zoomHeight: 0';
          $big_img_id = 'zoom1';

          if ($PRODUCT_IMAGE_SET) {
          $vars['show_product_image'] = '<div id="big-product-image" class="product-block">
<div class="big-image-nozoom">' . $big_image . '</div></div>';
          } else {
		  $vars['show_product_image'] = '<div id="product-image-placeholder" class="product-block">' . variable_get('openstore_empty_image_text', 'Sorry, image is not available') .'</div>';
		  }
        }

        // Блок с закладками
        $comment_count = $node->comment_count;
        drupal_add_css($path_to_lib . '/jquerytools/tabs/tabs.css', 'theme', 'screen');

        if (strip_tags($node->content['body']['#value']) || $vars['field_specs'][0]['value'] || theme('upload_attachments', $node->files) || $vars['field_media'][0]['value'] || $comment_count > 0) {
          drupal_add_js($path_to_lib . '/jquerytools/tabs/tabs.js', 'theme', 'header', FALSE, TRUE, FALSE);
          drupal_add_js('Drupal.behaviors.jstabsBehavior = function(context) {$("ul.product-tabs").tabs("div.panes > div");};', 'inline');
          $vars['show_product_tabs'] .= '<div id="product-tabs-wrapper" class="product-block">';
          $vars['show_product_tabs'] .= '<ul class="product-tabs">';
          if (strip_tags($node->content['body']['#value'])) {
            $vars['show_product_tabs'] .= '<li><a href="#">' . t('Product Tab 1') . '</a></li>';
          }
          if ($vars['field_specs'][0]['value']) {
            $vars['show_product_tabs'] .= '<li><a href="#">' . t('Product Tab 2') . '</a></li>';
          }
          if (theme('upload_attachments', $node->files) || $vars['field_media'][0]['value']) {
            $vars['show_product_tabs'] .= '<li><a href="#">' . t('Product Tab 3') . '</a></li>';
          }
          if ($comment_count > 0 && $node->comment != COMMENT_NODE_DISABLED && user_access('access comments')) {
            $vars['show_product_tabs'] .= '<li><a href="#">' . t('Product Tab 4') . '&nbsp;(' . $comment_count . ')</a></li>';
          }

          $vars['show_product_tabs'] .= '</ul>';
          $vars['show_product_tabs'] .= '<div class="panes">';
          if (strip_tags($node->content['body']['#value'])) {
            $vars['show_product_tabs'] .= '<div class="tab-product-desc">' . $node->content['body']['#value'] . '</div>';
          }
          if ($vars['field_specs'][0]['value']) {
            drupal_add_js('Drupal.behaviors.lioddBehavior = function(context) {$(\'div.tab-product-specs li:nth-child(odd)\').addClass(\'odd\');};', 'inline');
            $vars['show_product_tabs'] .= '<div class="tab-product-specs">' . $vars['field_specs'][0]['value'] . '</div>';
          }
          if (theme('upload_attachments', $node->files) || $vars['field_media'][0]['value']) {
            $vars['show_product_tabs'] .= '<div>';
            if ($vars['field_media'][0]['value']) {
              $vars['show_product_tabs'] .= '<div class="tab-product-media">' . $vars['field_media'][0]['value'] . '</div>';
            }
            if (theme('upload_attachments', $node->files)) {
              $vars['show_product_tabs'] .= '<div class="tab-product-files">' . theme('upload_attachments', $node->files) . '</div>';
            }
            $vars['show_product_tabs'] .= '</div>';
          }
          if ($comment_count > 0 && $node->comment != COMMENT_NODE_DISABLED && user_access('access comments')) {
            $vars['show_product_tabs'] .= '<div class="product-comments">' . $vars['show_product_custom_comments'];

            if (user_access('post comments') && $node->comment == COMMENT_NODE_READ_WRITE) {
              $vars['show_product_tabs'] .= '<span class ="tab-add-comment">' . l(t('Add comment'), 'comment/reply/' . $node->nid) . '</span>';
            }
            $vars['show_product_tabs'] .= '</div>';
          }
          $vars['show_product_tabs'] .= '</div>';
          $vars['show_product_tabs'] .= '</div>';

        }

        // Сворачивающиеся закладки
        $collapsible_style = variable_get('uc_product_tab_style', 'accordion');

        if ($vars['product_collapsible'] && $collapsible_style == 'accordion') {
          drupal_add_js('Drupal.behaviors.productaccordionBehavior = function(context) {$("#accordion").tabs("#accordion div.content", {tabs: \'h3\', effect: \'slide\', initialIndex: null});};', 'inline');
          $vars['show_product_accordion'] .= '<div id="accordion" class="product-block">';
          $vars['show_product_accordion'] .= $vars['product_collapsible'];
          $vars['show_product_accordion'] .= '</div>';
        }
        elseif ($vars['product_collapsible'] && $collapsible_style == 'cookie') {
          drupal_add_js($path_to_lib . '/cookie/jquery.cookie.js');
          drupal_add_js($path_to_lib . '/collapse/jquery.collapse.js');
          drupal_add_js('Drupal.behaviors.productcollapseBehavior = function(context) {$("#collapsible-cookie").collapse({open : true, head : "h3", group : "div", cookie : "productcollapse"});};', 'inline');
          $vars['show_product_accordion'] .= '<div id="collapsible-cookie">';
          $vars['show_product_accordion'] .= $vars['product_collapsible'];
          $vars['show_product_accordion'] .= '</div>';
        }
        else {
          $vars['show_product_accordion'] = '';
        }

        // Баллы
       if (module_exists('uc_userpoints_discount')) {
          $userpoints_ubercart_payment = variable_get('userpoints_ubercart_payment', FALSE);
          $uc_userpoints_discount_maxp  = variable_get('uc_userpoints_discount_maxp', FALSE);
          $uc_points_userpoints_discount  = variable_get('userpoints_discount', FALSE);

          if ($userpoints_ubercart_payment && $uc_points_userpoints_discount) {
            $pnt = userpoints_get_current_points($account->uid);

            $points_discount_value = $pnt / $userpoints_ubercart_payment;
            $points_discounted_price = uc_currency_format($node->sell_price - $points_discount_value);

            $vars['show_product_point_rates'] = '<div class="point-rates-text product-block">';

            if ($pnt > 0) {
              $vars['show_product_point_rates'] .= t('You can use your points') . '&nbsp;(' . t('currently you have') . '&nbsp;' . $pnt . ')&nbsp;' . t('to get discount for this product.') . '<br />';
            }
            else {
              $vars['show_product_point_rates'] .= t('You can use points to get a discount for this product, but you do not have them.') . '<br />';
            }
            if (!empty($uc_userpoints_discount_maxp)) {
              $vars['show_product_point_rates'] .= t('The maximum discount you can get using your points -') . '&nbsp;' . $uc_userpoints_discount_maxp . '%<br />';
            }
			if ($pnt > 0) {
            $vars['show_product_point_rates'] .= t('Rating exchange for your existing points -') . '&nbsp;' . $userpoints_ubercart_payment . '&nbsp;' . t('point(s) =') . '&nbsp;' . uc_currency_format(1) . t(', that means discount value') . '&nbsp;' . uc_currency_format($points_discount_value) .

t('To see price for you, please continue checkout') .

'<br />';
        }

            if (module_exists('uc_userpoints_award')) {
              $userpoints_ubercart_earn  = variable_get('userpoints_ubercart_earn', FALSE);
              $userpoints_min_purchase  = variable_get('userpoints_min_purchase', FALSE);
              $future_discount = ($node->sell_price * $userpoints_ubercart_earn) / $userpoints_ubercart_payment;


              if ($userpoints_ubercart_earn) {
                $vars['show_product_point_rates'] .= t('Every time you buy a product (using your points as discount or not), you get some points to your account calculated as') . '&nbsp;' . uc_currency_format(1) . '&nbsp;=&nbsp;' . $userpoints_ubercart_earn . '&nbsp;' . t('point(s)') . '<br />';
              }

              if ($node->sell_price < $userpoints_min_purchase && $userpoints_min_purchase) {

                $vars['show_product_point_rates'] .= t('NOTE: the minimum amount to get userpoints - ') . uc_currency_format($userpoints_min_purchase) . '<br />';
                $vars['show_product_point_rates'] .= t('You should increase your order amount to get points');

              }
              else {

                if ($userpoints_ubercart_earn) {

                  $vars['show_product_point_rates'] .= t('If you buy this product, you will get') . ' ' . uc_currency_format($future_discount) . ' ' . t('discount on next order, more amount - bigger discount.') . '<br />';
                }
              }
            }
          }
          $vars['show_product_point_rates'] .= '</div>';
        }

        if (module_exists('uc_discount_total')) {
          $rates_res = db_query('SELECT * FROM {uc_discount_total}');
          if ($rates_res->num_rows != NULL) {
            $header = array(t('Total amount range'), t('Your discount'));
            while ($row = db_fetch_array($rates_res)) {
              $rows[] = array(round($row['total_min']) . ' &#8212; ' . round($row['total_max']), round($row['total_rate']));
            }
            $vars['show_product_discount_rates'] = '<div class="discount-rates product-block">' . theme_table($header, $rows, FALSE, t('Currently we have the following discount rates enabled')) . '</div>';
          }
        }


        if (module_exists('comment') && user_access('post comments') && $node->comment == COMMENT_NODE_READ_WRITE) {
          if ($comment_count > 0) {
            $vars['show_product_comment_link'] = '<div class="add-comment">' . l(t('Add comment') . ' (' . $comment_count . ')', 'comment/reply/' . $node->nid) . '</div>';
          }
          else {
            $vars['show_product_comment_link'] = '<div class="add-comment product-string">' . l(t('Be first to review this product!'), 'comment/reply/' . $node->nid) . '</div>';
          }
        }


        $vars['show_product_additional_fields'] = drupal_render($node->content); // Render remaining fields


      } // / Препроцесс товара

      // Специальные классы для нод
      $classes = array('node');
      if ($vars['sticky']) {
        $classes[] = 'sticky';
      }

      if (!$vars['status']) {
        $classes[] = 'node-unpublished';
        $vars['unpublished'] = TRUE;
      }
      else {
        $vars['unpublished'] = FALSE;
      }
      if ($vars['uid'] && $vars['uid'] == $GLOBALS['user']->uid) {
        $classes[] = 'node-mine';
      }
      if ($vars['teaser']) {
        $classes[] = 'node-teaser';
      }
      $classes[] = 'clearfix';

      $classes[] = general_id_safe('node-type-' . $vars['type']);
      $vars['classes'] = implode(' ', $classes);

    //}


    if ((arg(0) == 'comment' && arg(1) == 'reply') || (arg(0) == 'comment' && arg(1) == 'edit')) {
      unset($vars['node']); // Убираем всё содержимое шаблона документа при комментировании или редактировании комментария
    }

  } // / Препроцесс node.tpl.php


  if ($hook == 'block' || $hook == 'node') {


    $vars['show_rss_news'] = '<div class="rss news-rss"><span class="rss-label">' . t('Subscribe to news RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'news/feed', t('Subscribe to news RSS feed')) . '</div>';
    $vars['show_rss_all'] = '<div class="rss common-rss"><span class="rss-label">' . t('Subscribe to common RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'rss.xml', t('Subscribe to common RSS feed')) . '</div>';
    $vars['show_rss_top_rated'] = '<div class="rss top-rated-rss"><span class="rss-label">' . t('Subscribe to top rated RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'top-rated/feed', t('Subscribe to top rated RSS feed')) . '</div>';
    $vars['show_rss_new_products'] = '<div class="rss new-product-rss"><span class="rss-label">' . t('Subscribe to new products RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'newproducts/feed', t('Subscribe to new products RSS feed')) . '</div>';
    $vars['show_rss_last_reviews'] = '<div class="rss last-reviews-rss"><span class="rss-label">' . t('Subscribe to last reviews RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'comments/feed', t('Subscribe to last reviews RSS feed')) . '</div>';
    $vars['show_rss_discounts'] = '<div class="rss discounts-rss"><span class="rss-label">' . t('Subscribe to discounts RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'discounts/feed', t('Subscribe to discounts RSS feed')) . '</div>';

    $vars['show_rss_promo'] = '<div class="rss promo-rss"><span class="rss-label">' . t('Subscribe to promo RSS feed') . '</span>&nbsp;' . theme_feed_icon($base_path . 'promotion/feed', t('Subscribe to promo RSS feed')) . '</div>';


    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $product_comments_path = $base_path . 'comments-feed/' . arg(1);
      $vars['show_rss_product_comments'] = '<div class="rss product-comments-rss"><span class="rss-label">' . t('Subscribe to product comments RSS feed') . '</span>&nbsp;' . theme_feed_icon($product_comments_path, t('Subscribe to this product comments RSS feed')) . '</div>';
    }
  }

  // Препроцесс для блоков
  if ($hook == 'block') {
    $block = $vars['block'];	

    if ($vars['block']->delta == 'conditional_blocks-block_6') {
      $vars['block']->subject = t('Related articles');
    }
	


    if ($vars['block']->module == 'node' && $vars['block']->delta == 0) {
      $vars['block']->content = $vars['show_rss_news'];
      $vars['block']->content .= $vars['show_rss_all'];
      $vars['block']->content .= $vars['show_rss_top_rated'];
      $vars['block']->content .= $vars['show_rss_new_products'];
      $vars['block']->content .= $vars['show_rss_last_reviews'];
      $vars['block']->content .= $vars['show_rss_discounts'];
      $vars['block']->content .= $vars['show_rss_product_comments'];
      $vars['block']->content .= $vars['show_rss_promo'];
    }

    if ($vars['block']->region == 'primary_menu' || $vars['block']->region == 'top_bar') {
      $vars['template_files'][] = 'block-nude';
    }

    // Специальные классы для блоков
    $classes = array('block');
    $classes[] = general_id_safe('block-' . $vars['block']->module);
    $classes[] = general_id_safe('block-' . $vars['block']->region);
    $classes[] = general_id_safe('block-id-' . $vars['block']->bid);
    $classes[] = 'clearfix';
    $classes[] = $vars['block']->extraclass;

    $vars['block_classes'] = implode(' ', $classes);


    if (theme_get_setting($block->theme . '_block_editing') && arg(0) != 'admin') {

      $edit_links = array();

      if (user_access('administer blocks')) {

        if ($block->module == 'block') {
          $edit_links[] = l('<span>' . t('edit block') . '</span>', 'admin/build/block/configure/' . $block->module . '/' . $block->delta,
            array(
            'attributes' => array(
              'title' => t('edit the content of this block'),
              'class' => 'block-edit',
            ),
            'query' => drupal_get_destination(),
            'html' => TRUE,
          )
        );
      }

        else {
          $edit_links[] = l('<span>' . t('edit block') . '</span>', 'admin/build/block/configure/' . $block->module . '/' . $block->delta,
            array(
            'attributes' => array(
              'title' => t('configure this block'),
              'class' => 'block-config',
            ),
            'query' => drupal_get_destination(),
            'html' => TRUE,
          )
         );
        }
      }

      if (($block->module == 'menu' || ($block->module == 'user' && $block->delta == 1)) && user_access('administer menu')) {
        $menu_name = ($block->module == 'user') ? 'navigation' : $block->delta;
        $edit_links[] = l('<span>' . t('edit menu') . '</span>', 'admin/build/menu-customize/' . $menu_name,
            array(
          'attributes' => array(
            'title' => t('edit the menu that defines this block'),
            'class' => 'block-edit-menu',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
       );
      }

      if ($block->module == 'menu_block' && user_access('administer menu')) {
        list($menu_name,  ) = split(':', variable_get("menu_block_{$block->delta}_parent", 'navigation:0'));
        $edit_links[] = l('<span>' . t('edit menu') . '</span>', 'admin/build/menu-customize/' . $menu_name,
            array(
          'attributes' => array(
            'title' => t('edit the menu that defines this block'),
            'class' => 'block-edit-menu',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
       );
      }


      if ($block->module == 'views') {

        if (user_access('administer views')) {

          $block_delta = $vars['block']->delta;
          $block_arg = explode('-', $block_delta);
          $block_view_name = $block_arg[0];
          $block_view_display = $block_arg[1];
          $edit_links[] = '<span><a title="' . t('settings for this view') . '" href ="' . $base_path . 'admin/build/views/edit/' . $block_view_name . '?' . drupal_get_destination() . '#views-tab-' . $block_view_display . '">' . t('view settings') . '</a></span>';

        }

        if (user_access('manipulate queues')) {
          $queue_delta  = $block->delta;
          $queue_name = 'queues';
          $queue_res = strpos($queue_delta, $queue_name);
          if ($queue_res !== false) {
            $queue_arr = explode('-', $queue_delta);
            $queue_view_name = $queue_arr[0];
            $queue_display_name = $queue_arr[1];
            $view = views_get_view($queue_view_name);
            $queue_id = $view->display[$queue_display_name]->display_options['relationships']['nodequeue_rel']['qids'];
            $queue_id = array_shift($queue_id);
            $queue_path = 'admin/content/nodequeue/' . $queue_id . '/view';
            $edit_links[] = l('<span>' . t('edit queue') . '</span>', $queue_path,
          array(
              'attributes' => array(
                'title' => t('edit a nodequeue which built the block'),
                'class' => 'block-edit-queue',
              ),
              'query' => drupal_get_destination(),
              'html' => TRUE,
            )
           );
          }
        }
      }

      if ($block->module == 'superfish' && user_access('administer menu')) {
        $block_delta = $vars['block']->delta;
        list($menu_name,  ) = split(':', variable_get('superfish_menu_' . $block_delta, FALSE));
        $edit_links[] = l('<span>' . t('edit menu') . '</span>', 'admin/build/menu-customize/' . $menu_name,
          array(
          'attributes' => array(
            'title' => t('edit the menu that defines this block'),
            'class' => 'block-edit-menu',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
       );
      }


      $vars['edit_links_array'] = $edit_links;
      $vars['edit_links'] = theme_item_list($edit_links, NULL, 'ul', array('class' => 'edit'));

    }

  } /// / Препроцесс для блоков



  // Препроцесс для комментариев
  if ($hook == 'comment') {
    $vars['unpublished'] = ($vars['comment']->status == COMMENT_NOT_PUBLISHED);

    if (variable_get('comment_subject_field_' . $vars['node']->type, 1) == 0) {
      $vars['title'] = '';
    }
    $classes = array('comment');
    if ($vars['comment']->new) {
      $classes[] = 'comment-new';
    }
    $classes[] = $vars['status'];
    $classes[] = $vars['zebra'];
    if ($vars['id'] == 1) {
      $classes[] = 'first';
    }
    if ($vars['id'] == $vars['node']->comment_count) {
      $classes[] = 'last';
    }
    if ($vars['comment']->uid == 0) {
      $classes[] = 'comment-by-anon';
    }
    else {
      if ($vars['comment']->uid == $vars['node']->uid) {

        $classes[] = 'comment-by-author';
      }
      if ($vars['comment']->uid == $GLOBALS['user']->uid) {
        $classes[] = 'comment-mine';
      }
    }
    $vars['classes'] = implode(' ', $classes);

  } // / Препроцесс для комментариев



  if ($hook == 'poll_results') {

    if ($vars['block'] == TRUE) {
      if (user_access('post comments') || user_access('cancel own vote')) {
        $vars['links'] = l(t('Add comment/Edit vote'), 'comment/reply/' . $vars['nid'], array('fragment' => 'comment-form'));
      }
    }
  }


  // Препроцесс профиля
  if ($hook == 'user_profile') {

    $vars['show_member_time'] = '<div class="member-for">' . t('You have been with us for') . ' ' . $vars['account']->content['summary']['member_for']['#value'] . '</div>';
    $vars['show_member_time_value'] = $vars['account']->content['summary']['member_for']['#value'];
    $vars['show_created_short_value'] = format_date($vars['account']->created, 'small');
    $vars['show_created_medium_value'] = format_date($vars['account']->created, 'medium');
    $vars['show_created_large_value'] = format_date($vars['account']->created, 'large');

    $roles = $vars['account']->roles;
    foreach ($roles as $roleid => $rolename) {
      if ($rolename == 'authenticated user') {
        unset($roles[$roleid]);
      }
    }


    if (!empty($roles)) {
      $vars['show_roles'] = '<div class="roles-list">' . theme_item_list($roles, t('Your role(s)'), 'ul', NULL) . '</div>';
    }

    $userpoints_string = strip_tags($vars['account']->content['userpoints']['points']['#value']);
    $vars['show_profile_userpoints_value'] = ereg_replace("[^0-9]", "", $userpoints_string); // Выделяем число из строки

    if (user_access('view own userpoints') && $vars['show_profile_userpoints_value']) {
      $vars['show_profile_userpoints'] = '<div class="userpoints">' . t('My userpoints') . ' ' . $vars['account']->content['userpoints']['points']['#value'] . '</div>';




      if (module_exists('uc_userpoints_discount')) {
        $userpoints_payment = variable_get('userpoints_ubercart_payment', FALSE);
        $userpoints_discount_maxp = variable_get('uc_userpoints_discount_maxp', FALSE);
        $userpoints_discount = variable_get('userpoints_discount', FALSE);

        if ($userpoints_payment && $userpoints_discount) {
          $points = $vars['show_profile_userpoints_value'];
          $points_discount_value = $points / $userpoints_payment;

          if ($points > 0) {
            $vars['show_profile_userpoints'] .= t('You can use your points to get discount for ordered products.') . '<br />';
          }

          $vars['show_profile_userpoints'] .= t('Rating exchange for your existing points -') . ' ' . $userpoints_payment . ' ' . t('point(s) =') . ' ' . uc_currency_format(1) . t(', that means discount value') . ' ' . uc_currency_format($points_discount_value) . '<br />';

          if ($userpoints_discount_maxp) {
            $vars['show_profile_userpoints'] .= t('The maximum discount you can get using your points -') . ' ' . $userpoints_discount_maxp . '%<br />';
          }

        }
      }
    }


    $vars['show_newsletters_link'] = '<div class="newsletters-link">' . $vars['account']->content['simplenews']['my_newsletters']['#value'] . '</div>';

    if (!empty($vars['account']->newsletters)) {
      $term_item = array();
      foreach ($vars['account']->newsletters as $tid) {
        if ($tid) {
          $term_obj = taxonomy_get_term($tid);
          $term_item[] = l($term_obj->name, 'taxonomy/term/' . $tid);
        }
      }
      $vars['show_subscribed_terms'] = '<div class="subscribed-terms">' . theme_item_list($term_item, t('You subscriber on:'), 'ul', NULL) . '</div>';
    }
    else {
      $vars['show_subscribed_terms'] = '<div class="subscribed-terms">' . t('You are not subscribed to any our newsletters.') .
                                   '<div>' . l(t('Subscribe now!'), 'user/' . $vars['account']->uid . '/edit/newsletter') . '</div></div>';
    }

    if (user_access('add/edit addresses')) {
      $vars['show_addresses_link'] = '<div class="addresses-link">' . l(t('Manage your address book'), 'user/' . $vars['account']->uid . '/addresses') . '</div>';
    }

    if (user_access('add/edit addresses')) {
      $vars['show_addresses_add_link'] = '<div class="addresses-add-link">' . l(t('Add address'), 'user/' . $vars['account']->uid . '/addresses/add') . '</div>';
    }

    $vars['show_edit_link'] = '<div class="edit-link">' . l(t('Edit your profile'), 'user/' . $vars['account']->uid . '/edit') . '</div>';

    if (module_exists('openid')) {
      $vars['show_openid_link'] = '<div class="openid-link">' . l(t('Manage openid account'), 'user/' . $vars['account']->uid . '/openid') . '</div>';
    }

    $vars['show_username'] = '<div class="profile-username">' . t('Profile username') . ' ' . $vars['account']->name . '</div>';

    $vars['show_mail'] = '<div class="profile-mail">' . t('Profile mail') . ' ' . $vars['account']->mail . '</div>';

    if (!$vars['account']->status) {
      $vars['show_status'] = '<div class="profile-status">' . t('This profile is blocked') . '</div>';
    }

    if (module_exists('uc_addresses') && arg(0) == 'user' && is_numeric(arg(1)) && !arg(2)) {

      $uid = arg(1);
      $sql = "SELECT first_name, last_name, phone, street1, city, zone, postal_code, country
  FROM {uc_addresses}
  JOIN {uc_addresses_defaults}
  ON uc_addresses.uid  = uc_addresses_defaults.uid
  WHERE uc_addresses_defaults.uid = %d";
      $result = db_fetch_array(db_query($sql, $uid));

      if (!empty($result)) {
        $rows = array();
        foreach ($result as $key => $value) {
          if ($key == 'zone') {
            $value = uc_zone_get_by_id($value);
          }
          if ($key == 'country') {
            $value = uc_country_get_by_id($value);
          }
          $rows[] = $value;
        }

        $rows = array($rows);

        $header = array(t('First name'), t('Last name'), t('Phone'), t('Street address 1'), t('City'), t('State/Province'), t('ZIP/Postal code'), t('Country'));

        $vars['show_addresses_default'] = theme_table($header, $rows, array('id' => 'default-address'), t('My default address'));


      }
      else {

        $vars['show_addresses_default'] = '<div>' . t('You do not have default address set yet.') . '</div>';
        $vars['show_addresses_default'] .= '<div>' . t('Please,provide at least one default address for quicker checkout.') . '</div>';
        $vars['show_addresses_default'] .= '<div>' . t('You may also enter billing and delivery information during checkout.') . '</div>';
        $vars['show_addresses_default'] .= '<div><form action="' . $base_path . 'user/' . $vars['account']->uid . '/addresses/add" method="get">
                                     <input type="submit" value="' . t('Add address') . '" />
                                     </form>
									 </div>';
      }
    }

    if (user_access('view own orders')) {
      $vars['show_order_link'] = '<div class="order-link">' . $vars['account']->content['orders']['link']['#value'] . '</div>';
    }

    $vars['show_logged_as'] = '<div class="logged-as">' . t('You are currently logged in as:') . ' ' . $vars['account']->name .
                             '<div><form action="' . $base_path . 'logout" method="get">
                              <input type="submit" value="' . t('Log out') . '" />
                              </form>
							  </div></div>';




  } // /Препроцесс профиля

  $vars['scripts'] = drupal_get_js();
  $vars['styles'] = drupal_get_css();

 } // Конец функции препроцесса
 
  function vocab_terms($node, $vid = NULL) {
      if (arg(0) == 'node' && is_numeric(arg(1))) {
        $vocabularies = taxonomy_get_vocabularies();
        foreach ($vocabularies as $vocabulary) {
          if ($vocabulary->vid == $vid) {
            $terms = taxonomy_node_get_terms_by_vocabulary($node, $vocabulary->vid);
            if ($terms) {
              $term_arr	= array();
              foreach ($terms as $term) {
                $term_arr[] = $term;
              }
            }
          }
        }
      }
      return $term_arr;
    }

function general_id_safe($string) {
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  if (!ctype_lower($string{0})) {
    $string = 'id' . $string;
  }
  return $string;
}

// Уьирам со страницы администрирования блоков ненужные блоки, чтобы они нас не смущали
function general_preprocess_block_admin_display_form(&$vars) {

  if ($vars['form']['system_0']['theme']['#value'] != 'administrator') {
    unset($vars['block_listing']['-1']['system_0']);
    unset($vars['block_listing']['-1']['profile_0']);
    unset($vars['block_listing']['-1']['fivestar_0']);
    unset($vars['block_listing']['-1']['userpoints_0']);
    unset($vars['block_listing']['-1']['locale_0']);
    unset($vars['block_listing']['-1']['views_advanced_catalog-block_1']);
    unset($vars['block_listing']['-1']['views_advanced_catalog-block_2']);
    unset($vars['block_listing']['-1']['views_advanced_catalog-block_3']);
    unset($vars['block_listing']['-1']['views_advanced_catalog-block_4']);
    unset($vars['block_listing']['-1']['views_admin_users-block_1']);
    unset($vars['block_listing']['-1']['views_orders-block_1']);
    unset($vars['block_listing']['-1']['views_tweets-block']);
    unset($vars['block_listing']['-1']['views_newsletters-block_1']);
    unset($vars['block_listing']['-1']['menu_block_1']);
    unset($vars['block_listing']['-1']['menu_block_2']);
    unset($vars['block_listing']['-1']['menu_block_3']);
    unset($vars['block_listing']['-1']['menu_block_4']);
    unset($vars['block_listing']['-1']['menu_block_5']);
    unset($vars['block_listing']['-1']['menu_block_6']);
    unset($vars['block_listing']['-1']['menu_block_9']);
    unset($vars['block_listing']['-1']['menu_devel']);
    unset($vars['block_listing']['-1']['menu_menu-info-pages']);
    unset($vars['block_listing']['-1']['menu_secondary-links']);
    unset($vars['block_listing']['-1']['twitter_signin_0']);
    unset($vars['block_listing']['-1']['fbconnect_invite_0']);
    unset($vars['block_listing']['-1']['devel_0']);
    unset($vars['block_listing']['-1']['devel_2']);
    unset($vars['block_listing']['-1']['domain_1']);
    unset($vars['block_listing']['-1']['domain_nav_0']);
    unset($vars['block_listing']['-1']['domain_conf_domain-primary-links']);
    unset($vars['block_listing']['-1']['domain_0']);
    unset($vars['block_listing']['-1']['domain_conf_domain-secondary-links']);
    unset($vars['block_listing']['-1']['domain_alias_domain_alias']);
    unset($vars['block_listing']['-1']['block_admin_display_for']);
    unset($vars['block_listing']['-1']['user_1']);
    unset($vars['block_listing']['-1']['user_2']);
    unset($vars['block_listing']['-1']['user_3']);
    unset($vars['block_listing']['-1']['comment_0']);
    unset($vars['block_listing']['-1']['userpoints_-1']);
    unset($vars['block_listing']['-1']['masquerade_0']);	
	unset($vars['block_listing']['-1']['menu_features']);
	unset($vars['block_listing']['-1']['general_3']);
	unset($vars['block_listing']['-1']['general_5']);
	unset($vars['block_listing']['-1']['general_2']);
	unset($vars['block_listing']['-1']['general_4']);	
	unset($vars['block_listing']['-1']['service_links_service_links_fisheye']);	
	
  }
}