#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%d\n", helper(0,1,0)); //start of fib sequence w/ total of 0
  return 0;
}

int helper( int n1, int n2, int total ) { //iterative approach to fib
  while (n2 <= 4000000) {
    if ( !(n2 % 2) ) total += n2; //if n2 is even, add it to total
    int tmp = n2;
    n2 += n1;
    n1 = tmp;
  }
  return total;
}
