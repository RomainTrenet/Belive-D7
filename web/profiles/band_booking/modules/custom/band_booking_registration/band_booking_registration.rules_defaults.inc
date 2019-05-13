<?php

/**
 * @file
 * band_booking_registration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function band_booking_registration_default_rules_configuration() {
  $items = array();
  $items['rules_on_registration'] = entity_import('rules_config', '{ "rules_on_registration" : {
      "LABEL" : "On registration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "registration" ],
      "ON" : { "registration_insert" : [] },
      "DO" : [
        { "mimemail" : {
            "USING" : {
              "key" : "node_registration",
              "to" : "[registration:mail]",
              "from_name" : [ "site:name" ],
              "from_mail" : [ "site:mail" ],
              "reply_to" : [ "site:mail" ],
              "list_unsubscribe" : "[site:url]node\\/[registration:entity-id]\\/state_registration\\/[registration:user-uid]",
              "subject" : "[site:name] | [registration:author] vous a inscrit \\u00e0 l\\u0027\\u00e9v\\u00e8nement [registration:entity:title]",
              "body" : "Bonjour [registration:user:name],\\r\\n\\r\\nVous avez \\u00e9t\\u00e9 ajout\\u00e9(e) \\u00e0 la prestation \\u003Ca href=\\u0022[site:url]node\\/[registration:entity-id]\\u0022\\u003E[registration:entity:title]\\u003C\\/a\\u003E.\\r\\nVeuillez me pr\\u00e9venir de votre pr\\u00e9sence \\u003Ca href=\\u0022[site:url]node\\/[registration:entity-id]\\/state_registration\\/[registration:user-uid]\\u0022\\u003E\\u00e0 cette adresse\\u003C\\/a\\u003E.\\r\\n\\r\\nMerci d\\u0027avance,\\r\\n[registration:author]."
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        },
        { "drupal_message" : { "message" : "[registration:user:name] a bien \\u00e9t\\u00e9 ajout\\u00e9 \\u00e0 l\\u0027\\u00e9v\\u00e8nement \\u0022[registration:entity:title]\\u0022." } }
      ]
    }
  }');
  $items['rules_on_registration_state_change'] = entity_import('rules_config', '{ "rules_on_registration_state_change" : {
      "LABEL" : "On registration state change",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "registration state" ],
      "REQUIRES" : [ "rules", "mimemail", "registration" ],
      "ON" : { "registration_update" : [] },
      "DO" : [
        { "mimemail" : {
            "USING" : {
              "key" : "node_registration",
              "to" : "[registration:author:mail]",
              "from_name" : [ "site:name" ],
              "from_mail" : [ "site:mail" ],
              "reply_to" : [ "site:mail" ],
              "subject" : "[site:name] | Changement de statut de pour l\\u0027\\u00e9v\\u00e8nement",
              "body" : "Bonjour [registration:author],\\r\\n\\r\\n[registration:user:name] a chang\\u00e9 son statut pour \\u0027[registration:state]\\u0027 pour l\\u0027\\u00e9v\\u00e8nement [registration:entity:title].\\r\\n[registration:user]\\r\\n\\r\\n[site:name]."
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        }
      ]
    }
  }');
  $items['rules_on_unregistration'] = entity_import('rules_config', '{ "rules_on_unregistration" : {
      "LABEL" : "On unregistration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "registration" ],
      "ON" : { "registration_delete" : [] },
      "DO" : [
        { "mimemail" : {
            "USING" : {
              "key" : "node_unregistration",
              "to" : "[registration:mail]",
              "from_name" : [ "site:name" ],
              "from_mail" : [ "site:mail" ],
              "reply_to" : [ "site:mail" ],
              "list_unsubscribe" : [ "site:mail" ],
              "subject" : "[site:name] | [registration:author] vous a retir\\u00e9 de l\\u0027\\u00e9v\\u00e8nement [registration:entity:title]",
              "body" : "Bonjour [registration:user:name],\\r\\n\\r\\nVous avez \\u00e9t\\u00e9 retir\\u00e9(e) de la prestation \\u0022[registration:entity:title]\\u0022.\\r\\n\\r\\nCordialement,\\r\\n[registration:author]."
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        },
        { "drupal_message" : { "message" : "[registration:user:name] a bien \\u00e9t\\u00e9 retir\\u00e9 de l\\u0027\\u00e9v\\u00e8nement \\u0022[registration:entity:title]\\u0022." } }
      ]
    }
  }');
  return $items;
}
