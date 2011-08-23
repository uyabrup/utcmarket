<?php
// $Id: uc_followup.admin.inc,v 1.10 2009/06/11 12:16:34 neochief Exp $

/**
 * @file
 * UC Follow-up admin forms and settings.
 */

/**
 * List all follow-ups.
 */
function uc_followup_list() {
  $result = db_query('SELECT followup_id, order_status, hours_past, name, status, repeat_after, repeat_max FROM {uc_followup} ORDER BY status DESC');
  
  $header = array(t('Name'), t('Triggers on'), t('Status'), '');
  $rows = array();
  while ($followup = db_fetch_array($result)) {
    $row = array();
    $row['name'] = check_plain($followup['name']);
    $row['triggers'] = t('%hours after order became %status', array('%hours' => format_plural($followup['hours_past'], '1 hour', '@count hours'), '%status' => uc_order_status_data($followup['order_status'], 'title')));
    $row['triggers'] .= $followup['repeat_after'] ? ' ('. t('repeat every %hours %times', array('%hours' => format_plural($followup['repeat_after'], '1 hour', '@count hours'), '%times' => $followup['repeat_max'] ? format_plural($followup['repeat_max'], '1 time', '@count times') : '')) .')' : '';
    $row['status'] = variable_get('uc_followup_auto_send', TRUE) ? $followup['status'] ? t('Auto') : t('Manual') : t('Manual (global)');
    $row['operations'] = l(t('Edit'), 'admin/store/follow-up/edit/'. $followup['followup_id']) .' &nbsp; &nbsp; &nbsp '. l(t('Delete'), 'admin/store/follow-up/delete/'. $followup['followup_id']);
    $rows[] = $row;
  }

  if (!empty($rows)) {
    $output = theme('table', $header, $rows);
  }
  else {
    $output = t('No follow-ups were created yet. <a href="!create-url">Create one?</a>', array('!create-url' => url('admin/store/follow-up/add')));
  }
  
  return $output;
}

/**
 * Follow-up compose/update form.
 */
function uc_followup_form($form_state, $followup = NULL) {
  if (isset($followup)) {
    if (isset($form_state['values'])) {
      $edit = $form_state['values'];
    }
    else {
      $edit = $followup;
    }

    $form['followup_id'] = array(
      '#type' => 'hidden',
      '#value' => $edit['followup_id'],
    );
    $btn = t('Update');
  }
  else {
    $btn = t('Create');
  }

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $edit['name'],
    '#description' => t("A brief description of your follow-up."),
    '#required' => TRUE,
  );

  foreach (uc_order_status_list() as $status) {
    $statuses[$status['id']] = $status['title'];
  }
  $form['order_status'] = array(
    '#type' => 'select',
    '#title' => t('Order status'),
    '#multiple' => FALSE,
    '#options' => $statuses,
    '#default_value' => $edit['order_status'],
    '#required' => TRUE,
  );
  $form['hours_past'] = array(
    '#type' => 'textfield',
    '#title' => t('Hours past'),
    '#default_value' => isset($edit['hours_past']) ? $edit['hours_past'] : 24,
    '#description' => t("Amount of hours needed to pass starting from the moment when order got status selected above in order to trigger follow-up."),
    '#required' => TRUE,
  );
  $form['repeat'] = array(
    '#type' => 'fieldset',
    '#title' => t('Repeat'),
    '#collapsible' => TRUE,
    '#collapsed' => !isset($edit['repeat_after']) || !$edit['repeat_after'],
    '#description' => t("<b>Warning!</b> If you will send too many follow-ups you will probably get banned by SPAM filters! So, do not overdo with repeats!"),
  );
  $form['repeat']['repeat_after'] = array(
    '#type' => 'textfield',
    '#title' => t('Repeat every N hours'),
    '#default_value' => isset($edit['repeat_after']) ? $edit['repeat_after'] : 0,
    '#description' => t("Amount of hours from last follow-up after which new follow-up will be send again. Zero or blank if you don't want to send any repeat."),
  );
  $form['repeat']['repeat_max'] = array(
    '#type' => 'textfield',
    '#title' => t('...but only X times'),
    '#default_value' => isset($edit['repeat_max']) ? $edit['repeat_max'] : 0,
    '#description' => t("Maximum amount of follow-ups to send (not includes initial one). Zero means unlimited."),
  );
  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Letter content'),
  );
  $form['message']['sender'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => $edit['sender'],
    '#description' => t('The "From" e-mail address. Example: <em>John Smith &lt;john@smith.com&gt;</em>. If blank, store defaults (%default) will be used.', array('%default' => uc_store_email_from())),
  );
  $form['message']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $edit['subject'],
    '#required' => TRUE,
  );
  $form['message']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $edit['body'],
    '#required' => TRUE,
    '#rows' => 20,
  );
  $form['message']['token_help'] = array(
    '#type' => 'fieldset',
    '#title' => t('Replacement patterns'),
    '#description' => t('You can make use of the replacement patterns in the e-mail from and recipients fields, the subject, and the message body.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  foreach (array('global', 'order') as $name) {
    $form['message']['token_help'][$name] = array(
      '#type' => 'fieldset',
      '#title' => t('@name replacement patterns', array('@name' => drupal_ucfirst($name))),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['message']['token_help'][$name]['content'] = array(
      '#value' => theme('token_help', $name),
    );
  }

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => isset($edit['status']) ? $edit['status'] : TRUE,
    '#required' => TRUE,
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $btn
  );

  return $form;
}

