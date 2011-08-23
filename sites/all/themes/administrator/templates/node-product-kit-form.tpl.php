<!-- ������ ����� �������������� -->

<div id = "edit-content-form" class = "edit-product-kit">
    <div id = "left"> <!-- ����� ������� -->
        <div class = "main"> <!-- �������� ����� -->
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_taxonomy_tags; ?>

            <?php print $show_edit_form_mutable; ?>

            <?php print $show_edit_form_select; ?>

            <!-- ����������� --><div class = "delimeter-10px">
            </div> <!-- /����������� -->

            <?php print $show_edit_form_items; ?>

            <!-- ����������� --><div class = "delimeter-5px">
            </div> <!-- /����������� -->

            <?php print $show_edit_form_default_qty; ?>

            <?php print $show_edit_form_ordering; ?>

            <?php print $show_edit_form_shipping; ?>

            <?php print $show_edit_form_image; ?>
        </div> <!-- /�������� ����� -->

        <div class = "additional"> <!-- �������������� ����� -->
            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /�������������� ����� -->
    </div> <!-- /����� ������� -->

    <div id = "right"> <!-- ������ ������� -->

        <!-- ���� � ������ -->
        <?php if ($show_edit_form_kit_total): ?>

            <div class = "prices">
                <h3><?php print t('Edit prices'); ?></h3>

                <?php print $show_edit_form_kit_total; ?>
            </div>

        <?php
        endif;
        ?>
        <!-- /���� � ������ -->

        <div class = "categories"> <!-- ���� � ����������� (����������) -->
            <h3><?php print t('Edit categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_categories; ?>

            <?php print $show_edit_form_taxonomy_promo; ?>
        </div> <!-- /���� � ����������� -->

        <div class = "buttons"> <!-- ���� � �������� -->
            <?php print $show_edit_form_submit; ?>

            <?php print $show_edit_form_save_continue; ?>

            <?php print $show_edit_form_submit_again; ?>

            <?php print $show_edit_form_submit_preview; ?>

            <?php print $show_edit_form_delete; ?>
        </div> <!-- /���� � �������� -->
    </div> <!-- /������ ������� -->

    <div id = "bottom"> <!-- /������ (���� ������� �� ��������������) -->
        <h3><?php print t('Other options'); ?></h3>

        <?php print $show_edit_form_path; ?>

        <?php print $show_edit_form_menu; ?>

        <?php print $show_edit_form_revision; ?>

        <?php print $show_edit_form_author; ?>

        <?php print $show_edit_form_options; ?>

        <?php print $show_edit_form_sitemap; ?>

        <?php print $show_edit_form_comment; ?>

        <?php print $show_edit_form_upload; ?>

        <?php print $show_edit_form_googlecheck; ?>
    </div>
</div>
<!-- /������ ����� �������������� -->

<?php
print drupal_render($form);
//drupal_render($form) �������� ������������ � ���� �������. ������ ��� ��������� �����.
?>

<?php
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ����� ��������� � ������ ���������� �� ��������� ���������� ����� ���� ������� �����: http://openstore.org.ua/node/137 /// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

<?php print $show_edit_form_taxonomy; ?> ���������� (�����)
<?php print $show_edit_form_taxonomy_categories; ?> ���������� (������� ��������� �������)
<?php print $show_edit_form_taxonomy_tags; ?> ���������� (����)
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
<?php print $show_edit_form_mutable; ?> ����� ������ �������
<?php print $show_edit_form_select; ?> ����� �������
<?php print $show_edit_form_items; ?> 
<?php print $show_edit_form_default_qty; ?> ���������� �������, ������� ����� �������� ����������
<?php print $show_edit_form_ordering; ?> ���������� �������
<?php print $show_edit_form_shipping; ?> ����� � ������� ��������
<?php print $show_edit_form_image; ?> ����������� ������
<?php print $show_edit_form_googlecheck; ?> ����� Google Checkout
<?php print $show_edit_form_kit_total; ?> ����� ����� ������

*/
?>