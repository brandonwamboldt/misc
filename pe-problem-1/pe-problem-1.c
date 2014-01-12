/**
 * Project Euler - Problem 1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * http://projecteuler.net/problem=1
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  unsigned int i;
  unsigned int sum = 0;
  unsigned int max = 1000; // 1000 is the problem's given maximum value

  // Get the number of iterations to run
  if (argc > 1) {
    max = atoi(argv[1]);
  }

  // Calculate the sum of numbers divisible by 3 or 5 under our max
  for (i = 0; i < max; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  printf("Sum Total Is: %d\n", sum);

  return 0;
}
