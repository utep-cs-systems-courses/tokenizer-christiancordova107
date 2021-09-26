#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.c"

void free_historyR(Item *dummy);


List* init_history()
{
  List *list = malloc(sizeof(List));
  Item *root_node = malloc(sizeof(Item));
  
  root_node->id = 0;
  root_node->str = NULL;
  root_node->next = NULL;
  list->root = root_node;

  return list;
}

void add_history(List *list, char *str)
{
  Item *dummy = list->root;
  int count = 0;
  short lengthOfStr = 0;

  for(int i = 0; *(str+i) != '\0'; i++) {
    lengthOfStr++;
  }  
  
  while (1) {
    if(dummy->next == NULL) {
      Item *newNode = malloc(sizeof(Item));
      newNode->id = count;
      newNode->str = copy_str(str, lengthOfStr);
      newNode->next = NULL;
      dummy->next = newNode;
      break;
    }

    else {
      dummy = dummy->next;
      count++;
    }
  }
}

char *get_history(List *list, int id)
{
  Item *dummy = list->root->next;
  
  while(dummy != NULL && id != 0) {
    
    if(dummy == NULL) {
      printf("invalid entry");
    }

    else if(id == 1) {
      return dummy->str;
    }

    else {
      id--;
      dummy = dummy->next;
    }
  }
}

void print_history(List *list)
{
  Item *dummy = list->root->next;
  int i = 1;  
  while(dummy != NULL) {
    printf("%d. %s\n", i++, dummy->str);
    dummy = dummy->next;
  }
}

void free_history(List *list)
{
  if(list->root->next != NULL) {
    free_historyR(list->root->next);
  }
  
  else {
    free(list->root);
  }
  
  free(list);
}

void free_historyR(Item *dummy)
{
  if(dummy->next != NULL)
  {
    free_historyR(dummy);
  }

  else {
    free(dummy->id);
    free(dummy->str);
    free(dummy->next);
    free(dummy);
    return;
  }
}
