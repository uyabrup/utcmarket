<?php if (!empty($node)): ?>

    <div id = "product-page" class = "sidebar-right">
        <?php print $show_title; ?>
        <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->

           <div id = "row-1"> <!-- Первая строка -->
               <div class = "col-left"> <!-- Левая колонка -->
                   <div id = "block-image"> <!-- Изображения -->
                       <?php print $show_product_image; ?>

                       <?php print $show_product_small_images; ?>
                   </div> <!-- /Изображения -->
               </div> <!-- /Левая колонка -->

               <div class = "col-right"> <!-- Правая колонка -->
                   <div id = "block-prices"> <!-- Цены -->
                       <?php print $show_product_price_full; ?>

                       <?php print $show_product_contact_bargain; ?>
                   </div> <!-- /Цены -->

                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_terms_trademark; ?>

                   <?php print $show_product_sku; ?>

                   <!-- Разделитель --><div class = "delimeter-5px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_product_state_text; ?>

                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_product_fivestar_widget_static; ?>

                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_product_fivestar_widget_dinamic; ?>

                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->
				   
				   <?php print $show_download_xls_catalog; ?>
                   <!-- Разделитель --><div class = "delimeter-5px">
                   </div> <!-- /Разделитель -->				   
                   <?php print $show_download_doc_catalog; ?>
                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->
                   <?php print $show_product_contact_product; ?>

                   <?php print $show_product_contact_error; ?>


                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_rss_product_comments; ?>

                   <!-- Разделитель --><div class = "delimeter-10px">
                   </div> <!-- /Разделитель -->

                   <?php print $show_cart_button; ?>

       <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
               </div> <!-- /Правая колонка -->

       <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
           </div> <!-- /Первая строка -->

        <!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->

        <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->

           <div id = "block-share"> <!-- Закладки -->

               <?php print $show_share_widget; ?>

               <?php print $show_bookmark_link; ?>
           </div> <!--/Закладки -->

        <!-- Разделитель --><div class = "delimeter-5px"></div> <!-- /Разделитель -->

        <!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->


           <!-- Разделитель --><div class = "delimeter-10px">
           </div> <!-- /Разделитель -->

           <?php print $show_product_tabs; ?>

           <?php print $show_product_notes; ?>

           <!-- Разделитель --><div class = "delimeter-10px">
           </div> <!-- /Разделитель -->

           <?php if ($show_product_left_region): ?>

               <div id = "product-left-region"><?php print $show_product_left_region; ?></div>

           <?php
           endif;
           ?>

           <?php if ($show_product_right_region): ?>

               <div id = "product-right-region"><?php print $show_product_right_region; ?></div>

           <?php
           endif;
           ?>


        <!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->

           <div id = "block-notes"> <!-- Опции, условия... -->

               <!-- Разделитель --><div class = "delimeter-10px">
               </div> <!-- /Разделитель -->

               <?php print $show_shipping_methods; ?>

               <?php print $show_payment_methods; ?>

               <?php print $show_product_warranty; ?>
           </div> <!-- /Опции, условия... -->

        <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->


        <!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->

           <div id = "block-discount"> <!-- Информация по скидкам -->

               <!-- Разделитель --><div class = "delimeter-10px">
               </div> <!-- /Разделитель -->

               <?php print $show_product_point_rates; ?>

               <!-- Разделитель --><div class = "delimeter-10px">
               </div> <!-- /Разделитель -->

               <?php print $show_product_discount_rates; ?>

         <!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
           </div> <!-- /Информация по скидкам -->


           <!-- Разделитель --><div class = "delimeter-20px">
           </div> <!-- /Разделитель -->
			   
			   
    </div>

<?php endif;?>


