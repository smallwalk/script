<?php
namespace Virus\Modules\Order;

class Order_t extends \Virus\Frame\Controller {

	public function run() {
		/*
		$this->view = array(
			'code' => 0,
			'info' => array('name' => 'chaoguo', 'age' => 27),
		);
		 */
		$goods = array(
			array('goods_id' => 131446419, 'sku_id' => 78),
			array('goods_id' => 131446419, 'sku_id' => 75),
			array('goods_id' => 222801817, 'sku_id' => 56311899),
		);
		/*
		foreach ($goods as $info) {
			$goods = GoodsFactory::createGoods($info);
			var_dump($goods->color());
			var_dump($goods->size());
			var_dump($goods->title());
		}
		 */

		$it = new MGoods($goods);
		$this->processFirst($it);
		$this->processSecond($it);
		die;
	}

	private function processFirst(MGoods $it) {
		foreach($it as $value) {
			var_dump($value->color());
			var_dump($value->skuId());
		}
	}

	private function processSecond(MGoods $it) {
		foreach($it as $value) {
			var_dump($value->color());
			var_dump($value->skuId());
		}
	}
}



class MGoods implements \Iterator {
	private $position = 0;
	private $load = FALSE;
	private $param = array();
	private $data = array();

	public function __construct($param) {
		var_dump(__METHOD__);
		$this->param = $param;
		$this->position = 0;
	}

	public function load() {
		//由另外的模块负责load，goods+shop+sku+price+inventory
		var_dump(__METHOD__);
		$i = 0;
		foreach ($this->param as $info) {
			$sku_info = \Virus\Package\BrdGoods\Brd_goods::Goods_info($info,'sku',array());
			if (!empty($sku_info['sku'])) {
				$this->data[$i] = $sku_info;
				$i++;
			}
		}
		$this->load = TRUE;
	}

	public function rewind() {
		var_dump(__METHOD__);
		if ($this->load === FALSE) {
			$this->load();
		}
		$this->position = 0;
	}

	public function current() {
		var_dump(__METHOD__);
		return GoodsFactory::createGoods($this->data[$this->position]);
	}

	public function key() {
		var_dump(__METHOD__);
		return $this->position;
	}

	public function next() {
		var_dump(__METHOD__);
		++$this->position;
	}

	public function valid() {
		var_dump(__METHOD__);
		return isset($this->data[$this->position]);
	}
}

class GoodsFactory {

	public static function createGoods($sku_info) {

		$skuId = $sku_info['sku']['sku_id'];
		if ($skuId < 100) {
			return new CGoods($skuId, $sku_info);
		}
		else {
			return new MainGoods($skuId, $sku_info);
		}
	}

}


abstract class Goods {

	protected $skuId = 0;
	protected $color = "";
	protected $size = "";
	protected $title = "";

	abstract protected function color();
	abstract protected function size();
	abstract protected function title();
	abstract protected function skuId();

}

class CGoods extends Goods {
	public function __construct($skuId, $skuInfo) {
		$this->skuId = $skuId;
		$this->color = !empty($skuInfo['color']) ? $skuInfo['color']['meta_name'] : '';
		$this->size = !empty($skuInfo['size']) ? $skuInfo['size']['meta_name'] : '';
		$this->title = $skuInfo['goods_title'];
	}

	public function color() {
		return $this->color;
	}
	public function size() {
		return $this->size;
	}
	public function title() {
		return $this->title;
	}
	public function skuId() {
		return $this->skuId;
	}
}

class MainGoods extends Goods {
	public function __construct($skuId, $skuInfo) {
		$this->skuId = $skuId;
		$this->color = !empty($skuInfo['color']) ? $skuInfo['color']['meta_name'] : '';
		$this->size = !empty($skuInfo['size']) ? $skuInfo['size']['meta_name'] : '';
		$this->title = $skuInfo['goods_title'];
	}
	public function color() {
		return "color:" . $this->color;
	}
	public function size() {
		return $this->size;
	}
	public function title() {
		return $this->title;
	}
	public function skuId() {
		return $this->skuId;
	}
}
