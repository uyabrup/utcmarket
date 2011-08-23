<?php

/**
 * Здесь мы создадим нужные очереди
 *
 */
function openstore_config_nodequeues() { 
 $queue_data = array(
    'queue1' => array(
      'title' => t(OPENSTORE_QUEUE_LARGE_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to large carousel'),
      'link_remove' => t('Remove from large carousel'),
      'roles' => array (OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),
      'types' => array (0 => OPENSTORE_CONTENT_BANNER_NAME, 1 => OPENSTORE_CONTENT_PAGE_NAME),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_LARGE_NAME),),
    ),
	
	  'queue2' => array(
      'title' => t(OPENSTORE_QUEUE_FEATURED_NAME),
      'subqueue_title' => '',
      'size' => '8',
      'reverse' => 0,
      'link' => t('Add to featured'),
      'link_remove' => t('Remove from featured'),
      'roles' => array (OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),
      'types' => array (0 => OPENSTORE_CONTENT_PRODUCT_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_FEATURED_NAME),),
    ),
	
	  'queue3' => array(
      'title' => t(OPENSTORE_QUEUE_SEO_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to SEO article'),
      'link_remove' => t('Remove from SEO article'),
      'roles' => array (),
      'types' => array (0 => OPENSTORE_CONTENT_PAGE_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_SEO_NAME),),
    ),
	
	  'queue4' => array(
      'title' => t(OPENSTORE_QUEUE_ARTICLE_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to category'),
      'link_remove' => t('Remove from category'),
      'roles' => array (),
      'types' => array (0 => OPENSTORE_CONTENT_PAGE_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_ARTICLE_NAME),),
    ),
	
	  'queue5' => array(
      'title' => t(OPENSTORE_QUEUE_BANNER_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to category banner'),
      'link_remove' => t('Remove from category banner'),
      'roles' => array (),
      'types' => array (0 => OPENSTORE_CONTENT_BANNER_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_BANNER_NAME),),
    ),
	
	  'queue6' => array(
      'title' => t(OPENSTORE_QUEUE_HOT_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to hot offers'),
      'link_remove' => t('Remove from hot offers'),
      'roles' => array (OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),
      'types' => array (0 => OPENSTORE_CONTENT_BANNER_NAME, 1 => OPENSTORE_CONTENT_PAGE_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_HOT_NAME),),
    ),
	
	  'queue7' => array(
      'title' => t(OPENSTORE_QUEUE_NEWS_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to store news'),
      'link_remove' => t('Remove from store news'),
      'roles' => array (OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),
      'types' => array (0 => OPENSTORE_CONTENT_SIMPLENEWS_NAME, 1 => OPENSTORE_CONTENT_PAGE_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_NEWS_NAME),),
    ),
	
	  'queue8' => array(
      'title' => t(OPENSTORE_QUEUE_POLL_NAME),
      'subqueue_title' => '',
      'size' => '0',
      'reverse' => 0,
      'link' => t('Add to poll block'),
      'link_remove' => t('Remove from poll block'),
      'roles' => array (),
      'types' => array (0 => OPENSTORE_CONTENT_POLL_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_POLL_NAME),),
    ),
	
	 'queue9' => array(
      'title' => t(OPENSTORE_QUEUE_REVIEW_NAME),
      'subqueue_title' => '',
      'size' => '4',
      'reverse' => 0,
      'link' => t('Add to customer reviews'),
      'link_remove' => t('Remove from customer reviews'),
      'roles' => array (OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER,),
      'types' => array (OPENSTORE_CONTENT_PRODUCT_NAME,),
      'i18n' => 0,
      'op' => 'Submit',
      'submit' => 'Submit',
      'owner' => 'nodequeue',
      'show_in_links' => true,
      'show_in_tab' => true,
      'show_in_ui' => true,
      'reference' => 0,
      'subqueues' => array (),
      'new' => true,
      'add_subqueue' => array (0 => t(OPENSTORE_QUEUE_REVIEW_NAME),),
    ),	
  );
  
   // Перебираем очереди в массиве выше и сохраняем их в БД
   foreach ($queue_data as $q) { 
    $queue = (object) $q;
    nodequeue_save($queue);	
   }
	
	// Убеждаемся, что созданные очереди имеют нужные нам ID, которые используют виды.
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_LARGE_ID, OPENSTORE_QUEUE_LARGE_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_FEATURED_ID, OPENSTORE_QUEUE_FEATURED_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_SEO_ID, OPENSTORE_QUEUE_SEO_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_ARTICLE_ID, OPENSTORE_QUEUE_ARTICLE_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_BANNER_ID, OPENSTORE_QUEUE_BANNER_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_HOT_ID, OPENSTORE_QUEUE_HOT_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_NEWS_ID, OPENSTORE_QUEUE_NEWS_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_POLL_ID, OPENSTORE_QUEUE_POLL_NAME);
	db_query("UPDATE {nodequeue_queue} SET qid = %d WHERE title = '%s'", OPENSTORE_QUEUE_REVIEW_ID, OPENSTORE_QUEUE_REVIEW_NAME);	
   }