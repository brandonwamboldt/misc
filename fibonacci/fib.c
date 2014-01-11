#include <stdio.h>
#include <stdlib.h>

int *calculateFibonacciSequence(int n, int start)
{
  int i;

  // Allocate memory for our fibonacci sequence from the heap
  int *numbers = malloc(sizeof(int) * n);

  // Need to calculate at least one number
  if (n <= 0) {
    return 0;
  }

  // Can't start with a number under zero
  if (start != 0 && start != 1) {
    return 0;
  }

  // Get the seed values
  if (start == 0) {
      numbers[0] = 0;
      numbers[1] = 1;
  } else {
      numbers[0] = 1;
      numbers[1] = 1;
  }

  // Calculate the sequence
  for (i = 1; i < n; i++) {
    numbers[i + 1] = numbers[i] + numbers[i - 1];
  }

  return numbers;
}

int main(int argc, char *argv[])
{
  int i, n;
  int start = 0;
  int *sequence;

  // Check to see how many arguments we got
  if (argc <= 1) {
    puts("Please pass the number of iterations to run.");
    return 1;
  }

  // Get the number of iterations to run
  n = atoi(argv[1]);

  // Did they specify a start value
  if (argc > 2) {
    start = atoi(argv[2]);
  }

  // Calculate the sequence
  sequence = calculateFibonacciSequence(n, start);

  // Output the sequence
  if (sequence) {
    printf("%d", sequence[0]);

    for (i = 1; i <= n; i++) {
      printf(",%d", sequence[i]);
    }

    // Newline
    puts("");
  } else {
    puts("Error processing fibonacci sequence");
  }

  // Free memory
  free(sequence);

  return 0;
}
