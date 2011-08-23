<?php print drupal_render($form['title']); ?>
<?php print drupal_render($form['help']); ?>
<table>
  <thead>
    <tr>
      <th><?php print t('Menu'); ?></th>
      <th><?php print t('Options'); ?></th>
      <th><?php print t('Enable Mega Menu Block'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($menu as $m): ?>
      <tr>
        <td><h3><?php print $m['details']['title']; ?></h3></td>
        <td><?php print l(t('configure mega'),'admin/build/megamenu/settings/' . $m['details']['menu_name']); ?></td>
        <td>
          <?php print drupal_render($form['enabled'][$m['details']['menu_name']]); ?>
        </td>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
<div><?php print drupal_render($form['save_configuration']); ?></div>
<?php print drupal_render($form); // Print the closing form elements (ID and hidden validation tags) ?>
