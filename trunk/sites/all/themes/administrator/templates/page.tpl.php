<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
  <head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
	
	<!--[if !IE 7]>
	<style type="text/css">
	#wrapper {
	display:table;
	height:100%
	} 
	</style>
	<![endif]-->

</head>
<body class="<?php print $body_classes; ?>">
<div id="wrapper">
    <?php if (!$hide_header && (admin_menu_blocks() || $slider_left || $slider_middle || $slider_right)) { ?>
    <div id="toppanel">
      <div id="panel">
       <?php print $slider ?>  
	   
	   <?php print admin_menu_blocks(); ?>  
	   
        <div id="slider-left">
          <?php if ($slider_left) print $slider_left; ?>
        </div>
         <div id="slider-right">
          <?php if ($slider_right) print $slider_right; ?>
        </div>
        <div id="slider-middle">
          <?php if ($slider_middle) print $slider_middle; ?>
        </div>
      </div>
      <div id="toppanel-head">
        <div id="go-home">
          <?php if (isset($go_home)) print $go_home; ?>
        </div>
        <div id="admin-links">
          <?php print $administrator_user_links ?>
        </div>
        <?php if (!$hide_panel) { ?>
        <div id="header-title" class="clearfix">
          <ul id="toggle"><li><?php print $panel_navigation ?></li></ul>
        </div>
        <?php } ?>
      </div>
    </div>
    <?php } ?>
    <div id="page-wrapper"><div id="page-wrapper-content">
      <?php print $header ?>
      <div id="navigation" class="clearfix<?php print $administrator_navigation_class ?>">
        <?php print $administrator_navigation ?>

      <?php
      if ($logo) {
        print '<img src="'. check_url($logo) .'" alt="'. $site_name .'" id="logo" />';
      }
      ?>
	  
	  			<?php if ($site_name): ?>
                      <h1 id="site-name"><?php print $site_name; ?></h1>
          <?php endif; ?>
      </div>
      <div id="content-wrap" class="<?php print $content_class; ?>">
      
      

      
      
      
        <div id="inside">
          <?php if ($admin_left) { ?>
            <div id ="sidebar-left" class="content-equal">
              <?php
              print $admin_left;
              ?>
            </div>
          <?php } ?>
          <?php if ($admin_right) { ?>
            <div id ="sidebar-right" class="content-equal">
              <?php
              print $admin_right;
              ?>
            </div>
          <?php } ?>
          <div id="content" class="content-equal">
		  
            <div class="content-in">
			      <div id="breadcrumb" class="alone">
        <?php if ($title): print '<h2 id="title">'. $title .'</h2>'; endif; ?>
        <?php print $breadcrumb; ?>
      </div>
	  
	     <?php  print $help; ?>

        <?php print $messages; ?>

<?php if ($admin_content_top): ?>
<div class="admin-content-top"><?php print $admin_content_top;  ?></div>
<?php endif; ?>

              <?php if (isset($tabs) && $tabs): print '<div id="tabs-primary"><ul class="tabs primary">'. $tabs .'</ul></div><div class="level-1">'; endif; ?>
              <?php if (isset($tabs2) && $tabs2): print '<div id="tabs-secondary"><ul class="tabs secondary">'. $tabs2 .'</ul></div><div class="level-2">'; endif; ?>

              <?php if (isset($dashboard)) { ?>
                <div id="dashboard" class="clearfix">
				<div id="dashboard-top">
                    <?php print $dashboard_top ?>
                  </div>
                  <div id="dashboard-left">
                    <?php print $dashboard_left ?>
                  </div>
                  <div id="dashboard-right">
                    <?php print $dashboard_right ?>
                  </div>
				  
				  <div id="dashboard-bottom">
                    <?php print $dashboard_bottom ?>
                  </div>
                </div>
              <?php } ?>
			  

			   
              <?php
                if (!$hide_content) {
                  print $content;
                }
              ?>
              <?php if (isset($tabs2) && $tabs2): print '</div>'; endif; ?>
              <?php if (isset($tabs) && $tabs): print '</div>'; endif; ?>
            </div><br class="clear" />
          </div>
        </div>
      </div>
    </div>
	</div>
	</div>
		<?php if ($footer) { ?>
        <div id="footer">
          <?php print $footer; ?>
        </div>
      <?php } ?>
	  
	<?php print $closure ?>
  </body>
</html>