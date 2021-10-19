#include "main.h"


//Read line from file pointer, return line or NULL if failed//


char * readline (FILE * fp) {
  size_t linesize;

  int linelength;
  char * lineBuffer = NULL;
  linesize = getline((char **)&lineBuffer, &linesize, fp);
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

  //new node

  Node * node = (Node *)malloc(sizeof(Node));
  node->word = line;
  node->next = NULL;

  //prepend node to dictionary
  if (dictionary == NULL)
  dictionary = node;

  else {
    node ->next = dictionary;
    dictionary = node;
  }
  fclose(file);


}

//check if word belongs to the dict

int isDictionaryWord(char * word) {
  Node * node = dictionary;

  while(node !=NULL) {
    if(strcmp(word, node->word) == 0 ) {
      return 1;
      //match found
    }
    node = node->next;
  }
  return 0;
  //match not found
}



