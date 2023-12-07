#include <stdio.h>
#include <string.h>

typedef enum {
  false = (1 == 0),
  true = !false
} bool;

int _getline(char *str, size_t size) // Gets a line of size _size_
{
  char c;
  int i = 0;
  while ((i < size - 1) && ((c = getchar()) != EOF)) {
    if (c != '\n') {
      str[i] = c;
      i++;
    } else {
      str[i] = '\0';
      i++;
      return i;
    }
  }
}

void str_uncomment(char *to, char *from, bool *in_comment_block) // Remove instances of comments in the line
{
  size_t size_from = strlen(from);
  bool in_str_constant = false;

  int i_from = 0;
  int i_to = 0;
  while (i_from < size_from) {
    
    while (*in_comment_block && i_from < size_from) {
      /* Somehow these aren't working */

      /*
        But these are
      */
      
      /* This
         also works */
        
      if (from[i_from] == '*' && from[i_from+1] == '/') {
        i_from++;
        *in_comment_block = false;
      } else {
        i_from++;
      }
    }
    
    if (from[i_from] == '/' && from[i_from+1] == '*' && !in_str_constant) {
      *in_comment_block = true;
    }
    if (!*in_comment_block) {
      if (from[i_from] == '"' && !in_str_constant) {
        in_str_constant = true;
      } else if (from [i_from] == '"' && in_str_constant) {
        in_str_constant = false;
      }
      if (from[i_from] == '/' && from[i_from+1] == '/' && !in_str_constant) {
        to[i_from] = '\0';
      } else {
        to[i_from] = from[i_from];
      }
      i_from++;
      i_to++;
    }
  }
  to[i_to] = '\0';
}

#define MAX_SIZE 1000

int main(void)
{
  char line[MAX_SIZE] = {0};
  char uncommented[MAX_SIZE] = {0};
  bool in_comment_block = false;

  while (_getline(line, MAX_SIZE) > 0) {
    str_uncomment(uncommented, line, &in_comment_block);
    printf("%s\n", uncommented);
  }

  return 0;
}
