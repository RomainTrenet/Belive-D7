<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php if(isset($row->field_field_date[0]['raw']['value'])) : ?>
    <?php
    $raw_date = $row->field_field_date[0]['raw']['value'];
    $time = strtotime($raw_date);
    $date_time = new DateTime("@$time");
    ?>
    <div>
        <div>
            <span><?php print t(date_format($date_time,"l")); ?></span>
            <span><?php print date_format($date_time,"j"); ?></span>
            <span><?php print t(date_format($date_time,"F")); ?></span>
            <span><?php print date_format($date_time,"o"); ?></span>
        </div>
        <div>
            <span><?php print date_format($date_time,"G"); ?></span>
            <span>:</span>
            <span><?php print date_format($date_time,"i"); ?></span>
        </div>
    </div>

<?php endif;