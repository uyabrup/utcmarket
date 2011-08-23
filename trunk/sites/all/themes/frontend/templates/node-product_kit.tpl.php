<div class = "node <?php print $classes; ?>" id = "node-<?php print $node->nid; ?>">
    <?php print $show_title; ?>
    <!-- Разделитель --><div class = "delimeter-10px">
    </div> <!-- /Разделитель -->

    <?php print $show_kit_main_image; ?>
<!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->

    <div id = "kit-left">
        <!-- Разделитель --><div class = "delimeter-20px">
        </div> <!-- /Разделитель -->

        <?php print $show_kit_items; ?>
<!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
<!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->
<!-- Разделитель --><div class = "delimeter-5px"></div> <!-- /Разделитель -->

        <div id = "block-share">
            <?php print $show_share_widget; ?>

            <?php print $show_bookmark_link; ?>
        </div>
<!-- Разделитель --><div class = "delimeter-5px"></div> <!-- /Разделитель -->
<!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->
        <!-- Разделитель --><div class = "delimeter-10px">
        </div> <!-- /Разделитель -->

        <?php print $show_description; ?>
<!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
<!-- Линейка --><div class = "ruler"></div> <!-- /Линейка -->
<!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->

        <div id = "block-notes">
            <?php print $show_shipping_methods; ?>

            <?php print $show_payment_methods; ?>
        </div>
    </div>

    <div id = "kit-right">
        <?php print $show_kit_amount_discounted; ?>
        <!-- Разделитель --><div class = "delimeter-10px">
        </div> <!-- /Разделитель -->

        <?php print $show_kit_text; ?>
        <!-- Разделитель --><div class = "delimeter-10px">
        </div> <!-- /Разделитель -->

        <?php print $show_rss_product_comments; ?>
        <!-- Разделитель --><div class = "delimeter-10px">
        </div> <!-- /Разделитель -->

        <?php print $show_cart_button; ?>
<!-- Разделитель --><div class = "delimeter-10px"></div> <!-- /Разделитель -->
    </div>
</div>