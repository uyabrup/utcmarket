<?php
/*
// ѕросмотр доступных переменных дл€ шаблона

foreach ($fields as $id => $field) {
  $out .= '<b>$fields[\''.$id.'\']</b> = '.check_plain($field->content).'<br/><br/>';
}
drupal_set_message($out);
*/
?>

<?php
// print $fields['some_id']->content;
?>

<?php
$banner_link=$fields['field_banner_link_value']->content;
$banner_src=$fields['field_banner_fid']->content;
$banner_ref=$fields['field_banner_ref_nid']->content;
$banner_ref_url=explode('"', $banner_ref);
if ($banner_ref_url[1] != NULL)
    {
    print '<a href="' . $banner_ref_url[1] . '">' . $banner_src . '</a>';
    }
else
    {
    print '<a href="' . $banner_link . '">' . $banner_src . '</a>';
    }
?>



