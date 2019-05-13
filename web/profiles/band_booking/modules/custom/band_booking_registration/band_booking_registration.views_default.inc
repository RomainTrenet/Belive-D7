<?php

/**
 * @file
 * band_booking_registration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function band_booking_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'band_booking_administration_registrations';
  $view->description = 'Lists of registrations';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Band booking | Administration : Registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'regist-lst';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Options avancées',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'state' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'blv-evt-[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'state_id' => 'state_id',
    'state' => 'state',
    'name' => 'name',
    'title' => 'title',
    'field_place' => 'title',
    'field_date' => 'title',
    'accept_link' => 'accept_link',
    'refuse_link' => 'accept_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'accept_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'refuse_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relation: Inscription : Utilisateur */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Relation: Inscription : Registration to Nœud */
  $handler->display->display_options['relationships']['registration_related_node']['id'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['table'] = 'registration';
  $handler->display->display_options['relationships']['registration_related_node']['field'] = 'registration_related_node';
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Inscription : State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Utilisateur inscrit';
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Prestation';
  /* Champ: Contenu : Lieu */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = ' ([field_date])';
  $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Champ: Inscription : Lien d'affichage */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Actions';
  /* Champ: Inscription : Lien de suppression */
  $handler->display->display_options['fields']['delete_registration']['id'] = 'delete_registration';
  $handler->display->display_options['fields']['delete_registration']['table'] = 'registration';
  $handler->display->display_options['fields']['delete_registration']['field'] = 'delete_registration';
  /* Champ: Inscription : User: Accept registration */
  $handler->display->display_options['fields']['accept_link']['id'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['table'] = 'registration';
  $handler->display->display_options['fields']['accept_link']['field'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['label'] = 'Changer le statut';
  /* Champ: Inscription : User: Refuse registration */
  $handler->display->display_options['fields']['refuse_link']['id'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['table'] = 'registration';
  $handler->display->display_options['fields']['refuse_link']['field'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['label'] = 'Changer le statut';
  /* Critère de tri: Inscription : State entity */
  $handler->display->display_options['sorts']['state']['id'] = 'state';
  $handler->display->display_options['sorts']['state']['table'] = 'registration';
  $handler->display->display_options['sorts']['state']['field'] = 'state';
  $handler->display->display_options['sorts']['state']['order'] = 'DESC';
  /* Critère de tri: Contenu : Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'registration_related_node';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Filtrer par statut';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Critère de filtrage: Utilisateur : Actif */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user_uid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Critère de filtrage: Contenu : Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-3:+10';

  /* Display: Bock | Performance admin registrations block */
  $handler = $view->new_display('block', 'Bock | Performance admin registrations block', 'block_nid_registration');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'adm-regist-lst';
  $handler->display->display_options['display_description'] = 'All registrations for a certain nid';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'blv-evt-[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'state_id' => 'state_id',
    'state' => 'state',
    'name' => 'name',
    'title' => 'title',
    'field_place' => 'title',
    'field_date' => 'title',
    'accept_link' => 'accept_link',
    'refuse_link' => 'accept_link',
    'postpone_link' => 'accept_link',
    'wait_link' => 'accept_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'accept_link' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'refuse_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'postpone_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'wait_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Aucune inscription pour le moment.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Inscription : State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Artiste';
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Prestation';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Champ: Contenu : Lieu */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_place']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = ' ([field_date])';
  $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Champ: Inscription : User: Accept registration */
  $handler->display->display_options['fields']['accept_link']['id'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['table'] = 'registration';
  $handler->display->display_options['fields']['accept_link']['field'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['label'] = 'Changer le statut de l\'inscription';
  /* Champ: Inscription : User: Refuse registration */
  $handler->display->display_options['fields']['refuse_link']['id'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['table'] = 'registration';
  $handler->display->display_options['fields']['refuse_link']['field'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['label'] = 'Changer le statut de l\'inscription';
  /* Champ: Inscription : User: Postpone registration */
  $handler->display->display_options['fields']['postpone_link']['id'] = 'postpone_link';
  $handler->display->display_options['fields']['postpone_link']['table'] = 'registration';
  $handler->display->display_options['fields']['postpone_link']['field'] = 'postpone_link';
  $handler->display->display_options['fields']['postpone_link']['label'] = 'Changer le statut de l\'inscription';
  /* Champ: Inscription : User: Wait registration */
  $handler->display->display_options['fields']['wait_link']['id'] = 'wait_link';
  $handler->display->display_options['fields']['wait_link']['table'] = 'registration';
  $handler->display->display_options['fields']['wait_link']['field'] = 'wait_link';
  $handler->display->display_options['fields']['wait_link']['label'] = 'Changer le statut';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'registration_related_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Inscriptions à "%1"';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['band_booking_administration_registrations'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Options avancées'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Utilisateur'),
    t('node from Registration'),
    t('Utilisateur inscrit'),
    t('Prestation'),
    t('Date'),
    t(' ([field_date])'),
    t('Actions'),
    t('Lien de suppression'),
    t('Changer le statut'),
    t('Filtrer par statut'),
    t('Bock | Performance admin registrations block'),
    t('All registrations for a certain nid'),
    t('Aucune inscription pour le moment.'),
    t('Artiste'),
    t('Changer le statut de l\'inscription'),
    t('Tout'),
    t('Inscriptions à "%1"'),
  );
  $export['band_booking_administration_registrations'] = $view;

  $view = new view();
  $view->name = 'last_registrations_change';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Band booking | Administration : Last registrations change';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dernières inscriptions';
  $handler->display->display_options['css_class'] = 'regist-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'state_id' => 'state_id',
    'name' => 'name',
    'state_past_tense_conjugation' => 'name',
    'title' => 'name',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state_past_tense_conjugation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Pas de nouveau changement d\'état des inscriptions depuis 7 jours.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relation: Inscription : Utilisateur */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Relation: Inscription : Registration to Nœud */
  $handler->display->display_options['relationships']['registration_related_node']['id'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['table'] = 'registration';
  $handler->display->display_options['relationships']['registration_related_node']['field'] = 'registration_related_node';
  /* Champ: Inscription : Date mise à jour */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'registration';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  $handler->display->display_options['fields']['updated']['label'] = '';
  $handler->display->display_options['fields']['updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['updated']['date_format'] = 'custom';
  $handler->display->display_options['fields']['updated']['custom_date_format'] = 'd M';
  $handler->display->display_options['fields']['updated']['second_date_format'] = 'long';
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Champ: Gestionnaire défectueux/manquant */
  $handler->display->display_options['fields']['state_past_tense_conjugation']['id'] = 'state_past_tense_conjugation';
  $handler->display->display_options['fields']['state_past_tense_conjugation']['table'] = 'registration';
  $handler->display->display_options['fields']['state_past_tense_conjugation']['field'] = 'state_past_tense_conjugation';
  $handler->display->display_options['fields']['state_past_tense_conjugation']['label'] = '';
  $handler->display->display_options['fields']['state_past_tense_conjugation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_past_tense_conjugation']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Global : Texte personnalisé */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[name] [state_past_tense_conjugation] [title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Critère de tri: Inscription : Date mise à jour */
  $handler->display->display_options['sorts']['updated']['id'] = 'updated';
  $handler->display->display_options['sorts']['updated']['table'] = 'registration';
  $handler->display->display_options['sorts']['updated']['field'] = 'updated';
  $handler->display->display_options['sorts']['updated']['order'] = 'DESC';
  /* Critère de filtrage: Inscription : Date mise à jour */
  $handler->display->display_options['filters']['updated']['id'] = 'updated';
  $handler->display->display_options['filters']['updated']['table'] = 'registration';
  $handler->display->display_options['filters']['updated']['field'] = 'updated';
  $handler->display->display_options['filters']['updated']['operator'] = '>=';
  $handler->display->display_options['filters']['updated']['value']['value'] = '-7 day';
  $handler->display->display_options['filters']['updated']['value']['type'] = 'offset';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'waiting' => 'waiting',
  );

  /* Display: Dernières inscriptions */
  $handler = $view->new_display('block', 'Dernières inscriptions', 'block');
  $translatables['last_registrations_change'] = array(
    t('Master'),
    t('Dernières inscriptions'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Pas de nouveau changement d\'état des inscriptions depuis 7 jours.'),
    t('Utilisateur'),
    t('node from Registration'),
    t('[name] [state_past_tense_conjugation] [title]'),
  );
  $export['last_registrations_change'] = $view;

  $view = new view();
  $view->name = 'registrations';
  $view->description = 'Lists of registrations';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Band booking | Front : Registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'regist-lst';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Options avancées',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'state' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'blv-evt-[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'state_id' => 'state_id',
    'state' => 'state',
    'name' => 'name',
    'title' => 'title',
    'field_place' => 'title',
    'field_date' => 'title',
    'accept_link' => 'accept_link',
    'refuse_link' => 'accept_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'accept_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'refuse_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relation: Inscription : Utilisateur */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Relation: Inscription : Registration to Nœud */
  $handler->display->display_options['relationships']['registration_related_node']['id'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['table'] = 'registration';
  $handler->display->display_options['relationships']['registration_related_node']['field'] = 'registration_related_node';
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Inscription : State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Utilisateur inscrit';
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Prestation';
  /* Champ: Contenu : Lieu */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = ' ([field_date])';
  $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Champ: Inscription : Lien d'affichage */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Actions';
  /* Champ: Inscription : Lien de suppression */
  $handler->display->display_options['fields']['delete_registration']['id'] = 'delete_registration';
  $handler->display->display_options['fields']['delete_registration']['table'] = 'registration';
  $handler->display->display_options['fields']['delete_registration']['field'] = 'delete_registration';
  /* Champ: Inscription : User: Accept registration */
  $handler->display->display_options['fields']['accept_link']['id'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['table'] = 'registration';
  $handler->display->display_options['fields']['accept_link']['field'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['label'] = 'Changer le statut';
  /* Champ: Inscription : User: Refuse registration */
  $handler->display->display_options['fields']['refuse_link']['id'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['table'] = 'registration';
  $handler->display->display_options['fields']['refuse_link']['field'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['label'] = 'Changer le statut';
  /* Critère de tri: Inscription : State entity */
  $handler->display->display_options['sorts']['state']['id'] = 'state';
  $handler->display->display_options['sorts']['state']['table'] = 'registration';
  $handler->display->display_options['sorts']['state']['field'] = 'state';
  /* Critère de tri: Contenu : Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'registration_related_node';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Filtrer par statut';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Critère de filtrage: Utilisateur : Actif */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user_uid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Critère de filtrage: Contenu : Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-3:+10';

  /* Display: Page | Waiting registrations */
  $handler = $view->new_display('page', 'Page | Waiting registrations', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'blv-evt-[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'nothing' => 'nothing',
    'state_id' => 'state_id',
    'state' => 'state',
    'field_date' => 'field_date',
    'title' => 'title',
    'field_place' => 'title',
    'accept_link' => 'accept_link',
    'refuse_link' => 'accept_link',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'accept_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'refuse_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<table class="views-table">
<caption>Inscriptions en attente<br><em>Vous n\'avez aucune inscription en attente à des évènements.</em></caption>
</table>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Global : Texte personnalisé */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Inscriptions en attente<br>
<em>Pensez à prévenir de vos disponibilités.</em>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Inscription : State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Prestation';
  /* Champ: Contenu : Lieu */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  /* Champ: Inscription : User: Accept registration */
  $handler->display->display_options['fields']['accept_link']['id'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['table'] = 'registration';
  $handler->display->display_options['fields']['accept_link']['field'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['label'] = 'Changer le statut de mon inscription';
  /* Champ: Inscription : User: Refuse registration */
  $handler->display->display_options['fields']['refuse_link']['id'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['table'] = 'registration';
  $handler->display->display_options['fields']['refuse_link']['field'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['label'] = 'Changer le statut de mon inscription';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Inscription : State entity */
  $handler->display->display_options['sorts']['state']['id'] = 'state';
  $handler->display->display_options['sorts']['state']['table'] = 'registration';
  $handler->display->display_options['sorts']['state']['field'] = 'state';
  /* Critère de tri: Contenu : Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'user_uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = 'Inscriptions de %1 aux prestations';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Utilisateur : Actif */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user_uid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Critère de filtrage: Contenu : Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-3:+10';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'registration';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'waiting' => 'waiting',
  );
  $handler->display->display_options['path'] = 'mes-prestations';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mes inscriptions';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block | Registrations page, user accepted/refused */
  $handler = $view->new_display('block', 'Block | Registrations page, user accepted/refused', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'blv-evt-[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'nothing' => 'nothing',
    'state_id' => 'state_id',
    'state' => 'state',
    'field_date' => 'field_date',
    'title' => 'title',
    'field_place' => 'title',
    'accept_link' => 'accept_link',
    'refuse_link' => 'accept_link',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'accept_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'refuse_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<table class="views-table cols-4">
        <caption>Inscriptions déjà statuées<br><em>Vous n\'avez aucune inscription statuée à des évènements.</em></caption>
</table>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Global : Texte personnalisé */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Inscriptions déjà statuées';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Inscription : State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Prestation';
  /* Champ: Contenu : Lieu */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  /* Champ: Inscription : User: Accept registration */
  $handler->display->display_options['fields']['accept_link']['id'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['table'] = 'registration';
  $handler->display->display_options['fields']['accept_link']['field'] = 'accept_link';
  $handler->display->display_options['fields']['accept_link']['label'] = 'Changer le statut de mon inscription';
  /* Champ: Inscription : User: Refuse registration */
  $handler->display->display_options['fields']['refuse_link']['id'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['table'] = 'registration';
  $handler->display->display_options['fields']['refuse_link']['field'] = 'refuse_link';
  $handler->display->display_options['fields']['refuse_link']['label'] = 'Changer le statut de mon inscription';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Contenu : Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'user_uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Utilisateur : Actif */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user_uid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Critère de filtrage: Contenu : Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'registration_related_node';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-3:+10';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'waiting' => 'waiting',
  );

  /* Display: Block | Performance user registrations block */
  $handler = $view->new_display('block', 'Block | Performance user registrations block', 'block_nid_uid_registration');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'regist-lst';
  $handler->display->display_options['display_description'] = 'User registration for a certain nid';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'registration_related_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Inscriptions à "%1"';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filtre contextuel: Inscription : Utilisateur */
  $handler->display->display_options['arguments']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_uid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['user_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_uid']['summary_options']['items_per_page'] = '25';
  $translatables['registrations'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Options avancées'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Utilisateur'),
    t('node from Registration'),
    t('Utilisateur inscrit'),
    t('Prestation'),
    t('Date'),
    t(' ([field_date])'),
    t('Actions'),
    t('Lien de suppression'),
    t('Changer le statut'),
    t('Filtrer par statut'),
    t('Page | Waiting registrations'),
    t('<table class="views-table">
<caption>Inscriptions en attente<br><em>Vous n\'avez aucune inscription en attente à des évènements.</em></caption>
</table>'),
    t('Inscriptions en attente<br>
<em>Pensez à prévenir de vos disponibilités.</em>'),
    t('Changer le statut de mon inscription'),
    t('Tout'),
    t('Inscriptions de %1 aux prestations'),
    t('Block | Registrations page, user accepted/refused'),
    t('<table class="views-table cols-4">
        <caption>Inscriptions déjà statuées<br><em>Vous n\'avez aucune inscription statuée à des évènements.</em></caption>
</table>'),
    t('Inscriptions déjà statuées'),
    t('Block | Performance user registrations block'),
    t('User registration for a certain nid'),
    t('Inscriptions à "%1"'),
  );
  $export['registrations'] = $view;

  $view = new view();
  $view->name = 'registrations_unchanged';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Band booking | Administration : Last registrations unchanged';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Inscriptions non statuées';
  $handler->display->display_options['css_class'] = 'regist-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = '[state_id]';
  $handler->display->display_options['style_options']['columns'] = array(
    'updated' => 'updated',
    'state_id' => 'state_id',
    'name' => 'name',
    'title' => 'name',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Pas de nouveau changement d\'état des inscriptions depuis 7 jours.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relation: Inscription : Utilisateur */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Relation: Inscription : Registration to Nœud */
  $handler->display->display_options['relationships']['registration_related_node']['id'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['table'] = 'registration';
  $handler->display->display_options['relationships']['registration_related_node']['field'] = 'registration_related_node';
  /* Champ: Inscription : Date mise à jour */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'registration';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  $handler->display->display_options['fields']['updated']['label'] = '';
  $handler->display->display_options['fields']['updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['updated']['date_format'] = 'custom';
  $handler->display->display_options['fields']['updated']['custom_date_format'] = 'd M';
  $handler->display->display_options['fields']['updated']['second_date_format'] = 'long';
  /* Champ: Inscription : Registration: State id */
  $handler->display->display_options['fields']['state_id']['id'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['table'] = 'registration';
  $handler->display->display_options['fields']['state_id']['field'] = 'state_id';
  $handler->display->display_options['fields']['state_id']['label'] = '';
  $handler->display->display_options['fields']['state_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state_id']['element_label_colon'] = FALSE;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Global : Texte personnalisé */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[name] - [title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Critère de tri: Inscription : Date mise à jour */
  $handler->display->display_options['sorts']['updated']['id'] = 'updated';
  $handler->display->display_options['sorts']['updated']['table'] = 'registration';
  $handler->display->display_options['sorts']['updated']['field'] = 'updated';
  $handler->display->display_options['sorts']['updated']['order'] = 'DESC';
  /* Critère de filtrage: Inscription : State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'waiting' => 'waiting',
  );

  /* Display: Inscriptions non statuées */
  $handler = $view->new_display('block', 'Inscriptions non statuées', 'block');
  $translatables['registrations_unchanged'] = array(
    t('Master'),
    t('Inscriptions non statuées'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Pas de nouveau changement d\'état des inscriptions depuis 7 jours.'),
    t('Utilisateur'),
    t('node from Registration'),
    t('[title]'),
    t('[name] - [title]'),
  );
  $export['registrations_unchanged'] = $view;

  return $export;
}
