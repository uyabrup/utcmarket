<?php

/**
 * Препроцесс полей формы редактирования документа "product"
 */
function general_preprocess_product_form(&$vars) {
  
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_tags'] = '<div class="edit-form-item tags-form">' . drupal_render($vars['form']['taxonomy']['tags'][5]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_tags'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/5', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_categories'] = '<div class="edit-form-item categories-form">' . drupal_render($vars['form']['taxonomy'][1]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_categories'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/1', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_manufacturers'] = '<div class="edit-form-item manufacturers-form">' . drupal_render($vars['form']['taxonomy'][3]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_manufacturers'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/3', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_promo'] = '<div class="edit-form-item promo-form">' . drupal_render($vars['form']['taxonomy'][6]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_promo'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/6', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_field']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
  
  $vars['show_edit_form_delete'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';

  $vars['show_edit_form_image'] = '<div class="edit-form-item image-form">' . drupal_render($vars['form']['field_image_cache']) . '</div>';
  $vars['show_edit_form_specs'] = '<div class="edit-form-item specs-form">' . drupal_render($vars['form']['group_specs']) . '</div>';
  $vars['show_edit_form_googlecheck'] = '<div class="edit-form-item googlecheck-item">' . drupal_render($vars['form']['google_checkout']) . '</div>';
  $vars['show_edit_form_additional'] = '<div class="edit-form-item additional-form">' . drupal_render($vars['form']['group_additional']) . '</div>';
  $vars['show_edit_form_media'] = '<div class="edit-form-item media-form">' . drupal_render($vars['form']['group_media']) . '</div>';
  $vars['show_edit_form_shipping'] = '<div class="edit-form-item shipping-form">' . drupal_render($vars['form']['shipping']) . '</div>';

  /* Если раскомментировать, будет выведен весь блок с параметрами товара, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_product'] = '<div class="edit-form-item product-form">' . drupal_render($vars['form']['base']) . '</div>';
   */
  
  $vars['form']['base']['#type'] = 'markup'; // Убираем пустой fieldset для блока с настройками товара. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_prices'] = '<div class="edit-form-item prices-form">' . drupal_render($vars['form']['base']['prices']) . '</div>';
  $vars['show_edit_form_list_price'] = '<div class="edit-form-item list-price-item">' . drupal_render($vars['form']['base']['prices']['list_price']) . '</div>';
  $vars['show_edit_form_cost'] = '<div class="edit-form-item cost-item">' . drupal_render($vars['form']['base']['prices']['cost']) . '</div>';
  $vars['show_edit_form_sell_price'] = '<div class="edit-form-item sell-price-item">' . drupal_render($vars['form']['base']['prices']['sell_price']) . '</div>';
  $vars['show_edit_form_shippable'] = '<div class="edit-form-item shippable-item">' . drupal_render($vars['form']['base']['shippable']) . '</div>';
  $vars['show_edit_form_weight'] = '<div class="edit-form-item weight-item">' . drupal_render($vars['form']['base']['weight']) . '</div>';
  $vars['show_edit_form_weight_weight'] = '<div class="edit-form-item weight-item">' . drupal_render($vars['form']['base']['weight']['weight']) . '</div>';
  $vars['show_edit_form_weight_units'] = '<div class="edit-form-item weight-units-item">' . drupal_render($vars['form']['base']['weight']['weight_units']) . '</div>';

  /* Если раскомментировать, будет выведен весь блок с параметрами размеров, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_dimensions'] = '<div class="edit-form-item dimensions-item">' . drupal_render($vars['form']['base']['dimensions']) . '</div>';
   */
  
  $vars['form']['base']['dimensions']['#type'] = 'markup'; // Убираем пустой fieldset для блока с настройками размеров. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_length_units'] = '<div class="edit-form-item length-units-item">' . drupal_render($vars['form']['base']['dimensions']['length_units']) . '</div>';
  $vars['show_edit_form_dim_length'] = '<div class="edit-form-item dim-length-item">' . drupal_render($vars['form']['base']['dimensions']['dim_length']) . '</div>';
  $vars['show_edit_form_dim_width'] = '<div class="edit-form-item dim-width-item">' . drupal_render($vars['form']['base']['dimensions']['dim_width']) . '</div>';
  $vars['show_edit_form_dim_height'] = '<div class="edit-form-item dim-height-item">' . drupal_render($vars['form']['base']['dimensions']['dim_height']) . '</div>';
  $vars['show_edit_form_pkg_qty'] = '<div class="edit-form-item pkg-qty-item">' . drupal_render($vars['form']['base']['pkg_qty']) . '</div>';
  $vars['show_edit_form_default_qty'] = '<div class="edit-form-item default-qty-item">' . drupal_render($vars['form']['base']['default_qty']) . '</div>';
  $vars['show_edit_form_ordering'] = '<div class="edit-form-item ordering-item">' . drupal_render($vars['form']['base']['ordering']) . '</div>';
  $vars['show_edit_form_model'] = '<div class="edit-form-item model-item">' . drupal_render($vars['form']['base']['model']) . '</div>';
}

/**
 * Препроцесс полей формы редактирования документа "page"
 */
function general_preprocess_page_form(&$vars) {
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_tags'] = '<div class="edit-form-item tags-form">' . drupal_render($vars['form']['taxonomy']['tags'][5]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_tags'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/5', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_categories'] = '<div class="edit-form-item categories-form">' . drupal_render($vars['form']['taxonomy'][1]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_categories'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/1', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_common'] = '<div class="edit-form-item common-categories-form">' . drupal_render($vars['form']['taxonomy'][4]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_common'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/4', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_manufacturers'] = '<div class="edit-form-item manufacturers-form">' . drupal_render($vars['form']['taxonomy'][3]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_manufacturers'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/3', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_promo'] = '<div class="edit-form-item promo-form">' . drupal_render($vars['form']['taxonomy'][6]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_promo'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/6', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_field']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';

  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
  
  $vars['show_edit_form_delete'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';
  $vars['show_edit_form_banners'] = '<div class="edit-form-item group-banners-item">' . drupal_render($vars['form']['group_banners']) . '</div>';
}

/**
 * Препроцесс полей формы редактирования документа "banner"
 */
function general_preprocess_banner_form(&$vars) {
  
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_categories'] = '<div class="edit-form-item categories-form">' . drupal_render($vars['form']['taxonomy'][1]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_categories'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/1', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_common'] = '<div class="edit-form-item common-categories-form">' . drupal_render($vars['form']['taxonomy'][4]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_common'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/4', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_manufacturers'] = '<div class="edit-form-item manufacturers-form">' . drupal_render($vars['form']['taxonomy'][3]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_manufacturers'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/3', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_promo'] = '<div class="edit-form-item promo-form">' . drupal_render($vars['form']['taxonomy'][6]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_promo'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/6', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_filter']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
  
  $vars['show_edit_form_delete'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь fieldset, но исчезнет вывод отдельных элементов, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_banners'] = '<div class="edit-form-item group-banners-item">' . drupal_render($vars['form']['group_banners']) . '</div>';
   */
  
  $vars['form']['group_banners']['#type'] = 'markup'; // Убираем пустой fieldset. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_banner'] = '<div class="edit-form-item field-banner-item">' . drupal_render($vars['form']['group_banners']['field_banner']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь fieldset, но исчезнет вывод отдельных элементов, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_links'] = '<div class="edit-form-item group-banners-item">' . drupal_render($vars['form']['group_banner_link']) . '</div>';
   */
  
  $vars['form']['group_banner_link']['#type'] = 'markup'; // Убираем пустой fieldset. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_link'] = '<div class="edit-form-item-contentedit-form-item field-banner-link-item">' . drupal_render($vars['form']['group_banner_link']['field_banner_link']) . '</div>';
  $vars['show_edit_form_ref'] = '<div class="edit-form-item field-banner-ref-item">' . drupal_render($vars['form']['group_banner_link']['field_banner_ref']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь fieldset, но исчезнет вывод отдельных элементов, так как  drupal_render() не проходит родительский уровень массива 2 раза
   */
  
  $vars['show_edit_form_other'] = '<div class="edit-form-item banner-other-item">' . drupal_render($vars['form']['group_banner_other']) . '</div>';
  // $vars['form']['group_banner_other']['#type'] = 'markup'; // Убираем пустой fieldset. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_ribbon'] = '<div class="edit-form-item banner-ribbon-item">' . drupal_render($vars['form']['group_banners']['field_banner_ribbon']) . '</div>';
  $vars['show_edit_form_pager'] = '<div class="edit-form-item banner-pager-item">' . drupal_render($vars['form']['group_banner_other']['field_banner_pager']) . '</div>';
  $vars['show_edit_form_pager_txt'] = '<div class="edit-form-item banner-pager-txt-item">' . drupal_render($vars['form']['group_banner_other']['field_banner_pager_txt']) . '</div>';
}

/**
 * Препроцесс полей формы редактирования документа "simplenews"
 */
function general_preprocess_simplenews_form(&$vars) {
  
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_newsletter'] = '<div class="edit-form-item newsletter-categories-form">' . drupal_render($vars['form']['taxonomy'][2]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_newsletter'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/2', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_field']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
  
  $vars['show_edit_form_delete'] = '<div class="edit-form-item delete-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';
  $vars['show_edit_form_token'] = '<div class="edit-form-item token-help-item">' . drupal_render($vars['form']['simplenews_subscription']['subscription_mail']['token_help']) . '</div>';
  $vars['form']['simplenews']['#type'] = 'markup';
  $vars['form']['simplenews']['advanced']['#type'] = 'markup';
  $vars['form']['simplenews']['test_address']['#size'] = 30;
  $vars['show_edit_form_simplenews'] = '<div class="edit-form-item simplenews-item">' . drupal_render($vars['form']['simplenews']) . '</div>';
}

/**
 * Препроцесс полей формы редактирования документа "poll"
 */
function general_preprocess_poll_form(&$vars) {
  
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_common'] = '<div class="edit-form-item common-categories-form">' . drupal_render($vars['form']['taxonomy'][4]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_common'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/4', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_field']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
  
  $vars['show_edit_form_delete'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';
  $vars['show_edit_form_choice'] = '<div class="edit-form-item choice-item">' . drupal_render($vars['form']['choice_wrapper']['choice']) . '</div>';
  $vars['show_edit_form_addpoll'] = '<div class="edit-form-item addpoll-item">' . drupal_render($vars['form']['choice_wrapper']['poll_more']) . '</div>';
  $vars['show_edit_form_state'] .= '<div class="edit-form-item pollstate-item">' . drupal_render($vars['form']['settings']['active']) . '</div>';
  $vars['show_edit_form_runtime'] = '<div class="edit-form-item runtime-item">' . drupal_render($vars['form']['settings']['runtime']) . '</div>';
  $vars['form']['settings']['#type'] = 'markup'; // Убираем пустой fieldset
}

/**
 * Препроцесс полей формы редактирования документа "product_kit"
 */
function general_preprocess_product_kit_form(&$vars) {
  //$vars['show_edit_form_taxonomy'] = '<div class="edit-form-item taxonomy-form">' . drupal_render($vars['form']['taxonomy']) . '</div>';
  $vars['show_edit_form_taxonomy_tags'] = '<div class="edit-form-item tags-form">' . drupal_render($vars['form']['taxonomy']['tags'][5]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_tags'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/5', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_categories'] = '<div class="edit-form-item categories-form">' . drupal_render($vars['form']['taxonomy'][1]) . '</div>'; // [1] - номер словаря
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_categories'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/1', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_taxonomy_promo'] = '<div class="edit-form-item promo-form">' . drupal_render($vars['form']['taxonomy'][6]) . '</div>';
  if (user_access('administer taxonomy')) {
    $vars['show_edit_form_taxonomy_promo'] .= '<div class="voc-edit-link">' . l(t('Edit vocabulary terms'), 'admin/content/taxonomy/6', array('attributes' => array('target' => '_blank'))) . '</div>';
  }
  $vars['show_edit_form_body'] = '<div class="edit-form-item body-item">' . drupal_render($vars['form']['body_filter']) . '</div>';
  $vars['show_edit_form_domain'] = '<div class="edit-form-item domain-form">' . drupal_render($vars['form']['domain']) . '</div>';
  $vars['show_edit_form_menu'] = '<div class="edit-form-item menu-form">' . drupal_render($vars['form']['menu']) . '</div>';
  $vars['show_edit_form_revision'] = '<div class="edit-form-item revision-form">' . drupal_render($vars['form']['revision_information']) . '</div>';
  $vars['show_edit_form_author'] = '<div class="edit-form-item author-form">' . drupal_render($vars['form']['author']) . '</div>';
  $vars['show_edit_form_options'] = '<div id="options-form" class="edit-form-item options-form">' . drupal_render($vars['form']['options']) . '</div>';
  $vars['show_edit_form_sitemap'] = '<div class="edit-form-item sitemap-form">' . drupal_render($vars['form']['xmlsitemap']) . '</div>';
  $vars['show_edit_form_metatags'] = '<div class="edit-form-item metatags-form">' . drupal_render($vars['form']['nodewords']) . '</div>';
  $vars['show_edit_form_comment'] = '<div class="edit-form-item comment-form">' . drupal_render($vars['form']['comment_settings']) . '</div>';
  $vars['show_edit_form_path'] = '<div class="edit-form-item path-form">' . drupal_render($vars['form']['path']) . '</div>';
  $vars['show_edit_form_upload'] = '<div class="edit-form-item upload-form">' . drupal_render($vars['form']['attachments']) . '</div>';
  
  /* Если раскомментировать, будет выведен весь блок с кнопками, но исчезнет вывод отдельных элементов блока, так как  drupal_render() не проходит родительский уровень массива 2 раза
   $vars['show_edit_form_buttons'] = '<div class="edit-form-item buttons-form">' . drupal_render($vars['form']['buttons']) . '</div>';
   */
   
  $vars['show_edit_form_submit'] = '<div class="edit-form-item submit-item">' . drupal_render($vars['form']['buttons']['submit']) . '</div>';
  $vars['show_edit_form_submit_preview'] = '<div class="edit-form-item preview-item">' . drupal_render($vars['form']['buttons']['preview']) . '</div>';
  $vars['show_edit_form_submit_again'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['submit_again']) . '</div>';
  $vars['show_edit_form_delete'] = '<div class="edit-form-item submit-again-item">' . drupal_render($vars['form']['buttons']['delete']) . '</div>';
  $vars['show_edit_form_save_continue'] = '<div class="edit-form-item save-continue-item">' . drupal_render($vars['form']['buttons']['save_continue']) . '</div>';
  $vars['show_edit_form_title'] = '<div class="edit-form-item title-item">' . drupal_render($vars['form']['title']) . '</div>';
  unset($vars['form']['field_image_cache']);
  $vars['show_edit_form_image'] = '<div class="edit-form-item image-form">' . drupal_render($vars['form']['field_banner']) . '</div>';
  $vars['show_edit_form_mutable'] = '<div class="edit-form-item mutable-item">' . drupal_render($vars['form']['base']['mutable']) . '</div>';
  $vars['show_edit_form_select'] = '<div class="edit-form-item select-item">' . drupal_render($vars['form']['base']['products']) . '</div>';
  $vars['show_edit_form_default_qty'] = '<div class="edit-form-item default-qty-item">' . drupal_render($vars['form']['base']['default_qty']) . '</div>';
  $vars['show_edit_form_ordering'] = '<div class="edit-form-item ordering-item">' . drupal_render($vars['form']['base']['ordering']) . '</div>';
  $vars['show_edit_form_ordering'] = '<div class="edit-form-item ordering-item">' . drupal_render($vars['form']['base']['ordering']) . '</div>';
  $vars['show_edit_form_shipping'] .= '<div class="edit-form-item shipping-item">' . drupal_render($vars['form']['shipping']) . '</div>';
  $vars['form']['base']['#type'] = 'markup'; // Убираем пустой fieldset для блока с настройками товара. Закомментируйте, если у вас раскомментирован код выше.
  $vars['show_edit_form_googlecheck'] = '<div class="edit-form-item googlecheck-item">' . drupal_render($vars['form']['google_checkout']) . '</div>';
  
  foreach ($vars['form']['base']['items'] as $key => $value) { // Добавляем картинки для товаров из набора
    if (is_numeric($key)) {
      $node = node_load($key);
      $vars['form']['base']['items'][$key]['image'] = array(
  '#type' => 'markup',
  '#value' => theme('imagecache', 'product_list', $node->field_image_cache[0]["filepath"], FALSE, FALSE,   FALSE),
  '#weight' => 1,
  );
      $vars['form']['base']['items'][$key]['#sorted'] = NULL;
      $vars['form']['base']['items'][$key]['link']['#weight'] = 2;
      $vars['form']['base']['items'][$key]['qty']['#weight'] = 3;
      $vars['form']['base']['items'][$key]['ordering']['#weight'] = 4;
      $vars['form']['base']['items'][$key]['discount']['#weight'] = 5;

      $vars['form']['base']['items'][$key]['#attributes'] = array('class' => 'product-kit-item');
    }
  }
  $vars['show_edit_form_items'] = '<div class="edit-form-item kit-items-item">' . drupal_render($vars['form']['base']['items']) . '</div>';
  if ($vars['form']['base']['kit_total']) {
    $vars['show_edit_form_kit_total'] = '<div class="edit-form-item kit-total-item">' . drupal_render($vars['form']['base']['kit_total']) . '</div>';
  }
}