/**
 * Validate follow-up.
 */
function uc_followup_form_validate($form, &$form_state) {
}

/**
 * Save a follow-up to database.
 */
function uc_followup_form_submit($form, &$form_state) {
  if ($form_state['values']['followup_id']) {
    drupal_write_record('uc_followup', $form_state['values'], 'followup_id');
    drupal_set_message(t('Follow-up updated.'));
  } 
  else {
    drupal_write_record('uc_followup', $form_state['values']);
    drupal_set_message(t('Follow-up created.'));
  }
  $form_state['redirect'] = 'admin/store/follow-up';
}

/**
 * Follow-up removal confirmation.
 */
function uc_followup_delete_confirm($form_state, $followup) {
  $form['followup_id'] = array(
    '#type' => 'value',
    '#value' => $followup['followup_id'],
  );

  return confirm_form($form, t('Are you sure you want to delete test @name?', array('@name' => $followup['name'])), 'admin/store/follow-up', NULL, t('Delete'));
}

/**
 * Submit detelete confirm — remove a follow-up from database.
 */
function uc_followup_delete_confirm_submit($form, &$form_state) {
  db_query("DELETE FROM {uc_followup} WHERE followup_id = %d", $form_state['values']['followup_id']);
  db_query("DELETE FROM {uc_followup_sent} WHERE followup_id = %d", $form_state['values']['followup_id']);

  drupal_set_message(t('Follow-up removed.'));
  $form_state['redirect'] = 'admin/store/follow-up';
}

/**
 * Compose message form.
 */
function uc_followup_customer($order) {
  // Load pending follow-ups
  $result = db_query('SELECT fu.*, fus.date, fus.manual, fus.email FROM {uc_followup} fu LEFT JOIN (SELECT * FROM {uc_followup_sent} WHERE order_id = %d GROUP BY followup_id ORDER BY date DESC) fus ON fu.followup_id = fus.followup_id WHERE fu.order_status = "%s" AND (fus.date IS NULL OR fu.repeat_after > 0) ORDER BY fu.status DESC', $order->order_id, $order->order_status);
  while ($data = db_fetch_array($result)) {
    $pending[$data['followup_id']] = $data;
  }
  // Render pending follow-ups
  $output .= '<h2>'. t('Pending follow-ups') .'</h2>';
  if (!empty($pending)) {
    $header = array(t('Follow-up'), t('Triggers on'), t('Status'), '');
    $rows = array();
    foreach ($pending as $followup) {
      $row = array();
      $row['name'] = check_plain($followup['name']);
      $row['triggers'] = t('%hours after order became %status', array('%hours' => format_plural($followup['hours_past'], '1 hour', '@count hours'), '%status' => uc_order_status_data($followup['order_status'], 'title')));
      $row['triggers'] .= $followup['repeat_after'] ? ' ('. t('repeat every %hours %times', array('%hours' => format_plural($followup['repeat_after'], '1 hour', '@count hours'), '%times' => $followup['repeat_max'] ? format_plural($followup['repeat_max'], '1 time', '@count times') : '')) .')' : '';
      $row['status'] = variable_get('uc_followup_auto_send', TRUE) ? $followup['status'] ? t('Auto') : t('Manual') : t('Manual (global)');
      $row['operations'] = l(t('Preview & send'), 'admin/store/orders/'. $order->order_id .'/follow-up/send/'. $followup['followup_id']) .' &nbsp; &nbsp; &nbsp '. l(t('Skip'), 'admin/store/orders/'. $order_id .'/follow-up/skip/'. $followup['followup_id']);
      $rows[] = $row;
    }
    $output .= theme('table', $header, $rows);
  }
  else {
    $output .= '<p>'. t('No follow-ups were schedulled for this stage.') .'</p>';
  }

  // Load sent follow-ups
  $result = db_query('SELECT fus.*, fu.name, fu.status FROM {uc_followup_sent} fus LEFT JOIN {uc_followup} fu ON fu.followup_id = fus.followup_id WHERE fus.order_id = %d ORDER BY fus.date, fu.order_status, fu.status', $order->order_id);
  while ($data = db_fetch_array($result)) {
    $processed[] = $data;
  }
  // Render sent follow-ups
  $output .= '<h2>'. t('Processed follow-ups') .'</h2>';
  if (!empty($processed)) {
    $header = array(t('Date'), t('Follow-up'), t('Status'), '');
    $rows = array();
    foreach ($processed as $followup) {
      $row = array();
      $row['date'] = format_date($followup['date']);
      $row['name'] = check_plain($followup['name']);
      $row['status'] = $followup['email'] ? t('Sent') : t('Skipped');
      $row['operations'] = l(t('Details'), 'admin/store/orders/'. $order->order_id .'/follow-up/details/'. $followup['follow_id']);
      $rows[] = $row;
    }
    $output .= theme('table', $header, $rows);
  }
  else {
    $output .= '<p>'. t('No follow-ups were sent on this stage yet.') .'</p>';
  }

  $replacements = uc_followup_get_token_replacements($order);
  drupal_set_title(t('Follow-ups for #@order (@customer)', array('@order' => $order->order_id, '@customer' => token_replace_multiple('[order-first-name] [order-last-name]', $replacements))));

  return $output;
}

