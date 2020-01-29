<?php

/**
 * @file
 * Taxonomy export csv admin inc file.
 */

/**
 * Implements hook_admin_settings().
 */
function taxonomy_export_csv_admin_settings() {
  $form['taxonomy_export_csv'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy terms export'),
  );

  $vocabulary = taxonomy_get_vocabularies();
  $checklist_vocab_array = array();

  foreach ($vocabulary as $item) {
    $key = $item->vid;
    $value = $item->name;
    $checklist_vocab_array[$item->machine_name] = $value;
  }

  $form['taxonomy_export_csv']['taxonomy'] = array(
    '#type' => 'select',
    '#title' => t('Select Vocabulary'),
    '#options' => $checklist_vocab_array,
    '#default_value' => variable_get('taxonomy', 5),
    '#description' => t("Select vocabulary for export csv file."),
  );
  return system_settings_form($form);
}

/**
 * Implements submit handler.
 */
function taxonomy_export_csv_submit($form, $form_state) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($form_state['values']['taxonomy']);
  $tree = taxonomy_get_tree($vocabulary->vid);
  $default_column = array(
    'name',
    'vid',
    'description',
    'format',
    'weight',
    'depth',
    'parents',
  );
  // Get header colunm name.
  $all_colunm = $taxonomy[0] = _taxonomy_csv_header($tree, $default_column);

  foreach ($tree as $term) {
    $taxonomy[] = _taxonomy_csv_term($default_column, $all_colunm, $vocabulary, $term);
  }
  // Download csv file.
  download_csv($form_state['values']['taxonomy'], $taxonomy);
}

/**
 * Get all taxonomy fields.
 */
function _taxonomy_csv_term($default_column, $all_column, $vocabulary, $term) {
  foreach ($all_column as $key => $value) {
    if (in_array($value, $default_column)) {
      $taxonomy_column[$value] = ($value == 'vid') ? $vocabulary->machine_name : $term->$value;
    }
    else {
      $taxonomy_column[$value] = _taxonomy_extra_field_info($term->tid, $value);
    }
  }
  $taxonomy_column['parents'] = ($term->parents[0] > 0) ? taxonomy_term_load($term->parents['0'])->name : '';
  return $taxonomy_column;
}

/**
 * Perpare csv header column.
 */
function _taxonomy_csv_header($taxonomy_column, $default_column) {
  foreach ($taxonomy_column as $term) {
    $taxonomy = taxonomy_term_load($term->tid);
    foreach ($taxonomy as $key => $value) {
      $column[] = $key;
    }
    $column[] = 'depth';
    // Unset tid column.
    unset($column['0']);
    // Unset vocabulary_machine_name column.
    unset($column['6']);
    break;
  }
  $column_marge = array_merge($default_column, $column);
  $all_column = array_unique($column_marge);
  return $all_column;
}

/**
 * Get taxonomy extra field value.
 */
function _taxonomy_extra_field_info($tid, $field_name) {
  $term = taxonomy_term_load($tid);
  $extra_field = field_get_items('taxonomy_term', $term, $field_name);
  if (isset($extra_field[0]['tid'])) {
    return taxonomy_term_load($extra_field[0]['tid'])->name;
  }
}

/**
 * Download csv file.
 */
function download_csv($file_name, $csv_array) {
  // Send response headers to the browser.
  drupal_add_http_header('Content-Type', 'text/csv');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=' . $file_name . '.csv');

  $fp = fopen('php://output', 'w');
  foreach ($csv_array as $line) {
    fputcsv($fp, $line);
  }
  fclose($fp);
  drupal_exit();
}
