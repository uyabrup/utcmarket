<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function openstore_all_features_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_banner_link
  $groups['banner-group_banner_link'] = array(
    'group_type' => 'standard',
    'type_name' => 'banner',
    'group_name' => 'group_banner_link',
    'label' => 'Ссылка',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '6',
    'fields' => array(
      '0' => 'field_banner_link',
      '1' => 'field_banner_ref',
    ),
  );

  // Exported group: group_banner_other
  $groups['banner-group_banner_other'] = array(
    'group_type' => 'standard',
    'type_name' => 'banner',
    'group_name' => 'group_banner_other',
    'label' => 'Пейджер',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_plain' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_html' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_banner_pager',
      '1' => 'field_banner_pager_txt',
    ),
  );

  // Exported group: group_banners
  $groups['banner-group_banners'] = array(
    'group_type' => 'standard',
    'type_name' => 'banner',
    'group_name' => 'group_banners',
    'label' => 'Изображения',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '5',
    'fields' => array(
      '0' => 'field_banner',
      '1' => 'field_banner_ribbon',
    ),
  );

  // Exported group: group_banners
  $groups['page-group_banners'] = array(
    'group_type' => 'standard',
    'type_name' => 'page',
    'group_name' => 'group_banners',
    'label' => 'Баннер страницы',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_plain' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'email_html' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '8',
    'fields' => array(
      '0' => 'field_banner',
      '1' => 'field_banner_pager_txt',
      '2' => 'field_banner_pager',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Баннер страницы');
  t('Изображения');
  t('Пейджер');
  t('Ссылка');

  return $groups;
}
