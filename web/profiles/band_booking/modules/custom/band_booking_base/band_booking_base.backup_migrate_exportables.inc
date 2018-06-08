<?php
/**
 * @file
 * band_booking_base.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function band_booking_base_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'belive_booking';
  $item->name = 'Belive Booking';
  $item->source_id = 'db';
  $item->destination_id = 'scheduled';
  $item->copy_destination_id = '';
  $item->profile_id = 'default';
  $item->keep = -2;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['belive_booking'] = $item;

  return $export;
}