/**
 * Global module's settings form.
 */
function uc_followup_settings() {
  $form = array();

  $form['uc_followup_auto_send'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send follow-ups automatically (via cron run)'),
    '#description' => t('If disabled, follow-ups could only be send manually through the order admin interface. Usefull when full control over the messaging with customers needed.'),
    '#default_value' => variable_get('uc_followup_auto_send', TRUE),
  );
  $form['uc_followup_send_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of letters sent by one cron run'),
    '#default_value' => variable_get('uc_followup_send_limit', 100),
    '#description' => t('Large amount of simultaneous sendings can be threated as SPAM by some of email services.'),
  );
  $form['uc_followup_bcc'] = array(
    '#type' => 'textfield',
    '#title' => t('Bcc email adress'),
    '#description' => t('Blind carbon copy is the e-mail address which will receive the copy of letter without giving beign tracked by original recepient.'),
    '#default_value' => variable_get('uc_followup_bcc', ''),
  );

  return system_settings_form($form);
}

/**
 * Validate global settings form.
 */
function uc_followup_settings_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['uc_followup_send_limit']) || $form_state['values']['uc_followup_send_limit'] < 0) {
    form_set_error('uc_followup_send_limit', t('Should be positive number or zero.'));
  }
  if (!empty($form_state['values']['uc_followup_bcc']) && !valid_email_address($form_state['values']['uc_followup_bcc'])) {
    form_set_error('uc_followup_bcc', t('The e-mail address %mail is not valid.', array('%mail' => $form_state['values']['uc_followup_bcc'])));
  }
}

/**
 * Review & send follow-up to customer.
 */
