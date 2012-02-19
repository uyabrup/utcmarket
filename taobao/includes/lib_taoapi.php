<?php
if (!defined('IN_ECS'))
{
    die('Hacking attempt');
}

include_once('taoapi.php'); 
$Taoapi_Config = Taoapi_Config::Init();
$Taoapi_Config->setCharset('UTF-8');
$Taoapi_Config->setAppKey("12342766"); // 12342026
$Taoapi_Config->setAppSecret("6031aa08a4c8c14c917cfafb19982498"); // f784d577c3088e8642e9010701ca29bc

$Taoapi = new Taoapi;

/*获取用户数据*/
function taobao_user_get($nick){
	
    $GLOBALS['Taoapi']->method = 'taobao.user.get';
	$GLOBALS['Taoapi']->fields = 'nick,user_id,seller_credit.level,seller_credit.total_num,seller_credit.good_num,location.address,created,last_visit';
	$GLOBALS['Taoapi']->nick = $nick;
	$TaoapiUser = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiUser['user'];
}

/*获取店铺数据*/
function taobao_shop_get($nick){
	$GLOBALS['Taoapi']->method = 'taobao.shop.get';
	$GLOBALS['Taoapi']->fields = 'sid,cid,title,desc,bulletin,pic_path,created,modified';
	$GLOBALS['Taoapi']->nick = $nick;
	$TaoapiShop = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiShop['shop'];
}

/*店铺推广链接*/
function taobao_taobaoke_shops_convert($sid){
	$GLOBALS['Taoapi']->method = 'taobao.taobaoke.shops.convert';
	$GLOBALS['Taoapi']->fields = 'user_id,shop_title,click_url,commission_rate';
	$GLOBALS['Taoapi']->sids = $sid;
	$GLOBALS['Taoapi']->nick = $GLOBALS['_CFG']['usernick'];
	$TaoapiShops = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();
	
	return $TaoapiShops['taobaoke_shops']['taobaoke_shop'];
}

/*获取淘宝客商品*/
function taobao_items_get($nicks, $page_size = 40, $page_no = 1){
	$GLOBALS['Taoapi']->method = 'taobao.items.get';
	$GLOBALS['Taoapi']->fields = 'iid,num_iid,title,type,cid,post_fee,desc,pic_url,price,modified,approve_status,auction_point,item_imgs,volume';
	$GLOBALS['Taoapi']->nicks = $nicks;
	$GLOBALS['Taoapi']->page_size = $page_size;
	$GLOBALS['Taoapi']->page_no = $page_no;
	return $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();
}

function taobao_taobaoke_items_detail_get($num_iid){
	
	$GLOBALS['Taoapi']->method = 'taobao.taobaoke.items.detail.get';
	$GLOBALS['Taoapi']->fields = 'iid,detail_url,title,nick,cid,pic_url,auction_point,price,volume,type,desc,num_iid,desc,click_url,cid,detail_url,num,list_time,delist_time,item_imgs';
	$GLOBALS['Taoapi']->num_iids = $num_iid;
	$GLOBALS['Taoapi']->nick = $GLOBALS['_CFG']['usernick'];
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();
	return $TaoapiItems['taobaoke_item_details']['taobaoke_item_detail'];
	
}

function taobao_taobaoke_items_detail_get_num($num_iid){
	
	$GLOBALS['Taoapi']->method = 'taobao.taobaoke.items.detail.get';
	$GLOBALS['Taoapi']->fields = 'iid,detail_url,title,nick,cid,pic_url,auction_point,price,volume,type,desc,num_iid,desc,click_url,cid,detail_url,num,list_time,delist_time,item_imgs';
	$GLOBALS['Taoapi']->num_iids = $num_iid;
	$GLOBALS['Taoapi']->nick = $GLOBALS['_CFG']['usernick'];
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();
	return $TaoapiItems;
	
}

function taobao_taobaoke_items_convert($iid){
	$GLOBALS['Taoapi']->method = 'taobao.taobaoke.items.convert';
	$GLOBALS['Taoapi']->fields = 'iid,commission,commission_rate,commission_num,commission_volume,item_location';
	$GLOBALS['Taoapi']->iids = $iid;
	$GLOBALS['Taoapi']->nick = $GLOBALS['_CFG']['usernick'];
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();
	return $TaoapiItems['taobaoke_items']['taobaoke_item'];
}

/*获取后台供卖家发布商品的标准商品类目*/
function taobao_itemcats_get($pid = 0){
	$GLOBALS['Taoapi']->method = 'taobao.itemcats.get';
	$GLOBALS['Taoapi']->fields = 'cid,parent_cid,name,status';
	$GLOBALS['Taoapi']->parent_cid = $pid;
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiItems['item_cats']['item_cat'];
}
/*获取标准商品属性，包括品牌，风格，价格区域等*/
function taobao_itemprops_get($cat_id = 0){
	$GLOBALS['Taoapi']->method = 'taobao.itemprops.get';
	$GLOBALS['Taoapi']->cid = $cat_id;
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiItems['item_props']['item_prop'];
}
/*获取标准类目属性值*/
function taobao_itempropvalues_get($cat_id = 0){
	$GLOBALS['Taoapi']->method = 'taobao.itempropvalues.get';
	$GLOBALS['Taoapi']->fields = 'cid,pid,prop_name,vid,name,name_alias,status,sort_order';
	$GLOBALS['Taoapi']->cid = $cat_id;
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiItems['prop_values']['item_prop'];
}
/*获取前台展示的店铺类目*/
function taobao_shopcats_list_get(){
	$GLOBALS['Taoapi']->method = 'taobao.shopcats.list.get';
	$GLOBALS['Taoapi']->fields = 'cid,parent_cid,name';
	$TaoapiItems = $GLOBALS['Taoapi']->Send('get','xml')->getArrayData();

	return $TaoapiItems;
}
