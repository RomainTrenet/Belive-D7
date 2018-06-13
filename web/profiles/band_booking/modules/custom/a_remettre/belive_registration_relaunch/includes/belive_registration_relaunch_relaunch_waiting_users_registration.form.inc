<?php

module_load_include('inc', 'band_booking_registration', 'includes/band_booking_registration_functions');

function belive_registration_relaunch_node_relaunch_waiting_users_registration_view ($node) {
	global $base_url;
	global $base_path;
	$destination = current_path();
	$content = '<p>' . l(t('Relaunch waiting registrations for this event'), $base_url . $base_path . 'relaunch_batch_manually/' . $node->nid, $options = array('query' => array('destination' => $destination))) . '</p>';
	$content .= '<p>' . t('This does not figure the days scheduled for the relaunch.') . '</p>';
	return ($content);
}

/**
 * Setup batch and operations to perform
 * We create a list of batch operations
 */
function belive_registration_relaunch_setup_batch($nid = 'NULL', $manual = FALSE, $today = TRUE)
{
	$operations = array();
	$operations[] = array(
		'belive_registration_relaunch_batch_process', array($nid, $manual, $today)
	);
	
	// Batch declaration
	$batch = array(
		'operations' => $operations,
		'title' => t('Relaunch batch'),
		'init_message' => t('Initialization of relaunches'),
		'error_message' => t('An error occurred'),
		'finished' => 'belive_registration_relaunch_finished_method',
	);
	
	// Batch initialization
	batch_set($batch);
	$batch =& batch_get();
	
	// Execution du batch and redirection to menu item
	if ($manual == FALSE) {
		//Progressive = false : no progress bar, and dpm
		$batch['progressive'] = FALSE;//For cron for example
	}
	
	batch_process();
	//return('<p>Uncomment that line to have a page view with dpm.</p>');
}

function belive_registration_relaunch_batch_process($nid, $manual, $today, &$context) {
	/*dpm($nid);
	dpm($manual ? 'manuel' : 'auto');
	dpm($today ? 'today' : 'everyday');*/
	
	//INIT of the batch.
	if (!isset($context['sandbox']['progress'])) {
		$context['sandbox']['progress'] = 0;
		
		//Get number of results to treat
		$query=db_select('users','u');
		$query->join('registration', 'r', 'r.user_uid = u.uid');
		$query->join('node', 'n', 'n.nid = r.entity_id');
		$query->join('field_data_field_mail_content', 'mc', 'mc.entity_id = n.nid');
		$query->join('field_data_field_objet_du_mail', 'mo', 'mo.entity_id = n.nid');
			
		$query->fields('u',array('uid', 'name', 'mail'))
			->condition('u.status', 1, '=')
			->condition('n.status', 1, '=')
			->condition('r.state', 'waiting', '=');
		
		//If today, filter by daily relaunches
		if ($today) {
			$query->join('field_data_field_relaunch', 'dr', 'dr.entity_id = n.nid');
			$startDate = time();
			$min_day = date('Y-m-d 00:00:00', $startDate);
			$max_day = date('Y-m-d 00:00:00', strtotime('+1 day', $startDate));
			$query->condition('dr.field_relaunch_value', $min_day, '>=')
				->condition('dr.field_relaunch_value', $max_day, '<');
		}
		
		//if nid specified, filter by node id, to
		($nid != 'NULL') ? $query->condition('n.nid', $nid, '=') : NULL;
		
		$context['sandbox']['max'] = $query->execute()->rowCount();
		
	}//EO Init batch
	
	//If there are results, batch the operations
	if ($context['sandbox']['max'] > 0) {
		
		// Limit is set in the begining of the .module file
		$limit = BATCH_LIMIT;
		
		$query=db_select('users','u');
		$query->join('registration', 'r', 'r.user_uid = u.uid');
		$query->join('node', 'n', 'n.nid = r.entity_id');
		$query->join('field_data_field_mail_content', 'mc', 'mc.entity_id = n.nid');
		$query->join('field_data_field_objet_du_mail', 'mo', 'mo.entity_id = n.nid');
		
		$query->fields('u',array('uid', 'name', 'mail'))
			->fields('r',array('registration_id'))
			->fields('n',array('nid', 'title'))
			->fields('mc',array('field_mail_content_value'))
			->fields('mo',array('field_objet_du_mail_value'))
			
			->condition('u.status', 1, '=')
			->condition('n.status', 1, '=')
			->condition('r.state', 'waiting', '=');
		
		//If today, filter by daily relaunches
		if ($today) {
			$query->join('field_data_field_relaunch', 'dr', 'dr.entity_id = n.nid');
			$startDate = time();
			$min_day = date('Y-m-d 00:00:00', $startDate);
			$max_day = date('Y-m-d 00:00:00', strtotime('+1 day', $startDate));
			$query->condition('dr.field_relaunch_value', $min_day, '>=')
				->condition('dr.field_relaunch_value', $max_day, '<');
		}
		//if nid specified, filter by node id, to
		($nid != 'NULL') ? $query->condition('n.nid', $nid, '=') : NULL;
		
		$query->range($context['sandbox']['progress'], $limit);
		$result = $query->execute();
		
		while ($relaunch = $result->fetchObject()) {
			//Treatment of the batch
			
			//Send mail
			$node = node_load($relaunch->nid);
			$user = user_load($relaunch->uid);
			$subject = token_replace($relaunch->field_objet_du_mail_value, array('node' => $node));
			$message = token_replace($relaunch->field_mail_content_value, array('node' => $node, 'user' => $user));
			$to = $relaunch->mail;
			$from = variable_get('site_mail', '');
			
			$params = array(
				'body' => $message,
				'subject' => $subject,
			);
			
			//TODO if manual : drupal set message; if auto = send mail
			/*$test = 'romain.trenet@gmail.com';
			$to = 'romain.trenet@gmail.com';*/
			
			if (drupal_mail('belive_registration_relaunch', 'send_relaunch_mail', $to, language_default(), $params, $from, TRUE)) {
				global $base_url;
				global $base_path;
				
				//if manual, print message
				if($manual) {
					//
					drupal_set_message('Relance envoyée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()));
				//If auto (cron), send mail to site
				} else {
					/*//Send mail to website email and set message to website
					//$body = 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation <a href="' .$base_url . $base_path . 'node/'.  $relaunch->nid . '">' . $relaunch->title . '</a>.';
					$body = '<html><body>Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()) . '.</body></html>';
					
					$params_mail_website = array(
						'body' => $body,
						'subject' => 'Relance effectuée à '.$relaunch->name .' pour la prestation ' . $relaunch->title,
					);
					drupal_mail('belive_registration_relaunch', 'send_relaunch_mail', $from, language_default(), $params_mail_website, $from, TRUE);*/
					watchdog('Belive relaunch', 'Bonjour,<br>Relance effectuée à '.$relaunch->name .' pour la prestation ' .l($relaunch->title, $base_url . $base_path . 'node/'.  $relaunch->nid, $options = array()));
				}
			}
			else {
				drupal_set_message("Une erreur s'est produite lors de l'envoi de votre email");
			}
			
			//Increment progress and record current subscription id.
			$context['sandbox']['progress']++;
		}
		
		//If batch is not at the end, record progress (use for percentage of progression)
		if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
			$context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
		}
	}
}

/**
 * @param $success
 * @param $results
 * @param $operations
 */
function belive_registration_relaunch_finished_method($success, $results, $operations) {
	drupal_set_message(t('Relaunch proceeding succesfully applied'));
}