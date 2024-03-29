﻿$(document).ready(function() {
	var dealer_profit = 5 / 100;
	var store_profit = 15 / 100;
	var dollar_curs = 6.7;

	$("#calc_price_btn").click(function() {
		var weight = $("#edit-weight").val();
		var yuan_price = $("#yuan_price").val();

		var cost = Math.ceil(dollar_curs * yuan_price * weight);
		var revenue_delta = cost * (dealer_profit + store_profit);
		var price = revenue_delta + parseInt(cost);
		var price = Math.ceil(price);
		// alert(revenue_delta);

		$("#edit-cost").val(cost);
		$("#edit-sell-price").val(price);
		$("#edit-list-price").val(price);
		$("#edit-crs-cost").val(cost);
		$("#edit-crs-sell-price").val(price);
		$("#edit-crs-list-price").val(price);
	});
});

$(document).ready(function() {
	var dealer_profit = 5/100;
	var store_profit = 15/100;
	var dollar_curs = 6.27;

	$("#import_data_call").click(function() {
		var prod_url = $("#prod_url").val();
	    if($.trim(prod_url) == '')
	     {
		  alert('Заполните URL продукта!');
		  return;
	     }
		var startIndex = prod_url.indexOf("id=");
		var endIndex = prod_url.indexOf("&", startIndex);
		var productId = -1;
		if (endIndex == -1) {
			productId = prod_url.substring(startIndex + 3);
		} else {
			productId = prod_url.substring(startIndex + 3, endIndex);
		}

		$.get("../../taobao/demo.php", {
			"productid" : productId
		}, fillImportedData);
	});

	$("#fill_form").click(function() {

	    var title = $("#prod_title_val_last").val();
	    var prod_url = $("#prod_url").val();
		var img_url = $("#prod_image").val();
		var prod_weight = $("#prod_weight").val();
        var prod_price = $("#prod_price_yuan").val();
   
	   if(   ($.trim(title) == '')
		 || (prod_price  == '' || prod_price <= 0)
		 || (prod_weight == '' || prod_weight <= 0))
	    {
		 alert('Заполните обязательные поля формы');
	 	 return;
	    }

	// Calculate a cost (цена + 15)*1,1/6,27+вес/1000*20
		var cost = Math.ceil((prod_price+15) * (1.1/dollar_curs) + ((prod_weight/1000)*20)); // CHANGE THIS FORMULA
	
		var revenue_delta = cost * (dealer_profit + store_profit);
		var price = revenue_delta + parseInt(cost);
		price = Math.ceil(price);
 
        $("#prod_price_usd").val(cost);
		$("#edit-cost").val(cost);
		$("#edit-sell-price").val(price);
		$("#edit-list-price").val(price);
		$("#edit-crs-cost").val(cost);
		$("#edit-crs-sell-price").val(price);
		$("#edit-crs-list-price").val(price);
		$("#edit-title").val(title);
		$("#edit-field-product-store-url-0-value").val(prod_url);
		$("#edit-field-image-cache-0-filefield-remote-url").val(img_url);
		$("#edit-weight").val(prod_weight);
		$("#edit-shippable").attr('checked', true);

  	});

	function fillImportedData(data) {
		var jsonData = Drupal.parseJson(data);
		var item = jsonData.taobaoke_item_details.taobaoke_item_detail.item;
		var prod_title = item.title;
		var prod_price = item.price;
       
		var prod_weight = 0;//item.weight;
		var prod_image = item.pic_url;

		$("#prod_title_val").val(prod_title);
		$("#prod_price_yuan").val(prod_price);
		$("#prod_weight").val(prod_weight);
		$("#prod_image").val(prod_image);
		$("#prod_image_show").attr("src", prod_image);
	}

});