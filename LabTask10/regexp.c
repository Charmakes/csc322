#include <stdio.h>
#include <string.h>
#include <regex.h>

int stringMatch (const char *string, const char *myPattern){
  regex_t cmprx;
  if (regcomp (&cmprx, myPattern, REG_EXTENDED | REG_NOSUB) != 0)
    return 0;
  int b = regexec (&cmprx, string, 0, NULL, 0);
  regfree (&cmprx);
  if (b != 0)
    return 0;
  return 1;
}

int wordCount (char *string){
  int cnt = 0;
  int i;

  for (i = 1; i < strlen (string); i++){
    if (string[i] == ' ')
      cnt++;
  }
  return cnt + 1;
}

int main (){
  char string[100], reg[50];
  printf ("Please enter the string to analyze\n");
  scanf ("%[^\n]", string);
  printf ("Please enter the regular expression:  ");
  scanf ("%s", reg);


  char *myToken;
  char dl[] = ".!?";
  char *t = string;

  while ((myToken = strtok_r (t, dl, &t))){
    printf ("%s\n", myToken);
    printf ("%s %d words \n", stringMatch(myToken, reg) ? "Yes" : "No", wordCount(myToken));
  }
  return 0;
}
