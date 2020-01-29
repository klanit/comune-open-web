<?php

/**
 * @file
 * Views fields displaying additional checkboxes.
 */

/**
 * Implementing serialized fields.
 */
class GdprConsentViewsHandlerFieldUnserializedList extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $extras = unserialize($values->{$this->field_alias});

    return theme('item_list', $extras);
  }

}
