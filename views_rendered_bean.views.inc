<?php

/**
 * Implements hook_views_plugins().
 */
function views_rendered_bean_views_plugins() {
  return array(
    'module' => 'views_rendered_bean',
    'row' => array(
      'views_rendered_bean' => array(
        'title' => t('Rendered Bean Entity'),
        'help' => t('Renders Bean entities using the view mode selection on the bean itself.'),
        'handler' => 'views_rendered_bean_plugin_bean_entity_view',
        'uses fields' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
        'base' => array("bean"),
      ),
    ),
  );
}


