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
        { "drupal_message" : {
            "message" : "La prestation a \\u00e9t\\u00e9 mise \\u00e0 jour. La prestation \\u00e9tait [node-unchanged:field_confirm], elle est d\\u00e9sormais [node:field_confirm].\\r\\nEnvoyer mail \\u00e0 : [node:registered_users_mail_list]",
            "type" : "warning"
          }
        },
        { "mail" : {
            "to" : "\\u003Cromain.trenet@gmail.com\\u003E,\\u003Cromain.trenet@outlook.fr\\u003E",
            "subject" : "Prestation [node:title] [node:field_confirm]",
            "message" : "La prestation [node:title] \\u00e9tait [node-unchanged:field_confirm] et d\\u00e9sormais [node:field_confirm]",
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
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--performance" : { "bundle" : "performance" } },
      "DO" : [ { "redirect" : { "url" : "node\\/[node:nid]\\/register_many" } } ]
    }
  }');
  return $items;
}
