<!-- Шаблон формы редактирования -->

<div id = "edit-content-form" class = "edit-product">
    <div id = "left"> <!-- Левая колонка -->
        <div class = "main"> <!-- Основные опции -->
         <!-- Product Import data form -->
         <div class="import_data_block">
            <h3>Import product data (DON'T USE THIS FORM)</h3>
            <div class="form-item" id="edit-prod-url">
             <label for="prod_url">Product URL: </label>
             <span class="field-prefix"></span> <input type="text" class="form-text" value="" id="prod_url"><span class="field-suffix"></span><input type="button" class="form-submit" onclick="" value="Import" id="import_data_call" />
             <div class="description">Fill Product URL</div>
            </div>
            <div class="import-title-block">
              <div class="edit-form-item" style="float: left; clear: none;">
               <div class="form-item" id="edit-product-title">
               <label for="prod_title_val">Product title imported</label>
               <span class="field-prefix"></span> <input type="text" maxlength="" name="" id="prod_title_val" size="" value="" class="form-text" /> <span class="field-suffix"></span>
               <div class="description">Product title imported need be updated</div>
               </div>
              </div>
              <div class="edit-form-item" style="float: right; clear: none;">
               <div class="form-item" id="edit-product-title-2">
               <label for="prod_title_val_last">Product title corrected <span class="form-required" title="">*</span></label>
               <span class="field-prefix"></span> <input type="text" maxlength="" name="" id="prod_title_val_last" size="" value="" class="form-text required" /> <span class="field-suffix"></span>
               <div class="description">Product title after correction</div>
               </div>
              </div>
              <div style="clear:both"></div>
            </div>
            <div class="import-price-block">
              <div class="edit-form-item" style="float: left; clear: none;">
               <div class="form-item" id="edit-product-price-yuan">
                <label for="prod_price_yuan">Product price yuan: <span class="form-required" title="">*</span></label>
                <span class="field-prefix"></span> <input type="text" maxlength="35" name="" id="prod_price_yuan" size="20" value="0" class="form-text required" /> <span class="field-suffix">yuan</span>
                <div class="description">Product price in yuan imported.</div>
               </div>
              </div>
              <div class="edit-form-item" style="float: right; clear: none;">
               <div class="form-item" id="edit-product-price-usd">
                <label for="prod_price_usd">Product price usd: <span class="form-required" title="">*</span></label>
                <span class="field-prefix"></span> <input type="text" maxlength="35" name="" id="prod_price_usd" size="20" value="0" class="form-text required" /> <span class="field-suffix">$</span>
                <div class="description">Product price in usd calculated.</div>
               </div>
              </div>
              <div style="clear:both"></div>
            </div> 
            <div class="edit-form-item">
             <div class="form-item" id="edit-product-weight">
              <label for="prod_weight">Weight: <span class="form-required" title="">*</span></label>
              <span class="field-prefix"></span> <input type="text" maxlength="35" name="" id="prod_weight" size="20" value="0" class="form-text required" /> <span class="field-suffix">gram</span>
              <div class="description">Product Weight.</div>
             </div>
            </div>						
            <div class="edit-form-item">
             <div class="form-item" id="edit-product-image">
              <label for="prod_image">Main image URL:</label>
              <span class="field-prefix"></span> <input type="text" maxlength="" name="" id="prod_image" size="" value="" class="form-text" /> <span class="field-suffix"></span>
              <div class="description">Will be used as the main product image.</div>
              <img id="prod_image_show" src="data:image/gif;base64,R0lGODlhAQABAIAAAP///////yH5BAEHAAEALAAAAAABAAEAAAICTAEAOw==" alt="" />
             </div>
            </div>						
            
           <input type="button" class="form-submit" onclick="" value="Fill form" id="fill_form" /> 		
           <hr />
          </div>
         <!-- /Product Import data form -->
                 
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_taxonomy_tags; ?>

            <?php print $show_edit_form_image; ?>
        </div> <!-- /Основные опции -->

        <div class = "additional"> <!-- Дополнительные опции -->
            <?php print $show_edit_form_specs; ?>

            <?php print $show_edit_form_additional; ?>
			
			<?php print $show_edit_form_media; ?>						

            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /Дополнительные опции -->
    </div> <!-- /Левая колонка -->

    <div id = "right"> <!-- Правая колонка -->
		<div class = "shipping"> <!-- Всё, что касается доставки (первоочередное) -->
            <h3><?php print t('Edit product shipping'); ?></h3>

            <?php print $show_edit_form_shippable; ?>

            <?php print $show_edit_form_weight_weight; ?>
        </div> <!-- Всё, что касается доставки -->
		
        <div class = "prices"> <!-- Блок с ценами -->
            <h3><?php print t('Edit product prices'); ?></h3>
<!--			<div class="form-item" id="edit-yuan_price">
			 <label for="yuan_price">Price: </label>
			 <span class="field-prefix"></span> <input type="text" class="form-text" value="0" id="yuan_price" /><span class="field-suffix">Y</span>
			 <div class="description">Price in yuan</div>
			</div>
			
			<input type="button" class="form-submit" onclick="" value="<? print t('Calculate')?>" id="calc_price_btn" />-->
			
			<?php print $show_edit_form_cost; ?>
						
			
			
            <?php print $show_edit_form_sell_price; ?>

            <?php print $show_edit_form_list_price; ?>
			
			<?php print $show_edit_form_crs_m; ?>
			
            <?php print $show_edit_form_model; ?>
        </div> <!-- /Блок с ценами -->

        <div class = "categories"> <!-- Блок с категориями (таксономия) -->
            <h3><?php print t('Edit product categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_categories; ?>

            <?php print $show_edit_form_taxonomy_manufacturers; ?>

            <?php print $show_edit_form_taxonomy_promo; ?>
        </div> <!-- /Блок с категориями -->

        

        <div class = "buttons"> <!-- Блок с кнопками -->
            <?php print $show_edit_form_submit; ?>

            <?php print $show_edit_form_save_continue; ?>

            <?php print $show_edit_form_submit_again; ?>

            <?php print $show_edit_form_submit_preview; ?>

            <?php print $show_edit_form_delete; ?>
        </div> <!-- /Блок с кнопками -->
    </div> <!-- /Правая колонка -->

    <div id = "bottom"> <!-- /Подвал (сюда пихайте всё второстепенное) -->
        <h3><?php print t('Other product options'); ?></h3>

        <?php print $show_edit_form_sitemap; ?>

        <?php print $show_edit_form_revision; ?>

        <?php print $show_edit_form_path; ?>

        <?php print $show_edit_form_menu; ?>

        <?php print $show_edit_form_author; ?>

        <?php print $show_edit_form_comment; ?>

        <?php print $show_edit_form_options; ?>

        <?php print $show_edit_form_upload; ?>

        <?php print $show_edit_form_shipping; ?>
    </div>
</div>
<!-- Шаблон формы редактирования -->

<?php

/*
* drupal_render($form) является обязательным в этом шаблоне. 
Служит для валидации формы.  Мы должны всегда располагать этот код в самом конце страницы, иначе поля, указанные выше, будут отсортированы по своим внутренним настройкам
*/
print drupal_render($form);
?>

<?php
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Более подробная и свежая информация по доступным переменным может быть найдена здесь: http://openstore.org.ua/node/137 /// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

<?php print $show_edit_form_taxonomy; ?> Таксономия (форма)
<?php print $show_edit_form_taxonomy_tags; ?> Таксономия (теги)
<?php print $show_edit_form_taxonomy_categories; ?> Таксономия (главная категория товаров)
<?php print $show_edit_form_taxonomy_manufacturers; ?> Таксономия (Производители)
<?php print $show_edit_form_taxonomy_promo; ?> Таксономия (Акции)

<?php print $show_edit_form_body; ?> Основной текст
<?php print $show_edit_form_domain; ?> Опции доменов
<?php print $show_edit_form_menu; ?> Ссылка на документ в меню
<?php print $show_edit_form_revision; ?> Варианты документа
<?php print $show_edit_form_author; ?> Автор
<?php print $show_edit_form_options; ?> Опции публикации
<?php print $show_edit_form_sitemap; ?> Карта сайта
<?php print $show_edit_form_metatags; ?> Метатеги
<?php print $show_edit_form_comment; ?> Настройки комментариев
<?php print $show_edit_form_path; ?> Адрес страницы
<?php print $show_edit_form_upload; ?> Вложенные файлы
<?php print $show_edit_form_buttons; ?> Блок с кнопками формы
<?php print $show_edit_form_submit; ?> Кнопка "Сохранить"
<?php print $show_edit_form_submit_preview; ?> Кнопка "Предварительный просмотр"
<?php print $show_edit_form_submit_again; ?> Кнопка "Сохранить и создать документ снова"
<?php print $show_edit_form_save_continue; ?> Кнопка "Сохранить и продолжить"
<?php print $show_edit_form_delete; ?> Кнопка "Удалить"
<?php print $show_edit_form_title; ?> Заголовок документа

<?php print $show_edit_form_image; ?> Блок с изображениями товара
<?php print $show_edit_form_specs; ?> Блок с техническими характеристиками
<?php print $show_edit_form_googlecheck; ?> Настройки Google Checkout
<?php print $show_edit_form_additional; ?> Блок с дополнительными опциями
<?php print $show_edit_form_shipping; ?> Блок с настройки доставки
<?php print $show_edit_form_product; ?> Блок с настроками товара
<?php print $show_edit_form_prices; ?> Блок с ценами
<?php print $show_edit_form_list_price; ?> Цена прайс-листа
<?php print $show_edit_form_cost; ?> Стоимость товара
<?php print $show_edit_form_sell_price; ?> Цена продажи
<?php print $show_edit_form_shippable; ?> Товар доставляется или нет
<?php print $show_edit_form_weight; ?> Блок с весом товара
<?php print $show_edit_form_weight_weight; ?> Значение веса
<?php print $show_edit_form_weight_units; ?> Единица измерения веса
<?php print $show_edit_form_dimensions; ?> Блок с размерами товара
<?php print $show_edit_form_length_units; ?> Единица измерения длины
<?php print $show_edit_form_dim_length; ?> Значение длины
<?php print $show_edit_form_dim_width; ?> Значение ширины
<?php print $show_edit_form_dim_height; ?> Значение высоты
<?php print $show_edit_form_pkg_qty; ?> Количество
<?php print $show_edit_form_default_qty; ?> Количество по умолчанию
<?php print $show_edit_form_ordering; ?> Сортировка
<?php print $show_edit_form_model; ?> Артикул


*/
?>