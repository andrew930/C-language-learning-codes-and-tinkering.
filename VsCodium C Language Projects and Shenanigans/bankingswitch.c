#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    int amount;
    int balance = 1000;
    int choice = (1, 2);

    fptr = fopen ("bank_account_details.txt", "r");
    if (fptr != NULL){
        fscanf(fptr, "balance: %d", &balance);
        fclose(fptr);
    }

    printf("Welcome to Bank of the Philippines");
    printf("\nYour current account balance is: %d", balance);
    printf("\nWould you like to deposit or withdraw?");
    printf("\n(1) for deposit and (2) for withdrawal");
    printf("\nInput here: ");scanf("%d", &choice);

    switch(choice){
        case 1:
        printf("Enter amount for deposit here: ");
        scanf("%d", &amount);
        balance = balance + amount;
        printf("Transaction is successful!");
        break;
        
        case 2:
        printf("Enter amount for withdrawal here: ");
        scanf("%d", &amount);
        balance = balance - amount;
        printf("Transaction is successful!");
        break;
    }

    fptr = fopen ("bank_account_details.txt", "w");
    if (fptr == NULL){printf("Error in saving account balance file!\n");return 1;}
    fprintf(fptr, "balance: %d", balance);
    fclose(fptr);

    printf("\nTotal money after deposit: %d", balance);
    return 0;
}