<?php

/**
 * @file
 * Theme functions for the uc_ups module.
 */

/**
 * Theme function to format the UPS service name and rate amount line-item
 * shown to the customer.
 *
 * @param $variables
 *   Associative array containing information needed to theme a quote.
 *   Contains two keys:
 *   - service: The UPS service name.
 *   - packages: Package information.
 *
 * @ingroup themeable
 */
function theme_uc_optimal_option_label($variables) {
  $service = t('Express Package');//$variables['service'];
  $packages = $variables['packages'];

  // Start with logo as required by the UPS terms of service.
  $output  = theme('image', array(
    'path' => drupal_get_path('module', 'uc_optimal') . '/dhl_small_logo.jpg',
    'alt' => t('Optimal logo'),
    'attributes' => array('class' => 'optimal-logo')
  ));

  // Add the Optimal service name.
  $output .= t('@service Rate', array('@service' => $service));

  // Add package information
  $output .= ' (' . format_plural(count($packages), '1 package', '@count packages') . ')';

  return $output;
}
