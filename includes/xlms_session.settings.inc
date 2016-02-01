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

  $form['kurento_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Kurento video server settings'),
    '#description' => t('Default settings for the Kurento video server.'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['kurento_settings']['xlms_session_kurento_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Kurento Server'),
    '#description' => t('The URI of the Kurento Server, exposed as ws_uri: ws://'),
    '#default_value' => variable_get('xlms_session_kurento_server', ''),
    '#size' =>  100,
    '#maxlength' => 200,
    '#required' => FALSE,
  );

  $form['kurento_settings']['xlms_session_kurento_video_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Video directory'),
    '#description' => t('A directory on the filesystem in which to store videos. Described as a file URI with the prefix file://'),
    '#default_value' => variable_get('xlms_session_kurento_video_directory', ''),
    '#size' =>  100,
    '#maxlength' => 200,
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
