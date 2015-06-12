<?php
$fruits = array(
	'apple' => 'yummy',
	'orange' => 'yaa',
);

$obj = new ArrayObject($fruits);
foreach ($obj as $key => $value) {
	echo "Key:$key  Value:$value \n";
}
