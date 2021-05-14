#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

  char const* const file_name = argv[1];
  FILE* file = fopen(file_name, "r");
  char line[256];
  char command[50];

  while (fgets(line, sizeof(line), file)){

    strcpy(command, line);
    system(command);
    printf("\n");
  }
  fclose(file);
  return 0;
}
