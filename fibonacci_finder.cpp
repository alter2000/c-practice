#include <stdio.h>
#include <stdlib.h>

char err_string[]="That's not a natural number. Reopen this program.";
void calls();
unsigned int func_calls = 0;
// Must declare (correct term?) namespaces before using them
namespace better {
  unsigned long int fib(unsigned int n, unsigned long int &c);
  void fib(float input);
  unsigned long int *store;
}
namespace old {
  unsigned long int fib(unsigned int n);
}

using namespace better;
int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("This program takes the n'th Fibonacci number as input and gives its value.\n");
    return 0;}
  float input = atof(argv[1]);
  fib(input);
  *store = 1;
  printf("%lu\n", fib(input, *store));
  calls();
  return 0;
}
unsigned long int better::fib(unsigned int n, unsigned long int &c=*store){
  if (n <= 2) {return 1;}
  unsigned long int result = better::fib(n-1) + better::fib(n-2);
  store = &result;
  func_calls++;
  return result;
}
void better::fib(float n) {
  if ((((int)(10 * n)) % 10) != 0)
    printf("Natural numbers aren't always fractions. Rounding down to what you typed\n");
}

unsigned long int old::fib(unsigned int n){
  func_calls++;
  if (n <=2){return 1;}
  return fib(n-1) + fib(n-2);
}

void calls(){
  printf("the fib() function has been called %u times.\n", func_calls);
}

/* I have no idea how to lower the number of function calls, besides not having them at all.
I could, though, store the (n - n/m)'th value (where "m" can be any number), but it still wouldn't
reach linear time, even if 'm' were to change with 'n'.
Calling a different function if a float were given would mean that I'd have to exctract the input
in some strange way. It should be neither an int, as the decimal part would get dropped, nor a
float, because that would never call the int function.

The iterative function I was talking about:
unsigned long int fib(unsigned int n){
  if (n <= 2) {return 1;}
  for (unsigned int count = 2; count <= n; count++){
  int c = a + b;    //adding the first 2 numbers of the sequence
      a = b;        //"rotating" the values stored to prepare
      b = c;        //for the next iteration
      }
  return b;
}

And what I managed to cobble up to use a function pointer (which slowed the inline):
unsigned long int (*val)(unsigned int);
val = fib;
unsigned long int fib1 = (*val)(n-1);
unsigned long int fib2 = (*val)(n-2);
unsigned long int result = fib1 + fib2;
return result;

The An'th value is:
An = A(n-1) + A(n-2) + 1
*/
