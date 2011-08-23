<?php
// $Id$

/**
 * @file
 * Western Union payment administration menu items.
 *
 */

/**
 * Receive a Western Union payment for an order.
 */
function uc_western_union_receive_western_union_form($form_state, $order) {
  $balance = uc_payment_balance($order);

  $context = array(
    'revision' => 'formatted-original',
    'type' => 'amount',
  );

  $options = array(
    'sign' => FALSE,
    'thou' => FALSE,
    'dec' => '.',
  );

  $form['balance'] = array('#value' => uc_price($balance, $context));

  $form['order_id'] = array(
    '#type' => 'hidden',
    '#value' => $order->order_id,
  );

  $form['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount'),
    '#default_value' => uc_price($balance, $context, $options),
    '#size' => 10,
    '#field_prefix' => variable_get('uc_sign_after_amount', FALSE) ? '' : variable_get('uc_currency_sign', '$'),
    '#field_suffix' => variable_get('uc_sign_after_amount', FALSE) ? variable_get('uc_currency_sign', '$') : '',
  );

  $form['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('Reciept No. / Comment'),
    '#description' => t('Any notes about the Western Union transfer, like receipt number.'),
    '#size' => 64,
    '#maxlength' => 256,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Receive Western Union transfer'),
  );

  return $form;
}

function theme_uc_western_union_receive_western_union_form($form) {
  uc_add_js(drupal_get_path('module', 'uc_payment') .'/uc_payment.js');

  $output = '<p>'. t('Use the form to enter the Western Union transfer into the payments system.') .'</p>';
  $output .= '<p><strong>'. t('Order balance:') .'</strong> '
           . drupal_render($form['balance']) .'</p>';

  $output .= drupal_render($form);

  return $output;
}

function uc_western_union_receive_western_union_form_validate($form, &$form_state) {
  if (!$form_state['values']['western_union_exists'] && !is_numeric($form_state['values']['amount'])) {
    form_set_error('amount', t('The amount must be a number.'));
  }
}

function uc_western_union_receive_western_union_form_submit($form, &$form_state) {
  global $user;
  uc_payment_enter($form_state['values']['order_id'], 'western_union', $form_state['values']['amount'], $user->uid, '', $form_state['values']['comment']);
  drupal_set_message(t('Western union transfer received.'));
  $form_state['redirect'] = 'admin/store/orders/'. $form_state['values']['order_id'];
}


