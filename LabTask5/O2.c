#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char getGroup(float p) {
  char group;

  char c;
    float holder = 0.0;
    float increment = 0.1;
    for (c = 'A'; c <= 'Z'; ++c){
    holder = holder + increment;
    if (p>=holder-increment && p<=holder) { 
    group = c;
    break;
    } 
    		       }
    return (group);
}


int main(void) {
printf("\nEnter depth\t\t: ");
float depth;
scanf("%f",&depth);

printf("Enter percentage oxygen\t: ");
float percentage;
scanf("%f",&percentage);

float constant = 33.0;

 float ambpressure = (depth / constant) + 1;
 float partpressure = (percentage / 100.0) * ambpressure;
 char group = getGroup(partpressure);

 printf("\nAmbient pressure\t: %.1f\n",ambpressure);
 printf("O2 Pressure\t\t: %.2f\n",partpressure);
 printf("O2 Group\t\t: %c\n\n",group);

 if(partpressure >= 1.4) printf("\nExceeds maximal O2 pressure\t: %s\n","true");
 else printf("\nExceeds maximal O2 pressure\t: %s\n","false");
 if(partpressure >= 1.6) printf("Exceeds contingency O2 pressure\t: %s\n\n","true");
 else printf("Exceeds contingency O2 pressure\t: %s\n\n","false");

 return(EXIT_SUCCESS);

}
