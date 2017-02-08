#include "stdlib.h"
#include "stdio.h"

unsigned long int fib(int n){
  if (n <= 2) return 1;
  return fib(n-1)+fib(n-2);
}

int main(int argc, char const *argv[]){
  unsigned int n = atol(argv[1]);
  printf("%lu\n", fib(n));
}
