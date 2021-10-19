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

//free given list

void freeList(Node ** headptr) {
  //free every node

  Node * node = *headptr;

  while(node != NULL) {
    Node * next = node ->next;
    free(node->word);
    free(node);
    node = next;
  }

  *headptr = NULL;
}

int main() {
  //prepare dict
  readDictionary("dictionary.txt");
  //open an output file
  FILE * file;
  char * filename = "shifts.txt";

  if((file = fopen(filename,"w"))== NULL) {
    printf("Error! File %s can't be opened.\n", filename);
    exit(1);
  }

  //read a line from stdin 1 by 1

  int index =0;
  char * line = NULL;

  while((line = readline(stdin))==NULL) {
    //increase line count
    index++;
    //print first sentence
    if (index == 1) {
      printf(file,"First line in file:\n");
      printf("line, %d: %s\n", index, line);

      Node * words = NULL;

      //split line and put them in a linked list

      char * word = strtok(line,"");

      while(word!= NULL){
        //new node
        Node * node = (Node *)malloc(sizeof(Node));
        node ->word = (char *)malloc(sizeof(word) +1);
        strcpy(node->word,word);
        node->next = NULL;
        //prepend 2 words
        if(words == NULL)
        words = node;
        else {
          node ->next = words;
          words = node;
        }
        word = strtok(NULL, "");
      }

      free(line);
      //find shift

    }
  }
}





