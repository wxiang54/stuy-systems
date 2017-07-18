#include "main.h"

/*
 * Function: printDirs
 * ----------------------
 *   Prints names of all subdirs in dir
 *   path: char array for path of (main) dir
 */
void printDirs( char * path ) {
  DIR* stream = opendir(path);
  printf("Directories:\n");
  struct dirent *fileInfo = readdir(stream);
  
  while (fileInfo) {
    if (fileInfo->d_type == DT_DIR) { //if file type is dir
      printf("\t%s\n", fileInfo->d_name);
    }
    fileInfo = readdir(stream);
  }
  closedir(stream);
}

/*
 * Function: printFiles
 * ----------------------
 *   Prints names of all reg files in dir
 *   path: char array for path of dir
 */
void printFiles( char * path ) {
  DIR* stream = opendir(path);
  printf("Regular Files:\n");
  struct dirent *fileInfo = readdir(stream);
  
  while (fileInfo) {
    if (fileInfo->d_type == DT_REG) { //if file type is reg file
      printf("\t%s\n", fileInfo->d_name);
    }
    fileInfo = readdir(stream);
  }
  closedir(stream);
}


/*
 * Function: printAll
 * ----------------------
 *   Prints all directories and regular
 *   files in given directory
 *
 *   path: char array for path of dir
 */
void printAll( char * path ) {
  printf("\nPRINTING FILES...\n");
  printDirs(path);
  printFiles(path);
}

/*
 * Function: getFileSize
 * ----------------------
 *   Returns size of given file
 *   path: char array for path of file
 */
size_t getFileSize( char * path ) {
  struct stat foo;
  if ( stat(path, &foo) < 0 ) {
    printf("\nERROR: %d - %s\n", errno, strerror(errno));
  } else {
    return foo.st_size;
  }
}

/*
 * Function: getDirSize
 * ----------------------
 *   Returns size of all reg files and 
 *   subdirs (recursively) in given directory
 *
 *   path: char array for path of dir
 */
size_t getDirSize( char * path ) {
  DIR* stream = opendir(path);
  struct dirent *fileInfo = readdir(stream);
  size_t totalSize = 0;
  
  while (fileInfo) {
    char newPath[1000]; //bc relative to main.c
    strcat( strcat( strcpy(newPath, path), "/" ), fileInfo->d_name);
    
    //. and .. wreak recursive havoc lmao
    if ( fileInfo->d_type == DT_DIR && strcmp(fileInfo->d_name, ".") && strcmp(fileInfo->d_name, "..") ) { 
      //printf("DIR: %s\n", newPath);
      totalSize += getDirSize( newPath );
    }
    else if (fileInfo->d_type == DT_REG) {
      //printf("FILE: %s\n", newPath);
      totalSize += getFileSize( newPath );
    }
    fileInfo = readdir(stream);
  }

  closedir(stream);
  return totalSize;
}



int main() {
  char dirPath[] = ".";

  size_t size = getDirSize(dirPath);
  float floatSize = (float)size;
  char sizePrefix[4][3] = {"B","KB","MB","GB"};
  
  int i = 0;
  while (floatSize/1024 > 1) {
    floatSize /= 1024;
    i++;
  }

  printf("\nTOTAL DIR SIZE: %f %s\n", floatSize, sizePrefix[i]);
  printAll(dirPath);
}
