<?php

function _administrator_admin_navigation() {
  $path = base_path() . path_to_theme();
  $base = path_to_theme();

  global $user;

  if ($user->uid != 1) {
    $role_menu = _administrator_init_role_menu();
    if ($role_menu) {
      $administrator_navigation = theme_get_setting('administrator_navigation_source_'. $role_menu);
    }
  }
  else {
    $administrator_navigation = theme_get_setting('administrator_navigation_source_admin');
    if (!isset($administrator_navigation)) {
      $administrator_navigation = '_administrator_default_navigation';
    }
  }

  $menu_tree = array();
  if (!$administrator_navigation) {
    if (!$user->uid) {
      $menu_tree[] = array('href' => 'user/login', 'title' => t('User login'));
    }
  }
  elseif ($administrator_navigation == '_administrator_default_navigation') {

    $menu_tree[] = array('href' => 'admin', 'title' => t('Dashboard'));
	$menu_tree[] = array('href' => 'admin/store', 'title' => t('Manage store'));
    $menu_tree[] = array('href' => 'admin/content/nodequeue', 'title' => t('Manage queues'));     
	$menu_tree[] = array('href' => 'admin/store/orders/all-orders', 'title' => t('Manage orders'));
	$menu_tree[] = array('href' => 'admin/product-manager', 'title' => t('Manage produsts&pages'));	
  }
  else {
    $menu_tree = menu_navigation_links($administrator_navigation);
  }
    $match = _administrator_besturlmatch($_GET['q'], $menu_tree);
    $items = array();
    foreach ($menu_tree as $key => $item) {
      $router_item = menu_get_item($item['href']);
      if (!$router_item['access']) {
        continue;
      }
      $id = '';
      $class= '';

      if ($key == $match) {
        $id = 'current';
      }
      $class = "";
      if (is_array($arg)) {
        $class = implode($arg, '-');
      }

      $item['data'] = l($item['title'], $item['href'], array('html' => TRUE));
      if (!empty($id)) $item['id'] = $id;
      if (!empty($class)) $item['class'] = $class;
      if (!empty($item['attributes'])) {
        unset($item['attributes']);
      }
      $items[] = $item;
    }
    $level = 1;
    if ($administrator_navigation == '_administrator_default_navigation') {
      $administrator_navigation = 'navigation';
      $level = 2;
    }
    return array(
      'navigation' => theme('admin_navigation', $items, $list_class),
      'menu' => $administrator_navigation,
      'level' => $level,
    );
  } 

function administrator_admin_navigation($items, $class) {
  return theme('item_list', $items);
}

function _administrator_besturlmatch($needle, $menuitems) {
  $needle = drupal_get_path_alias($needle);
  $lastmatch = NULL;
  $lastmatchlen = 0;
  $urlparts = explode('/', $needle);
  $partcount = count($urlparts);

  foreach ($menuitems as $key => $menuitem) {
    $href = $menuitem['href'];
    $menuurlparts = explode('/', $href);
    $matches = _administrator_countmatches($urlparts, $menuurlparts);
    if (($matches > $lastmatchlen) || (($matches == $lastmatchlen) && (($lastmatch && drupal_strlen($menuitems[$lastmatch]['href'])) > drupal_strlen($href)) )) {
      $lastmatchlen = $matches;
      $lastmatch = $key;
    }
  }
  return $lastmatch;
}
 
