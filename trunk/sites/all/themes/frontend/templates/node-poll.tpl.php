<div class = "node <?php print $classes; ?>" id = "node-<?php print $node->nid; ?>">
    <div class = "node-inner">
        <?php if ($teaser): ?>

            <h2 class = "title"><?php print $title; ?></h2>

            <div class = "content"><?php print $node->content['body']['#value']; ?></div>

            <?php if (user_access('post comments') && node_comment_mode($nid) == COMMENT_NODE_READ_WRITE): ?>

                <div class = "add-poll-comment">
                    <?php print l(t('Add also comment'), 'comment/reply/' . $node->nid); ?>
                </div>

            <?php
            endif;
            ?>

        <?php else: ?>

            <?php if (!$page): ?>

                <h2 class = "title"><?php print $title; ?></h2>

        <?php
            endif;
        ?>

            <?php if ($node_creator || $node_created_date): ?>

                <div class = "submitted"><?php print $node_creator; ?>

                    <?php print $node_created_date; ?></div>

        <?php
            endif;
        ?>

            <div class = "content">
                <?php print $content; ?>
            </div>

            <?php if ($terms): ?>

                <div class = "taxonomy"><?php print $terms; ?></div>

            <?php
            endif;
            ?>

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