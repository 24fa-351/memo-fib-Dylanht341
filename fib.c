#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long long memo_array[100000000] = {0};
int using_iterative = 1;

unsigned long long recursive_fibonacci(int n);
unsigned long long iterative_fibonacci(int n);

unsigned long long fib_wrapper(int n) {
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   if (memo_array[n] != 0) {
      return memo_array[n];
   }
   // Checks the method of calculation and calls the respective function and returns the result
   if (using_iterative) {
      memo_array[n] = iterative_fibonacci(n);
   } else {
      memo_array[n] = recursive_fibonacci(n);
   }
   return memo_array[n];
}

unsigned long long recursive_fibonacci(int n) {     // Takes in the nth number to calculate to
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return fib_wrapper(n - 1) + fib_wrapper(n - 2);
}

unsigned long long iterative_fibonacci(int n) {     // Takes in the nth number to calculate to
   unsigned long long first = 0;
   unsigned long long second = 1;
   unsigned long long sum;
   int ix;                 // Iterator variable that keeps track of the nth iteration of the Fibonacci sequence
   
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   for (ix = 3; ix <= n; ix++) {
      sum = first + second;         // Stores the current Fibonacci number
      first = second;               // Sets variable to the next Fibonacci number
      second = sum;                 // Sets variable to the next Fibonacci number
   }
   return second;
}



int main(int argc, char *argv[]) {   // Reads command line arguments and stores them in argv
   
   int command_line_input = atoi(argv[1]);   // Stores the integer to be added to the one in the file
   const char *method = argv[2];             // Stores the method of calculating the Fibonacci Sequence
   unsigned long long answer;                // Creates an integer to store the answer

   if (strcmp(method, "i") == 0) {
      using_iterative = 1;
   } else if (strcmp(method, "r") == 0) {
      using_iterative = 0;
   } else {
      printf("Invalid input.");
   }

   answer = fib_wrapper(command_line_input);
   printf("%llu", answer);
   return 0;
}
