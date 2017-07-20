#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

void addSong(char *name, char *artist){
  int ind;
  if (artist[0] >= 97 && artist[0] <= 122) //lowercase
    ind = artist[0] - 97;
  else //uppercase
    ind = artist[0] - 65;
  table[ind] = insert(table[ind],name,artist);
}

struct song_node * searchSong( char *name, char *artist){
  int ind = artist[0] - 97;
  return find_song(table[ind],name);
}

struct song_node * searchArtist( char *artist){
  int ind = artist[0] - 97;
  return find_artist(table[ind],artist);
}

void printArtistsWithLetter(char letter){
  int ind = letter - 97;
  printf("Artists with letter %c:\n", letter);
  print(table[ind]);
}

void printSongsOfArtist( char *art){
  song_node *start = searchArtist(art);
  while(start && strcmp(art, start->artist) == 0){
    printf("%s - %s\n", start->artist, start->name);
    start = start->next;
  }
}

void printAll(){
  int x = 97; //start of ASCII lowercase a
  for (; x < 123; x++){
    printArtistsWithLetter(x);
  }
}

void shuffle() {
  int i;
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      song_node *randSong = find_random(table[i]);
      printf("\"%s\" by %s\n", randSong->name, randSong->artist);
    }
  }
}

void deleteSong( char *name, char *art){
  int ind = art[0] - 97;
  remove_node(table[ind],name,art);
}

void deleteAll(){
  int x = 0;
  for (; x < 26; x++){
    free_list(table[x]);
  }
}
