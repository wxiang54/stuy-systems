#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "linkedList.h"

song_node *table[26];	

void addSong(char *name, char *artist );

struct song_node * findSong( char *name, char *artist );
struct song_node * findArtist( char *artist );

void printArtistsWithLetter( char letter );
void printSongsOfArtist( char *art );
void printAll();

void shuffle();

void deleteSong( char *name, char *art );
void deleteAll();

#endif
