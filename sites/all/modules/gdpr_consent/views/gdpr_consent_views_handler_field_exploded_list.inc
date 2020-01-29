<?php

/**
 * @file
 * Views field displaying explanations of changes to consent.
 */

/**
 * Implementing archived field.
 */
class GdprConsentViewsHandlerFieldExplodedList extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $extras = explode("\r\n", $values->{$this->field_alias});

    return theme('item_list', $extras);
  }

}
