<?php

function general_block($op = 'list', $delta = 0, $edit = array()) {

  $block = array();
  $items_contacts = array();
  $items_location = array();

  if (variable_get('uc_store_name', FALSE)) {
    $items_contacts[] = t('Store name:') . '&nbsp;' . variable_get('uc_store_name', FALSE);
  }

  if (variable_get('uc_store_owner', FALSE)) {
    $items_contacts[] = t('Store owner:') . '&nbsp;' . variable_get('uc_store_owner', FALSE);
  }

  if (variable_get('uc_store_email', FALSE)) {
    $items_contacts[] = t('Store e-mail:') . '&nbsp;' . variable_get('uc_store_email', FALSE);
  }

  if (variable_get('uc_store_phone', FALSE)) {
    $items_contacts[] = t('Store phone:') . '&nbsp;' . variable_get('uc_store_phone', FALSE);
  }

  if (variable_get('uc_store_fax', FALSE)) {
    $items_contacts[] = t('Store fax:') . '&nbsp;' . variable_get('uc_store_fax', FALSE);
  }

  if (variable_get('uc_store_city', FALSE)) {
    $items_contacts[] = t('Store city:') . '&nbsp;' . variable_get('uc_store_city', FALSE);
  }

  if (variable_get('uc_store_street1', FALSE)) {
    $items_contacts[] = t('Store street 1:') . '&nbsp;' . variable_get('uc_store_street1', FALSE);
  }

  if (variable_get('uc_store_postal_code', FALSE)) {
    $items_contacts[] = t('Store postal code:') . '&nbsp;' . variable_get('uc_store_postal_code', FALSE);
  }

  if (variable_get('uc_store_yandex_map', FALSE)) {
    $items_location[] = l(t('See us on Yandex Map'), variable_get('uc_store_yandex_map', FALSE), array(
      'attributes' => array(
        'target' => '_blank',
        'rel' => 'nofollow',
      ),
    ));
  }

  if (variable_get('uc_store_google_map', FALSE)) {
    $items_location[] = l(t('See us on Google Map'), variable_get('uc_store_google_map', FALSE), array(
      'attributes' => array(
        'target' => '_blank',
        'rel' => 'nofollow',
      ),
    ));

  }


  $items_download = array();
  $items_download[] = '<div class="download-link download-xls">' . l(t('Download .XLS price'), 'export-xls/all', array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .XLS price for all products')))) . '</div>';
  $items_download[] = '<div class="download-link download-doc">' . l(t('Download .DOC price'), 'export-doc/all', array('attributes' => array('rel' => 'nofollow', 'title' => t('Download .DOC price for all products')))) . '</div>';

 


     $menu_name = 'navigation';
     $tree = menu_tree_all_data($menu_name, NULL);
     $parent_url = 'node/add';
     $node_add_link = array();
     $node_add_block = array();
       foreach ($tree as $chunk) {   
        if ($chunk['link']['link_path'] == $parent_url) {     
          foreach($chunk['below'] as $item) {  
          $node_add_link[] = l($item['link']['title'], $item['link']['link_path']);  
          }
        }
      }
    
	$node_add_menu = '<div class="node-add-menu">' . theme_item_list($node_add_link, NULL, 'ul', NULL) . '</div>'; 
  

 
 if ($op == 'list') {

      $block[0] = array('info' => t('Store contacts'),);      
      $block[1] = array('info' => t('Download price'),);      
      $block[2] = array('info' => t('Users'),);      
      $block[3] = array('info' => t('Nodes'),);      
      $block[4] = array('info' => t('Watchdog'),);      
      $block[5] = array('info' => t('Systems charts'));
      $block[6] = array('info' => t('Add content'));	  

  }

 if ($op == 'view') {

   if ($delta == 0) {
          $block['subject'] = t('Store contacts');
          $block['content'] = theme_item_list($items_contacts, NULL, 'ul', array('class' => 'store-contact')) .
		                      theme_item_list($items_location, NULL, 'ul', array('class' => 'store-location')); // Блок 1 контент
   }
   
  
   if ($delta == 1) {       
          $block['subject'] = t('Download price');
          $block['content'] = theme_item_list($items_download, NULL, 'ul', array('class' => 'download-links')); // Блок 2 контент
    } 
   
   if (module_exists('chart')) {
    
	if ($delta == 2) {         
          $block['subject'] = t('Users'); 
          $block['content'] = '<div id="system-charts">' . sys_charts_display($page = 'users') . '</div>'; 
    }
          
   if ($delta == 3) {         
          $block['subject'] = t('Nodes'); 
          $block['content'] = '<div id="system-charts">' . sys_charts_display($page = 'nodes') . '</div>';                
    }
       
   if ($delta == 4) {       
          $block['subject'] = t('Watchdog'); 
          $block['content'] = '<div id="system-charts">' . sys_charts_display($page = 'watchdog') . '</div>';      
    }
 
   if ($delta == 5) { 	
		$block['subject'] = t('Systems charts');	
        $block['content'] .= '<div id="system-charts-wrapper">';
		if (arg(0) == 'admin' && !arg(1)){
		if (fsockopen("www.google.com", 80)) {		
		$block['content'] .= '<div class="chart-section-1">';
		$block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'watchdog_count') . '</div>';
		$block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'watchdog_message') . '</div>';
		$block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'nodes_activity') . '</div>';
		$block['content'] .= '</div>';
		$block['content'] .= '<br style="clear:both;">';
		$block['content'] .= '<div class="chart-section-2">';
        $block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'users') . '</div>'; 
        $block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'nodes_counts_published') . '</div>';
        $block['content'] .= '<div class="system-charts">' . sys_charts_display($page = 'nodes_counts_unpublished') . '</div>';		
		$block['content'] .= '</div>';
		} else {		
	    $block['content'] .= '<div class="no-charts">' . t('No connection to internet. Charts are not available.') . '</div>';
		}
      }		
		$block['content'] .= '</div>';   
     }
   
   if ($delta == 6) { 
        $block['subject'] = t('Add content');
        $block['content'] = $node_add_menu;     
     }     
   } 
 }
  
  return $block;

}
