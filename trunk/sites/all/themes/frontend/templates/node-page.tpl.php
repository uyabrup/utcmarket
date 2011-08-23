<div class = "node <?php print $classes; ?>" id = "node-<?php print $node->nid; ?>">
    <div class = "node-inner">
        <?php if ($teaser): ?>

            <?php print $show_title; ?>

            <?php print $show_description; ?>

        <?php else: ?>

            <?php print $show_title; ?>

            <?php print $show_document_status; ?>

            <?php print $node_creator; ?>

            <?php print $node_created_date; ?>

            <?php print $show_banner; ?>

            <?php print $show_description; ?>

            <?php print $show_terms_catalog; ?>

            <?php print $show_terms_trademark; ?>

            <?php print $show_terms_common; ?>

            <?php print $show_terms_tags; ?>

            <?php print $show_share_widget; ?>

            <?php if ($links): ?>

                <div class = "links"><?php print $links; ?></div>

        <?php
            endif;
        ?>

        <?php
        endif;
        ?>
    </div>
</div>