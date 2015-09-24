<?php

/**
 * Implements hook_default_services_endpoint().
 */
function xlms_session_default_services_endpoint() {
  $endpoints = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'xlms_session';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'xlms/session';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'xlms_session' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;

  $endpoints[] = $endpoint;

  return $endpoints;
}
