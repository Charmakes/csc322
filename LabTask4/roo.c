#include <stdio.h>
#include <stdlib.h>

int main (void) {
  printf("Enter side of square in km: ");
  float sqrside;
  scanf("%f", &sqrside); 

  printf("Enter road length in km: ");
  float rlength;
  scanf("%f", &rlength);

  printf("Enter number of 'roos: ");
  float myroos;
  scanf("%f", &myroos);


  float width = 10.0 / 1000.0;
  float cnstant = 1.47;
  float square  = sqrside * sqrside;
  float density = myroos / square;
  float area = rlength * width;
  float kills = density * area * cnstant;

  printf("Expected number of kills is: %.1f\n", kills);
  return(EXIT_SUCCESS); 

}
