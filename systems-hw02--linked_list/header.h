//STRUCT DEF
struct node { char c; struct node *next; };

//LLIST METHODS
void print_list( struct node *list );
struct node * insert_front( struct node *list, char data );
struct node * free_list( struct node *list );
