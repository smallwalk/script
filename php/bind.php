<?php
class A {
    public static $sfoo = 1;
    public $ifoo = 2;
}
$cl1 = static function() {
    return A::$sfoo;
};
$cl2 = function() {
    return $this->ifoo;
};

class B{
    public static $sfoo = 3;
    public $ifoo = 4;
}

$bcl1 = Closure::bind($cl1, null, 'A');
$bcl2 = Closure::bind($cl2, new B(), 'B');
echo $bcl1(), "\n";
echo $bcl2(), "\n";
