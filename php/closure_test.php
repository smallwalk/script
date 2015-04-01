<?php
class A {
	private $msg;
	public function __construct($msg) {
		$this->msg = $msg;
	}
	public function echoMsg() {
		echo "I'm A\n";
	}

}


class B {
	private $app;
	public function __construct() {
		$this->share(function($msg) {return new A($msg);});
	}

	function share(Closure $closure) {
		var_dump($closure);die;
		$object = $closure('haha');
		$object->echoMsg();	
	}
}

$b = new B();
