<?php

/**
 * @file
 * Rule configuration.
 */

/**
 * Implements hook_rules_event_info().
 */
function gdpr_consent_rules_event_info() {
  return array(
    'gdpr_consent_accepted' => array(
      'label'     => t('After user accepts consent'),
      'group'     => t('User'),
      'variables' => array(
        'account'    => array(
          'type'  => 'user',
          'label' => t('Updated user'),
        ),
        'conditions' => array(
          'type'  => 'text',
          'label' => t('GDPR consent text'),
        ),
        'accepted'   => array(
          'type'  => 'text',
          'label' => t('Timestamp of acceptance'),
        ),
      ),
    ),
  );
}
