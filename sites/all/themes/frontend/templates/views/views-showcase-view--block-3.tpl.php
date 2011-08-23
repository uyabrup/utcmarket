<?php

$pager_title=$options['showcase_display_options']['navigation_box_field']['title'];
$pager_img=$options['showcase_display_options']['navigation_box_field']['field_banner_pager_fid'];
$pager_text=$options['showcase_display_options']['navigation_box_field']['field_banner_pager_txt_value'];

if ($pager_img && !$pager_title && !$pager_text) $add_class=' pager-image';
else if ($pager_title && $pager_text && !$pager_img) $add_class=' pager-title';
else if ($pager_img && $pager_title && $pager_text) $add_class=' pager-title-image';
else $add_class='';
?>

<div class = "skin-<?php print $skin; ?> item-list views-showcase clear-block<?php print $add_class; ?>">
    <div class = "views-showcase-navigation-container">
        <ul class = "views-showcase-mini-list">
            <?php foreach ($structured_rows as $row_index => $structured_row): ?>
            <?php if ($structured_row['field_banner_pager_txt_value']->content) unset($structured_row['title']); ?>
                <li class = "<?php print $structured_row['nav_box_classes']; ?>">
                  <div class = "views-showcase-pager-item-sublist">
                    <?php foreach ($structured_row as $field_id => $field):?>
                        <?php if ($field->navigation_box && $field->content): ?>
                            <div class = "views-showcase-pager-subitem views-showcase-navigation-box-<?php print $field_id; ?>">
                                <?php if ($field->link_anchor): ?>
                                    <a href = "<?php print '#' . $structured_row['anchor_name']; ?>">
                                    <?php print $field->content; ?></a>
                                <?php else: ?>
                                   <?php print $field->content; ?>
                                <?php endif;?>
                            </div>
                    <?php endif;?>
                    <?php endforeach;?>
                </div>
                </li>
            <?php endforeach;?>
        </ul>
    </div>

    <div class = "views-showcase-content-container">
        <ul class = "views-showcase-big-panel">
            <?php foreach ($structured_rows as $row_index => $structured_row):?>

                <li class = "<?php print $structured_row['big_box_classes']; ?>">
                <a name = "<?php print $structured_row['anchor_name']; ?>"
                  id = "<?php print $structured_row['anchor_name']; ?>"></a>

                <?php foreach ($structured_row as $field_id => $field):?>

                    <?php $fieldid=$field_id; ?>

                <?php endforeach;?>

                <?php if ($structured_row['field_banner_fid']->big_box): ?>

                    <div class = "views-showcase-subitem views-showcase-big-box-<?php print $fieldid; ?>">
                        <?php if ($structured_row['field_banner_fid']->label): ?>

                            <label class = "views-label-<?php print $fieldid; ?>"><?php print $structured_row['field_banner_fid']->label; ?></label>

                        <?php endif;?>

                        <?php
                        $banner_link=$structured_row['field_banner_link_value']->content;
                        $banner_ref_nid=$structured_row['field_banner_ref_nid']->content;
                        $banner_show_ribbon=$structured_row['field_banner_ribbon_value']->content;
                        $banner_title=$structured_row['title']->content;
                        $banner_nid=$structured_row['nid']->content;
                        $banner_type=$structured_row['type']->content;
						$banner_body = $structured_row['body']->content;

                        $banner_nodequeue=$structured_row['nodequeue_links']->content;
                        $banner_edit=$structured_row['edit_node']->content;

                        $banner_src= theme_image($structured_row['field_banner_fid']->content, $banner_title, $banner_title, NULL, FALSE);

                        if ($banner_nodequeue || $banner_edit) {
                            print '<div class="carousel-admin">';
                            if ($banner_nodequeue) print '<div class="banner-queue">' . $banner_nodequeue . '</div>';
                            if ($banner_edit) print '<div class="banner-edit">' . $banner_edit . '</div>';
                            print '</div>';
                            }

                        preg_match('/href="([^"]*)"/i', $banner_ref_nid, $regs);						
						global $base_path;
						$banner_ref_url= ltrim($regs[1], $base_path);
                        if ($banner_ref_url) print l($banner_src, $banner_ref_url, array('html' => TRUE));
                        else if ($banner_link) print l($banner_src, $banner_link, array('html' => TRUE, 'absolute' => TRUE));
                        else if ($banner_type != 'banner') print l($banner_src, 'node/' . $banner_nid, array('html' => TRUE));
                        else print $banner_src;

                        if ($banner_show_ribbon)print '<div class="ribbon-title"><h3>' . $banner_title . '</h3></div>';						
                        if ($banner_body) print '<div class="banner-body">' . '<h2 class="carousel-title">' . $banner_title . '</h2>' . $banner_body . '</div>';						
							
                        ?>
                    </div>

                <?php endif; ?>

                </li>

            <?php endforeach; ?>
        </ul>
    </div>
</div>