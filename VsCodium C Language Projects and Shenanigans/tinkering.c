#include <stdio.h>
#include <string.h>

int main(){
    int balance = 1000;
    int amount;
    char choice[30];

    printf("This is the Philippines Bank\n");
    printf("Your current account balance is: %d\n", balance);
    printf("Do you want to Deposit or Withdraw?\n");
    printf("Type it in here: \n");scanf("%s", &choice);

    if(strcmp(choice, "Deposit") ==0 || strcmp(choice, "deposit") == 0){
        printf("\nEnter amount: ");scanf("%d", &amount);balance=balance+amount;
        printf("\n Transaction complete");
    }
    else if(strcmp(choice, "Withdraw") ==0 || strcmp(choice, "withdraw") ==0) {
        printf("\nEnter amount; ");scanf("%d", &amount);if(amount <= balance){
        balance=balance-amount;
        printf("\nTransaction complete");}
        else{printf("\n Insufficient Funds ");}}
    else{printf("\nInvalid choice");}
    

    printf("The account total balance now is: %d\n", balance);
}