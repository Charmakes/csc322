#include <stdio.h>
#include <stdlib.h>

float input(void) {
float income = 0;
float deduction = 0;
float amount;

printf("Enter next amount  : ");
  scanf("%f",&amount);
  while(amount != 0) {
    if(amount > 0) income += amount;
    else if(amount < 0) deduction += amount;
    printf("Enter next amount  : ");
    scanf("%f",&amount);
  }

printf("\nIncome\t\t: $%.2f",income);
printf("\nDeductions\t: $%.2f\n",deduction* -1);
  return(income + deduction);
}

char Group(float x) {
  char group;
  if(x >= 500000) group = 'S';
  else if(x >= 200000) group = 'Q';
  else if(x >= 100000) group = 'M';
  else if(x >= 50000) group = 'A';
  else if(x >= 20000) group = 'R';
  else group = 'P';
  return(group);
}

float getmyTax(char c, float t) {
  float tax = 0;
  if(c == 'S' || c == 'Q') tax = t * 0.25;
  else if(c == 'M') tax = t * 0.10;
  else if(c == 'A' || c == 'R') tax = t * 0.03;
  else return(tax);
  if(tax > 50000) tax = 50000;
  return(tax);
}

float getmyTaxableIncome(float x) {
  if(x > 0) return(x);
  else return(0);
}

int main(void) {
  float difference = input();
  float taxableincome = getmyTaxableIncome(difference);
  printf("Taxable Income\t: $%.2f",taxableincome);
  char taxgroup = Group(taxableincome);
  printf("\nTax Group\t: %c",taxgroup);
  float tax = getmyTax(taxgroup, taxableincome);
  printf("\nTax Owed\t: $%.2f\n",tax);
  return(EXIT_SUCCESS);
}
