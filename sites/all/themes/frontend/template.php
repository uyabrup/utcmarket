<?php

function frontend_blocks($region) {
  $output = '';

  if ($list = block_list($region)) {
    $blockcounter = 1;
    foreach ($list as $key => $block) {
      $block->extraclass = '';
      $block->extraclass .= ( $blockcounter == 1 ? 'block-first' : '' );
      $block->extraclass .= ( $blockcounter == count($list) ? 'block-last' : '' );
      $output .= theme('block', $block);
      $blockcounter++;
    }
  }

  $output .= drupal_get_content($region);

  return $output;
}
 	

function frontend_menu_item_link($link) {
  global $user;
  
  $path = explode('/', $link['href']);
  $path = $path[2];
  
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }


  if ($link['type'] & MENU_IS_LOCAL_TASK) {
    $link['title'] = '<span class="tab">' . check_plain($link['title']) . '</span>';
    $link['localized_options']['html'] = TRUE;
	$path_arg = explode("/", $link['path']);
	if ($path_arg[0] == 'node' && $path_arg[2] == 'edit') {
    $link['localized_options']['query'] = drupal_get_destination();
    }
	
  }  

  if($link['menu_name'] == 'menu-common' && (arg(1) == 'checkout' || arg(0) == 'user')) {
    $link['localized_options']['attributes']['target'] = '_blank';
  }
 
  if ($link['href'] == 'admin/build/block' && $link['path'] == 'admin/build/block/list/frontend') {
  $link['title'] = t('frontend theme');
  }
  
  if (arg(0) == 'user' && $user->uid) {   
 $pblocks = array_keys(block_list('profile_blocks')); // Мы смотрим, какие блоки включены в регионе profile_blocks и отключаем табы в профиле, если есть аналогичные блоки в этом регионе.
  if (arg(0) == 'user' && !arg(2) && !empty($pblocks)) {   
    if (in_array('views_orders-block_2', $pblocks) && $path == 'orders') {  
     unset($link['title']); // Отключаем вкладку "Мои заказы", если включен блок "Мои заказы" в регионе profile_blocks
     }  
    if (in_array('views_flag_bookmarks-block_1', $pblocks) && $path == 'bookmarks') {  
     unset($link['title']); // Отключаем вкладку "Мои закладки", если включен блок "Мои закладки" в регионе profile_blocks
     }  
  } else {
  if ($path == 'orders' || $path == 'bookmarks') {
  unset($link['title']);
  }
 }
  if (module_exists('uc_file') && arg(0) == 'user' && $user->uid) {
  $uid = arg(1);
  $sql = "SELECT file_key FROM {uc_file_users} WHERE uid = %d"; // Смотрим, есть ли у пользователя купленные файлы и если нет, то скрываем ненужный таб
  $result = db_fetch_array(db_query($sql, $uid)); 
  if (empty($result) && $path == 'purchased-files') {
  unset($link['title']);
  }
 }
}
  
  if ($link['title'] && $link['href']) {
  
return l($link['title'], $link['href'], $link['localized_options']);

} else {
return '';
}
}


function frontend_menu_local_tasks() {
  $output = '';
  if ($primary = menu_primary_local_tasks()) {
    if(menu_secondary_local_tasks()) {
      $output .= '<ul class="tabs primary with-secondary clearfix">' . $primary . '</ul>';
    }
    else {
      $output .= '<ul class="tabs primary clearfix">' . $primary . '</ul>';
    }
  }
  if ($secondary = menu_secondary_local_tasks()) {
    $output .= '<ul class="tabs secondary clearfix">' . $secondary . '</ul>';
  }
  return $output;
}
	
function frontend_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  static $zebra = FALSE;
  $zebra = !$zebra;
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
    if ($zebra) {
    $class .= ' even';
  }
  else { 
    $class .= ' odd';
  }

static $item_id = 0;
  $item_id += 1;
  $id .= 'id-' . $item_id;

  return '<li id="'.$id.'" class="'. $class .'">' . $link . $menu ."</li>\n";
}


    function frontend_breadcrumb($breadcrumb) { 
    $b_txt = variable_get('uc_cart_breadcrumb_text', FALSE); // Check if cart breadcrumb text is set
    if (!empty($breadcrumb) && arg(0) != 'cart' && count($breadcrumb)>1) {
    return '<div class="breadcrumb">'. implode(' » ', $breadcrumb) .'</div>';
    }
	
    else if (!empty($b_txt) && arg(0) == 'cart') {
    return '<div class="breadcrumb">'. implode(' » ', $breadcrumb) .'</div>';	
    }
  
    else if (!empty($breadcrumb) && count($breadcrumb) == 1) {
    return '<div class="breadcrumb">'. l(t('Back to main page'), '<front>') .'</div>';
    } else {
    return ''; 
    }
}

function phptemplate_uc_catalog_browse($tid = 0) {  
    $catalog = uc_catalog_get_page($tid);	
	if (variable_get('uc_cat_auto_pic', FALSE) && module_exists('general') && !empty($catalog->children)) {
	return general_catalog_browse($tid);
	} 	
    else if (module_exists('uc_advanced_catalog') && empty($catalog->children)) {		
	return uc_advanced_catalog_browse($tid);
	} else {
	return theme_uc_catalog_browse($tid);
	}
}

function frontend_theme() {
  return array(
    'comment_form' => array(
    'arguments' => array('form' => NULL),
    ),
  );
}

   function frontend_comment_form($form) {
   unset($form['_author']);
   unset($form['comment_filter']['format']);
   unset($form['comment']['#type']['#title']);
   unset ($form['homepage']);
   unset($form['preview']);
   $form['comment_filter']['comment']['#title'] = t('Enter your message');
  $form['comment_filter']['comment']['#rows'] = 5;
   if(arg(0) == 'node' && is_numeric(arg(1))){ 
   unset($form['comment_filter']);
   unset($form['submit']);
   
   } 
  return drupal_render($form);
}

function frontend_links($links, $attributes = array()) {

    if ($links['comment_reply']) {
	unset($links['comment_reply']); // Удаляем ссылку "Ответить на комментарий"
	}

    return theme_links($links, $attributes = array('class' => 'links'));
}

function frontend_uc_empty_cart() {
  
  $empty = drupal_get_path('module', 'general') . '/images/empty_bag.png';
  
  return '<div class="empty-cart">' . theme('image', $empty, t('There are no products in your shopping cart.')) . '<p>'. t('There are no products in your shopping cart.') . '</p></div>';
 
}
