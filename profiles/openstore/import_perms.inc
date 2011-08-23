 <?php

/* 
 *   Массив с правами пользователей
 */
function openstore_import_permissions() {
  $permissions = array();

  $permissions[] = array(
    'name' => 'access admin theme',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),
     );
     
  $permissions[] = array(
    'name' => 'view advanced help index',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER, OPENSTORE_ROLE_AFFILIATE),
     );
     
  $permissions[] = array(
    'name' => 'view advanced help popup',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER, OPENSTORE_ROLE_AFFILIATE),
     );
     
  $permissions[] = array(
    'name' => 'view advanced help topic',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER, OPENSTORE_ROLE_AFFILIATE),
    );
    
  $permissions[] = array(
    'name' => 'access backup and migrate',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),
    );
    
  $permissions[] = array(
    'name' => 'access backup files',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),
    );
    
  $permissions[] = array(
    'name' => 'perform backup',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),    
    );
    
  $permissions[] = array(
    'name' => 'access ckeditor',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
    );
    
  $permissions[] = array(
    'name' => 'access ckeditor link',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
    );
    
  $permissions[] = array(
    'name' => 'access comments',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'administer comments',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),    
    );
    
  $permissions[] = array(
    'name' => 'post comments',
    'roles' => array('authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'post comments without approval',
    'roles' => array('authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'access site-wide contact form',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'rate content',
    'roles' => array('authenticated user'),    
  );
    
  $permissions[] = array(
    'name' => 'view imagecache cart',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache category_banner',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache hot_offer',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache pager',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache product',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache product_adjusted',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache product_full',
    'roles' => array('anonymous user', 'authenticated user'),    
  );
    
  $permissions[] = array(
    'name' => 'view imagecache product_kit',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache product_list',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache product_list_promo',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache uc_category',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'view imagecache uc_thumbnail',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'translate interface',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'access content',
    'roles' => array('anonymous user', 'authenticated user'),    
  );
    
  $permissions[] = array(
    'name' => 'administer content types',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'administer nodes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'create banner content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'create page content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'create simplenews content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'delete any banner content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'delete any page content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'delete any simplenews content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'delete own banner content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'delete own page content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'delete own simplenews content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'delete revisions',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'edit any banner content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'edit any page content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'edit any simplenews content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'edit own banner content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'edit own page content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'edit own simplenews content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'revert revisions',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'view revisions',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'manipulate all queues',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'manipulate queues',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'create url aliases',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'notify of path changes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'cancel own vote',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'create poll content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );
   
  $permissions[] = array(
    'name' => 'delete any poll content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'delete own poll content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),    
   );
    
  $permissions[] = array(
    'name' => 'edit any poll content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'edit own poll content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );   
   
  $permissions[] = array(
    'name' => 'inspect all votes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),    
   );
    
  $permissions[] = array(
    'name' => 'vote on polls',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'access service links',
    'roles' => array('anonymous user', 'authenticated user'),    
   );
    
  $permissions[] = array(
    'name' => 'administer newsletters',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 
   
  $permissions[] = array(
    'name' => 'administer simplenews subscriptions',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );       
   
  $permissions[] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array('anonymous user', 'authenticated user'),        
   );    
        
  $permissions[] = array(
    'name' => 'access administration pages',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'access site reports',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'select different theme',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'administer taxonomy',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'translate content',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'add/edit addresses',
    'roles' => array('authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'view all addresses',
    'roles' => array('authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'view default addresses',
    'roles' => array('authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'act as affiliate',
    'roles' => array(OPENSTORE_ROLE_AFFILIATE),        
   ); 

  $permissions[] = array(
    'name' => 'adjust user commissions',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'administer affiliates',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'administer attributes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'administer product attributes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'administer product options',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'administer cart links',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'view cart links report',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'view catalog',
    'roles' => array('anonymous user', 'authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'download file',
    'roles' => array('authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'view all downloads',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'administer order workflow',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'create orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'delete orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'edit orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'unconditionally delete orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'view all orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 

  $permissions[] = array(
    'name' => 'view own orders',
    'roles' => array('authenticated user'),        
   ); 

  $permissions[] = array(
    'name' => 'delete payments',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   ); 

  $permissions[] = array(
    'name' => 'manual payments',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   ); 
   
  $permissions[] = array(
    'name' => 'view payments',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer product classes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   );    
   
  $permissions[] = array(
    'name' => 'administer product features',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'create products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'delete all products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   );    
   
  $permissions[] = array(
    'name' => 'delete own products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'edit all products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   );    
   
  $permissions[] = array(
    'name' => 'edit own products',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer product kits',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'create product kits',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'edit all product kits',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'edit own product kits',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER, OPENSTORE_ROLE_CONTENTMANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer product power tools settings',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   );    
   
  $permissions[] = array(
    'name' => 'configure quotes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'view reports',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'view all role expirations',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'fulfill orders',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer product stock',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'import stock and price data',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer store',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR),        
   );    
   
  $permissions[] = array(
    'name' => 'view customers',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'view store reports',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'configure taxes',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );   
   
  $permissions[] = array(
    'name' => 'access user profiles',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'administer users',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'change own username',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );   
   
  $permissions[] = array(
    'name' => 'administer userpoints',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );    
   
  $permissions[] = array(
    'name' => 'view own userpoints',
    'roles' => array('authenticated user'),        
   );    
   
  $permissions[] = array(
    'name' => 'view userpoints',
    'roles' => array(OPENSTORE_ROLE_DIRECTOR, OPENSTORE_ROLE_MANAGER),        
   );   
   
  return $permissions;
}