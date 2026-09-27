#include <stdio.h>
#include <string.h>
#include "readfile.h"
#include "typechecker.h"

/* Main Loop */
void mainLoop(char *filename, char *CheckC)
{
  char *dmlExtension = strstr(filename, ".dml");
  char line[256];
  
  if (dmlExtension)
  {
    FILE *file = fopen(filename, "r");

    int is_checkC = strcoll(CheckC, "-checkC");
    
    if (is_checkC == 0)
    {
      checkComment(filename, line);
    }
    else if (is_checkC < 1)
    {
      readFile(filename, dmlExtension, line);
    }
    else
    {
      printf("%s is not a valid flag\n", CheckC);
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
      
  return 0;
}
