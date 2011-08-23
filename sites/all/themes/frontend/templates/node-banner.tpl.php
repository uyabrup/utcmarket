<div class = "node <?php print $classes; ?>" id = "node-<?php print $node->nid; ?>">
    <div class = "node-inner">
        <?php if (!$page): ?>

            <h2 class = "title"><a href = "<?php print $node_url; ?>">

            <?php print $title; ?></a></h2>

        <?php
        endif;
        ?>

        <div class = "content">
            <?php
            global $base_path;
            $banner_link=$node->field_banner_link[0]['value'];
            $banner_ref=$node->field_banner_ref[0]['view'];
            $banner_ref_url=explode('"', $banner_ref);

            if ($banner_ref_url[1] != NULL)
                {
                print '<a href="' . $banner_ref_url[1] . '"><img src="' . $base_path
                  . $node->field_banner[0]["filepath"] . '" /></a>';
                }
            else if ($banner_link)
                {
                print '<a href="' . $banner_link . '"><img src="' . $base_path . $node->field_banner[0]["filepath"]
                  . '" /></a>';
                }
            else
                {
                print '<img src="' . $base_path . $node->field_banner[0]["filepath"] . '" />';
                }
            ?>
        </div>

        <?php if ($links): ?>

            <div class = "links"><?php print $links; ?></div>

        <?php
        endif;
        ?>
    </div>
</div>