<?php if (!empty($node)): ?>

    <div id = "product-page" class = "sidebar-left-right">
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

                    <?php print $show_download_xls_catalog; ?>

                    <!-- Разделитель --><div class = "delimeter-5px">
                    </div> <!-- /Разделитель -->

                    <?php print $show_download_doc_catalog; ?>

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


            <!-- Разделитель --><div class = "delimeter-15px">
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

                <?php print $show_product_breadcrumb; ?>
    </div>

<?php
endif;
?>