function administrator_preprocess(&$vars, $hook) { 

      $path_to_theme = drupal_get_path('theme', 'administrator');
	  
	  drupal_add_js($path_to_theme . '/js/tools.js');
	  
	   if (module_exists('general')) {
	  $path_to_lib = drupal_get_path('module', 'general') . '/lib';
	  }
	  
 if ($hook == 'page') {
 
 
 if (arg(0) == 'admin' && !arg(1) && theme_get_setting('administrator_dashboard_display_message')) {
 unset($vars['messages']);
 }
 
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'edit') {
  $vars['title'] = t('Editing of') . '&nbsp;&#8220;' . $vars['title'] . '&#8221;';

 }
 
 if (arg(3) == 'add' && arg(4) == 'nodequeue') {
 $vars['title'] = $vars['head_title'] = t('Add to Nodequeues');

 }

 
 if(arg(0)=='admin' && arg(1)== NULL) {
    $vars['tabs'] = "";
  }

  $vars['tabs2'] = menu_secondary_local_tasks();
  $admin_theme = variable_get('admin_theme', 'garland');
  if (arg(0) == 'admin' AND arg(1) == 'settings' AND arg(2) == 'admin' AND ($admin_theme == 'administrator')) {
    $message = t('Thank you for using Administrator.<br />Did you know, that Administrator theme has advanced settings (Theme-specific settings fieldset)? You can change these settings at <a href="@configure-page">theme configuration page</a>.', array('@configure-page' => url('admin/build/themes/settings/'. $admin_theme)));
    $vars['messages'] .= '<div class="messages administrator">'. $message .'</div>';
  }

  if (arg(0) == 'admin' || ((arg(0) == 'node' AND is_numeric(arg(1)) AND arg(2) == 'edit') || (arg(0) == 'node' AND arg(1) == 'add'))) {
    $vars['go_home'] = '<a href="'. url() .'">'. t('Go Back to Homepage') .'</a>';
  }
  $vars['hide_header'] = theme_get_setting('administrator_header_display');
  $vars['hide_panel'] = theme_get_setting('administrator_hide_panel');
  $vars['hide_content'] = '';	

  if (theme_get_setting('administrator_help_display')) {
    unset($vars['help']);
  }
  
   if (arg(0) == 'admin' AND !arg(1)) {
    if (!theme_get_setting('administrator_dashboard_display')) {
      $vars['dashboard'] = 1;
	  }	
	
    if (theme_get_setting('administrator_dashboard_content_display')) {
      $vars['hide_content'] = theme_get_setting('administrator_dashboard_content_display');
    }	
  }
  
   if (theme_get_setting('administrator_dashboard_tabs') == 'collapsed' && arg(0) == 'admin' && arg(1) == NULL) {
     drupal_add_js($path_to_lib . '/cookie/jquery.cookie.js');
     drupal_add_js($path_to_lib . '/collapse/jquery.collapse.js');
	 drupal_add_js('Drupal.behaviors.collapseadminblockBehavior = function(context) {$("#dashboard .block-inner").collapse({open : false, head : "h3", group : "div", cookie : "admincollapsed"});};', 'inline');
	}
 
 if (theme_get_setting('administrator_dashboard_tabs') == 'tabs' && arg(0) == 'admin' && arg(1) == NULL) {
 
 $block_arr = block_list('dashboard_top');
 $tabs_ul = '<ul class="admin-tabs-blocks">';
 foreach ($block_arr as $key => $item) {
 
 if ($item->title) {
 $tabs_ul .= '<li><a href="#">'.$item->title.'</a></li>';
 } else {
  $tabs_ul .= '<li><a href="#">'.$item->subject.'</a></li>';
}
}
$tabs_ul .= '</ul>'; 
$vars['admin_content_top'] = $tabs_ul;
 
 
     drupal_add_js($path_to_lib . '/jquerytools/tabs/tabs.js');
	 drupal_add_css($path_to_lib .'/jquerytools/tabs/tabs-admin.css', 'theme', 'screen');
	 
	 drupal_add_js('Drupal.behaviors.tabsadminblockBehavior = function(context) {$("ul.admin-tabs-blocks").tabs("div.block-tabs");};', 'inline');
 
 }

  $vars['panel_navigation'] = '<a id="open" class="open" href="#" title="'.t('Warning! Advanced settings for core. Do not change unless you know what you are doing!').'"><span class="panel-open">'. t('Open Panel') .'</span></a>';
  $vars['panel_navigation'] .= '<a id="close" style="display: none;" class="close" href="#"><span class="panel-close">'. t('Close Panel') .'</span></a>';
  
   if (arg(0) == 'admin' AND $GLOBALS['user']->uid != 1) {
   unset($vars['panel_navigation']);
   }

  $administrator_nav = _administrator_admin_navigation();
  $vars['administrator_navigation'] = $administrator_nav['navigation'];

  if (arg(0) == 'admin' AND arg(2)) {
    $menu = menu_navigation_links($administrator_nav['menu'], $administrator_nav['level']);
    $menu_links = _administrator_links($menu, array('id' => 'administrator-menu'));
      $vars['admin_left'] = $menu_links . $vars['admin_left'];
  }

  if ((arg(0) == 'admin' && arg(1) == 'user' && arg(2) == 'permissions') || (arg(0) == 'admin' && arg(1) == 'content' && arg(2) == 'backup_migrate')) {
  
 $vars['admin_content_top'] = $menu_links;
  unset($vars['admin_left']);
 
  }

  	   if (arg(0) == 'admin' && arg(1) == 'content' && arg(2) == 'node-type') {
       $vars['admin_content_top'] = $menu_links;
  unset($vars['admin_left']);
     }	 
	 
	 if (arg(0) == 'admin' && arg(1) == 'build' && arg(2) == 'modules') {
	   $vars['admin_content_top'] = $menu_links;
  unset($vars['admin_left']);
	 }
	 
	 
  	 if (arg(0) == 'admin' && arg(1) == 'user' && arg(2) == 'user') {
	   $vars['admin_content_top'] = $menu_links;
  unset($vars['admin_left']);
	 }

	   	 if (arg(0) == 'admin' && arg(1) == 'build' && arg(2) == 'domain') {
	   $vars['admin_content_top'] = $menu_links;
  unset($vars['admin_left']);
	 }
	 
	 	   	 if (arg(0) == 'devel' && module_exists('devel')) {			 
		  	  $dev_block = module_invoke('menu', 'block', 'view', 'devel');		 
	          $vars['admin_content_top'] = $dev_block['content'];
              unset($vars['admin_left']);
	 }
	 
	 if (arg(0) == 'admin' && arg(1) == 'store' && arg(2) == 'orders' && is_numeric(arg(3)) && arg(4) == 'invoice') {
	 unset($vars['admin_left']);
	 }	
	 
	 if (arg(0) == 'admin' && arg(3) == 'all-orders' && !arg(4)) {
	 unset($vars['admin_left']);
	 }	
	 
	 	 if (arg(0) == 'admin' && arg(2) == 'features' && arg(4) == 'recreate') {
	 unset($vars['admin_left']);
	 }
	 
	 	 	 if (arg(0) == 'admin' && arg(2) == 'features' && arg(3) && !arg(4)) {
	 unset($vars['admin_left']);
	 }

	 

  global $user;
  if ($user->uid) {
    $links[] = '<a href="'. url('user') .'" class="user-name">'. $user->name .'</a>';
    $links[] = '<a href="'. url('logout') .'">'. t('Logout') .'</a>';
    $links = implode(' | ', $links);

    $vars['administrator_user_links'] = $links;
  }
  





	 unset($vars['admin_right']);   
	   
$body_classes = array($vars['body_classes']);

        
			             if (arg(3)) {
    $body_classes[] = administrator_id_safe(arg(3)); 
  }
  
  			             if (arg(4)) {
    $body_classes[] = administrator_id_safe(arg(4)); 
  }
  
    			             if (arg(0) == 'admin' && arg(1) == NULL) {
    $body_classes[] = 'admin-dashboard'; 
  }
		
	   if ((arg(0) == 'admin' && arg(2)) || theme('blocks', 'admin_left')) { 
	   $vars['content_class'] = 'left-sidebar';
	   }else{
	   $vars['content_class'] = 'no-left-sidebar';
	   unset($vars['admin_left']);
	   }
	   
	             if (!$vars['hide_header']) {
    $body_classes[] = 'header-on';
  }
	   
  if (arg(0) == 'admin' && arg(1)) {
   $body_classes[] = administrator_id_safe('page-'. arg(0).'-'.arg(1).'-'.arg(2) );  
 }
  if ($vars['admin_left'] && !$vars['admin_right']) {
    $body_classes[] = 'sidebar-left';
  }
  if (!$vars['admin_left'] && $vars['admin_right']) {
    $body_classes[] = 'sidebar-right';
  }

  if (user_access('administer blocks')) {
	  $body_classes[] = 'admin';
	}

  if (!empty($vars['primary_links']) or !empty($vars['secondary_links'])) {
    $body_classes[] = 'with-navigation';
  }
  if (!empty($vars['secondary_links'])) {
    $body_classes[] = 'with-secondary';
  }
  
    $body_classes[] = ($vars['language']->language) ? ''. $vars['language']->language : '';
	
	if (arg(0) && arg(1) && is_numeric(arg(2))) {
	$body_classes[] = 'path-'.arg(0).'-'.arg(1);
    }


  $vars['body_classes'] = implode(' ', $body_classes);
  
  }
  
  if ($hook == 'block') {
    $block = $vars['block'];
    $classes = array('block');
    $classes[] = administrator_id_safe('block-' . $vars['block']->module);
    $classes[] = administrator_id_safe('block-' . $vars['block']->region);
    $classes[] = administrator_id_safe('block-id-' . $vars['block']->bid);
    $classes[] = 'clearfix';
    $classes[] = $vars['block']->extraclass;   
    $vars['block_classes'] = implode(' ', $classes);      
   if ($vars['block']->region == 'dashboard_top' && theme_get_setting('administrator_dashboard_tabs') == 'tabs') {
    $vars['template_files'][] = 'block-tabs';
	}	
}		
	
   $vars['scripts'] = drupal_get_js();
   $vars['styles'] = drupal_get_css();	
	
}


