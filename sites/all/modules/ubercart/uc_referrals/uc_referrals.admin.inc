<?php
//$Id: uc_referrals.admin.inc,v 1.3 2009/03/02 07:12:17 ryangroe Exp $

/**
 * @file
 * Referrals administration menu items.
 */


/**
 * Display a list of referrals.
 */
function uc_referrals_admin_settings_list()
{
	$header = array(
		array("data" => t("Org Name"), "field" => "r.name", "sort" => "asc"),
		array("data" => t("Org Description"), "field" => "r.description"),
		array("data" => t("User"), "field" => "u.name"),
		array("data" => t("Rate"), "field" => "r.rate"),
		array("data" => t("Code & URL link"), "field" => "r.code"),
		array("data" => t("Operations"), "colspan" => 3),
	);

	$query = "SELECT r.*, u.name username, u.mail email FROM {uc_referrals} r"
		. " LEFT JOIN {users} u ON r.user_id=u.uid";
	$tablesort = tablesort_sql($header);
	$result = pager_query($query . $tablesort, 50);

	$rows = array();
	while ( $referral = db_fetch_object($result) )
	{
		$total_use_count = ( is_numeric($referral->total_use_count) ) ? $referral->total_use_count : 0;
		$total_times_applied = ( is_numeric($referral->total_times_applied) ) ? $referral->total_times_applied : 0;

		$rows[] = array("data" =>
			//Cell data
			array(
				$referral->name, 
				substr($referral->description, 0, 30), 
				( !is_null($referral->username) ) ? $referral->username . " (" . $referral->email . ")" : t("No User"),
				sprintf("%.2f%%", $referral->rate * 100), 
				"<a href='" . uc_referrals_get_url($referral->code) . "'>" . $referral->code . "</a>",
				l( t("view usage"), "admin/reports/uc_referrals/referral/" . $referral->referral_id), 
				l( t("edit"), "admin/store/settings/uc_referrals/edit/" . $referral->referral_id), 
				l(t("delete"), "admin/store/settings/uc_referrals/delete/" . $referral->referral_id),
			),
		);
	}

	if ( empty($rows) )
		$rows[] = array( array("data" => t("No referrals."), "colspan" => 8) );

	$output .= theme( "table", $header, $rows, array("id" => "uc_referrals_table") );
	$output .= theme("pager", NULL, 50, 0);

	$output .= "<br/>";
	$output .= l(t("Create a new referral account."), "admin/store/settings/uc_referrals/edit");

	return $output;
}

/**
 * Form for global referral settings.
 *
 * @ingroup forms
 * @see uc_referrals_global_settings_form_submit()
 */
function uc_referrals_global_settings_form($form_state)
{
	$form = array();
	$form_submitted = $form_state["submitted"];

	if ( !$form_submitted)
	{
		$uc_referrals_calculated_line_item_types = NULL;
		try
		{
			$uc_referrals_calculated_line_item_types = 
				variable_get( UC_REFERRALS_CALCULATED_LINE_ITEM_TYPES_KEY, array() );
		}
		catch (Exception $e)
		{
			$uc_referrals_calculated_line_item_types = array();
		}

		$remove_referral_code_after_order_submit = 
			variable_get(UC_REFERRALS_REMOVE_REFERRAL_CODE_AFTER_ORDER_SUBMIT_KEY, TRUE);
	}

	$options = array();
	foreach (_line_item_list() as $line_item)
	{
		if (  !in_array( $line_item["id"], array("subtotal", "tax_subtotal", "total") )  )
			$options[ $line_item["id"] ] = $line_item["title"];
	}

	$form[UC_REFERRALS_CALCULATED_LINE_ITEM_TYPES_KEY] = array(
		"#type" => "checkboxes",
		"#title" => t("Calculated line item types"),
		"#options" => $options,
		"#default_value" => $uc_referrals_calculated_line_item_types,
		"#description" => t("Line item types to include when calculating referral amount."),
	);

	$form[UC_REFERRALS_REMOVE_REFERRAL_CODE_AFTER_ORDER_SUBMIT_KEY] = array(
		"#type" => "checkbox",
		"#title" => t("Remove referral code after order submit"),
		"#default_value" => $remove_referral_code_after_order_submit,
		"#description" => t("Checking this will allow only the first order from a user to count for a referral account."),
	);

	$form["submit"] = array( "#type" => "submit", "#value" => t("Submit") );

	return $form;
}

