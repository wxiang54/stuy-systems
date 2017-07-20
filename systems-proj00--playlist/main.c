#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "playlist.h"

int main() {
  srand ( time(NULL) );

  /*********************************
  //TESTING LLIST FXNALITY
  *********************************/

  //setup
  song_node *llist;
  llist = (struct song_node*) malloc( sizeof(struct song_node) );
  printf("\nInitial llist: ");
  strcpy(llist->name, "sampleName");
  strcpy(llist->artist, "sampleArtist");
  print(llist);


  //insert_front
  printf("\nInserting 'bob' by 'builder'...\n");
  llist = insert_front(llist, "bob", "builder");
  print(llist);

  
  //insert
  printf("\nInserting 'base' by 'aonderland'... \n");
  llist = insert(llist, "base", "aonderland");
  print(llist);

  printf("\nInserting 'alice' by 'wonderland'... \n");
  llist = insert(llist, "alice", "wonderland");
  print(llist);

  printf("\nInserting 'sandstorm' by 'darude'... \n");
  llist = insert(llist, "sandstorm", "darude");
  print(llist);

  llist = insert(llist, "spaghetti", "eminem");
  printf("\nInserting 'spaghetti' by 'eminem'... \n");
  print(llist);

   
  //random
  printf("\n\nTesting random song selection...\n");
  int i;  
  for (i = 1; i < 11; i++) {
    struct song_node *randSong = find_random(llist);
    printf("\tRandom Song #%d: \"%s\" by %s\n", i, randSong->name, randSong->artist);
  }

  
  //find_song
  printf("\n\nLooking for song \"sandstorm\"... ");
  if (find_song(llist, "sandstorm")) {
    printf("\nSong found!\n");
  } else {
    printf("\nError: No song found with that name!\n");
  }

  printf("\nLooking for song \"spag heddy\"... ");
  if (find_song(llist, "spag heddy")) {
    printf("\nSong found!\n");
  } else {
    printf("\nError: No song found with that name!\n");
  }

  
  //find_artist
  printf("\nLooking for artist \"builder\"...\n");
  if (find_artist(llist, "builder")) {
    printf("Song found!\n");
  } else {
    printf("Error: No song found with that name!\n");
  }

  printf("\nLooking for artist \"3pac\"...\n");
  if (find_artist(llist, "3pac")) {
    printf("Artist song found!\n");
  } else {
    printf("Error: No artist found with that name!\n");
  }
  

  //remove_node
  printf("\nRemoving sampleArtist-\"sampleName\" entry...\n");
  llist = remove_node(llist, "sampleName", "sampleArtist");
  print(llist);

  
  //free_list
  printf("\nFreeing list...\n");
  llist = free_list(llist);
  print(llist);



  /*********************************
  //TESTING PLAYLIST FXNALITY
  *********************************/

  //addSong  
  printf("\nPopulating table...\n");
  addSong("Mom's Spaghetti", "Einem");
  addSong("Kappa Kappa Kappa", "Forsen");
  addSong("Levitate", "Kendrick Lamar");
  addSong("God is Gangsta", "Kdot");
  addSong("Holy Key", "DJ Khaled");
  addSong("Before We Fade", "Tristam");
  addSong("Once Again", "Tristam");
  addSong("Stressed Out", "Twenty One Pilots");
  addSong("ey ey GI GI GRRRRAHeh", "Desiigner");
  addSong("Suburban Home", "Descendents");
  printAll();


  //findSongs (dysfunctional :/ )
  printf("\n\nLooking for artist tristam...\n");
  printSongsOfArtist( "tristam" );
  printf("\n\nLooking for artist twenty one pilots...\n");
  printSongsOfArtist( "twenty one pilots" );


  //printf( (find_artist(table['t'-97], "tristam")) );
  
  //shuffle
  shuffle();


  //deleteSong
  printf("\n\nDeleting song \"Holy Key\" by DJ Khaled...\n");
  deleteSong("holy key", "dj khaled"); //this doesnt work either :/
  printAll(); 
  return 0;
}
