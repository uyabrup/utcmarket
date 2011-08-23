<?php
// Просмотр доступных переменных для шаблона
/*
foreach ($fields as $id => $field) {
  $out .= '<b>$fields[\''.$id.'\']</b> = '.check_plain($field->content).'<br/><br/>';
}
drupal_set_message($out);
*/
?>

<?php // print $fields['some_id']->content; ?>


<?php

if ($fields['tid']->content)
    {
    print '<div class="cat-product-img">' . $fields['field_image_cache_fid']->content
. '</div>'; // оригинальное изображение
    }
else
    {
    print '<div class="cat-product-img">' . $fields['field_image_cache_fid_1']->content
      . '</div>'; // изображение для акции
    }

print '<div class="cat-product-info">';
print '<div class="cat-product-title">' . $fields['title']->content . '</div>'; // заголовок
print '<div class="cat-product-tid">' . $fields['tid']->content . '</div>'; // термин из словаря "Производители"
//print '<div class="cat-product-tid">' . $fields['tid_1']->content . '</div>'; // термин из словаря "Производители"
print '<div class="cat-product-teaser">' . $fields['teaser']->content . '</div>'; // аннотация описания товара
print '<div class="cat-product-price">' . $fields['sell_price']->content . '</div>';              // цена продажи
print '<div class="cat-product-discount">' . $fields['field_discount_value']->content . '</div>'; // скидка
print '</div>';
?>