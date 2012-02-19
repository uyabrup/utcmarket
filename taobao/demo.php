<?PHP
header ('Content-type: text/html; charset=utf-8');
define('IN_ECS', true);

include_once(dirname(__FILE__).'/includes/lib_taoapi.php');
$id = $_GET["productid"];
$items = taobao_taobaoke_items_detail_get_num("\'" + $id + "\'");

echo json_encode($items);

