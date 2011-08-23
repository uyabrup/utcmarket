<?php if (!empty($title)): ?>

    <h3><?php print $title; ?></h3>

<?php
endif;
?>

<table class = "views-view-grid">
    <tbody>
        <?php
        foreach ($rows as $row_number => $columns):
        ?>

        <?php
            $row_class='row-' . ($row_number + 1);

            if ($row_number == 0)
                {
                $row_class.=' row-first';
                }

            if (count($rows) == ($row_number + 1))
                {
                $row_class.=' row-last';
                }

            if (($row_number == 0) && (count($rows) == ($row_number + 1)))
                {
                $row_class.=' row-first-last';
                }
        ?>

            <tr class = "<?php print $row_class; ?>">
                <?php
                foreach ($columns as $column_number => $item):
                ?>

                <?php
                    $col_tpl=$options['columns'];

                    $col_count=count($columns);
                    $col_num=$column_number + 1;

                    if ($col_count == $col_num && $col_tpl != 1)
                        { // ƒобавл€ем класс дл€ последней колонки
                        $col_pos_class=' last-column';
                        }
                    else if ($column_number == 0 && $col_tpl != 1)
                        { //  ласс дл€ начальной колонки
                        $col_pos_class=' first-column';
                        }
                    else
                        {
                        $col_pos_class='';
                        }

                    $td_width=' col-width-'
                      . round(100 / $col_count); //  ласс ширины дл€ автоматической центровки колонок в таблице
                ?>

                    <td class = "<?php print 'col-'. $col_num; ?><?php print $col_pos_class . $td_width; // ƒополнительные классы ?>">
                        <div class = "grid-col-wrapper">
                            <?php print $item; ?>
                        </div>
                    </td>

                <?php
                endforeach;
                ?>
            </tr>

        <?php
        endforeach;
        ?>
    </tbody>
</table>