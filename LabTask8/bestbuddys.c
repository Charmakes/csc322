#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[128];
typedef enum{ false, true } bool;
typedef struct node{
  String name;
  struct node *next;
  struct node *buddy;
} myNode;



myNode *buddyFind(myNode * head, String name){
  myNode *temp = head;

  while(temp->next != NULL) {
    temp = temp->next;
    if(!strcmp(name, temp->name)){
      return temp;
    }
  }

  return NULL;
}

bool buddyNation(myNode *head, myNode *newNode){

  printf("Enter nation name : ");
  scanf("%s", newNode->name);

  if(!strcmp(newNode->name, "quit")){

    free(newNode);
    return false;
  } else {
    newNode->next = head->next;
    head->next = newNode;
    return true;
  }
}


void buddyAdd(myNode *head){

  String name;
  myNode *foundFriend = NULL;
  myNode *temp = head;
  while(temp->next != NULL){

    temp = temp->next;
    int a = 1;

    while(a == 1) {
      printf("Enter best ally name for %s : ", temp->name);
      scanf("%s", name);

      if(!strcmp(name, temp->name)){

	printf("You can't ally with yourself\n");

      } else if((foundFriend = buddyFind(head, name)) == NULL) {
	printf("That nation does not exist\n");

      } else {
	a = -1;
      }
    }

    temp->buddy = foundFriend;
  }
}

void print(myNode *head){
  myNode *temp;


  while(head->next != NULL){
    temp = head->next;
    free(head);
    head = temp;
    printf("The best ally of %s is %s\n", head->name, head->buddy->name);
  }
  free(head);
}



int main(void){
  myNode *head = malloc(sizeof(myNode));

  head->next = NULL;

  printf("Enter \'quit\' to stop entering nations\n");

  while(buddyNation(head, malloc(sizeof(myNode))));

  if(head->next == NULL) {
    free(head);
    return -1;
  }

  buddyAdd(head);

  print(head);

  return (EXIT_SUCCESS);
}