<?php /* Переменные, которые можно использовать в этом шаблоне. Смотрите также http://openstore.org.ua/node/137 	 
	 
<?php print $show_product_accordion; ?> // Регион "Сворачивающиеся блоки"
<?php print $show_product_point_rates; ?> // Информация по курсу обмена баллов для скидки
<?php print $show_product_discount_rates; ?> // Таблица с информацией по накопительным скидкам 
<?php print $show_product_comment_link; ?> // Ссылка добавления комментария (с числом имеющихся комментариев)
<?php print $show_product_additional_fields; ?> // CCK поля, в обычном формате 
<?php print $show_rss_all; ?> //Иконка со ссылкой на общую RSS ленту сайта
<?php print $show_rss_top_rated; ?> // Иконка со ссылкой на RSS ленту с самыми рейтинговыми товарами
<?php print $show_rss_new_products; ?> // Иконка со ссылкой на RSS ленту с последними добавленными товарами
<?php print $show_rss_last_reviews; ?> // Иконка со ссылкой на RSS ленту с последними отзывами
<?php print $show_rss_discounts; ?> // Иконка со ссылкой на RSS ленту с товарами, имеющими скидку
<?php print $show_rss_promo; ?>// Иконка со ссылкой на RSS ленту с акциями
<?php print $show_rss_product_comments; ?> // Иконка со ссылкой на RSS ленту с отзывами по текущему товару
<?php print $show_share_widget; ?> // Кнопки для добавления в социальные закладки
<?php print $show_share_widget_text; ?> // Кнопки для добавления в социальные закладки с текстом
<?php print $show_title; ?> // Заголовок документа
<?php print $show_document_status; ?> // Индикатор "Опубликовано/Неопубликовано" для администратора
<?php print $show_terms_catalog; ?> // Категории из словаря "Каталог" 
<?php print $show_terms_trademark; ?> // Категория из словаря "Производители"
<?php print $show_terms_common; ?> // Категория из словаря "Общие категории"
<?php print $show_terms_tags; ?> // Категории из словаря "Теги"
<?php print $show_terms_promo; ?> // Категории из словаря "Акции" 
<?php print $show_cart_button; ?> // Кнопка добавления в корзину
<?php print $show_bookmark_link; ?> // Ссылка "Добавить/Удалить" из закладок
<?php print $show_shipping_methods; ?> // Список включённых в магазине способов доставки
<?php print $show_payment_methods; ?> // Список включённых способов оплаты
<?php print $show_download_xls_catalog; ?> // Экспорт товаров в .xls c такой же категорией в словаре "Каталог", что и текущий товар
<?php print $show_download_doc_catalog; ?> // Экспорт товаров в .doc c такой же категорией в словаре "Каталог", что и текущий товар
<?php print $show_download_xls_tags; ?> // Экспорт товаров в .xls c такой же категорией в словаре "Теги", что и текущий товар
<?php print $show_download_doc_tags; ?> // Экспорт товаров в .doc c такой же категорией в словаре "Теги", что и текущий товар
<?php print $show_product_custom_comments; ?> // Отзывы (комментарии) на текущий товар
<?php print $show_product_right_region; ?> // Правый регион для блока в теле документа
<?php print $show_product_left_region; ?> // Левый регион для блока в теле документа
<?php print $show_product_simple_image_block; ?> // Монолитный блок с основной и дополнительными изображениями товара
<?php print $show_product_description; ?> // Текст главного описания товара
<?php print $show_product_price_cost; ?> // Стоимость товара (см.ограничения на вывод этого поля в шаблоне формы редактирования)
<?php print $show_product_weight; ?> // Вес товара
<?php print $show_product_dimensions; ?> // Габариты товара
<?php print $show_product_warranty; ?> // Текст гарантии
<?php print $show_product_fivestar_widget_dinamic; ?> // Виджет голосования с возможностью выбора голоса
<?php print $show_product_fivestar_widget_static; ?> // Виджет голосования без возможности выбора голоса (только показ)
<?php print $show_product_files; ?> // Таблица с вложенными файлами
<?php print $show_product_breadcrumb; ?> // Хлебные крошки
<?php print $show_product_media; ?> // Флэш-проигрыватель 
<?php print $show_product_notes; ?> // Текст предупреждения, замечания к товару
<?php print $show_product_specs; ?> // Характеристики товара
<?php print $show_product_sku; ?> // Артикул товара
<?php print $show_product_userpoints; ?> // Баллы с текстом
<?php print $show_product_userpoints_value; ?> // Значение баллов (без дополнительного текста)
<?php print $show_product_state_text; ?> // Индикатор наличи/отсутствия товара на складе ("В наличии" - "Под заказ")
<?php print $show_product_contact_bargain; ?> // Ссылка на контактную форму ("Я видел этот товар дешевле")
<?php print $show_product_contact_error; ?> // Ссылка на контактную форму ("Сообщить об ошибке в описании")
<?php print $show_product_contact_common; ?> // Ссылка на контактную форму ("Общие вопросы")
<?php print $show_product_contact_partnership; ?> // Ссылка на контактную форму ("Сотрудничество")
<?php print $show_product_contact_product; ?> // Ссылка на контактную форму ("Вопрос по товару")
<?php print $show_product_price_sell; ?> // Цена продажи (с текстом)
<?php print $show_product_price_discount; ?> // Скидка с текстом. Разница между ценой продажи и рекомендованной ценой
<?php print $show_product_price_full; ?> // Блок с ценой. Включает продажную цену и, если установлено, рекомендованную цену и, если цена продажи меньше рекомендованной цены, сумма скидки с текстом
<?php print $show_product_list_value; ?> // Сырое значение рекомендованной цены
<?php print $show_product_sell_value; ?> // Сырое значение цены продажи
<?php print $show_product_small_images; ?> // Дополнительные изображения товара
<?php print $show_product_image; ?> // Основное крупное изображение товара
<?php print $show_product_tabs; ?> // Блок с "быстрыми" закладками.
<?php print $show_product_accordion; ?> // Регион для сворачивающихся блоков.

-----------------------------------------------------------------------------------------------*/
?>
