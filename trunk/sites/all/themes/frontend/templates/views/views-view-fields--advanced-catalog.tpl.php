<?php
// �������� ��������� ���������� ��� �������
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
. '</div>'; // ������������ �����������
    }
else
    {
    print '<div class="cat-product-img">' . $fields['field_image_cache_fid_1']->content
      . '</div>'; // ����������� ��� �����
    }

print '<div class="cat-product-info">';
print '<div class="cat-product-title">' . $fields['title']->content . '</div>'; // ���������
print '<div class="cat-product-tid">' . $fields['tid']->content . '</div>'; // ������ �� ������� "�������������"
//print '<div class="cat-product-tid">' . $fields['tid_1']->content . '</div>'; // ������ �� ������� "�������������"
print '<div class="cat-product-teaser">' . $fields['teaser']->content . '</div>'; // ��������� �������� ������
print '<div class="cat-product-price">' . $fields['sell_price']->content . '</div>';              // ���� �������
print '<div class="cat-product-discount">' . $fields['field_discount_value']->content . '</div>'; // ������
print '</div>';
?>