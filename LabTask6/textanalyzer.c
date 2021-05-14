#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
typedef char STRING[MAXLEN];

int GetNumOfCharacters (char mystring[]){
  int i; 
  for (i=0; mystring[i] != '\0'; i++);  
  return i-1;
}

void OutputWithoutWhitespace (char *mystring){
  int i;
  int count;
  count = 0;
 
  for(i=0;mystring[i];i++){
      mystring[i]=mystring[i+count];
      if(mystring[i]==' '|| mystring[i]=='\t'){
	  count++;
	  i--;
	}
  }
  
  
 }


int main()
{
  STRING mystring;

  printf("Enter your string: ");
  fgets(mystring, MAXLEN, stdin);
 

  printf("Your string is:  %s\n",mystring);
  int mycn;
  mycn = GetNumOfCharacters(mystring);
  printf("Your char count is:  %d\n", mycn);
   OutputWithoutWhitespace(mystring);
   printf("Without spaces:  %s\n", mystring); 
  return 0;
}
