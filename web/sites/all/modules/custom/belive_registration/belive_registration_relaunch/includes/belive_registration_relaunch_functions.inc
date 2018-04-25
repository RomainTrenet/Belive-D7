<?php

/**
 * Custom function to get default state for a given registation type
 */
function belive_registration_relaunch_get_bidule($nid = NULL) {
	
	//
	$startDate = time();
	$min_day = date('Y-m-d 00:00:00', $startDate);
	$max_day = date('Y-m-d 00:00:00', strtotime('+1 day', $startDate));
	
	//
	$query=db_select('users','u');
	$query->join('registration', 'r', 'r.user_uid = u.uid');
	$query->join('node', 'n', 'n.nid = r.entity_id');
	$query->join('field_data_field_relaunch', 'dr', 'dr.entity_id = n.nid');
	$query->join('field_data_field_mail_content', 'mc', 'mc.entity_id = n.nid');
	$query->join('field_data_field_objet_du_mail', 'mo', 'mo.entity_id = n.nid');
	
	$query->fields('u',array('uid', 'name', 'mail'));
	$query->fields('r',array('registration_id'));
	$query->fields('n',array('nid', 'title'));
	$query->fields('mc',array('field_mail_content_value'));
	$query->fields('mo',array('field_objet_du_mail_value'));
	
	$query->condition('u.status', 1, '=');
	$query->condition('r.state', 'waiting', '=');
	$query->condition('dr.field_relaunch_value', $min_day, '>=');
	$query->condition('dr.field_relaunch_value', $max_day, '<');
	
	($nid != NULL) ? $query->condition('n.nid', $nid, '=') : NULL;
	return $query->execute()->fetchAll();
}

/*function _get_node_registrations_id_for_users($nid, $users_id) {
    $ids = array();

    $query = db_select('registration', 'r')
        ->condition('r.entity_id', $nid, '=')
        ->condition('r.user_uid', $users_id, 'IN')
        ->fields('r', array('registration_id'))
        ->execute();

    while($registration = $query->fetchAssoc()) {
        $ids[] = $registration['registration_id'];
    }
    return $ids;
}

function _get_node_registered_users($nid) {
    if ( is_numeric($nid) ) {
        $ids = array();

        $query = db_select('registration', 'e')
            ->condition('e.entity_id', $nid, '=')
            ->fields('e', array('user_uid'))
            ->execute();

        while($user = $query->fetchAssoc()) {
            $ids[] = $user['user_uid'];
        }

        return user_load_multiple($ids);
    }
}*/