<div class="hot-offer-wrapper">
<?php
$banner_link =  $fields['field_banner_link_value']->content;

$banner_link = strip_tags($banner_link);

$banner_src = $fields['field_banner_fid']->content;
$banner_ref = $fields['field_banner_ref_nid']->content;
$banner_title = $fields['title']->content;
$banner_show_title = $fields['field_banner_ribbon_value']->content;


preg_match('/href="([^"]*)"/i', $banner_ref, $regs);
$banner_ref_url = $regs[1];


if ($banner_ref_url) {

print '<a href="'.$banner_ref_url.'">'.$banner_src.'</a>';

if ($banner_show_title) {

print '<div class="ribbon"><a href="'.$banner_ref_url.'">'.$banner_title.'</a></div>';

}

}

if (!$banner_ref_url && $banner_link) {

print '<a href="'.$banner_link.'">'.$banner_src.'</a>';

if (!$banner_ref_url && $banner_link && $banner_show_title) {

print '<div class="ribbon"><a href="'.$banner_link.'">'.$banner_title.'</a></div>';

}

}

if (!$banner_ref_url && !$banner_link) {

print $banner_src;

}

?>
</div>




