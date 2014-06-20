<?php

$plugin = array(
  'form'     => 'multi_file_url_tamper_form',
  'callback' => 'multi_file_url_callback',
  'name'     => 'Multi File URL Tamper',
  'multi'    => 'direct',
  'category' => 'Other',
);

function multi_file_url_tamper_form($importer, $element_key, $settings) {
  $form = array();

  $form['instructions'] = array(
    '#markup' => t('Expected input: a string containing concatenated URL')
  );

  return $form;
}

/*
 * PRE: All file URL begin with http
 */
function multi_file_url_callback($source, $item_key, $element_key, &$field, $settings) {
  if (!is_array($field)) {
    $field = array($field);
  }
  $out = array();
  foreach ($field as $f) {
  	$out_tmp = preg_split("/http/", $f, -1, PREG_SPLIT_NO_EMPTY);
  	$out_tmp = "http".implode(";http",$out_tmp);
    $out_tmp = explode(";", $out_tmp);
    $out = array_merge($out, $out_tmp);
  }
  $field = $out;
}
