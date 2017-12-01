<?php
/**
 * @file
 * Optimal administration menu items.
 */

/**
 * Optimal Online Tool settings.
 *
 * Records Optimal account information necessary to use the service. Allows testing
 * or production mode. Configures which UPS services are quoted to customers.
 *
 * @see uc_optimal_admin_settings_validate()
 * @see uc_optimal_admin_settings_submit()
 * @ingroup forms
 */
function uc_optimal_admin_settings($form, &$form_state) {

$form['uc_optimal_acc'] =array(
  '#type' => 'textfield', 
  '#title' => t('Export Number'),
  '#suffix'=> t('Allows customers to get accurate Optimal Ship rate based on account number.'), 
  '#default_value' => variable_get('uc_optimal_acc',''),
  );

$form['uc_optimal_enable'] = array(
  '#type'=> 'checkbox',
  '#title' => t('Enable'),
  '#suffix'=> t('Enable the shipping method'),	
  '#default_value' => variable_get('uc_optimal_enable',''),
	);

$form['uc_optimal_enable_dim_weights'] = array(
	'#type'=>'checkbox',
	'#title'=> t('Enable Dimensional Weights'),
	'#suffix'=>t('Enable dimensional calculations. Dimensions must be entered for all your products.'),
	'#default_value' => variable_get('uc_optimal_enable_dim_weights',''),
	);
$form['uc_optimal_title'] = array(
	'#type' => 'textfield',
	'#title' => t('title'),
	'#suffix' => t('Title to be displayed on site.'),
	'#default_value' => variable_get('uc_optimal_enable_title','DHL with Optimal Ship'),
  );
  return system_settings_form($form);
}

/**
 * Validation handler for uc_ups_admin_settings.
 *
 * Requires password only if it hasn't been set.
 *
 * @see uc_optimal_admin_settings()
 * @see uc_optimal_admin_settings_submit()
 */
function uc_optimal_admin_settings_validate($form, &$form_state) {
  
}

/**
 * Submit handler for uc_ups_admin_settings().
 *
 * Emulates system_settings_form_submit(), but only on a subset of the
 * form values.
 *
 * @see uc_optimal_admin_settings()
 * @see uc_optimal_admin_settings_validate()
 */
function uc_optimal_admin_settings_submit($form, &$form_state) {

  foreach($form_state['values'] as $key=> $value){
  	if ($key == 'uc_optimal_acc'|| $key == 'uc_optimal_title'  || $key == 'uc_optimal_enable_dim_weights'){
  		variable_set($key,$value);
  	}
    if ($key =='uc_optimal_enable'){
      variable_set($key,$value);
     

    }
  }
}
