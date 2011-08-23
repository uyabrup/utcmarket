<!-- ������ ����� �������������� -->

<div id = "edit-content-form" class = "edit-newsletters">
    <div id = "left"> <!-- ����� ������� -->
        <div class = "main"> <!-- �������� ����� -->
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_token; ?>
        </div> <!-- /�������� ����� -->

        <div class = "additional"> <!-- �������������� ����� -->
            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /�������������� ����� -->
    </div> <!-- /����� ������� -->

    <div id = "right"> <!-- ������ ������� -->
        <div class = "categories"> <!-- ���� � ����������� (����������) -->
            <h3><?php print t('Edit categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_newsletter; ?>
        </div> <!-- /���� � ����������� -->

        <div class = "newsletter"> <!-- ���� � ����������� �������� -->
            <h3><?php print t('Newsletters options'); ?></h3>

            <?php print $show_edit_form_simplenews; ?>
        </div> <!-- /���� � ����������� �������� -->

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

        <?php print $show_edit_form_menu; ?>

        <?php print $show_edit_form_author; ?>

        <?php print $show_edit_form_comment; ?>

        <?php print $show_edit_form_options; ?>

        <?php print $show_edit_form_upload; ?>
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

<?php print $show_edit_form_taxonomy; ?> ���������� (����� ���������)
<?php print $show_edit_form_taxonomy_newsletter; ?> ���������� (����� ��������� ��������)
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
<?php print $show_edit_form_simplenews; ?> ���� � ����������� ��������

*/
?>