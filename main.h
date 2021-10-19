#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct Node
{
    char * word;
    struct Node * next;
} Node;

Node * dictionary = NULL;
Node * sentence = NULL;

#endif
