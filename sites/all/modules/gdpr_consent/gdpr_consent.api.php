<?php

/**
 * @file
 * This file contains no working PHP code.
 *
 * This exists to provide additional documentation for doxygen as well as to
 * document hooks in the standard Drupal manner.
 */

/**
 * @defgroup gdpr_consent module integrations.
 *
 * Module integrations with the gdpr_consent module.
 */

/**
 * @defgroup gdpr_consent_hooks hooks.
 *
 * Hooks to be implemented by other modules in order to extend gdpr_consent.
 */

/**
 * Runs actions when GDPR consent is accepted.
 *
 * @param array $data
 *   Data relating to the current acceptance.
 *   Includes:
 *     - uid: The ID of the user that accepted the terms.
 *     - version: The version of Terms accepted.
 *     - revision: The revision of Terms accepted.
 *     - accepted: The timestamp the Terms were accepted at.
 *     - language: The current language.
 */
function hook_gdpr_consent_accepted(array $data) {
  if (module_exists('rules')) {
    $user = user_load($data['uid']);
    $conditions = gdpr_consent_get_conditions($data['language']);
    rules_invoke_event('gdpr_consent_accepted', $user, $conditions, $data['accepted']);
  }
}
