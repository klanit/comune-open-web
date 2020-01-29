<?php

/**
 * @file
 * Views handler and plugin definitions for the gdpr_consent module.
 */

/**
 * Implements hook_views_data().
 */
function gdpr_consent_views_data() {
  $data = array();
  $data['gdpr_consent_accepted']['table']['group'] = t('Consent');

  $data['gdpr_consent_accepted']['table']['join']['users'] = array(
    'left_field' => 'uid',
    'field'      => 'uid',
  );

  $data['users']['gdpr_consent_accepted_rel'] = array(
    'real field'   => 'uid',
    'title'        => t('Accepted user'),
    'group'        => t('Consent'),
    'help'         => t('An accepted user'),
    'relationship' => array(
      'handler'            => 'views_handler_relationship',
      'base'               => 'gdpr_consent_accepted',
      'base field'         => 'uid',
      'label'              => t('Consent'),
      'relationship field' => 'uid',
    ),
  );

  $data['gdpr_consent_accepted']['gdpr_consent_conditions_rel'] = array(
    'group'        => t('Consent'),
    'title'        => t('Consent conditions relationship'),
    'help'         => t('Create a relationship to a GDPR consent conditions and GDPR consent accepted.'),
    'relationship' => array(
      'handler'            => 'views_handler_relationship',
      'base'               => 'gdpr_consent_conditions',
      'base field'         => 'tc_id',
      'label'              => t('Consent'),
      'relationship field' => 'tc_id',
    ),
  );

  $data['gdpr_consent_accepted']['version'] = array(
    'title'    => t('Version'),
    'help'     => t('Version ID accepted.'),
    'field'    => array(
      'handler'        => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gdpr_consent_accepted']['revision'] = array(
    'title'    => t('Revision'),
    'help'     => t('Revision ID accepted.'),
    'field'    => array(
      'handler'        => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort',
    ),
  );

  if (module_exists('locale')) {
    $data['gdpr_consent_accepted']['language'] = array(
      'title'    => t('Language'),
      'help'     => t('Language of GDPR consent accepted by user.'),
      'field'    => array(
        'handler'        => 'views_handler_field_locale_language',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_locale_language',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_locale_language',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }

  $data['gdpr_consent_accepted']['uid'] = array(
    'title'        => t('User ID'),
    'help'         => t('User ID of user that accepted.'),
    'field'        => array(
      'handler'        => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter'       => array(
      'handler'     => 'views_handler_filter_user_name',
      'allow empty' => TRUE,
    ),
    'argument'     => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'sort'         => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base'       => 'users',
      'base_field' => 'uid',
      'handler'    => 'views_handler_relationship',
      'label'      => t('Acceptances to user relationship'),
    ),
  );

  $data['gdpr_consent_accepted']['accepted'] = array(
    'title'  => t('Time accepted'),
    'help'   => t('Time and date user accepted GDPR consent.'),
    'field'  => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler'     => 'views_handler_filter_date',
      'allow empty' => TRUE,
    ),
    'sort'   => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['gdpr_consent_accepted']['revoked'] = array(
    'title'  => t('Time revoked'),
    'help'   => t('Time and date user revoked GDPR consent.'),
    'field'  => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler'     => 'views_handler_filter_date',
      'allow empty' => TRUE,
    ),
    'sort'   => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['gdpr_consent_conditions'] = array(
    'version'    => array(
      'title'    => t('Version'),
      'help'     => t('Version of GDPR consent.'),
      'field'    => array(
        'handler'        => 'views_handler_field_markup',
        'click sortable' => TRUE,
        'format'         => array('field' => 'format'),
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'revision'   => array(
      'title'    => t('Revision'),
      'help'     => t('Revision of GDPR consent.'),
      'field'    => array(
        'handler'        => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'conditions' => array(
      'title'    => t('Consent'),
      'help'     => t('Text of GDPR consent.'),
      'field'    => array(
        'handler'        => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_string',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'date'       => array(
      'title'  => t('Date added'),
      'help'   => t('Date consents where added'),
      'field'  => array(
        'handler'        => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler'     => 'views_handler_filter_date',
        'allow empty' => TRUE,
      ),
      'sort'   => array(
        'handler' => 'views_handler_sort_date',
      ),
    ),
    'changes'    => array(
      'title'    => t('Changes'),
      'help'     => t('Explanation of changes to consent'),
      'field'    => array(
        'handler'        => 'gdpr_consent_views_handler_field_exploded_list',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_string',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'table'      => array(
      'group' => t('Consent'),
      'base'  => array(
        'field'    => 'tc_id',
        'title'    => t('GDPR consent'),
        'help'     => 'Versions of the consent text',
        'weight'   => 10,
        'database' => 'default',
      ),
    ),
  );

  if (module_exists('locale')) {
    $data['gdpr_consent_conditions']['language'] = array(
      'title'    => t('Language'),
      'help'     => t('Language of consents.'),
      'field'    => array(
        'handler'        => 'views_handler_field_locale_language',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_locale_language',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_locale_language',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }

  return $data;
}
