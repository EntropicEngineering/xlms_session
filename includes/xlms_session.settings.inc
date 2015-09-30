<?php

/**
 * Settings form for XLMS session configuration.
 */
function xlms_session_settings() {
  $form = array();

  $form['xlms_session_chrome_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Chrome URL'),
    '#default_value' => variable_get('xlms_session_chrome_url', ''),
    '#size' => 100,
    '#maxlength' => 200,
    '#description' => t("The URL for the Chrome app that is managing this session."),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
