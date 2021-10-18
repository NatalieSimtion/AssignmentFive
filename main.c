#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct Node {
  char * word;
  struct Node * next;
} Node;

Node * dictionary = NULL;
Node * sentence = NULL;

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