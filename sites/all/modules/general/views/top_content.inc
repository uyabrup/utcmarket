<?php 

$view = new view;
$view->name = 'top_content';
$view->description = 'Самые рейтинговые товары.';
$view->tag = 'votingapi';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'votingapi_cache' => array(
    'id' => 'votingapi_cache',
    'table' => 'node',
    'field' => 'votingapi_cache',
  ),
));
$handler->override_option('fields', array(
  'name' => array(
    'label' => 'Author',
    'link_to_user' => 1,
    'exclude' => 0,
    'id' => 'name',
    'table' => 'users',
    'field' => 'name',
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => 'Title',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'created' => array(
    'label' => 'Posted',
    'date_format' => 'time ago',
    'custom_date_format' => '1',
    'exclude' => 0,
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'value' => array(
    'id' => 'value',
    'table' => 'votingapi_cache',
    'field' => 'value',
    'relationship' => 'votingapi_cache',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => 1,
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'product' => 'product',
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
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'value' => array(
    'operator' => '>',
    'value' => array(
      'value' => '0',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'value',
    'table' => 'votingapi_cache',
    'field' => 'value',
    'relationship' => 'votingapi_cache',
    'override' => array(
      'button' => 'Override',
    ),
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Блок с самыми рейтинговыми товарами');
$handler->override_option('empty', 'Нет содержимого.');
$handler->override_option('empty_format', '1');
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 1,
  'order' => 'desc',
  'columns' => array(
    'name' => 'name',
    'title' => 'title',
    'created' => 'created',
  ),
  'info' => array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'title',
));
$handler = $view->new_display('page', 'Страница с самыми рейтинговыми товарами', 'page_1');
$handler->override_option('relationships', array(
  'votingapi_vote' => array(
    'label' => '',
    'required' => 0,
    'votingapi' => array(
      'value_type' => 'percent',
      'tag' => '',
    ),
    'current_user' => 0,
    'id' => 'votingapi_vote',
    'table' => 'node',
    'field' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
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
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
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
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => 'Title',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
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
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
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
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'value' => array(
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
    'set_precision' => 0,
    'precision' => '0',
    'decimal' => '.',
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'appearance' => 'fivestar_views_value_display_handler',
    'exclude' => 0,
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('sorts', array(
  'value' => array(
    'order' => 'DESC',
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => 1,
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'product' => 'product',
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
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'value' => array(
    'operator' => '>',
    'value' => array(
      'value' => '0',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('header', 'Эта страница демонстрирует интеграцию модуля "API голосования" с модулем "Виды". ДЖокументы отсортированы по процентному рейтингу.');
$handler->override_option('header_format', '1');
$handler->override_option('header_empty', 0);
$handler->override_option('items_per_page', 20);
$handler->override_option('style_plugin', 'grid');
$handler->override_option('style_options', array(
  'grouping' => '',
  'columns' => '4',
  'alignment' => 'horizontal',
));
$handler->override_option('path', 'top-rated');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Top content (Fivestar)',
  'description' => '',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('page', 'Current user', 'page_3');
$handler->override_option('relationships', array(
  'votingapi_vote' => array(
    'label' => 'Individual votes',
    'required' => 1,
    'votingapi' => array(
      'value_type' => '',
      'tag' => '',
    ),
    'current_user' => 0,
    'id' => 'votingapi_vote',
    'table' => 'node',
    'field' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'title' => array(
    'label' => 'Title',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'value_type' => array(
    'label' => 'Vote type',
    'exclude' => 0,
    'id' => 'value_type',
    'table' => 'votingapi_vote',
    'field' => 'value_type',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'votingapi_vote',
  ),
  'value' => array(
    'label' => 'Value',
    'set_precision' => FALSE,
    'precision' => 0,
    'decimal' => '.',
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'appearance' => '',
    'exclude' => 0,
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'votingapi_vote',
  ),
  'timestamp' => array(
    'label' => 'Timestamp',
    'date_format' => 'time ago',
    'custom_date_format' => '1',
    'exclude' => 0,
    'id' => 'timestamp',
    'table' => 'votingapi_vote',
    'field' => 'timestamp',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'votingapi_vote',
  ),
));
$handler->override_option('sorts', array(
  'timestamp' => array(
    'order' => 'DESC',
    'id' => 'timestamp',
    'table' => 'votingapi_vote',
    'field' => 'timestamp',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'votingapi_vote',
  ),
));
$handler->override_option('arguments', array(
  'uid' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'Everyone',
    'title' => '%1\'s votes',
    'default_argument_type' => 'current_user',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'uid',
    'table' => 'votingapi_vote',
    'field' => 'uid',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => 1,
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'value' => array(
    'operator' => 'not empty',
    'value' => array(
      'value' => '',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'votingapi_vote',
  ),
));
$handler->override_option('title', 'Ваши голоса');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 1,
  'order' => 'desc',
  'columns' => array(
    'title' => 'title',
    'value_type' => 'value_type',
    'value' => 'value',
    'timestamp' => 'timestamp',
  ),
  'info' => array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_type' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'timestamp',
));
$handler->override_option('path', 'your-votes');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Your votes',
  'description' => '',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('block', 'Блок с самыми рейтинговыми товарами', 'block_1');
$handler->override_option('relationships', array(
  'votingapi_vote' => array(
    'label' => '',
    'required' => 0,
    'votingapi' => array(
      'value_type' => 'percent',
      'tag' => '',
    ),
    'current_user' => 0,
    'id' => 'votingapi_vote',
    'table' => 'node',
    'field' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
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
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
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
      'button' => 'Use default',
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
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
  'value' => array(
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
    'set_precision' => 0,
    'precision' => '0',
    'decimal' => '.',
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'appearance' => 'fivestar_views_value_display_handler',
    'exclude' => 0,
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('sorts', array(
  'value' => array(
    'order' => 'DESC',
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
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
    'relationship' => 'none',
    'override' => array(
      'button' => 'Использовать установки по умолчанию',
    ),
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'product' => 'product',
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
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'value' => array(
    'operator' => '>',
    'value' => array(
      'value' => '0',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'value',
    'table' => 'votingapi_vote',
    'field' => 'value',
    'relationship' => 'votingapi_vote',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('title', '');
$handler->override_option('items_per_page', 3);
$handler->override_option('use_pager', '0');
$handler->override_option('use_more', 1);
$handler->override_option('use_more_always', 0);
$handler->override_option('use_more_text', 'Смотреть всё');
$handler->override_option('style_plugin', 'grid');
$handler->override_option('style_options', array(
  'grouping' => '',
  'columns' => '3',
  'alignment' => 'horizontal',
  'fill_single_line' => 1,
));
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('feed', 'Фид', 'feed_1');
$handler->override_option('style_plugin', 'rss');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
));
$handler->override_option('row_plugin', 'node_rss');
$handler->override_option('row_options', array(
  'relationship' => 'none',
  'item_length' => 'title',
));
$handler->override_option('path', 'top-rated/feed');
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
  'block_1' => 'block_1',
  'default' => 0,
  'page_1' => 0,
  'page_3' => 0,
));
$handler->override_option('sitename_title', FALSE);

$views['top_content'] = $view;
