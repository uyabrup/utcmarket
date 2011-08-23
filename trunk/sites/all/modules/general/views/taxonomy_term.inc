<?php 

$view = new view;
$view->name = 'taxonomy_term';
$view->description = 'Отображает дерево терминов (категорий), имитируя стандартную системную структуру вида taxonomy/term/term_id';
$view->tag = 'default';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'field_image_cache_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'product_list_linked',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '1',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_cache_fid',
    'table' => 'node_data_field_image_cache',
    'field' => 'field_image_cache_fid',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'teaser' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 1,
      'max_length' => '300',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 1,
      'strip_tags' => 1,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'teaser',
    'table' => 'node_revisions',
    'field' => 'teaser',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'sell_price' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 1,
    'set_precision' => 0,
    'precision' => '0',
    'decimal' => '.',
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'format' => 'uc_price',
    'revision' => 'themed',
    'exclude' => 0,
    'id' => 'sell_price',
    'table' => 'uc_products',
    'field' => 'sell_price',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'field_discount_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 1,
      'text' => 'Скидка [field_discount_value]%',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'computed_value',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_discount_value',
    'table' => 'node_data_field_discount',
    'field' => 'field_discount_value',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'totalcount' => array(
    'order' => 'ASC',
    'id' => 'totalcount',
    'table' => 'node_counter',
    'field' => 'totalcount',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'term_node_tid_depth' => array(
    'id' => 'term_node_tid_depth',
    'table' => 'node',
    'field' => 'term_node_tid_depth',
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => TRUE,
      'override' => FALSE,
      'items_per_page' => 25,
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '%1',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'taxonomy_term',
    'validate_fail' => 'not found',
    'depth' => '0',
    'break_phrase' => 1,
    'relationship' => 'none',
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'album' => 0,
      'artist' => 0,
      'book' => 0,
      'page' => 0,
      'story' => 0,
      'track' => 0,
    ),
    'validate_argument_vocabulary' => array(
      '3' => 0,
      '4' => 0,
      '1' => 0,
      '5' => 0,
      '2' => 0,
    ),
    'validate_argument_type' => 'tids',
    'validate_argument_php' => '',
  ),
  'term_node_tid_depth_modifier' => array(
    'id' => 'term_node_tid_depth_modifier',
    'table' => 'node',
    'field' => 'term_node_tid_depth_modifier',
    'default_action' => 'ignore',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => TRUE,
      'override' => FALSE,
      'items_per_page' => 25,
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
  ),
));
$handler->override_option('filters', array(
  'status_extra' => array(
    'id' => 'status_extra',
    'table' => 'node',
    'field' => 'status_extra',
    'operator' => '=',
    'value' => '',
    'group' => 0,
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
  'role' => array(),
  'perm' => '',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('use_pager', '1');
$handler->override_option('row_options', array(
  'inline' => array(),
  'separator' => '',
  'hide_empty' => 1,
));
$handler = $view->new_display('page', 'Страница таксономии', 'page');
$handler->override_option('fields', array(
  'field_image_cache_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'product_list_linked',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '1',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_cache_fid',
    'table' => 'node_data_field_image_cache',
    'field' => 'field_image_cache_fid',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'teaser' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 1,
      'max_length' => '300',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 1,
      'strip_tags' => 1,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'teaser',
    'table' => 'node_revisions',
    'field' => 'teaser',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
  'sell_price' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 1,
      'text' => 'Цена [sell_price]',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 1,
    'set_precision' => 0,
    'precision' => '0',
    'decimal' => '.',
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'format' => 'uc_price',
    'revision' => 'themed',
    'exclude' => 0,
    'id' => 'sell_price',
    'table' => 'uc_products',
    'field' => 'sell_price',
    'override' => array(
      'button' => 'Использовать установки по умолчанию',
    ),
    'relationship' => 'none',
  ),
  'field_discount_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 1,
      'text' => 'Скидка [field_discount_value]%',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'computed_value',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_discount_value',
    'table' => 'node_data_field_discount',
    'field' => 'field_discount_value',
    'override' => array(
      'button' => 'Переписать',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'override' => array(
      'button' => 'Использовать установки по умолчанию',
    ),
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'not in',
    'value' => array(
      'banner' => 'banner',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Использовать установки по умолчанию',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('style_options', array(
  'grouping' => '',
));
$handler->override_option('path', 'taxonomy/term/%');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('feed', 'Системный RSS фид', 'feed');
$handler->override_option('items_per_page', 15);
$handler->override_option('style_plugin', 'rss');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
));
$handler->override_option('row_plugin', 'node_rss');
$handler->override_option('row_options', array(
  'item_length' => 'default',
));
$handler->override_option('path', 'taxonomy/term/%/%/feed');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('displays', array(
  'page' => 'page',
  'default' => 0,
));
$handler->override_option('sitename_title', FALSE);
$handler = $view->new_display('feed', 'Пользовательский фид', 'feed_1');
$handler->override_option('items_per_page', 15);
$handler->override_option('style_plugin', 'rss');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
));
$handler->override_option('row_plugin', 'node_rss');
$handler->override_option('row_options', array(
  'item_length' => 'default',
));
$handler->override_option('path', 'taxonomy/term/%/feed');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('displays', array());
$handler->override_option('sitename_title', FALSE);

$views['taxonomy_term'] = $view;
