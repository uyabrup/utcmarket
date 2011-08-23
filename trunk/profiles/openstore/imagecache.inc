<?php

function openstore_config_imagecache() {
 $presets = array(
    
	// Обновляем существующие пресеты, которые предоставил Ubercart
	array(
      'presetname' => 'product',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 300, 'height' => ''),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_300_300.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',	  
        ),
		*/
      ),
    ),
    array(
      'presetname' => 'uc_thumbnail',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 55, 'height' => 55, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center','ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_60_60.gif','dimensions' => 'background'),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),
    array(
      'presetname' => 'product_full',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 600, 'height' => 600, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
      ),
    ),
    array(
      'presetname' => 'product_list',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 100, 'height' => 100, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => '100', 'alpha' => 100, 'path' => 'actions/pad_100_100.jpg','dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),
    array(
      'presetname' => 'uc_category',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 100, 'height' => 100, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_100_100.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),
	array(
      'presetname' => 'cart',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 50, 'height' => 50, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_60_60.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),
	
	// Добавляем новые пресеты
	array(
      'presetname' => 'category_banner',
      'actions' => array(),
    ),
	array(
      'presetname' => 'hot_offer',
      'actions' => array(
        array(
          'action' => 'imagecache_crop',
          'data' => array('width' => 180, 'height' => 90, 'xoffset' => 'center', 'yoffset' => 'center',),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
      ),
    ),	
	array(
      'presetname' => 'pager',
      'actions' => array(
        array(
          'action' => 'imagecache_resize',
          'data' => array('width' => 60, 'height' => 60,),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
      ),
    ),	
	array(
      'presetname' => 'product_adjusted',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 400, 'height' => 400, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_400_400.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),		
	array(
      'presetname' => 'product_list_promo',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 100, 'height' => 100, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_100_100.jpg', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		array(
          'action' => 'canvasactions_file2canvas',
          'data' => array('xpos' => 'top', 'ypos' => 'lef', 'alpha' => 100, 'path' => 'actions/sale_promotion.png',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),	
    array(
      'presetname' => 'product_kit',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 300, 'height' => 300, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_300_300.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ),
	array(
      'presetname' => 'product_kit_main',
      'actions' => array(
        array(
          'action' => 'imagecache_scale',
          'data' => array('width' => 400, 'height' => 400, 'upscale' => 0),
          'weight' => 0,
          'module' => 'imagecache',       
        ),
		/*
		array(
          'action' => 'canvasactions_canvas2file',
          'data' => array('xpos' => 'center', 'ypos' => 'center', 'alpha' => 100, 'path' => 'actions/pad_400_400.gif', 'dimensions' => 'background',),
          'weight' => 1,
          'module' => 'imagecache_canvasactions',		  
        ),
		*/
      ),
    ), 
  );
   
	// Сохраняем пресеты в БД
    foreach ($presets as $preset) {
    drupal_write_record('imagecache_preset', $preset);
    foreach ($preset['actions'] as $action) {
      $action['presetid'] = $preset['presetid'];
      drupal_write_record('imagecache_action', $action);
    }
  }
  
  //На всякий случай очищаем пресеты
  imagecache_presets(true);
}
 