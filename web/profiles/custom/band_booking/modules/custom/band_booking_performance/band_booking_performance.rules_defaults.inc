<?php

/**
 * @file
 * band_booking_performance.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function band_booking_performance_default_rules_configuration() {
  $items = array();
  $items['rules_on_performance_confirmation_change'] = entity_import('rules_config', '{ "rules_on_performance_confirmation_change" : {
      "LABEL" : "On performance confirmation change",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--performance" : { "bundle" : "performance" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-confirm" ],
            "value" : [ "node-unchanged:field-confirm" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:registered_users_mail_list]",
            "subject" : "Prestation [node:title] [node:field_confirm]",
            "message" : "La prestation \\u0022[node:title]\\u0022 a \\u00e9t\\u00e9 mise \\u00e0 jour.\\r\\nElle \\u00e9tait [node-unchanged:field_confirm], elle est d\\u00e9sormais [node:field_confirm].",
            "from" : "[site:mail]",
            "language" : [ "site:current-user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_on_performance_creation'] = entity_import('rules_config', '{ "rules_on_performance_creation" : {
      "LABEL" : "On performance creation",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--performance" : { "bundle" : "performance" } },
      "DO" : [ { "redirect" : { "url" : "node\\/[node:nid]\\/register_many" } } ]
    }
  }');
  return $items;
}
