#include <stdio.h>
#include <stdlib.h>

/*here is my comment */


int main(void) {
  printf("enter a comment and I will repeat it:"); 
  int c;

  while((c = getchar()) != EOF) {

    if(c == '/') {

    if((c = getchar()) == '/') {

      while((c = getchar()) != '\n') {
	  printf("%c",c);

	}
	printf("\n");
      }
      else if(c == '*') {

      while((c = getchar()) != '*') {

	  printf("%c",c);

	}
	printf("\n");
      }
    }
  }

  return(EXIT_SUCCESS);
}
