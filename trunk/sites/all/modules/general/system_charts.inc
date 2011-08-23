<?php

/*-----------------------------------------------------------------
 * Hook Implementations
 *------------------------------------------------------------------*/


/**
 * Implementation of hook_chart_color_schemes();
 */
function sys_charts_chart_color_schemes(&$colors) {
  $colors['watchdog_severity'] = array(
      'Error'   => 'a00000',
      'Warning' => 'e06000',
      'Notice'  => 'f0c040',
    );
}

/* -----------------------------------------------------------------

  General Functionality

------------------------------------------------------------------ */



/**
 * Display charts and content in context to the current page.
 *
 */
function sys_charts_display($page = 'nodes') {

  $output = '';

  switch($page){
    case 'users':
      $output .= sys_charts_build('users_per_role');
      $output .= sys_charts_build('user_status');
      break;

    case 'nodes':
      $output .= sys_charts_build('node_counts');
      $output .= sys_charts_build('node_counts_published');
      $output .= sys_charts_build('node_counts_unpublished');
      $output .= sys_charts_build('node_activity');
      break;
	  
    case 'watchdog':
      $output .= sys_charts_build('watchdog_counts');
      $output .= sys_charts_build('watchdog_severity');
      break;	  

    case 'nodes_counts_published':
      $output = sys_charts_build('node_counts_published');
      break;

    case 'nodes_counts_unpublished':
      $output = sys_charts_build('node_counts_unpublished');
      break;

    case 'nodes_activity':
      $output = sys_charts_build('node_activity');
      break;	  
	  
    case 'watchdog_count':
      $output = sys_charts_build('watchdog_counts');
      break;
	  
    case 'watchdog_message':
      $output = sys_charts_build('watchdog_severity');
      break;

    case 'user_role':
      $output = sys_charts_build('users_per_role');
      break;

    case 'user_status':
      $output = sys_charts_build('user_status');
      break;	  
	  
	  
  }

  return $output;
}

/**
 * Gather data and build a chart API structure.
 *
 */
