<?php


/**
 * Last chance for user to review shipment.
 *
 * @see uc_optimal_confirm_shipment_submit()
 * @see theme_uc_optimal_confirm_shipment()
 * @ingroup forms
 */
function uc_optimal_confirm_shipment($form, &$form_state, $order) {
  $form['digest'] = array(
    '#type' => 'hidden',
    '#value' => $_SESSION['optimal']['digest']
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Request Pickup')
  );

  return $form;
}

/**
 * Generates label and schedules pickup of the shipment.
 *
 * @see uc_optimal_confirm_shipment()
 */
function uc_optimal_confirm_shipment_submit($form, &$form_state) {
  // Request pickup using parameters in form.
  $order_id = $_SESSION['optimal']['order_id'];
  $packages = array_keys($_SESSION['optimal']['packages']);
  $request = uc_optimal_request_pickup($form_state['values']['digest'], $order_id, $packages);
  $result = drupal_http_request();

}

function uc_optimal_request_pickup($digest, $order_id = 0, $packages = array()) {
  $packages = (array)$packages;
    if ($order_id || count($packages)) {
    	
    }
}
