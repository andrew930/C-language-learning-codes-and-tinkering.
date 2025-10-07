#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    int balance = 1000;
    int amount;
    char choice[50];

    fptr = fopen ("bank_account_details.txt", "r");
    
    if(fptr != NULL){
    
        fscanf(fptr, "balance = %d", &balance);
    
    fclose(fptr);}

    printf("BPI BANK");
    printf("\nAccount balance: %d", balance);
    printf("\nWould you like to deposit or withdraw?:");scanf("%s", &choice);

    if(strcmp(choice, "Withdraw")==0){printf("Enter amount for withdrawal: ");scanf("%d", &amount);
    balance = balance - amount;printf("Successfully withdrawn!");}
    
    else if(strcmp(choice, "Deposit")==0){printf("Enter amount for deposit: ");scanf("%d", &amount);
    balance = balance + amount;printf("Successfully deposited!");}
   
    else{printf("Invalid option!");}

    fptr = fopen("bank_account_details.txt", "w");
    
    if(fptr == NULL){printf("Error in saving account balance file!\n");return 1;}
    fprintf(fptr, "balance: %d\n", balance);
    fclose(fptr);printf("\nAccount balance saved!");
    printf("\nRemaining balance: %d", balance);
    
    
}