<!-- ������ ����� �������������� -->

<div id = "edit-content-form" class = "edit-page">
    <div id = "left"> <!-- ����� ������� -->
        <div class = "main"> <!-- �������� ����� -->
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_taxonomy_tags; ?>
        </div> <!-- /�������� ����� -->

        <div class = "additional"> <!-- �������������� ����� -->
            <?php print $show_edit_form_banners; ?>

            <?php print $show_edit_form_menu; ?>

            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /�������������� ����� -->
    </div> <!-- /����� ������� -->

    <div id = "right"> <!-- ������ ������� -->
        <div class = "categories"> <!-- ���� � ����������� (����������) -->
            <h3><?php print t('Edit categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_categories; ?>

            <?php print $show_edit_form_taxonomy_common; ?>

            <?php print $show_edit_form_taxonomy_manufacturers; ?>

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

        <?php print $show_edit_form_sitemap; ?>

        <?php print $show_edit_form_revision; ?>

        <?php print $show_edit_form_path; ?>

        <?php print $show_edit_form_author; ?>

        <?php print $show_edit_form_comment; ?>

        <?php print $show_edit_form_options; ?>

        <?php print $show_edit_form_upload; ?>

        <?php print $show_edit_form_shipping; ?>
    </div>
</div>
<!-- ������ ����� �������������� -->

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
<?php print $show_edit_form_taxonomy_tags; ?> ���������� (����)
<?php print $show_edit_form_taxonomy_categories; ?> ���������� (������� ��������� �������)
<?php print $show_edit_form_taxonomy_common; ?> ���������� (����� �������)
<?php print $show_edit_form_taxonomy_tags; ?> ���������� (����)
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

*/

?>