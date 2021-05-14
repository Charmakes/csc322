#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 5
typedef int *pointer;
typedef int intarray[5];
typedef pointer pointerarray[5];


void initialize(intarray m, pointerarray n) {
  srand(getpid());
  int i;
  for(i = 0; i < SIZE; i++) {
    m[i] = rand();
  
  }
  int j;
  for(j = 0; j < SIZE; j++) {
    n[j] = &m[j];
  }
}



void sortintgrz(intarray m) {
  int i;
  for(i = 0; i < SIZE; i++) {
    int j = 0;
    while(j < SIZE - (i + 1)) {
      if(*(m + j) > *(m + j + 1)) {
	int temp = *(m + j + 1);
	*(m + j + 1) = *(m + j);
	*(m + j) = temp;
      }
      j++;
    }
  }
}

void printintgrz(intarray a) {
  int i;
  for(i = 0; i < SIZE; i++) printf(" %2d : %12d\n",i,a[i]);
}



void sortpointrz(pointerarray m) {
  int i;
  for(i = 0; i < SIZE; i++) {
    int j = 0;
    while(j < SIZE - (i + 1)) {
      if(*(*(m + j)) > *(*(m + j + 1))) {
	int *temp = *(m + j + 1);
	*(m + j + 1) = *(m + j);
	*(m + j) = temp;
      }
      j++;
    }
  }
}


void printpointrz(pointerarray m) {
  int i;
  for(i = 0; i < SIZE; i++) printf(" %2d : %12d\n",i,*m[i]);
}


int main(void) {
  intarray intgrz;
  pointerarray pointrz;
   
  printf("\n");

  printf("---- Initialized array of integers ----\n");

  initialize(intgrz, pointrz);
  printintgrz(intgrz);

  int **p;
  p = pointrz;
  printf("---- Sorted array of pointers ----\n");

  sortpointrz(pointrz);
  printpointrz(pointrz);


  printf("---- Sorted array of integers ----\n");

  sortintgrz(intgrz);
  printintgrz(intgrz);


  printf("---- Array of pointers ----\n");
  printpointrz(p);
  printf("\n");

  return(EXIT_SUCCESS);
}
