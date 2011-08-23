Drupal.behaviors.admintabsBehavior = function (context) {
	
	// Expand Panel
	$("#open").click(function(){
		$("div#panel").slideDown(400);
	
	});	
	
	// Collapse Panel
	$("#close").click(function(){
		$("div#panel").slideUp(400);	
	});		
	
	// Switch buttons from "Log In | Register" to "Close Panel" on click
	$("#toggle a").click(function () {
		$("#toggle a").toggle();
	});	
	
};