function uc_followup_send($form_state, $order, $followup = NULL, $follow_id = NULL) {
  if (isset($form_state['values'])) {
    $edit = $form_state['values'];
  }
  else {
    // New follow-up message.
    if (!empty($followup)) {
      $edit = $followup;
    }
    // Sent follow-up details.
    elseif ($follow_id) {
      $edit = uc_followup_sent_details($follow_id);
    }
  }
  $form['#order'] = $order;
  $form['#followup'] = $followup;

  $replacements = uc_followup_get_token_replacements($order);

  // Apply token replacements to from and recipient e-mail addressses.
  $edit['sender'] = token_replace_multiple($edit['sender'], $replacements);
  $edit['subject'] = token_replace_multiple($edit['subject'], $replacements);
  $edit['body'] = token_replace_multiple($edit['body'], $replacements);
  $edit['order-email'] = token_replace_multiple('[order-email]', $replacements);

  if (isset($edit['date'])) {
    if (isset($edit['email'])) {
      $form['email_sent'] = array(
        '#type' => 'item',
        '#title' => t('Sent to'),
        '#default_value' => $edit['email'],
      );
    }
    else {
      $form['email_sent'] = array(
        '#type' => 'item',
        '#title' => t('Sent to'),
        '#value' => t('This follow-up was skipped.'),
      );
    }
  }
  else {
    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Send to'),
      '#default_value' => $edit['order-email'],
    );
  }

  $form['sender'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => !empty($edit['sender']) ? $edit['sender'] : uc_store_email_from(),
    '#description' => t('The "From" e-mail address. Example: <em>John Smith &lt;john@smith.com&gt;</em>. If blank, store defaults (%default) will be used.', array('%default' => uc_store_email_from())),
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $edit['subject'],
    '#required' => TRUE,
  );
  $form['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $edit['body'],
    '#required' => TRUE,
    '#rows' => 20,
  );

  if (isset($edit['date'])) {
    $form['forward'] = array(
      '#type' => 'fieldset',
      '#title' => t('Forward'),
      '#description' => '<p>'. t('You may edit the message before forwarding it to e-mail listed below.') .'</p>',
      '#prefix' => '<div class="container-inline">',
      '#suffix' => '</div>',
    );
    $form['forward']['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Forward to'),
      '#default_value' => isset($edit['email']) ? $edit['email'] : $edit['order-email'],
    );
    $form['forward']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send'),
    );
  }
  else {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send'),
    );
    $form['back'] = array(
      '#type' => 'markup',
      '#value' => l(t('Cancel'), 'admin/store/orders/'. $order->order_id .'/follow-up'),
    );
  }

  
  return $form;
}

/**
 * Validate follow-up.
 */
function uc_followup_send_validate($form, &$form_state) {
  if (isset($form_state['values']['email']) && !valid_email_address($form_state['values']['email'])) {
    form_set_error('emal', t('The e-mail address %mail is not valid.', array('%mail' => $form_state['values']['emal'])));
  }
}

/**
 * Send follow-up.
 */
function uc_followup_send_submit($form, &$form_state) {
  $order = $form['#order'];
  $followup = $form['#followup'];
  $replacements = uc_followup_get_token_replacements($order);

  $settings = $form_state['values'];

  $sent = drupal_mail('uc_followup', '', $settings['email'], '', $settings, empty($settings['sender']) ? uc_store_email_from() : $settings['sender']);
  if (!$sent['result']) {
    watchdog('ca', 'Attempt to e-mail invoice for order @order_id to @email failed.', array('@email' => $settings['email'], '@order_id' => $order->order_id), WATCHDOG_ERROR);
  }
  else {
    // If follow-up object is empty, than we're sending forward.
    if (empty($followup)) {
      drupal_set_message(t('Message sent.'));
    }
    // else we should save data about this message
    else {
      $settings['date'] = time();
      $settings['followup_id'] = $followup['followup_id'];
      $settings['order_id'] = $order->order_id;
      $settings['manual'] = TRUE;
      drupal_write_record('uc_followup_sent', $settings);
      drupal_set_message(t('Follow-up was sent successfully.'));
    }
    $form_state['redirect'] = 'admin/store/orders/'. $order->order_id .'/follow-up';
  }
}

/**
 * Follow-up skip confirmation.
 */
function uc_followup_skip_confirm($form_state, $order, $followup) {
  $replacements = uc_followup_get_token_replacements($order);

  // Apply token replacements to from and recipient e-mail addressses.
  $form['#sender'] = token_replace_multiple($edit['sender'], $replacements);
  $form['#subject'] = token_replace_multiple($edit['subject'], $replacements);
  $form['#body'] = token_replace_multiple($edit['body'], $replacements);

  $form['#order'] = $order;
  $form['#followup'] = $followup;
  return confirm_form($form, t('Are you sure you want to skip followup @name for order #@order (@customer)?', array('@name' => $followup['name'], '@order' => $order->order_id, '@customer' => token_replace_multiple('[order-first-name] [order-last-name]', $replacements))), 'admin/store/follow-up', NULL, t('Skip follow-up'));
}

/**
 * Skip a follow-up.
 */
function uc_followup_skip_confirm_submit($form, &$form_state) {
  $order = $form['#order'];
  $followup = $form['#followup'];

  $data = array(
    'order_id' => $order->order_id,
    'followup_id' => $followup['followup_id'],
    'manual' => 1,
    'date' => time(),
    'sender' => $form['#sender'],
    'subject' => $form['#subject'],
    'body' => $form['#body'],
  );
  drupal_write_record('uc_followup_sent', $data);
  drupal_set_message(t('Follow-up skipped.'));

  $form_state['redirect'] = 'admin/store/orders/'. $order->order_id .'/follow-up';
}