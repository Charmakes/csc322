#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char String[128];
typedef enum{ false, true } bool;
typedef enum{ mammal, insect, bird, fish } AnimalType;
typedef struct { String name; double size; AnimalType type;} Animal;

char *stringType(AnimalType type){
  switch (type){
  case mammal:
    return "mammal";
    break;
  case insect:
    return "insect";
    break;
  case bird:
    return "bird";
    break;
  case fish:
    return "fish";
    break;
  default:
    return "error";
    break;
  }
}

void p(Animal **found, int size){
  int i;
  Animal *a;
  printf("The following new species were found:");
  for(i = 0; i < size; i++) {
    a = *(found + i);
    printf("\n%-20s has size %6.2f and is a %s", a->name, a->size, stringType(a->type));
  }
}

void reallocate(Animal ***found, int *size) {
  *size *= 2;
  *found = realloc(*found, *size * sizeof(Animal *));

  if(*found == NULL) {
    perror("exiting... could not reallocate");
  }
}

AnimalType myAtype(String type){
  if(!strcmp(type,"mammal")){
    return mammal;
  }else if(!strcmp(type,"insect")){
    return insect;
  }else if(!strcmp(type,"bird")){
    return bird;
  }else if(!strcmp(type,"fish")){
    return fish;
  }else{
    perror("exiting... invalid animal type");
   return 0;
  }
}


bool input(Animal *a){
  String type;
  printf("Enter animal information (\"exit\" to exit)\n");
  printf("What is the name :  ");
  scanf("%s", a->name);


  if(!strcmp(a->name, "exit")){
    return false;
  }
  printf("What is the size :  ");
  scanf("%lf", &a->size);
  printf("What is the type :  ");
  scanf("%s", type);
  a->type = myAtype(type);
  return true;
}

int main(void) {
  int size = 1;
  int index = -1;
  Animal **found = malloc(sizeof(Animal *));

  while(true) {
    Animal *a = malloc(sizeof(Animal));

    if(++index >= size) {
      reallocate(&found, &size);
    }

    if(!input(a)) {
      break;
    } else {
      *(found + index) = a;
    }
  }

  printf("\n");
  p(found, index);
  printf("\n");

  return(EXIT_SUCCESS);
}
