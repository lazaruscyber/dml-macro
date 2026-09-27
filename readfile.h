#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>
#include <string.h>

void readFile(char *filename, char *extension, char line[])
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    perror("File does not exist");
  }

  while (fgets(line, sizeof(line), file))
  {
    printf("%s", line);
  }

  fclose(file);
}

#endif READ_FILE_H
