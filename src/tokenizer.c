#include <stdio.h>
#include <stdlib.h>


int space_bar(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_bar(char c)
{
  if(!space_bar(c){
      return 1;
  }
    
  else{
      return 0;
    }
}

  char *word_start(char *str)
  {
    int count = 0;
    char *dummy = str;

    while((*(dummy++)) != '\0' && space_bar(*dummy)){
      count++;
    }

    if(count == 0){
      return NULL;
    }

    else{
      return dummy;
    }
  }

  char *word_terminator(char *word)
  {
    char *dummy = word;

    while(1)
    {
      if((*dummy) == '\0'){
	return dummy;  
      }
      else{
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
      }

      while(non_space_char(*dummy){
	  dummy++;
      }
	count++;
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
