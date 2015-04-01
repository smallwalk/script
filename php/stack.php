<?php
$stack = new SplStack();
$stack->push('a');
$stack->push('b');
$stack->push('c');

$stack->rewind();

while ($stack->valid()) {
	echo $stack->current() . "\n";
	$stack->next();
}
