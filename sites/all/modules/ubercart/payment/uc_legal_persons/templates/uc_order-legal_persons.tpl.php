<?php
// $Id: uc_order-legal_persons.tpl.php,v 1.1 2011/02/12 10:55:26 podarok Exp $

/**
 * @file
 * This file is the default customer invoice template for Ubercart.
 */
?>


	<table border="0" cellpadding="0" cellspacing="5"><tr><td>&nbsp;</td><td><b><?php echo $store_name; ?></b></td></tr><tr><td valign="top"><b><?php echo t('Supplier'); ?></b></td><td>

        <?php echo $uc_uk_zkpo; ?>, <?php echo $store_phone; ?><br/>

        <?php echo $uc_uk_rr; ?><br/>

        <?php echo $uc_uk_mfo; ?> <?php echo $uc_uk_ipn; ?><br/>

        <?php echo $uc_uk_sv_number; ?><br/>

        <?php echo $store_address; ?></td></tr><tr><td><b><?php echo t('Customer:'); ?> <?php echo $order->billing_company; ?></b></td><td/></tr><tr><td><b><?php echo t('Customer'); ?></b></td><td><?php echo t('the same'); ?></td></tr></table>
		<b><?php echo t('Products on order:'); ?>&nbsp;</b>
		<table width="100%" border="0" cellpadding="0" cellspacing="2"><tr bgcolor="#C0E0E0"><td colspan="8" align="center"><b><?php echo t('Order #:'); ?> <?php echo $order_link; ?> <?php echo $order_date_created; ?>
		</b></td></tr><tr bgcolor="#E3E3E3"><td><?php echo t('№'); ?></td><td><?php echo t('SKU: '); ?></td><td><?php echo t('Product'); ?></td><td><?php echo t('Measuring'); ?></td><td><?php echo t('Quantity'); ?></td><td><?php echo t('Amount'); ?></td><td><?php echo t('UA PDV'); ?></td><td><?php echo t('Total'); ?></td></tr>

                          <?php if (is_array($order->products)) {
                            $context = array(
                              'revision' => 'formatted',
                              'type' => 'order_product',
                              'subject' => array(
                                'order' => $order,
                              ),
                            );
							$invoice_counter = 1;
                            foreach ($order->products as $product) {
							
                              $price_info = array(
                                'price' => $product->price,
                                'qty' => $product->qty,
                              );
                              $context['subject']['order_product'] = $product;
                              $context['subject']['node'] = node_load($product->nid);
                              ?>
                          
						  
						  <tr><td><?php echo $invoice_counter; ?></td><td><?php echo $product->model; ?></td><td><?php echo $product->title; ?></td><td><?php echo t('items'); ?></td><td><?php echo $product->qty; ?></td><td><?php echo uc_currency_format(($product->price));?></td><td><?php echo uc_currency_format(($product->price)*($product->qty)/6);?></td><td><?php echo uc_price($price_info, $context); ?></td></tr>

						  

                          <?php $invoice_counter++; }
                              }?> 
							  
							  <tr>
  <td colspan="5" align="right">
    <b><?php echo t('Invoice total:'); ?></b>
  </td>
  <td>
    <b>  </b>
  </td>
  <td>
    <b>  <?php $line_items = &$order->line_items; echo uc_currency_format(($line_items[0]['amount'])/6);?></b>
  </td>
  <td>
    <b>  <?php echo $order_subtotal; ?> </b>
  </td>
</tr>
                        </table>

                      </table>