/**
 * Submit handler for uc_referrals_global_settings_form().
 */
function uc_referrals_global_settings_form_submit($form, &$form_state)
{
	$op = isset($form_state["values"]["op"]) ? $form_state["values"]["op"] : "";
	if ( $op == t("Submit") )
	{
		$values = $form_state["values"];

		$line_item_types = array();
		foreach (_line_item_list() as $line_item)
		{
			if ( in_array($line_item["id"], $values[UC_REFERRALS_CALCULATED_LINE_ITEM_TYPES_KEY], TRUE) )
				$line_item_types[] = $line_item["id"];
		}
		variable_set(UC_REFERRALS_CALCULATED_LINE_ITEM_TYPES_KEY, $line_item_types);

		variable_set(UC_REFERRALS_REMOVE_REFERRAL_CODE_AFTER_ORDER_SUBMIT_KEY, 
			$values[UC_REFERRALS_REMOVE_REFERRAL_CODE_AFTER_ORDER_SUBMIT_KEY]);

		drupal_set_message( t("Referral settings have been saved.") );
	}

	$form_state["redirect"] = "admin/store/settings/uc_referrals";
}

/**
 * Create or edit a referral.
 *
 * @ingroup forms
 * @see uc_referrals_form_submit()
 */
function uc_referrals_form($form_state, $referral_id = 0)
{
	$form = array();
	$form_submitted = $form_state["submitted"];
	$is_edit = $referral_id != 0;
	$seed = rand(1, 1000000);

	if ( !$form_submitted && $is_edit)
		$form_state["values"] = db_fetch_array( db_query("SELECT * FROM {uc_referrals} WHERE referral_id=%d", $referral_id) );

	$form["referral_id"] = array("#type" => "hidden", "#value" => $form_state["values"]["referral_id"]);

	$form["name"] = array(
		"#type" => "textfield",
		"#title" => t("Organization Name"),
		"#description" => t("This field will be visible to the associated user (if one exists)."),
		"#default_value" => $form_state["values"]["name"],
		"#size" => 50,
		"#required" => TRUE,
	);

	$form["description"] = array(
		"#type" => "textfield",
		"#title" => t("Organization Description"),
		"#default_value" => $form_state["values"]["description"],
		"#size" => 75,
		"#required" => TRUE,
	);

	//Create user_id form element
	$options = array();
	$result = db_query("SELECT uid, name username, mail email FROM {users} WHERE uid<>0");
	$options[NO_REFERRAL_USER] = t("<No User>");
	while ( $row = db_fetch_object($result) )
		$options[$row->uid] = $row->username . " (" . $row->email . ")";
	$form["user_id"] = array(
		"#type" => "select",
		"#title" => t("User"),
		"#description" => t("User associated with this referral account."),
		"#options" => $options,
		"#default_value" => $form_state["values"]["user_id"],
	);

	$form["rate"] = array(
		"#type" => "textfield",
		"#title" => t("Referral rate"),
		"#description" => t("The rate the referrer receives as a percent or decimal.  6%, .06"),
		"#default_value" => $form_state["values"]["rate"],
		"#size" => 15,
		"#required" => TRUE,
	);

	$auto_generate_code = isset($form_state["values"]["auto_generate_code"]) 
		? $form_state["values"]["auto_generate_code"] : AUTO_GENERATE_CODE_DEFAULT;

	$code_container_id = "code-container-" . $seed;
	$code_prefix = sprintf("<div id='%s' onclick='if ( jQuery(\"#%s input[type=\\\"checkbox\\\"]\").attr(\"checked\") )"
		. "{ jQuery(\"#%s .code-container input\").attr(\"disabled\", true); }"
		. "else { jQuery(\"#%s .code-container input\").attr(\"disabled\", false); }'>", 
		$code_container_id, $code_container_id, $code_container_id, $code_container_id);

	$form["code_header"] = array(
		"#type" => "hidden",
		"#prefix" => $code_prefix,
	);

	$form["auto_generate_code"] = array(
		"#type" => "checkbox",
		"#title" => t("Automatically generate referral code."),
		"#default_value" => $auto_generate_code,
	);

	$attributes = array();
	if ($auto_generate_code)
		$attributes["disabled"] = "true";
	
	//If in auto generation mode, show existing code during edit and "" during insert
	if ($auto_generate_code)
		$code = ($is_edit) ? $form_state["values"]["code"] : "";
	//Otherwise use form code
	else
		$code = $form_state["values"]["code"];

	$form["code"] = array(
		"#type" => "textfield",
		"#title" => t("Referral code"),
		"#default_value" => $code,
		"#attributes" => $attributes,
		"#prefix" => "<div class='code-container'>",
		"#suffix" => "</div>",
	);

	$form["code_footer"] = array(
		"#type" => "hidden",
		"#suffix" => "</div>",
	);

	$has_user_message = isset($form_state["values"]["has_user_message"]) 
		? $form_state["values"]["has_user_message"] : HAS_USER_MESSAGE_DEFAULT;
	$display_string = ($has_user_message) ? "" : " style='display:none'";

	$user_message_container_id = "user-message-container-" . $seed;
	$user_message_prefix = sprintf("<div id='%s' onclick='if ( jQuery(\"#%s input[type=\\\"checkbox\\\"]\").attr(\"checked\") )"
		. "{ jQuery(\"#%s .user-message-container\").slideDown(); }"
		. "else { jQuery(\"#%s .user-message-container\").slideUp(); }'>", 
		$user_message_container_id, $user_message_container_id, $user_message_container_id, $user_message_container_id, $user_message_container_id, $user_message_container_id);

	$form["user_message_header"] = array(
		"#type" => "hidden",
		"#prefix" => $user_message_prefix,
	);

	$form["has_user_message"] = array(
		"#type" => "checkbox",
		"#title" => t("Show user message"),
		"#description" => t("Whether or not to show user message during checkout."),
		"#default_value" => $has_user_message,
	);

	$form["user_message"] = array(
		"#type" => "textfield",
		"#title" => t("User message")
			. sprintf("<span title='" . t("This field is required.") . "' class='form-required'>*</span>"),
		"#description" => t("Message shown to user during checkout."),
		"#default_value" => $form_state["values"]["user_message"],
		"#size" => 100,
		"#prefix" => sprintf("<div class='user-message-container'%s>", $display_string),
		"#suffix" => "</div>",
	);

	$form["user_message_footer"] = array(
		"#type" => "hidden",
		"#suffix" => "</div>",
	);

	$form["submit"] = array( "#type" => "submit", "#value" => t("Submit") );

	return $form;
}

