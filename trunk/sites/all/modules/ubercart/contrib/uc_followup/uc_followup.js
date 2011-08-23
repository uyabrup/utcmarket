Drupal.behaviors.uc_folowup_tooltips = function(context){
  /* CONFIG */
    xOffset = 10;
    yOffset = 20;
    // these 2 variable determine popup's distance from the cursor
    // you might want to adjust to get the right result
  /* END CONFIG */
  $("img.tooltip", context).hover(function(e){
    this.t = $(this).attr('alt');
    $(this).attr('alt', '');
    $("body").append("<div id='ucf-tooltip'>"+ this.t +"</div>");
    $("#ucf-tooltip")
      .css("top",(e.pageY - xOffset) + "px")
      .css("left",(e.pageX + yOffset) + "px")
      .fadeIn("fast");
    },
    function(){
      $(this).attr('alt', this.t);
      $("#ucf-tooltip").remove();
    }
  );
  $("img.tooltip").mousemove(function(e){
    $("#ucf-tooltip")
      .css("top",(e.pageY - xOffset) + "px")
      .css("left",(e.pageX + yOffset) + "px");
  });
};