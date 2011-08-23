<?php
// Просмотр доступных значений для этого шаблона
/*
foreach ($widgets as $id => $widget) {
  $out .= '<b>$widgets[\''.$id.'\']</b> = '.check_plain($widget->content).'<br/><br/>';
}
drupal_set_message($out);
*/
?>

<?php
/*
print $widgets['some_id']->operator;  // вывод оператора
print $widgets['some_id']->widget; // вывод виджета
print $widgets['some_id']->label; // вывод надписи
print $button; // вывод кнопки
*/
?>

<div class = "product-filters">
    <div class = "price container-inline filter-item">
        <label><?php print $widgets['filter-sell_price']->label; ?></label>

        <?php print $widgets['filter-sell_price']->widget; ?>

        <?php print variable_get('uc_currency_sign', FALSE); ?>
    </div>

    <div class = "categories container-inline filter-item">
        <?php print $widgets['filter-tid']->widget; ?>
    </div>

    <div class = "trademarks container-inline filter-item">
        <?php print $widgets['filter-tid_1']->widget; ?>
    </div>

    <br style = "clear: both;" />

    <div class = "title container-inline filter-item">
        <label><?php print $widgets['filter-title']->label; ?></label>

        <?php print $widgets['filter-title']->widget; ?>
    </div>

    <div class = "button">
        <?php print $button; ?>
    </div>
</div>