/**
 * Validate handler for uc_referrals_form().
 */
function uc_referrals_form_validate($form, &$form_state)
{
	$values = $form_state["values"];
	$has_errors = FALSE;

	//Check rate

	if (  ( $index = strpos($values["rate"], "%") ) !== FALSE  )
		$value = substr($values["rate"], 0, $index);
	else
		$value = $values["rate"];

	if ( !is_numeric($value) )
	{
		form_set_error( "rate", t("Referral rate must be decimal or percentage.") );
		$has_errors = TRUE;
	}


	//Check code (ensure code doesn't already exist)
	$referral = get_referral_for_code($values["code"]);
	//If there is an existing referral account with this referral code
	if ( !empty($referral) )
	{
		$has_code_error = FALSE;
		
		//If this is an insert, return an error
		if ( empty($values["referral_id"]) )
			$has_code_error = TRUE;
		//If this is an edit and existing referral account is not this referral account, return an error
		else if ($values["referral_id"] != $referral->referral_id)
			$has_code_error = TRUE;
		
		if ($has_code_error)
		{
			form_set_error( "code", t("Referral code already exists.") );
			$has_errors = TRUE;
		}
	}

	//Requires rebuilding form so auto_generate_code and has_user_message blocks will display correctly
	if ($has_errors)
		$form_state["rebuild"] = TRUE;
}

/**
 * Submit handler for uc_referrals_form().
 */
