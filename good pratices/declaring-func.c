#include <stdio.h>

//It is considered good practice to write it like this instead:

// Function declaration
int myFunction(int, int);

// The main method
int main() {
  int result = myFunction(5, 3); // call the function
  printf("Result is = %d\n", result);

  return 0;
}

// Function definition
int myFunction(int x, int y) {
  return x + y;
}