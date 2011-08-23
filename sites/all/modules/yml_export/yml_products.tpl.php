<?php echo "<?xml version=\"1.0\" encoding=\"windows-1251\"?>\n" ?> 
<!DOCTYPE yml_catalog SYSTEM "shops.dtd">
<yml_catalog date="<?php echo date('Y-m-d h:i'); ?>">
<shop>
<name><?php echo variable_get('site_name', 'OpenStore'); ?></name>
  <company><?php echo variable_get('site_name', 'OpenStore'); ?></company>
  <url><?php echo $GLOBALS['base_url']; ?></url>

<currencies><currency id="<?php echo variable_get('uc_currency_code', 'UAH'); ?>" rate="1"/></currencies>

<categories>
	<?php foreach ($categories as $term): ?>
	<category id="<?php echo $term -> tid ?>" parentId="><?php echo $term -> parent ?>"><?php echo ys($term -> name)?></category>
	<?php endforeach; ?>  
</categories>

<offers>
	<?php 
	foreach ($nodes as $node): ?>
	<offer id="<?php echo $node -> model ?>" available="true">
	<url><?php echo url('node/' . $node -> nid, array('absolute' => TRUE)); ?></url>	
	<?php /* <vendorCode> echo $node -> model </vendorCode> */?>
	<price><?php echo $node -> sell_price ?></price>
	<currencyId><?php echo variable_get('uc_currency_code', 'UAH'); ?></currencyId>
	<categoryId><?php foreach($node -> taxonomy as $t) { if($t -> vid == variable_get('yml_export_vid', '')) echo $t -> tid; break; } ?></categoryId>
	<picture><?php echo $GLOBALS['base_url'] . '/' . ($node -> field_image_cache[0]['filepath']); ?></picture>
	<delivery><?php echo variable_get('yml_export_delivery', 'true'); ?></delivery>
	<name><?php echo ys($node -> title) ?></name>
	<description><?php echo ys(truncate_utf8(strip_tags($node -> teaser ? $node -> teaser : $node -> body), 255, TRUE)) ?></description>
	<sales_notes></sales_notes>
	</offer>
	<?php endforeach; ?>
</offers>  
  
</shop>
</yml_catalog>
