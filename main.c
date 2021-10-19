#include "main.h"


//Read line from file pointer, return line or NULL if failed//


char * readline (FILE * fp) {
  ssize_t linesize;

  int linelength;
  char * lineBuffer = NULL;
  linesize = getline(char **)&lineBuffer, &linesize, fp);
  //if eof is reached
  if(linesize == -1)
  return NULL;
  //remove new line character
  linelength = strlen(lineBuffer);

  if(lineBuffer[linelength - 1] == '\n')
  lineBuffer[--linelength] = '\0';

  //empty line check
  if (linelength == 0) {
    free(lineBuffer);
    return NULL;
  }

  return lineBuffer;

}

//read text file and dictionary, node linked list

void readDictionary(char * filename) {

  //open file

  FILE *file;

  if((file = fopen(filename, "r"))== NULL ) {
    printf("Error! File %s does not exist.\n, filename");
    exit(1);
  }

  //read line by line

  char * line = NULL;
  while ((line = readline(file)) != NULL) {
    
  }
}