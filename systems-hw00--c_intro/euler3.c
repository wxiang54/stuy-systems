#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//returns 1 if input is prime, 0 otherwise
char isPrime( long n ) {
  //check every number from 2 to sqrt(n)
  int root = sqrt(n);
  int i;
  for (i = 2; i <= root; i++) {
    if ( !(n%i) ) return 0;
  }
  return 1;
}


int main() {
  //check for prime factors in descending order
  //first prime factor = largest prime factor
  long input = 600851475143;
  long factor = input;
  while (input > 0) {
    if (isPrime(input) && !(input%factor)) {
      printf("%ld\n", input);
      break;
    }
    input--;
  }
  
  return 0;
}
