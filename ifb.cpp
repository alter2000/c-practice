#include <stdio.h>
#include <stdlib.h>

unsigned int func_calls = 0;
unsigned long int *store;

unsigned long int fib(unsigned int n, unsigned long int &c=*store);
void calls(){
  printf("the fib() function has been called %u times.\n", func_calls);
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("This program takes the n'th Fibonacci number as input and gives its value.\n");
    return 0;}
  float input = atof(argv[1]);
  *store = 1;
  printf("%lu\n", fib(input));
  calls();
  return 0;
}
unsigned long int fib(unsigned int n, unsigned long int &c){
  if (n <= 2) {return 1;}
  unsigned long int result = *store;
  store = &result;
  result = fib(n-1) + fib(n-2);
  func_calls++;
  return result;
}
