<!-- ������ ����� �������������� -->

<div id = "edit-content-form" class = "edit-product">
    <div id = "left"> <!-- ����� ������� -->
        <div class = "main"> <!-- �������� ����� -->
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_taxonomy_tags; ?>

            <?php print $show_edit_form_image; ?>
        </div> <!-- /�������� ����� -->

        <div class = "additional"> <!-- �������������� ����� -->
            <?php print $show_edit_form_specs; ?>

            <?php print $show_edit_form_additional; ?>
			
			<?php print $show_edit_form_media; ?>						

            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /�������������� ����� -->
    </div> <!-- /����� ������� -->

    <div id = "right"> <!-- ������ ������� -->
        <div class = "prices"> <!-- ���� � ������ -->
            <h3><?php print t('Edit product prices'); ?></h3>

			<?php print $show_edit_form_cost; ?>
						
			<input type="button" class="form-submit" onclick="" value="<? print t('Calculate')?>" id="calc_price_btn" />
			
            <?php print $show_edit_form_sell_price; ?>

            <?php print $show_edit_form_list_price; ?>
			
			<?php print $show_edit_form_crs_m; ?>
			
            <?php print $show_edit_form_model; ?>
        </div> <!-- /���� � ������ -->

        <div class = "categories"> <!-- ���� � ����������� (����������) -->
            <h3><?php print t('Edit product categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_categories; ?>

            <?php print $show_edit_form_taxonomy_manufacturers; ?>

            <?php print $show_edit_form_taxonomy_promo; ?>
        </div> <!-- /���� � ����������� -->

        <div class = "shipping"> <!-- ��, ��� �������� �������� (��������������) -->
            <h3><?php print t('Edit product shipping'); ?></h3>

            <?php print $show_edit_form_shippable; ?>

            <?php print $show_edit_form_weight_weight; ?>
        </div> <!-- ��, ��� �������� �������� -->

        <div class = "buttons"> <!-- ���� � �������� -->
            <?php print $show_edit_form_submit; ?>

            <?php print $show_edit_form_save_continue; ?>

            <?php print $show_edit_form_submit_again; ?>

            <?php print $show_edit_form_submit_preview; ?>

            <?php print $show_edit_form_delete; ?>
        </div> <!-- /���� � �������� -->
    </div> <!-- /������ ������� -->

    <div id = "bottom"> <!-- /������ (���� ������� �� ��������������) -->
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
<!-- ������ ����� �������������� -->

<?php

/*
* drupal_render($form) �������� ������������ � ���� �������. 
������ ��� ��������� �����.  �� ������ ������ ����������� ���� ��� � ����� ����� ��������, ����� ����, ��������� ����, ����� ������������� �� ����� ���������� ����������
*/

print drupal_render($form);
?>

<?php
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ����� ��������� � ������ ���������� �� ��������� ���������� ����� ���� ������� �����: http://openstore.org.ua/node/137 /// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

<?php print $show_edit_form_taxonomy; ?> ���������� (�����)
<?php print $show_edit_form_taxonomy_tags; ?> ���������� (����)
<?php print $show_edit_form_taxonomy_categories; ?> ���������� (������� ��������� �������)
<?php print $show_edit_form_taxonomy_manufacturers; ?> ���������� (�������������)
<?php print $show_edit_form_taxonomy_promo; ?> ���������� (�����)

<?php print $show_edit_form_body; ?> �������� �����
<?php print $show_edit_form_domain; ?> ����� �������
<?php print $show_edit_form_menu; ?> ������ �� �������� � ����
<?php print $show_edit_form_revision; ?> �������� ���������
<?php print $show_edit_form_author; ?> �����
<?php print $show_edit_form_options; ?> ����� ����������
<?php print $show_edit_form_sitemap; ?> ����� �����
<?php print $show_edit_form_metatags; ?> ��������
<?php print $show_edit_form_comment; ?> ��������� ������������
<?php print $show_edit_form_path; ?> ����� ��������
<?php print $show_edit_form_upload; ?> ��������� �����
<?php print $show_edit_form_buttons; ?> ���� � �������� �����
<?php print $show_edit_form_submit; ?> ������ "���������"
<?php print $show_edit_form_submit_preview; ?> ������ "��������������� ��������"
<?php print $show_edit_form_submit_again; ?> ������ "��������� � ������� �������� �����"
<?php print $show_edit_form_save_continue; ?> ������ "��������� � ����������"
<?php print $show_edit_form_delete; ?> ������ "�������"
<?php print $show_edit_form_title; ?> ��������� ���������

<?php print $show_edit_form_image; ?> ���� � ������������� ������
<?php print $show_edit_form_specs; ?> ���� � ������������ ����������������
<?php print $show_edit_form_googlecheck; ?> ��������� Google Checkout
<?php print $show_edit_form_additional; ?> ���� � ��������������� �������
<?php print $show_edit_form_shipping; ?> ���� � ��������� ��������
<?php print $show_edit_form_product; ?> ���� � ���������� ������
<?php print $show_edit_form_prices; ?> ���� � ������
<?php print $show_edit_form_list_price; ?> ���� �����-�����
<?php print $show_edit_form_cost; ?> ��������� ������
<?php print $show_edit_form_sell_price; ?> ���� �������
<?php print $show_edit_form_shippable; ?> ����� ������������ ��� ���
<?php print $show_edit_form_weight; ?> ���� � ����� ������
<?php print $show_edit_form_weight_weight; ?> �������� ����
<?php print $show_edit_form_weight_units; ?> ������� ��������� ����
<?php print $show_edit_form_dimensions; ?> ���� � ��������� ������
<?php print $show_edit_form_length_units; ?> ������� ��������� �����
<?php print $show_edit_form_dim_length; ?> �������� �����
<?php print $show_edit_form_dim_width; ?> �������� ������
<?php print $show_edit_form_dim_height; ?> �������� ������
<?php print $show_edit_form_pkg_qty; ?> ����������
<?php print $show_edit_form_default_qty; ?> ���������� �� ���������
<?php print $show_edit_form_ordering; ?> ����������
<?php print $show_edit_form_model; ?> �������


*/
?>