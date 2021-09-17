#include <stdio.h>
#include <stdlib.h>

int main()
{
  char input[100];

  while(1){
    putchar('$');
    fgets(input, 100, stdin);
    printf("%s", input);
  }
  
  return 0;
}
