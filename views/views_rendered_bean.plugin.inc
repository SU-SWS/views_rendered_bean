<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class views_rendered_bean_plugin_bean_entity_view extends entity_views_plugin_row_entity_view {

  /**
   * Do not provide any view mode options.
   *
   * @return array
   *   [description]
   */
  public function options_form(&$form, &$form_state) {
    // parent::options_form($form, $form_state);
    $form['notice']["#markup"] = "<p>" . t("The view mode that is used for rendering each bean is configured on the bean's edit form. If you want to set all beans to render as a specific view mode change this format to Rendered Entity instead of Rendered Bean Entity.") . "</p>";
    return $form;
  }

  /**
   * Render each bean with the view mode setting included on the bean.
   *
   * @param array $values
   *   An array of result values.
   */
  public function pre_render($values) {

    if (!empty($values)) {
      list($this->entity_type, $this->entities) = $this->view->query->get_result_entities($values, !empty($this->relationship) ? $this->relationship : NULL, isset($this->field_alias) ? $this->field_alias : NULL);
    }

    // Render the Beans.
    if ($this->entities) {
      foreach ($this->entities as $i => $entity) {
        // View mode from the bean entity.
        $vm = $entity->view_mode;
        // The render array.
        $render = entity_view($this->entity_type, array($entity), $vm);
        // The part of the array we want.
        $content = $render[$this->entity_type][$entity->delta][$this->entity_type];
        // Add to rendered content output.
        $this->rendered_content[$entity->delta] = $content;
      }
    }

  }

}
