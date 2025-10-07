#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    int balance = 1000;
    int amount;
    char choice[49];
//
    fptr = fopen ("bank_account_details.txt", "r");
    if (fptr != NULL){
        fscanf(fptr, "balance: %d", &balance);
    fclose(fptr);}
//
    printf("Welcome to AEV bank!");
    printf("\nThe account's current balance is %d", balance);
    printf("\nWould you like to Deposit or Withdraw?:");
        scanf("%49s", choice);
//
    if((strcmp(choice, "Deposit")==0) || (strcmp(choice, "deposit")==0 )) {
        printf("Enter here the amount deposit: ");
            scanf("%d", &amount);
                balance = balance + amount;
                    printf("Successfully deposited! Transcation Complete!");
    }
//
    else if((strcmp(choice, "Withdraw")==0) || (strcmp(choice, "withdraw")==0)) {
        printf("Enter here the amount to withdraw: ");
            scanf("%d", &amount);
    if ( balance < amount) {
        printf("\nInsufficient money!");
            return 1;
        }
    else if( amount < 0) {
        printf("\nInvalid amount!");
        }
    else {balance = balance - amount;
        printf("Successfully withdrawn! Transaction Complete!");
        }
    }    
//
    else {
        printf("Invalid choice!");
    }


    fptr = fopen ("bank_account_details.txt", "w");
    if(fptr == NULL) {printf("Error in saving account balance file!\n");return 1;}
    fprintf(fptr, "balance: %d", balance);
    fclose(fptr);
        

    printf("\nRemaining balance: %d\n", balance);
    return 0;
}