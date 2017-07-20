#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

struct song_node *insert_front(song_node *list, char *newname, char *newartist);
struct song_node *insert(song_node *list, char *newname, char *newartist);

void print(song_node *list);

struct song_node *find_song(song_node *list, char *songname);
struct song_node *find_artist(song_node *list, char *songartist);

struct song_node *find_random(song_node *list);

struct song_node *remove_node(song_node *list, char *songname, char *songartist);
struct song_node *free_list(song_node *list);
#endif
