#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedList.h"


struct song_node *insert_front(song_node *list, char *newname, char *newartist){
  struct song_node *new= (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name, newname);
  strcpy(new->artist, newartist);
  new->next = list;
  return new;
}

struct song_node *insert(song_node *list, char *newname, char *newartist){
  if (!list) return insert_front(list, newname, newartist);

  int artistCmp = strcmp(newartist, list->artist);
  int nameCmp = strcmp(newname, list->name);
  if ( artistCmp < 0 || (artistCmp == 0 && nameCmp <= 0) ) {
    return insert_front(list, newname, newartist);
  }

  else { //keep iterating
    struct song_node *tmp = list;
    for ( ; tmp->next; tmp = tmp->next) {

      int artistCmp_next = strcmp(newartist, tmp->next->artist);
      int nameCmp_next = strcmp(newname, tmp->next->name);

      if ( artistCmp_next < 0 || (artistCmp_next == 0 && nameCmp_next <= 0) ) {
	struct song_node *newNode = insert_front(tmp->next, newname, newartist);
	tmp->next = newNode;
	return list;
      }
    }
        
    struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(new->name, newname);
    strcpy(new->artist, newartist);
    tmp->next = new;
    return list;
  }
}

void print(song_node *list){
  while(list){
    printf("\t%s - %s\n", list->artist, list->name);
    list=list->next;
  }
}

struct song_node *find_random(song_node *list){
  song_node *ret = list;
  int i = 2;
  for (; list; i++) { //keep incrementing until list is NULL 
    if ( !(rand() % i) ) { //theoretical 1/i chance to be true
      ret = list;
    }
    list = list->next;
  }
  return ret;
}

struct song_node *find_song(song_node *list, char *songName) {
  if (!list) return NULL; //not found
  if ( !strcmp(list->name, songName) ) return list; //if match, return node
  return find_song( list->next, songName );
}

struct song_node *find_artist(song_node *list, char *songArtist) {
  if (!list) return NULL; //not found
  if ( !strcmp(list->artist, songArtist) ) return list; //if match, return node
  return find_artist( list->next, songArtist );
}


struct song_node *remove_node(song_node *list, char *songName, char *songArtist) {
  //if first node, just remove  
  song_node *ret;
  if(!(strcmp(list->name,songName)||(strcmp(list->artist,songArtist)))){
    ret = list->next;
    free(list);
    return ret;
  }
  ret = list;
  while(list->next){
    song_node *temp = list->next;
    if(!(strcmp(temp->name,songName)||(strcmp(temp->artist,songArtist))))
      list->next = (temp)->next;
    list=temp;
  }
  return ret;
}


struct song_node *free_list(song_node *list) {
  if (!list) return list;
  if (list -> next) free_list(list -> next);
  free(list);
  list = NULL;
  return list;
}
