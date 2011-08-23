<!-- Шаблон формы редактирования -->

<div id = "edit-content-form" class = "edit-newsletters">
    <div id = "left"> <!-- Левая колонка -->
        <div class = "main"> <!-- Основные опции -->
            <?php print $show_edit_form_title; ?>

            <?php print $show_edit_form_body; ?>

            <?php print $show_edit_form_token; ?>
        </div> <!-- /Основные опции -->

        <div class = "additional"> <!-- Дополнительные опции -->
            <?php print $show_edit_form_metatags; ?>

            <?php print $show_edit_form_domain; ?>
        </div> <!-- /Дополнительные опции -->
    </div> <!-- /Левая колонка -->

    <div id = "right"> <!-- Правая колонка -->
        <div class = "categories"> <!-- Блок с категориями (таксономия) -->
            <h3><?php print t('Edit categories'); ?></h3>

            <?php print $show_edit_form_taxonomy_newsletter; ?>
        </div> <!-- /Блок с категориями -->

        <div class = "newsletter"> <!-- Блок с настройками рассылки -->
            <h3><?php print t('Newsletters options'); ?></h3>

            <?php print $show_edit_form_simplenews; ?>
        </div> <!-- /Блок с настройками рассылки -->

        <div class = "buttons"> <!-- Блок с кнопками -->
            <?php print $show_edit_form_submit; ?>

            <?php print $show_edit_form_save_continue; ?>

            <?php print $show_edit_form_submit_again; ?>

            <?php print $show_edit_form_submit_preview; ?>

            <?php print $show_edit_form_delete; ?>
        </div> <!-- /Блок с кнопками -->
    </div> <!-- /Правая колонка -->

    <div id = "bottom"> <!-- /Подвал (сюда пихайте всё второстепенное) -->
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
<!-- Шаблон формы редактирования -->

<?php
print drupal_render($form);
//drupal_render($form) является обязательным в этом шаблоне. Служит для валидации формы.
?>

<?php
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Более подробная и свежая информация по доступным переменным может быть найдена здесь: http://openstore.org.ua/node/137 /// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

<?php print $show_edit_form_taxonomy; ?> Таксономия (выбор категорий)
<?php print $show_edit_form_taxonomy_newsletter; ?> Таксономия (выбор категории рассылки)
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
<?php print $show_edit_form_simplenews; ?> Блок с настройками рассылки

*/
?>