#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter an integer and find the sum of all multiples of 3 or 5 below it.\n");
  int input;
  scanf("%d", &input);
  printf("%d\n", helper(--input));
  return 0;
}


int helper( int n ) { //recursive approach
  if (n) {
    if ( !(n%3) || !(n%5) ) { //if n is a factor of 3 or 5
      return n + helper(n-1); 
    }
    return helper(n-1);
  }
  else {
    return 0; //done recursing
  }
  
}
