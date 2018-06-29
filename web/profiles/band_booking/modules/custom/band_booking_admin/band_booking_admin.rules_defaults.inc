<?php
/**
 * @file
 * band_booking_admin.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function band_booking_admin_default_rules_configuration() {
  $items = array();
  $items['rules_on_manager_login'] = entity_import('rules_config', '{ "rules_on_manager_login" : {
      "LABEL" : "On manager login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "admin\\/dashboard" } } ]
    }
  }');
  $items['rules_on_musician_login'] = entity_import('rules_config', '{ "rules_on_musician_login" : {
      "LABEL" : "On musician login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "pathrules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } },
        { "NOT pathrules_checkpath" : { "path" : "?destination" } }
      ],
      "DO" : [ { "redirect" : { "url" : "mes-prestations" } } ]
    }
  }');
  return $items;
}