function sys_charts_build($type) {

$user_role_height = variable_get('openstore_charts_user_role_height', 120); 
$user_role_width = variable_get('openstore_charts_user_role_width', 230);

$user_status_height = variable_get('openstore_charts_user_status_height', 120);
$user_status_width = variable_get('openstore_charts_user_status_width', 230);

$nodes_height = variable_get('openstore_charts_nodes_height', 120);
$nodes_width = variable_get('openstore_charts_nodes_width', 230);

$watchdog_counts_height = variable_get('openstore_charts_watchdog_counts_height', 180);
$watchdog_counts_width = variable_get('openstore_charts_watchdog_counts_width', 340);

$watchdog_severity_height = variable_get('openstore_charts_watchdog_severity_height', 180);
$watchdog_severity_width = variable_get('openstore_charts_watchdog_severity_width', 340);

$node_activity_height = variable_get('openstore_charts_node_activity_height', 180);
$node_activity_width = variable_get('openstore_charts_node_activity_width', 260);

$users_role  = variable_get('openstore_charts_users_role', TRUE);
$users_status = variable_get('openstore_charts_users_status', TRUE);
$nodes_total = variable_get('openstore_charts_nodes_total', TRUE);
$nodes_published = variable_get('openstore_charts_nodes_published', TRUE);
$nodes_unpublished = variable_get('openstore_charts_nodes_unpublished', TRUE);
$nodes_activity = variable_get('openstore_charts_nodes_activity', TRUE);
$watchdog_messages = variable_get('openstore_charts_watchdog_messages', TRUE);
$watchdog_severity = variable_get('openstore_charts_watchdog_severity', TRUE);


  $chart = array();
  $now   = (isset($_GET['year']) && isset($_GET['month'])) ? mktime(0, 0, 0, $_GET['month'], 30, $_GET['year']) : time();

  if($type == 'node_counts' || $type == 'node_counts_published' || $type == 'node_counts_unpublished' || $type == 'node_counts_today') {

        if ($type == 'node_counts' && $nodes_total){
          $title = t('Total pages');
          }

        if ($type == 'node_counts_published' && $nodes_published){
          $title = t('Published pages');
          $sql_where = " WHERE status = '1' ";
          }

        if ($type == 'node_counts_unpublished' && $nodes_unpublished){
          $title = t('Unpublished pages');
          $sql_where = " WHERE status = '0' ";
          }
      if ($sql_where) {
      $results = db_query("
          SELECT COUNT(*) as count, type
          FROM {node}
          " . $sql_where . "
          GROUP BY type
          ORDER BY type
        ", $sql_args);

      while ($result = db_fetch_array($results)){
        $chart['#data'][]        = $result['count'];
        $chart['#labels'][]      = $result['type'].': '.$result['count'];
        $chart['#data_colors'][] = chart_unique_color($result['type']);
      }

      $chart['#chart_id'] = $type;
      $chart['#title']    = chart_title($title);
      $chart['#type']     = variable_get('openstore_charts_nodes_style', CHART_TYPE_PIE);
      $chart['#size']     = chart_size($nodes_width, $nodes_height);
    }
  }

  if($type == 'node_activity' && $nodes_activity) {
      $results = db_query("
          SELECT type, created
          FROM {node}
          WHERE created  < %d AND created > %d
          ORDER BY created
        ", $now, mktime(0, 0, 0, date('m', $now), 1, date('Y', $now)));

      $max    = array();
      $counts = array();
      $types  = array();

      while ($result = db_fetch_array($results)){
        $day = ltrim(date('d', $result['created']), '0');
        $types[$result['type']] = $result['type'];
        $counts[$day][$result['type']]++;
        $max[$result['type']]++;
      }

      // Generate data and labels
      if (count($counts) && count($types)){
        for($i = 0; $i <= date('d', $now); $i++){
          $chart['#labels'][] = $i;

          foreach($types AS $type){
            if ($counts[$i][$type]){
              $chart['#data'][$type][] = $counts[$i][$type];
            }
            else {
              $chart['#data'][$type][] = '0';
            }
          }
        }
      }

      // Data colors, legends, line styles, and labels
      if (count($types)){
        foreach($types AS $type){
          $chart['#data_colors'][] = chart_unique_color($type);
          $chart['#legends'][]     = $type;
          $chart['#line_styles'][] = chart_line_style(2);
        }
      }

      $max = count($max) ? max($max) : 0;

      $chart['#chart_id']   = 'node_activity';
      $chart['#title']      = chart_title(t('Node Activity for !date', array('!date' => date('F Y', $now))));
      $chart['#type']       = CHART_TYPE_LINE;
      $chart['#size']       = chart_size($node_activity_width, $node_activity_height);
      $chart['#grid_lines'] = chart_grid_lines(25, 9.5, 1, 3);
      $chart['#mixed_axis_labels'][CHART_AXIS_Y_LEFT][0][] = chart_mixed_axis_range_label(0, $max);
      $chart['#adjust_resolution'] = TRUE;
  }
    
	if (module_exists('dblog')) {
    if ($type == 'watchdog_counts' && $watchdog_messages){
      $results = db_query("
          SELECT COUNT(*) as count, type
          FROM {watchdog}
          GROUP BY type
          ORDER BY type
        ");

      while ($result = db_fetch_array($results)){
        $chart['#data'][]        = $result['count'];
        $chart['#labels'][]      = $result['type'] . ': ' . $result['count'];
        $chart['#data_colors'][] = chart_unique_color($result['type']);
      }

      $chart['#chart_id'] = 'watchdog_counts';
      $chart['#title']    = chart_title(t('Watchdog Messages'));
      $chart['#type']     = variable_get('openstore_charts_watchdog_counts_style', CHART_TYPE_PIE);
      $chart['#size']     = chart_size($watchdog_counts_width, $watchdog_counts_height);
   }

  if ($type == 'watchdog_severity' && $watchdog_severity){
      $results = db_query("
          SELECT COUNT(*) as count, severity
          FROM {watchdog}
          GROUP BY severity
          ORDER BY severity
        ");

      while ($result = db_fetch_array($results)){
        $severity_label          = _sys_charts_watchdog_severity_label($result['severity']);
        $chart['#data'][]        = $result['count'];
        $chart['#labels'][]      = $severity_label . ': ' . $result['count'];
        $chart['#data_colors'][] = chart_unique_color($severity_label, 'watchdog_severity');
      }

      $chart['#chart_id'] = 'watchdog_severity';
      $chart['#title']    = chart_title(t('Message Severity'));
      $chart['#type']     = variable_get('openstore_charts_watchdog_severity_style', CHART_TYPE_PIE);
      $chart['#size']     = chart_size($watchdog_severity_width, $watchdog_severity_height);
   }
 }

    if ($type == 'users_per_role' && $users_role){
      $results = db_query("
          SELECT COUNT(*) as count, r.*
          FROM {users_roles} ur
          LEFT JOIN {users} u ON ur.uid = u.uid
          LEFT JOIN {role} r ON r.rid = ur.rid
          GROUP BY r.rid
          ORDER BY r.name
        ");

      while ($result = db_fetch_array($results)){
        $chart['#data'][]        = $result['count'];
        $chart['#labels'][]      = $result['name'] . ': ' . $result['count'];
        $chart['#data_colors'][] = chart_unique_color('role_' . $result['name']);
      }

      $chart['#chart_id'] = 'users_per_role';
      $chart['#title']    = chart_title(t('Users Per Role'));
      $chart['#type']     = variable_get('openstore_charts_user_role_style', CHART_TYPE_PIE);
      $chart['#size']     = chart_size($user_role_width, $user_role_height);
      

   }

    if ($type == 'user_status' && $users_status){
      $results = db_query("
          SELECT COUNT(*) as count, status
          FROM {users}
          WHERE uid != 0
          GROUP BY status
          ORDER BY status
        ");

      while ($result = db_fetch_array($results)){
        $chart['#data'][]        = $result['count'];
        $chart['#labels'][]      = _sys_charts_user_status_label($result['status']) . ': ' . $result['count'];
        $chart['#data_colors'][] = chart_unique_color('status_' . $result['status']);
      }

      $chart['#chart_id'] = 'user_status';
      $chart['#title']    = chart_title(t('User Status'));
      $chart['#type']     = variable_get('openstore_charts_user_status_style', CHART_TYPE_PIE);
      $chart['#size']     = chart_size($user_status_width, $user_status_height);
     }
     
  return chart_render($chart);
}

/**
 * Get available report page information.
 *
 * @return array
 *   report information.
 */
function sys_charts_get_page_info() {
  return array(
      'nodes' => array(
          '#title'       => t('Nodes'),
          '#type'        => 'nodes',
          '#description' => t('Various node data reports.'),
        ),
      'users' => array(
          '#title'       => t('Users'),
          '#type'        => 'users',
          '#description' => t('User access and information reporting.'),
        ),
      'watchdog' => array(
          '#title'       => t('Watchdog'),
          '#type'        => 'watchdog',
          '#description' => t('Log charts.'),
        ),
    );
}

/*-----------------------------------------------------------------
 * Helpers
 *------------------------------------------------------------------*/

/**
 * Return the watchdog severity label
 */
function _sys_charts_watchdog_severity_label($severity) {
  switch($severity){
    case WATCHDOG_NOTICE:
      return t('Notice');
      break;

    case WATCHDOG_WARNING:
      return t('Warning');
      break;

    case WATCHDOG_ERROR:
      return t('Error');
      break;
  }
}

/**
 * Return user status label
 */
function _sys_charts_user_status_label($status) {
  return $status ? t('Active') : t('Blocked') ;
}