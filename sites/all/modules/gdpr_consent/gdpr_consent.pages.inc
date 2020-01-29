<?php

/**
 * @file
 * Page output.
 */

/**
 * Page callback.
 */
function gdpr_consent_page() {
  $form = drupal_get_form('gdpr_consent_accept_form');
  $output = drupal_render($form);

  // Return page output.
  return $output;
}
