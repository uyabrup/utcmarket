$(function(){
  var div = $('div.image-thumb'),
               ul = $('ul.image-thumb'),
               ulPadding = 5;
  var divWidth = div.width();
  div.css({overflow: 'hidden'});
  var lastLi = ul.find('li:last-child');
  div.mousemove(function(e){
    var ulWidth = lastLi[0].offsetLeft + lastLi.outerWidth() + ulPadding;
    var left = (e.pageX - div.offset().left) * (ulWidth-divWidth) / divWidth;
    div.scrollLeft(left);
  });
});