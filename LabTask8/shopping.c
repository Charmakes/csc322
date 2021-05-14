#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Item{
  char name[100];
  float price;
  int quantity;

}Item;

Item* reAllocate(Item items[],int *size){
  int nSize = *size * 2;
  Item *nItem = (Item *)malloc(sizeof(Item) * nSize);
  int i = 0;

  for(i = 0;i<*size;i++){
    strcpy(nItem[i].name,items[i].name);
    nItem[i].price = items[i].price;
    nItem[i].quantity = items[i].quantity;
  }
  *size = nSize;
  return nItem;
}
//copy items
void itemCP(Item *target, Item src){
  strcpy(target->name , src.name);
  target->price = src.price;
  target->quantity = src.quantity;
}

//swap items
void itemSW(Item *one,Item *two){
  Item temp;
  itemCP(&temp,*one);
  itemCP(one,*two);
  itemCP(two,temp);

}

//sort items
void itemST(Item items[], int size){
  int i,j;
  float a,b;
  for(i = 0;i<size;i++){
    for(j = 0;j<size-i-1;j++){
      a = items[j].price * items[j].quantity;
      b = items[j+1].price * items[j+1].quantity;
      if(a < b){
	itemSW(items+j,items+j+1);
      }
    }
  }
}

//print items
void itemP(Item items[], int size){
  int i;
  printf("\nYour List\n");
  float totalCost = 0;
  float itemsTally = 0;
  for(i = 0;i<size;i++){
    itemsTally = items[i].price*items[i].quantity;
    printf("\n%-20s %-10d %-10.2f\n",items[i].name,items[i].quantity,itemsTally);
    totalCost += itemsTally;
  }
  printf("\n----------------------------------------\n");
  printf("Total %30.2f\n",totalCost);
}




int main(void) {

  int size=1;
  Item* items=(Item*)malloc(sizeof(Item)*size);
  char name [100];
  float price;
  int quantity;
  char mychar;
  int itemPlace = 0;

  do{
    printf("\nEnter item information (\"exit\" to exit)\n");
    printf("Item %d: ",itemPlace+1);
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1]='\0'; 
    if(strcmp(name,"exit")==0) {
      break;
    }
    printf("price: ");
    scanf("%f",&price);

    if(price <0){
      printf("\nError: please try again, your price can't be negative!!");
      continue;
    }
    printf("quantity: ");
    scanf("%d",&quantity);
    scanf("%c",&mychar);
    if(quantity <=0){
      printf("\nError: Quantity cannot be negative or zero");
      continue;
    }

    strcpy(items[itemPlace].name,name);
    items[itemPlace].quantity = quantity;
    items[itemPlace].price = price;
    itemPlace++;
    if(itemPlace == size){
      items = reAllocate(items,&size);
    }


  }while(strcmp(name,"exit") != 0);

  itemST(items,itemPlace);
  itemP(items,itemPlace);
  return(EXIT_SUCCESS);

}
