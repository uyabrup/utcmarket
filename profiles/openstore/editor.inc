<?php

/**
 * Настройка Ckeditor
 */
function openstore_config_editor() {

// Назначаем роли для профилей Ckeditor
db_query("DELETE FROM {ckeditor_role} WHERE name = '%s'", OPENSTORE_CKEDITOR_ADV_NAME);    
db_query("INSERT INTO {ckeditor_role} (name, rid) VALUES ('%s', %d)", OPENSTORE_CKEDITOR_ADV_NAME, OPENSTORE_ROLEID_DIRECTOR);
db_query("INSERT INTO {ckeditor_role} (name, rid) VALUES ('%s', %d)", OPENSTORE_CKEDITOR_ADV_NAME, OPENSTORE_ROLEID_MANAGER);
db_query("INSERT INTO {ckeditor_role} (name, rid) VALUES ('%s', %d)", OPENSTORE_CKEDITOR_ADV_NAME, OPENSTORE_ROLEID_CONTENTMANAGER);         
       
         $settings = array();
         $settings['allow_user_conf'] = 'f'; 
         $settings['filters'] = array (
                                 'ckeditor_link/0' => 0, 
                                 'filter/3' => 0, 
                                 'twitter/1' => 0, 
                                 'twitter/0' => 0, 
                                 'filter/0' => 1, 
                                 ); 
        $settings['ss'] = 2; 
        $settings['min_rows'] = 1;
        $settings['excl_mode'] = 1; 
		// Где загружать CKEditor
        $settings['excl'] = "page@*.edit-body\r\nsimplenews@*.edit-body\r\nproduct@*.edit-body\r\nproduct-kit@*.edit-body\r\nproduct@node/add/product.edit-field-specs-0-value\r\nproduct@node/*/edit.edit-field-specs-0-value\r\nproduct@node/*/edit.edit-field-notes-0-value\r\nadmin/store/settings/cart/edit.edit-openstore-cart-text\r\nadmin/store/settings/products/edit.edit-openstore-empty-image-text";
        $settings['default'] = 't'; 
        $settings['show_toggle'] = 't'; 
        $settings['popup'] = 'f'; 
        $settings['skin'] = 'kama'; 
        $settings['uicolor'] = 'default'; 
        $settings['uicolor_textarea'] = t('Click on the UI Color Picker button to set your color preferences');
        $settings['uicolor_user'] = 'default';
        $settings['toolbar'] = 'DrupalFiltered'; 
        $settings['expand'] = 'f'; 
        $settings['width'] = '100%'; 
        $settings['lang'] = 'ru'; 
        $settings['auto_lang'] = 't'; 
        $settings['language_direction'] = 'default'; 
        $settings['enter_mode'] = 'p'; 
        $settings['shift_enter_mode'] = 'br'; 
        $settings['font_format'] = 'p;div;pre;address;h1;h2;h3;h4;h5;h6'; 
        $settings['custom_formatting'] = 'f'; 
        $settings['formatting']['custom_formatting_options'] = array ( 
                                                                'indent' => 'indent', 
                                                                'breakBeforeOpen' => 'breakBeforeOpen', 
                                                                'breakAfterOpen' => 'breakAfterOpen', 
                                                                'breakAfterClose' => 'breakAfterClose', 
                                                                'breakBeforeClose' => 0, 
                                                                'pre_indent' => 0, 
                                                                ); 
 
        $settings['css_mode'] = 'none'; 
        $settings['css_style'] = 'default'; 
        $settings['filebrowser'] = 'imce'; 
        $settings['filebrowser_image'] = 'imce'; 
        $settings['filebrowser_flash'] = 'imce'; 
        $settings['UserFilesPath'] = '%b%f/'; 
        $settings['UserFilesAbsolutePath'] = '%d%b%f/';
        $settings['ckeditor_load_method'] = 'ckeditor.js'; 
        $settings['ckeditor_load_time_out'] = 0; 
        $settings['forcePasteAsPlainText'] = 'f'; 
        $settings['theme_config_js'] = 'f';      
        
		// Сохраняем в БД настройки для расширенного профиля
		db_query("UPDATE {ckeditor_settings} SET settings = '%s' WHERE name = '%s'", serialize($settings), OPENSTORE_CKEDITOR_ADV_NAME); 
 
       $settings = array();      
       $settings['rank'] = array ( 0 => 5, 1 => 4, 2 => 3); 
       $settings['excl_mode'] = 1; 
       // Где загружать CKEditor
	   $settings['excl'] = "page@*.edit-body\r\nsimplenews@*.edit-body\r\nproduct@*.edit-body\r\nproduct-kit@*.edit-body\r\nproduct@node/add/product.edit-field-specs-0-value\r\nproduct@node/*/edit.edit-field-specs-0-value\r\nproduct@node/*/edit.edit-field-notes-0-value\r\nadmin/store/settings/cart/edit.edit-openstore-cart-text\r\nadmin/store/settings/products/edit.edit-openstore-empty-image-text";
       $settings['ckeditor_path'] = '%m/ckeditor'; 
       $settings['show_fieldnamehint'] = 't'; 
       
	   // Сохраняем в БД настройки для глобального профиля
       db_query("UPDATE {ckeditor_settings} SET settings = '%s' WHERE name = '%s'", serialize($settings), OPENSTORE_CKEDITOR_GLOBAL_NAME);
	   
	   // Обновляем настройки для Ckeditor
	   module_load_include('inc', 'ckeditor', 'includes/ckeditor.admin');
       ckeditor_rebuild_selectors();
    } 