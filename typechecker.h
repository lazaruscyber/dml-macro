#ifndef TYPECHECKER_H
#define TYPECHECKER_H

#include <stdio.h>
#include <string.h>

void checkComment(char *filename, char line[])
{
  FILE *file = fopen(filename, "r");

  while (fgets(line, sizeof(line), file))
  {
    char *comment_type = "/*";
    char *comment = strstr(line, comment_type);
    
    if (comment)
    {
      printf("Comment: %s\n", comment);
    }
  }

  fclose(file);
}

#endif TYPECHECKER_H