function uc_referrals_form_submit($form, &$form_state)
{
	$op = isset($form_state["values"]["op"]) ? $form_state["values"]["op"] : "";
	if ( $op == t("Submit") )
	{
		$values = $form_state["values"];
		$is_edit = !empty($values["referral_id"]);

		//Set rate
		if (  ( $index = strpos($values["rate"], "%") ) !== FALSE  )
			$rate = floatval( substr($values["rate"], 0, $index) ) / 100;
		else
			$rate = floatval($values["rate"]);

		$user_id = ( empty($values["user_id"]) || ($values["user_id"] == NO_REFERRAL_USER) ) 
			? NULL : intval($values["user_id"]);

		//Generate code (if necessary)
		$code = $values["code"];
		if ($values["auto_generate_code"])
		{
			//If this is an insert, generate code
			if (!$is_edit)
				$code = generate_referral_code();
			//If this is an edit
			else
			{
				$referral = get_referral($values["referral_id"]);
				//If existing code was auto-generated, keep existing code
				if ($referral->auto_generate_code)
					$code = $referral->code;
				//Otherwise generate code
				else
					$code = generate_referral_code();
			}
		}

		$user_message = ($values["has_user_message"]) ? $values["user_message"] : "";

		if ( empty($values["referral_id"]) )
		{
			//Insert base referral
			$referral_id = uc_referrals_insert($values["name"], 
				$values["description"], 
				$user_id, 
				$rate, 
				$values["auto_generate_code"], 
				$code,
				$values["has_user_message"], 
				$user_message);

			db_last_insert_id("uc_referrals", "referral_id");
		}
		else
		{
			$referral_id = $values["referral_id"];

			//Update base referral
			uc_referrals_update($referral_id,
				$values["name"], 
				$values["description"], 
				$user_id, 
				$rate, 
				$values["auto_generate_code"], 
				$code,
				$values["has_user_message"], 
				$user_message);
		}

		drupal_set_message(  t("%name settings have been saved.", array( "%name" => $values["name"]) )  );
	}

	$form_state["redirect"] = "admin/store/settings/uc_referrals";
}

/**
 * Delete a referral.
 *
 * @ingroup forms
 * @see uc_referrals_delete_submit()
 */
function uc_referrals_delete($form_state, $referral_id = 0)
{
	if ($referral_id != 0)
	{
		$referral = db_fetch_object( db_query("SELECT * FROM {uc_referrals} WHERE referral_id=%d", $referral_id) );
		$form = array( "referral_id" => array("#type" => "value", "#value" => $referral_id) );
		$output = confirm_form( $form, t("Delete @row?", array( "@row" => $referral->name) ), 
			"admin/store/settings/uc_referrals", "", t("Continue"), t("Cancel") );
		return $output;
	}
	else
		drupal_goto("admin/store/settings/uc_referrals");
}

/**
 * Submit handler for uc_referrals_delete().
 */
function uc_referrals_delete_submit($form, &$form_state)
{
	if ($form_state["values"]["confirm"])
	{
		$referral_id = $form_state["values"]["referral_id"];
		uc_referrals_delete_all($referral_id);
	}

	drupal_set_message( t("Referral deleted.") );

	$form_state["redirect"] = "admin/store/settings/uc_referrals";
}

/**
 * Generate report for all referrals.
 */
function uc_referrals_report($passed_user = NULL)
{
	$can_configure_referrals = user_access("configure referrals");

	$header = array(
		array("data" => t("Name"), "field" => "r.name", "sort" => "asc"),
		array("data" => t("Description"), "field" => "r.description"),
		array("data" => t("User"), "field" => "u.name"),
		array("data" => t("Uses"), "field" => "use_count"),
		array("data" => t("Total Amount"), "field" => "total_amount"),
	);

	$colspan = count($header);
	if ($can_configure_referrals)
	{
		$header[] = array("data" => t("Operations"), "colspan" => 3);
		$colspan += 3;
	}

	$user_id_query = "";
	if ( !is_null($passed_user) )
	{
		global $user;
		
		//Current user must be passed user or user must have "access site reports" permission
		if ( ($user->uid != $passed_user->uid) && !user_access("access site reports") )
		{
//TO DO return error
			return;
		}

		$user_id_query = sprintf(" WHERE r.user_id=%d", $passed_user->uid);
	}
	//Otherwise user must have "access site reports" permission
	else if ( !user_access("access site reports") )
	{
//TO DO return error
			return;
	}

	$query = "SELECT r.*, COUNT(ru.referral_use_id) total_use_count"
		. ", SUM(ru.amount) total_amount, u.name username, u.mail email FROM {uc_referrals} r"
		. " LEFT JOIN {users} u ON r.user_id=u.uid"
		. " LEFT JOIN {uc_referrals_uses} ru ON r.referral_id=ru.referral_id"
		. $user_id_query
		. " GROUP BY r.referral_id";
	$tablesort = tablesort_sql($header);
	$result = pager_query($query . $tablesort, 50);

	$rows = array();
	while ( $referral = db_fetch_object($result) )
	{
		$total_use_count = ( is_numeric($referral->total_use_count) ) ? $referral->total_use_count : 0;

		$cell_data = array( 
			$referral->name, 
			$referral->description,
			( !is_null($referral->username) ) ? $referral->username . " (" . $referral->email . ")" : t("No User"),
			$total_use_count,
			uc_currency_format($referral->total_amount),
		);

		if ($can_configure_referrals)
		{
			$cell_data[] = l( t("view usage"), "admin/reports/uc_referrals/referral/" . $referral->referral_id);
			$cell_data[] = l( t("edit"), "admin/store/settings/uc_referrals/edit/" . $referral->referral_id);
			$cell_data[] = l(t("delete"), "admin/store/settings/uc_referrals/delete/" . $referral->referral_id);
		}

		$rows[] = array("data" => $cell_data);
	}

	if ( empty($rows) )
		$rows[] = array( array("data" => t("No referral data available."), "colspan" => $colspan) );

	$output .= theme( "table", $header, $rows, array("id" => "uc_referrals_report") );
	$output .= theme("pager", NULL, 50, 0);

	return $output;
}

