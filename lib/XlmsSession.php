<?php

/**                                                                              
 * @file                                                                         
 * Defines the base class for XLMS Session objects.
 */ 

class XlmsSession {

  var $id;

  // @TODO: Still getting a fatal error in common.inc if this is protected or private.
  var $result_id;

  private $quizResult;

  var $trainer_id;

  var $session_data;

  var $start_time;

  var $elapsed_time;

  var $success;

  function XlmsSession($id = NULL) {
    if ($id) {
      $result = db_query("SELECT * FROM {xlms_session} WHERE id=:id", array(':id' => $id));
      foreach ($result->fetchObject() as $property => $value) {
        if (property_exists($this, $property)) {
          $this->$property = $value;
        }
      }
    }
    watchdog('alert','test');
    drupal_alter('xlms_session_load', $this);
  }

  function setSessionData($data) {
    // TODO - not sure exactly what this data looks like yet?                      
    $this->trainer_id = $data->trainer_id;                                 
    $this->session_data = $data->session_data;                             
    $this->start_time = $data->start_time;                             
    $this->elapsed_time = $data->elapsed_time;                             
    $this->success = $data->success;                             
                                                                                 
    // Inform any other modules that an update occurred and pass the session data. 
    module_invoke_all('xlms_session_update', $this);

    $this->save();
  }

  function unsetSessionData($data) {
    $this->trainer_id = NULL;
    $this->session_data = NULL;
    $this->start_time = NULL;
    $this->elapsed_time = NULL;
    $this->success = NULL;

    $this->save();
  }

  function save() {
    $primary_key = !empty($this->id) ? array('id') : NULL;                 
    drupal_write_record('xlms_session', $this, $primary_key); 
  }

  function chromeUrl() {
    return variable_get('xlms_session_chrome_url', '');
  }

  function chromeUrlQuery() {
    if (!isset($this->url_query)) {
      $this->url_query = array();
    }
    $this->url_query['endpoint'] = $this->endpoint();
    return $this->url_query;
  }

  function endpoint() {
    $path = '';

    if ($endpoint = services_endpoint_load('xlms_session')) {                    
      $path = url($endpoint->path . '/' . $endpoint->name, array('absolute' => TRUE));
    }                                                                            

    // Add our id to the URL so Chrome app doesn't need to parse anything.       
    if ($this->id) {
      $path .= '/' . $this->id;                                            
    }

    return $path;
  }

  function quizResult() {
    if (!isset($this->quizResult)) {
      if (isset($this->result_id)) {
        $result = db_query("SELECT * FROM {quiz_node_results} WHERE result_id=:id", array(':id' => $this->result_id));
        $this->quizResult = $result->fetchObject();
      }
    }
    return $this->quizResult;
  }

  function setQuizResult($result_id) {
    $this->result_id = $result_id;
    return $this->quizResult();
  }
}
