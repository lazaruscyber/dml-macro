#include <stdio.h>
#include <string.h>
#include "readfile.h"
#include "typechecker.h"

/* Main Loop */
void mainLoop(char *filename, char *CParam)
{
  char *dmlExtension = strstr(filename, ".dml");
  char line[256];
  
  if (dmlExtension)
  {
    FILE *file = fopen(filename, "r");

    int onlyRead = strncmp(CParam, "-read", 7);
    int is_checkC = strncmp(CParam, "-checkC", 7);

    if (onlyRead == 0)
    {
      readFile(filename, dmlExtension, line);
    }
    else if (is_checkC == 0)
    {
      checkComment(filename, line);
    }
    else if (onlyRead || is_checkC > 1)
    {
      printf("%s is not a valid flag", CParam);
    }
    
  }
  else
  {
    printf("%s is not a DML script", filename);
  }
}

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    mainLoop(argv[1], argv[2]);
  }
  else
  {
    printf("Needs 2 arguments\n");
  }
      
  return 0;
}
