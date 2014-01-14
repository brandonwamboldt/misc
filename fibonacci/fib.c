/**
 * Fibonacci Sequence
 *
 * Calculates n digits of the fibonacci sequence, where n is a command line
 * argument to the program.
 */

#include <stdio.h>
#include <stdlib.h>

long long *calculateFibonacciSequence(int n)
{
  if (n <= 0) {
    return 0;
  }

  int i = 0;
  unsigned long long *numbers = malloc(sizeof(long long) * (n + 1));

  if (!numbers) {
    return 0;
  }

  numbers[0] = 0;
  numbers[1] = 1;

  for (i = 1; i < n; i++) {
    numbers[i + 1] = numbers[i] + numbers[i - 1];
  }

  return numbers;
}

int main(int argc, char *argv[])
{
  int i, n;
  unsigned long long *sequence;

  if (argc <= 1) {
    puts("Please pass the number of iterations to run");
    return 1;
  }

  n = atoi(argv[1]);

  if (n <= 0) {
    puts("Please provide a valid number of iterations to run");
    return 1;
  }

  if (n > 93) {
    puts("This program is only capable of producing 93 fibonacci numbers");
    return 1;
  }

  sequence = calculateFibonacciSequence(n);

  if (sequence) {
    for (i = 0; i <= n; i++) {
      printf("%d: %llu\n", i, sequence[i]);
    }

    free(sequence);
  } else {
    puts("Error processing fibonacci sequence");
    return 1;
  }

  return 0;
}
