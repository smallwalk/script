<?php

class Application {

	public $service = array();

	public function __construct() {
		$this->registerBaseService();
	}

	protected function registerBaseService() {
		$this->register(new EventServiceProvider($this)); 	
	}

	protected function register($provider) {
		$provider->register();
	}

	public function share(Closure $closure) {
		return function($container) use ($closure) {
			static $object;

			if (is_null($object)) {
				$object = $closure($container);
			}

			return $object;
		};
	}
}

class EventServiceProvider {
	
	protected $app;

	public function __construct($app) {
		$this->app = $app;
	}

	public function register() {
		$this->app->service['event'] = $this->app->share(function($app) {
			return new Dispatcher($app);	
		});
	}
}

class Dispatcher {
	public function __construct($container) {
		var_dump("SS");
		$this->container = $container;
	}
}

$app = new Application;