/**
 * Generate report for referral.
 */
function uc_referrals_report_for_referral($referral_id)
{
	//Add link to all referral data
	$output = l(t("Report for all referrals."), "admin/reports/uc_referrals/all");
	
	$output .= "<br/><br/>";


	//Add table for referral's data

	$header = array(
		t("Name"),
		t("User"),
		t("Uses"),
		t("Total Amount"),
		array("data" => t("Operations"), "colspan" => 3)
	);

	$query = "SELECT r.*, COUNT(ru.referral_use_id) total_use_count, u.name username, u.mail email "
		. ", SUM(ru.amount) total_amount FROM {uc_referrals} r"
		. " LEFT JOIN {uc_referrals_uses} ru ON r.referral_id=ru.referral_id"
		. " LEFT JOIN {users} u ON r.user_id=u.uid"
		. " WHERE r.referral_id=%d"
		. " GROUP BY r.referral_id";
	$referral = db_fetch_object( db_query($query, $referral_id) );
	$total_use_count = ( is_numeric($referral->total_use_count) ) ? $referral->total_use_count : 0;
	$referrals[] = array(
		$referral->name, 
		( !is_null($referral->username) ) ? $referral->username . " (" . $referral->email . ")" : t("No User"),
		$total_use_count,
		uc_currency_format($referral->total_amount),
		l( t("edit"), "admin/store/settings/uc_referrals/edit/" . $referral->referral_id), 
		l(t("delete"), "admin/store/settings/uc_referrals/delete/" . $referral->referral_id),
	);
	$output .= theme("table", $header, $referrals);

	$output .= "<br/><br/>";

	
	//Add table of referral's usage data

	$header = array(
		array("data" => t("User"), "field" => "user_id"),
		array("data" => t("Order"), "field" => "order_id"),
		array("data" => t("Code"), "field" => "code"),
		array("data" => t("Amount"), "field" => "amount"),
		array("data" => t("Date"), "field" => "insert_timestamp", "sort" => "asc"),
	);

	$query = sprintf("SELECT ru.*, u.name username, u.mail email FROM {uc_referrals_uses} ru"
		. " LEFT JOIN {users} u ON ru.user_id=u.uid"
		. " WHERE referral_id=%d", $referral_id);
	$tablesort = tablesort_sql($header);
	$result = pager_query($query . $tablesort, 50);

	$rows = array();
	while ( $use = db_fetch_object($result) )
	{
		$rows[] = array("data" =>
			//Cell data
			array(
				$use->username . " (" . $use->email . ")", 
				$use->order_id, 
				( !empty($use->code) ) ? $use->code : check_plain("<" . t("no code") . ">"),
				uc_currency_format($use->amount),
				date("Y-m-d H:i:s", $use->insert_timestamp),
			),
		);
	}

	if ( empty($rows) )
		$rows[] = array( array("data" => t("No referral data available."), "colspan" => 7) );

	$output .= theme( "table", $header, $rows, array("id" => "uc_referrals_report") );
	$output .= theme("pager", NULL, 50, 0);


	return $output;
}
