#!/usr/bin/env php
<?php

/**
 * Calculate the fibonacci sequence to $n digits, starting at $start. Mostly
 * putting this in a function so that HipHopVM can optimize it efficiently (it
 * won't optimize global code).
 *
 * @param  integer $n
 * @param  integer $start
 * @return array
 */
function calculateFibonacciSequence($n, $start = 0)
{
    // Need to calculate at least one number
    if ($n <= 0) {
      throw new InvalidArgumentException('Expected $n to be greater than zero, got ' . $n);
    }

    // Can't start with a number under zero
    if ($start !== 0 && $start !== 1) {
      throw new InvalidArgumentException('Expected $start to be 0 or 1, got ' . $start);
    }

    // Get the seed values
    if ($start === 0) {
        $numbers = [0, 1];
    } else {
        $numbers = [1, 1];
    }

    // Calculate the sequence
    for ($i = 1; $i < $n; $i++) {
        $numbers[] = $numbers[$i] + $numbers[$i - 1];
    }

    return $numbers;
}

// Check to see how many arguments we got
if ($argc <= 1) {
    echo "Please pass the number of iterations to run.\n";
    exit(1);
}

// Get the number of arguments to run
$n = (int) $argv[1];

// Did they specify a start value
if (isset($argv[2])) {
    $start = (int) $argv[2];
} else {
    $start = 0;
}

try {
    // Calculate the sequence
    $sequence = calculateFibonacciSequence($n, $start);

    // Concatenate the array of numbers with ',' as a separator
    echo implode(',', $sequence) . "\n";
} catch (Exception $e) {
    echo $e->getMessage() . "\n";
    exit(1);
}
