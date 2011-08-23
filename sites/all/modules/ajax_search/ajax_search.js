$(document).ready(function() {

  var cl = 1;
  var search_cache = new Array( );
  var form = $(Drupal.settings.ajax_search_form);
  var search_string_old = search_string = $(form).val();
  $(form).wrap('<div id="ajax_search_wrap"></div>');
  $(form).after('<div id="ajax_search"></div>');

  $(Drupal.settings.ajax_search_form + ', #ajax_search_result, #ajax_search').click(function(){
    cl = 0;
    search_string = $(form).val();
    if(!$('#ajax_search_result').html() && search_string.length >1){
      result_data($(form).val());
    }
  });
  
  $('body').click(function(){
    if(cl==1) del_result();
    cl = 1;
  });
    
  
  $(document).keydown(function(e) {
    setTimeout(function(){
      var search_string = $(form).val();
      if(search_string_old!=search_string && search_string.length > 1){
        search_string_old=search_string;
        result_data(search_string);
      }
      else if (search_string.length < 2){
        del_result();
      }
    },600);
  }); 
  
  
  function result_data(str){
    var out = '';
    if(search_cache[str]){
      out = search_cache[str];
      $('#ajax_search').html(out); 
      $('#ajax_search a').click(function(){del_result();});
    }
    else{
      $('#ajax_search').html('<div class="loading" id="ajax_search_result"><br><br><br></div>');
      $.post(Drupal.settings.ajax_search_patch + '/load' ,{ search: str }, function(data){
        $('#ajax_search_result').html('<br><br><br>'); 
        data = eval('(' + data + ');');
        out += parse_data(data, 'users');
        out += parse_data(data, 'taxonomy');
        out += parse_data(data, 'node');
        out = '<div id="ajax_search_result" ><table><tr>'+ out +'</tr></table></div>'
        search_cache[str] = out; 
        $('#ajax_search').html(out); 
        $('#ajax_search a').click(function(){del_result();});
      });
    }
  }
  
  
  

  function parse_data(arr, type){
    var search_string = $(form).val();
    var out = links = '';
    var url = Drupal.settings.ajax_search_patch;

     if(arr[type + '_title']){
      for(var i=0; i<arr[type + '_title'].length;i++){
        var title = arr[type + '_title'][i]; 
        var patch = url + '/result/' + type.charAt(0) + '/' + arr[type + '_id'][i];
        if(title) {
          title = highlight(title,search_string);
          links += '<li><a href="'+ patch +'">'+ title +'</a></li>'; 
        }
      }
    if(arr[type][0]){
      out += '<td valign="top" class="'+ type +'"><h2>'+ arr[type][0] + '</h2>';
      if(links) out +=  '<ul>'+ links +'</ul>';
      else out +=  ' - Not found -';
      out +='</td>';
    }
     }
    return out
  }
  


  function highlight(title,search){
    var re = new RegExp('(' + search + ')', "ig");
    return title.replace(re, "<i>$1</i>");
  }

  function del_result(){
    $("#ajax_search>div").fadeTo(200,0,function(){
      $('#ajax_search').html(''); 
    });
  }
  

});