function administrator_admin_block_content($content) {
  if (!$content) {
    return '';
  }

  if (system_admin_compact_mode()) {

   $counter = 1;
   $output = '<ul class="admin-menu-compact">';
    foreach ($content as $item) {
      $additional_class = $counter % 4 == 0 ? ' last' : '';
      $item['localized_options']['html'] = TRUE;

      $output .= '<li class="leaf'. $additional_class .'">'. $link .'</li>';
      $counter++;
    }
    $output .= '</ul>';
  }
  else {
    $output = '<dl class="admin-list">';
    foreach ($content as $item) {
      $output .= '<dt>'. l($item['title'], $item['href'], $item['localized_options']) .'</dt>';
      $output .= '<dd>'. $item['description'] .'</dd>';
    }
    $output .= '</dl>';
  }

  return $output;
}

function administrator_menu_local_tasks() {
  return menu_primary_local_tasks();
}

function administrator_filter_xss($string) {
  return filter_xss($string);
}

function administrator_settings_init($theme) {
  $themes = list_themes();
  $defaults = (is_array($themes[$theme]->info['settings'])) ? $themes[$theme]->info['settings'] : array();
  $settings = theme_get_settings($theme);
  if (module_exists('node')) {
    foreach (node_get_types() as $type => $name) {
      unset($settings['toggle_node_info_'. $type]);
    }
  }

  variable_set(
    str_replace('/', '_', 'theme_'. $theme .'_settings'),
    array_merge($defaults, $settings)
  );
  theme_get_setting('', TRUE);
}

