#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_bar(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c)
{
  if(!space_bar(c)){
      return 1;
  }
    
  else{
      return 0;
    }
}

  char *word_start(char *str)
  {
    char *dummy = str;

    while((*dummy) != '\0' && space_bar(*dummy)){
      dummy++;
    }

    return dummy; 
  }

  char *word_terminator(char *word)
  {
    char *dummy = word;

    while(1) {
      if((*dummy) == '\0') {
	return dummy;  
      }
      else {
	dummy++;
      }
    }
  }

  int count_words(char *str)
  {
    char *dummy = str;
    char *end = word_terminator(str);
    int count = 0;

    while(dummy < end){
      if(non_space_char(*dummy)){
	dummy++;

	while (non_space_char(*dummy)) {
	  dummy++;
	}
	count++;
      }
      dummy++;
    }
      return count;
  }

char *copy_str(char *inStr, short len)
{
  char *p = malloc(sizeof(*inStr) * len + 1);
  char *dummy = inStr;

  for(int i = 0; i<len; i++){
    *(p+i) = *dummy;
    dummy++;
  }

  *(p + len) = '\0';

  return p;
}    

 char **tokenize(char *str)
 {
   int numOfWords = count_words(str);
   char **tokens = malloc((numOfWords + 1) * sizeof(char *));
   char *dummy = str;
   char *terminator = word_terminator(str);
   int wordSize;
   
   for (int i = 0; i<numOfWords; i++) {
     wordSize = 0;
     char *start;
     
     dummy = start = word_start(dummy);
     
     while(non_space_char(*dummy) && dummy  != terminator) {
       dummy++;
       wordSize++;
     }
     
     char word[wordSize];
     
     for (int i = 0; i < wordSize; i++) {
       word[i] = *(start++);
     }
     
     word[wordSize] = '\0';
     
     tokens[i] = copy_str(word, wordSize);
   }
   
   tokens[numOfWords] = NULL;
   return tokens;
 }

 void print_tokens(char **tokens)
 {
   char **dummy = tokens;
   
   while (*dummy != NULL) {
     printf("%s\n", *(dummy++));
   }
 }

 void free_tokens(char **tokens)
 {
   char **dummy = tokens;

   while (*dummy != NULL) {
     free(*dummy);
   }

   free(tokens);
 }
