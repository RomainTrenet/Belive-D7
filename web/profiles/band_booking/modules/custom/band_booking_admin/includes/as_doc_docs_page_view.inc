<?php

/**
 * @file
 * Module to manage pages.
 */

/**
 * Documentation page content.
 */
function _as_doc_docs_page_view() {
  // Variable needed in the content function.
  /*
  $is_node_tab = FALSE;

  // Init products array.
  $products = array();

  // Get the contextual product id, if there is one.
  $contextual_pid = _as_doc_get_contextual_pid();

  // If a contextual product is set.
  if (is_numeric($contextual_pid)) {
    $product = node_load($contextual_pid);
    if (!empty($product)) {
      $products[$product->nid] = $product;
    }
  }
  // Get authorized products.
  else {
    $nids = product_list_products();
    $nids = array_reverse($nids);
    $products = node_load_multiple($nids);
  }*/

  return as_doc_documentation_content();
}

function as_doc_documentation_content() {
  return ('<p>WIZZZZ</p>');
}