if (arg(0) == 'admin' && arg(2) == 'themes' && arg(4)) {
  global $theme_key;
  administrator_settings_init($theme_key);
}

function administrator_get_page_classes($path = NULL) {
  if (!isset($path)) $path = $_GET['q'];
  if ($path) {
    $path = ' '. administrator_id_safe($path);
  }
  return $path;
}

function administrator_id_safe($string) {
  return check_plain(strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string)));
}

function administrator_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. str_replace(t('Administer'), t('Dashboard'), implode(' » ', $breadcrumb)) .'</div>';
  }
}

function _administrator_links($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = $key;
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }

      $check_path = $_GET['q'];
      $check_path = explode("/", $check_path);
      $q_path = $check_path[0] .'/'. $check_path[1] .'/'. $check_path[2];
      if (isset($link['href']) && ($link['href'] == $q_path || ($link['href'] == '<front>' && drupal_is_front_page()))) {
        $class .= ' active';
      }
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';

      if (isset($link['href'])) {
        $output .= l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

function administrator_menu_item_link($link) {
  if ($link['href'] == 'admin') {
    $link['title'] = t('Dashboard');
  } 
  
    if ($link['href'] == 'admin/content/nodequeue/add/nodequeue') {
    $link['title'] = t('Add');
  } 

  return theme_menu_item_link($link);
}

function _administrator_countmatches($arrayone, $arraytwo) {
  $matches = 0;
  foreach ($arraytwo as $i => $part) {
    if (!isset($arrayone[$i])) break;
    if ($arrayone[$i] == $part) $matches = $i+1;
  }
  return $matches;
}

function administrator_system_settings_form($form) {
  $themes = list_themes();
  $enabled_theme = arg(4);
  if ($form['#id'] == 'system-theme-settings' AND ($enabled_theme == 'administrator' || $themes[$enabled_theme]->base_theme == 'administrator')) {

    foreach ($form['theme_specific']['rows'] as $rid => $row) {
      if (intval($rid)) {
        $this_row = $row['data']['#value'];
        $weight = $form['theme_specific']['rows'][$rid]['role-weight-'. $rid]['#value'];
        $this_row[] = drupal_render($form['theme_specific']['navigation']['nav-by-role']['administrator_navigation_source_'. $rid]);
        $this_row[] = drupal_render($form['theme_specific']['rows'][$rid]['role-weight-'. $rid]);
        $table_rows[$weight] = array('data' => $this_row, 'class' => 'draggable');
      }
    }
    ksort($table_rows);

    $header = array(
      "Role", "Navigation menu", "Order"
    );

    $form['theme_specific']['navigation']['role-weights']['content']['#value'] = theme('table', $header, $table_rows, array('id' => 'administrator-settings-table'));
    $output = drupal_render($form);

    drupal_add_tabledrag('administrator-settings-table', 'order', 'sibling', 'weight');
  }
  else {
    $output = drupal_render($form);
  }
  return $output;
}

function administrator_theme() {
  return array(
    'system_settings_form' => array(
      'arguments' => array('form' => NULL),
    ),
    'admin_navigation' => array(
      'arguments' => array('items' => NULL, 'class' => NULL),
    ),
  );
}

function _administrator_init_role_menu() {
  global $theme_key;
  global $user;
  $i = 100;
  $settings = theme_get_settings($theme_key);
  $menu = array();

  $roles = user_roles(FALSE);

  foreach ($user->roles as $rid => $role) {
    if (!$weight = $settings['role-weight-'. $rid]) {
      $settings['role-weight-'. $rid] = $i++;
    }
    $menu[$settings['role-weight-'. $rid]] = $rid;
  }
  ksort($menu);
  return $menu[key($menu)];
}

function administrator_uc_admin_dashboard($type, $menus) {
  if ($type == 1) {
  drupal_add_js(drupal_get_path('module', 'uc_store') .'/uc_store.js', 'module');
  drupal_add_js(array('ucTextShow' => t('- Show links -'), 'ucTextHide' => t('- Hide links -')), 'setting');
  }  
  $output = '<div class="uc-store-admin-table">';
  $panel = 0;
  if (is_array($menus)) {
    foreach ($menus as $menu) {
      $panel++;
      $panel_title = $menu['title'];
      if ($type == 3) {
      $panel_links = '';
      } else {
      $panel_links = theme('admin_block_content', system_admin_menu_block(menu_get_item($menu['href'])));
      }
	  
	  if ($menu['href'] == 'admin/store/order_management') {
	  $menu['href'] = 'admin/store/orders/all-orders';
	  }
	  
	  
	  $href = $menu['href'];	  
	  list($img_name, ) = explode('/', $href, 0);
      $img_name = administrator_id_safe($img_name);
      $img_path = path_to_theme() . '/images/admin-dashboard/' . $img_name . '.png';
      if (file_exists($img_path)) {
	  $dash_img = '<div class="dashboard-img">'.theme_image($img_path, $panel_title, $panel_title, FALSE, FALSE).'</div>';
	  } else {
	  $dash_img = '';
	  }  
      $panel_links = theme('admin_block_content', system_admin_menu_block(menu_get_item($menu['href'])));
      $panel_table = $dash_img;
	  $panel_table .= '<div class="panel-wrap">';
	  $panel_table .= '<div class="panel-title">'. l($menu['title'], $menu['href']) .'</div>';	  
      if (strlen($panel_links) > 0) {
	  if ($type == 1) {
      $disp = 'display: none;';
      }
      $panel_table .= '<div class="panel-links" style="'. $disp .'">'. $panel_links .'</div>';
	  if ($type == 1) {
      $panel_table .= '<div class="panel-show-link" id="show-links-'. $panel .'"><a>'. t('- Show links -') .'</a></div>';
      }
      }
	  $panel_table .= '</div>';
      $output .= '<div class="uc-store-admin-panel" id="panel-'. $panel .'">'. $panel_table .'</div>';
    }
  }
  $output .= '</div>';
  return $output;
}

function administrator_blocks($region) {
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


function administrator_summary_overview($summaries, $link = TRUE) {

  $output = '';

  foreach ($summaries as $summary) {
    $output .= '<div class="summary-overview summary-overview-item">';
	  $href = $summary['href'];	  
	  list($img_name) = explode('/', $href, 0);
      $img_name = administrator_id_safe($img_name);
      $img_path = path_to_theme() . '/images/admin-summary/' . $img_name . '.png';
      if (file_exists($img_path)) {
	  $output .= '<div class="summary-icon">'.theme_image($img_path, $summary['title'], $summary['title'], FALSE, FALSE).'</div>';
	  } else {
	  $img_path = path_to_theme() . '/images/admin-summary/summary_default.png';
	  $output .= '<div class="summary-icon">'.theme_image($img_path, $summary['title'], $summary['title'], FALSE, FALSE).'</div>';
	  }  
    $output .= '<div class="summary-content"><span class="summary-title">' . check_plain($summary['title']) .': </span>';

    $output .= ' <span class="summary-link">' . l(t('edit'), $summary['href']) . '</span>';

    $output .= theme('item_list', $summary['items']);
    $output .= '</div>';
    $output .= '</div>';
  }

  return $output;
}


// Вывод блоков в скользящую панель из системного меню "Навигация"
function admin_menu_blocks() {
  $menu_name = 'navigation'; // Название меню
  $tree = menu_tree_all_data($menu_name, NULL);
  $menu_url = array('admin/content', 'admin/build', 'admin/settings', 'admin/user', 'admin/reports',); // Список путей ссылок родительских пунктов меню, по которым мы достаём нужные нам группы ссылок.
  $admin_blocks = array();
   foreach ($tree as $admin) {   
     if (!empty($admin['below']) && $admin['link']['link_path'] == 'admin') {
       foreach ($admin['below'] as $children) {
         if (in_array($children['link']['link_path'], $menu_url)) {
	       $output = array();
             foreach ($children as $link_item) {			 
                 foreach ($link_item as $item) { 
		           if (is_array($item['link'])) {				   
				     $path = explode('/', $item['link']['link_path']);				   
				        if (count($path) <= 3) {
                            $output[] = l($item['link']['title'], $item['link']['link_path']);
                        }					  
		           }
                 }
               }
			 $class = str_replace ('/', '-', $children['link']['link_path']);  
             $admin_blocks[] = '<div class="admin-menu-block admin-block' . count($admin_blocks) . '">' . theme_item_list($output, $children['link']['title'], 'ul', array('class' => $class. ' menu-content')) . '</div>';
        }
      }
    }
  }   
   return '<div class="admin-menu-blocks">' . theme_item_list($admin_blocks, NULL, 'ul', NULL) . '</div>';
}    