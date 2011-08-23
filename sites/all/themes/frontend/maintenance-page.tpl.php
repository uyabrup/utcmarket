<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml" xml:lang = "<?php print $language->language ?>"
  lang = "<?php print $language->language ?>" dir = "<?php print $language->dir ?>">
    <head>
        <title><?php print $head_title; ?></title>
        <?php print $head; ?>
        <?php print $styles; ?>      
		<?php print $scripts; ?>
		
    </head>
        <body class = "<?php print $body_classes; ?>">
	        <div id="maintenance">                 
		             <div class="maintenance-content">
					     <?php if ($title): ?><h1 class = "title"><?php print $title; ?></h1><?php endif; ?>
		                <?php print $content; ?>
						<?php 
						
	if (variable_get('openstore_add_contact_info', TRUE)) {					

    $store_name = variable_get('uc_store_name', FALSE);
    $store_owner = variable_get('uc_store_owner', FALSE);
    $store_email = variable_get('uc_store_email', FALSE);
    $store_phone = variable_get('uc_store_phone', FALSE);
    $store_fax = variable_get('uc_store_fax', FALSE);
    $store_city = variable_get('uc_store_city', FALSE);
    $store_street1 = variable_get('uc_store_street1', FALSE);
    $postal_code = variable_get('uc_store_postal_code', FALSE);
    $store_country = uc_country_get_by_id(variable_get('uc_store_country', FALSE));

    $items = array();
    $items[] = ($store_name) ?  t('Store name:') . ' ' . $store_name : '';
    $items[] = ($store_owner) ? t('Store owner:') . ' ' . $store_owner : '';
    $items[] = ($store_email) ?  t('Store e-mail:') . ' ' . $store_email : '';
    $items[] = ($store_phone) ? t('Store phone:') . ' ' . $store_phone : '';
    $items[] = ($store_fax) ? t('Store fax:') . ' ' . $store_fax : '';
    $items[] = ($store_city) ? t('Store city:') . ' ' . $store_city : '';
    $items[] = ($store_street1) ? t('Store street 1:') . ' ' . $store_street1 : '';
    $items[] = ($postal_code) ? t('Store postal code:') . '&nbsp;' . $postal_code : '';	
    
	$items = array_filter($items);
	
	if (!empty($items)) {
	print '<div class="shop-contacts">' . theme_item_list($items, t('Store contacts'), 'ul', NULL) . '</div>';
    }
    }
						?>						
			         </div>						
	        </div>
		     <?php print $closure; ?>
        </body>
</html>