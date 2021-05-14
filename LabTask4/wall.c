#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  printf("Enter height of the wall in ft: ");
  float height;
  scanf("%f", &height);

  printf("Enter width of the wall in ft: ");
  float width;
  scanf("%f", &width);

  float area = width * height;

  float pg = area / 350;
  
   

  printf("Wall area: %.2f sqft\n" , area); 
  printf("Paint needed: %.2f gallons\n", pg);
  printf("Cans needed: %.0f can\n", pg);

  return(EXIT_SUCCESS);

}
