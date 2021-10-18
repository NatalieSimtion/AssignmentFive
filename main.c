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
  
}