$(document).ready(function(){
	var dealer_profit = 5/100;
	var store_profit = 15/100;
	var dollar_curs = 6.7;

	$("#calc_price_btn").click(function() {
	 var weight = $("#edit-weight").val();
		var yuan_price = $("#yuan_price").val();
		
		var cost = Math.ceil(dollar_curs*yuan_price*weight);
		var revenue_delta = cost*(dealer_profit+store_profit);
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

$(document).ready(function(){
 var dealer_profit = 5/100;
	var store_profit = 15/100;
	var dollar_curs = 6.7;
 
	$("#import_data_call").click(function() {
	    var prod_url = $("#prod_url").val();
		//Do API call here
  //CALLBACK fillImportedData(data)
	});
 
 $("#fill_form").click(function() {

   var title       = $("#prod_title_val").val();
   var prod_url    = $("#prod_url").val();
   var img_url     = $("#prod_image").val();
   var prod_weight = $("#prod_weight").val();
  
   var cost = $("#prod_price_usd").val();
   var revenue_delta = cost*(dealer_profit+store_profit);
   var price = revenue_delta + parseInt(cost);
       price = Math.ceil(price);
  
	  $("#edit-sell-price").val(price);
   $("#edit-list-price").val(price);
   $("#edit-crs-cost").val(cost);
   $("#edit-crs-sell-price").val(price);
   $("#edit-crs-list-price").val(price);
   $("#edit-title").val(title);
   $("#edit-field-product-store-url-0-value").val(prod_url);
   $("#edit-field-image-cache-0-filefield-remote-url").val(img_url);
   $("#edit-weight").val(prod_weight);
   
	});
 
 function fillImportedData(data)
  {
   var prod_title = data.title;
   var prod_price = data.price;
   var prod_weight = data.weight;
   var prod_image = data.image;
   
   $("#prod_title_val").val(prod_title);   
   $("#prod_price_yuan").val(prod_price);   
   $("#prod_weight").val(prod_weight);   
   $("#prod_image").val(prod_image);
   $("#prod_image_show").attr("src", prod_image);
   
   //Calculate a cost
   var cost = Math.ceil(dollar_curs*prod_price*prod_weight); //CHANGE THIS FORMULA
   $("#prod_price_usd").val(cost);
   $("#edit-cost").val(cost);
  }
 
});