#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void print_list( struct node *list ) {
  while( list ) {
    printf("%c --> ", list -> c);
    list = list -> next;
  }
  printf("NULL\n");
  return;
}


struct node * insert_front( struct node *list, char data ) {
  struct node *newNode;
  newNode = (struct node *)malloc( sizeof(struct node) );
  newNode -> c = data;
  newNode -> next = list;
  return newNode;
}


struct node * free_list( struct node *list ) {
  if ( !list ) return list; //if there's nothing in the list, nothing to free
  
  if (list -> next) { //if this isn't the last element
    free_list( list -> next ); //free rest of list
  }
  
  //Assert: this is *CURRENT* end element in list
  free(list); //free self
  list = NULL; //more likely to crash if pointer reused
  return list;
}





int main() {

  struct node *list;
  list = (struct node *)malloc( sizeof(struct node) );
  list -> c = 'k';
  list -> next = NULL;
  
  printf("\nINITIAL LIST: \n");
  print_list(list);

  printf("\nINSERTING '3' IN FRONT...\n");
  list = insert_front(list, '3');
  print_list(list);

  printf("\nINSERTING 'K' IN FRONT...\n");
  list = insert_front(list, 'K');
  print_list(list);

  printf("\nAFTER FREEING...\n");
  list = free_list(list);
  print_list(list);

  return 0;
}
