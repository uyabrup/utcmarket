<?php


/**
 * Добавляем и настраиваем роли 
 */
function openstore_config_roles() {  

  // На всякий случай убеждаемся, что системные роли имеют правильный RID
  db_query("UPDATE {role} SET rid = 1 WHERE name = 'anonymous user'");
  db_query("UPDATE {role} SET rid = 2 WHERE name = 'authenticated user'"); 
  
  // Добавляем наши роли
  db_query("INSERT INTO {role} (rid, name) VALUES (%d, '%s')", OPENSTORE_ROLEID_DIRECTOR, OPENSTORE_ROLE_DIRECTOR);
  db_query("INSERT INTO {role} (rid, name) VALUES (%d, '%s')", OPENSTORE_ROLEID_MANAGER, OPENSTORE_ROLE_MANAGER);
  db_query("INSERT INTO {role} (rid, name) VALUES (%d, '%s')", OPENSTORE_ROLEID_CONTENTMANAGER, OPENSTORE_ROLE_CONTENTMANAGER);
  db_query("INSERT INTO {role} (rid, name) VALUES (%d, '%s')", OPENSTORE_ROLEID_AFFILIATE, OPENSTORE_ROLE_AFFILIATE);
}  
 
 /**
 * Настройка прав
 * 
 */
function openstore_config_perms() {
  // Включаем файл с параметрами прав
  include_once 'import_perms.inc'; 
  $roles_data = array();   
  $roles = db_query("SELECT * FROM {role}");
  while ($role = db_fetch_object($roles)) {
    $roles_data[$role->name] = array(
      'rid' => $role->rid,
      'permissions' => array(),
    );  
  }
  // Импортируем права из файла import_perms.inc
  $permissions = openstore_import_permissions(); 
  // Добавляем права к ролям
  foreach ($permissions as $permission) {
    // Находим, какие роли имеет данные права
    foreach ($permission['roles'] as $role) {
      $roles_data[$role]['permissions'][] = $permission['name'];
    }
  }
  
  // Очищаем на всякий случай таблицу с правами
  db_query("DELETE FROM {permission}");
  
  // Сохраняем права
  foreach ($roles_data as $role_data) {
    $perm = new stdClass;
    $perm->rid = $role_data['rid'];
    $perm->perm = implode($role_data['permissions'], ', ');
    drupal_write_record('permission', $perm);
  }
}

/**
 * Генератор паролей для создаваемых пользователей. Safety first :)
 * 
 */
function openstore_pass(){
$raw = crypt('password');
$pass = substr(preg_replace("/[^a-zA-Z0-9s]/", "", $raw), 0, 8);
return $pass;
}

function openstore_config_users(){

//Мыла для создаваемых пользователей
$current_domain = $_SERVER['HTTP_HOST'];
if ($current_domain == 'localhost') {
$mail_domain = '@domain.com'; 
} else {
$mail_domain = '@' . $current_domain; 
}

$new_users = array (
$user1 = array(
'name' => OPENSTORE_USER_DIRECTOR,
'pass' => openstore_pass(),
'mail' => OPENSTORE_USER_DIRECTOR . $mail_domain,
'access' => 0,
'status' => 1,
),	

$user2 = array(
'name' => OPENSTORE_USER_MANAGER,
'pass' => openstore_pass(),
'mail' => OPENSTORE_USER_MANAGER . $mail_domain,
'access' => 0,
'status' => 1,
),

$user3 = array(
'name' => OPENSTORE_USER_CONTENTMANAGER,
'pass' => openstore_pass(),
'mail' => OPENSTORE_USER_CONTENTMANAGER . $mail_domain,
'access' => 0,
'status' => 1,
),

$user4 = array(
'name' => OPENSTORE_USER_AFFILIATE,
'pass' => openstore_pass(),
'mail' => OPENSTORE_USER_AFFILIATE . $mail_domain,
'access' => 0,
'status' => 1,
),

);

  foreach ($new_users as $new_user) { 
    user_save(NULL, $new_user);	// Сохраняем пользователей в БД    
   }

  // Окончательно убеждаемся, что созданные пользователи имеют правильные роли
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", OPENSTORE_USERID_DIRECTOR, OPENSTORE_ROLEID_DIRECTOR);
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", OPENSTORE_USERID_MANAGER, OPENSTORE_ROLEID_MANAGER);     
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", OPENSTORE_USERID_CONTENTMANAGER, OPENSTORE_ROLEID_CONTENTMANAGER);       
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", OPENSTORE_USERID_AFFILIATE, OPENSTORE_ROLEID_AFFILIATE);

}