<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml" xml:lang = "<?php print $language->language ?>"
  lang = "<?php print $language->language ?>" dir = "<?php print $language->dir ?>">
    <head>
        <title><?php print $head_title; ?></title>

        <?php print $head; ?>

        <?php print $styles; ?>
<!--[if lte IE 6]><style type="text/css" media="all">@import "<?php print $base_path . path_to_theme() ?>/css/ie6.css"</style><![endif]-->
<!--[if IE 7]><style type="text/css" media="all">@import "<?php print $base_path . path_to_theme() ?>/css/ie7.css"</style><![endif]-->
        <?php print $scripts; ?>
    </head>

    <body class = "<?php print $body_classes; ?>"<?php print $gridder; ?>>
        <?php print $admin_tabs; ?>

        <div id = "page">
            <div id = "header">
                <div id = "logo-title">
                    <?php if (!empty($logo)): ?>

                    <a href = "<?php print $front_page; ?>" title = "<?php print t('Home'); ?>" rel = "home" id = "logo">

                    <img src = "<?php print $logo; ?>" alt = "<?php print t('Home'); ?>" /> </a>

                    <?php endif; ?>
                </div>

                <?php if ($header_1 || $header_2): ?>

                    <div id = "header-blocks">
                        <?php if ($header_1): ?>

                            <div class = "header-block-1">
                                <?php print $header_1; ?>
                            </div>

                        <?php endif; ?>

                        <?php if ($header_2): ?>

                            <div class = "header-block-2">
                                <?php print $header_2; ?>
                            </div>

                        <?php endif; ?>
                    </div>

                <?php endif; ?>

                <?php print $show_login_links; ?>

                <?php if ($header): ?>

                    <div id = "header-region">
                        <?php print $header; ?>
                    </div>

                <?php endif; ?>
            </div>

            <div id = "main" class = "clearfix">
                <div id = "content">
                    <div id = "content-inner" class = "inner column center">
                        <?php if ($content_top): ?>

                            <div id = "content-top">
                                <?php print $content_top; ?>
                            </div> <!-- /#content-top -->

                        <?php endif; ?>

                        <?php if ($title || $mission || $messages || $help || $tabs): ?>

                            <div id = "content-header">
                                <?php if ($title): ?>

                                    <h1 class = "title"><?php print $title; ?></h1>

                                <?php endif; ?>

                                <?php print $show_checkout_steps; ?>

                                <?php if ($mission): ?>

                                    <div id = "mission"><?php print $mission; ?></div>

                                <?php endif; ?>

                                <?php print $messages; ?>

                                <?php print $help; ?>

                                <?php if ($tabs): ?>

                                    <div class = "tabs"><?php print $tabs; ?></div>

                                <?php endif; ?>
                            </div>

                        <?php endif; ?>

                        <div id = "content-area">
                            <?php print $content; ?>
                        </div>

                        <?php if ($profile_blocks): ?>

                            <div id = "profile-blocks"><?php print $profile_blocks; ?></div>

                        <?php endif; ?>

                        <?php if ($content_bottom): ?>

                            <div id = "content-bottom">
                                <?php print $content_bottom; ?>
                            </div>

                        <?php endif; ?>
                    </div>
                </div>

                    <?php if ($primary_menu || $primary_links || $secondary_links): ?>

                        <div id = "navigation">
                            <?php if ($primary_menu): ?>

                                <div class = "primary-menu">
                                    <?php print $primary_menu; ?>
                                </div>

                            <?php endif; ?>

                            <?php print $show_search_form; ?>

                            <?php if ($primary_links): ?>

                                <div class = "primary-menu">
                                    <?php
                                    print theme('links', $primary_links, array
                                        (
                                        'id' => 'primary',
                                        'class' => 'links main-menu'
                                        ));
                                    ?>
                                </div>

                            <?php endif; ?>

                            <?php if ($secondary_links): ?>

                                <div class = "secondary-menu">
                                    <?php
                                    print theme('links', $secondary_links, array
                                        (
                                        'id' => 'secondary',
                                        'class' => 'links sub-menu'
                                        ));
                                    ?>
                                </div>

                            <?php endif; ?>
                        </div>

                    <?php endif; ?>

                    <?php if ($wide_blocks): ?>

                        <div id = "wide-blocks">
                            <?php print $wide_blocks; ?>
                        </div>

                    <?php endif; ?>

                    <?php if ($breadcrumb): ?>

                        <div id = "breadcrumb">
                            <?php print $breadcrumb; ?>
                        </div>

                    <?php endif; ?>

                    <?php if ($left): ?>

                        <div id = "sidebar-first" class = "column sidebar first">
                            <div id = "sidebar-first-inner" class = "inner">
                                <?php print $left; ?>
                            </div>
                        </div>

                    <?php endif; ?>

                    <?php if ($right): ?>

                        <div id = "sidebar-second" class = "column sidebar second">
                            <div id = "sidebar-second-inner" class = "inner">
                                <?php print $right; ?>
                            </div>
                        </div>

                    <?php endif; ?>
            </div>

        <?php if ($footer_message || $footer_block || $show_store_short_contacts || $show_copyright): ?>

            <div id = "footer">
                <?php print $footer_message; ?>

                <div class = "first-line">
                    <?php print $show_store_short_contacts; ?>

                    <?php print $footer_block; ?>
                </div>

                <div class = "second-line">
                    <?php print $show_copyright; ?>
                </div>
            </div>

        <?php endif; ?>
        </div>

        <?php print $noscript_warning; ?>

        <?php print $closure; ?>
    </body>
</html>