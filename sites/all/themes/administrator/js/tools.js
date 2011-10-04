$(document).ready(function(){
	var dealer_profit = 5/100;
	var store_profit = 15/100;
	$("#calc_price_btn").click(function() {
		var cost = $("#edit-cost").val();
		var revenue_delta = cost*(dealer_profit+store_profit);
		var price = revenue_delta + parseInt(cost);
		var price = Math.ceil(price);
		//alert(revenue_delta);
		
		$("#edit-sell-price").val(price);
		$("#edit-list-price").val(price);
		$("#edit-crs-cost").val(cost);
		$("#edit-crs-sell-price").val(price);
		$("#edit-crs-list-price").val(price);
	});
});