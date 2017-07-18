#include <stdio.h>
#include <string.h>

/******************************************************
// CancerCode (c) //
// Return pointers kinda screwed up cuz recursion
// But they get the job done so your call :)
*******************************************************
//STRLEN
int n(char*c){return*c?1+n(++c):0;}

//STRCPY
char*p(char*d,char*s){*d=*s;return*s?p(d+1,s+1):d;}
//STRNCPY
char*y(char*d,char*s,int n){*d=*s;return--n&&*s?y(++d,++s,n):d;}

//STRCMP
int m(char*a,char*b){return!*a||!*b||*a-*b?*a-*b:m(++a,++b);}

//STRCHR
char*h(char*s,char c){return*s-c?*s?h(++s,c):0:s;}

//STRCAT
char*t(char*d,char*s){return p(h(d,0),s);}
//STRNCAT
char*a(char*d,char*s,int n){return y(h(d,0),s,n);}
******************************************************/


int my_strlen( const char *c ) {
  if (*c) { //if c isn't at terminating null
    return 1 + my_strlen(++c); //add on 1, move c, and recurse
  }
  return 0;
}


char *my_strcpy( char *dest, const char *src ) {
  *dest = *src;
  if (*src) { //if src isn't at terminating null
    my_strcpy(dest + 1, src + 1); //recurse on next pair of chars
  }
  return dest;
}
char *my_strncpy( char *dest, const char *src, int n ) {
  *dest = *src;
  if ( --n && *src ) { //n isn't at 0 and src isn't at termNUL
    my_strncpy( dest + 1, src + 1, n ); //recurse on next pair of chars
  }
  return dest;
}


char *my_strchr( const char *s ,char c ) {
  if (*s == c) { //if char was found
    return s; //return the pointer to it
  }
  else if (*s) { //if s isn't at termNUL yet
    return my_strchr( ++s, c ); //keep recursing
  }
  return NULL; //went thru entire s and c not found
}


char *my_strcat( char *dest, const char *src ) {
  char *tmp = dest; //preserve orig dest
  my_strcpy( my_strchr(tmp, '\0'), src ); //find termNUL, copy from there
  return dest;
}
char *my_strncat( char *dest, const char *src, int n ) { 
  char *tmp = dest; //preserve orig dest
  my_strncpy( my_strchr(tmp, '\0'), src, n ); //find termNUL, copy n chars from there
  return dest;
}


int my_strcmp( const char *a, const char *b ) {
  if (*a && *b && *a == *b) { //neither a or b at termNUL && a equals b
    return my_strcmp( ++a, ++b ); //need to keep recursing
  }
  return *a - *b;
}


int main() {

  char s1[] = "Hella";
  char s2[10] = "";

  printf("\nBefore applying regular functions:\n");
  printf("s1 = \"%s\", length = %d\n", s1, my_strlen(s1));
  printf("s2 = \"%s\", length = %d\n", s2, my_strlen(s2));

  printf("\nTesting regular functions:\n");
  printf("Copy s1 to s2: s2 = \"%s\"\n", my_strcpy(s2, s1));
  printf("Cat \"Man\" to s2: s2 = \"%s\"\n", my_strcat(s2, "Man"));

  printf("\nBefore applying \"n\"functions:\n");
  printf("s1 = \"%s\", length = %d\n", s1, my_strlen(s1));
  printf("s2 = \"%s\", length = %d\n", s2, my_strlen(s2));

  printf("\nTesting \"n\" functions:\n");
  printf("Copy 3 chars from \"Test\" to s1: s1 = \"%s\"\n", my_strncpy(s1, "Test", 3));
  printf("Cat 4 chars from s2 to s1: s1 = \"%s\"\n", my_strncat(s1, s2, 4));

  printf("\nTesting strcmp:\n");
  printf("Compare \"ab\" to \"abc\": %d\n", my_strcmp("ab", "abc"));
  printf("Compare \"abc\" to \"ab\": %d\n", my_strcmp("abc", "ab"));
  printf("Compare \"abc\" to \"abc\": %d\n", my_strcmp("abc", "abc"));

  printf("\nTesting strchr:\n");
  printf("Looking for 1 in \"Hello123\": Index [%c]\n", *my_strchr("Hello123", '1'));
  printf("Looking for 0 in \"Hello123\": Index [%c]\n", my_strchr("Hello123", '0')); //can't deref NULL


  return 0;
}
