/**
 * Fibonacci Sequence
 *
 * Calculates n digits of the fibonacci sequence, where n is a command line
 * argument to the program.
 */

#include <stdio.h>
#include <stdlib.h>

int *calculateFibonacciSequence(int n)
{
  if (n <= 0) {
    return 0;
  }

  int i = 0;
  int *numbers = malloc(sizeof(int) * n);
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
  int *sequence;

  if (argc <= 1) {
    puts("Please pass the number of iterations to run.");
    return 1;
  }

  // Get the number of iterations to run
  n = atoi(argv[1]);

  sequence = calculateFibonacciSequence(n);

  if (sequence) {
    printf("%d", sequence[0]);

    for (i = 1; i <= n; i++) {
      printf(",%d", sequence[i]);
    }

    putchar('\n');
  } else {
    puts("Error processing fibonacci sequence");
    return 1;
  }

  free(sequence);

  return 0;
}
