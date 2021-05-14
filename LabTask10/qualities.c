#include<stdio.h>
#include<unistd.h>
#include<string.h>



const char myFile[] ="MyQualities.txt";

int main(){
  char QUALITIES[1024] = "The qualities are ";
  char growingS[1024] = "";
  FILE *file = fopen(myFile , "w" );

  if (file == NULL){
    printf("Error, can not wrtie file [%s] \n", myFile);
    return 0;
  }

  printf("Please enter sentences, . to end.\n");

  while( fgets(growingS, 1024, stdin) ){
    char temp[100] = "";

    if ( strstr(growingS,"I am") ){
      int len = strlen(growingS + 5);
      len = len - 1 ;
      strncpy(temp, growingS + 5 , len );
      fputs(temp,file);
      fputc('\n',file);
      strcat(temp, ",");
      strcat(QUALITIES,temp);
      memset(growingS, 0 , sizeof(growingS));
      continue;
    }

    int len = strlen(growingS);
    growingS[len-1] = '\0';
    if (strcmp(growingS,"." ) == 0 ) {
      break;
    }


    memset(growingS, 0 , sizeof(growingS));
  }


  int len = strlen(QUALITIES);
  QUALITIES[len - 1 ] = '\0';
  printf("%s.\n\n", QUALITIES);
  fclose(file);

  file = fopen(myFile , "r" );
  printf("Confirming the saved qualities ...\n");

  while(fgets(growingS, 1024, file )){
    printf("%s", growingS);
  }

  remove(myFile);
  fclose(file);
}
