<div id="block-<?php print $block->module .'-'. $block->delta ?>" class="block-wrap <?php print $block_classes . ' ' . $block_zebra; ?>">
  <div class="block-inner">

    <?php if (!empty($block->subject)): ?>
      <h3 class="title block-title"><?php print $block->subject; ?></h3>
    <?php endif; ?>

    <div class="content">
      <?php print $block->content; ?>
    </div>

  </div>
</div>
