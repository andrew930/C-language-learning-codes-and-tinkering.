#include <stdio.h>
#include <string.h>

int main(){
    char choice[50];
    
    printf("True or False\n");
    printf("Is it true that Dennis Ritchie made the C language?\n");
    printf("Answer: ");scanf("%s", choice);
    
    if(strcmp(choice, "True") ==0){
        printf("\nYour answer is correct");scanf("%s", &choice);
    }
    else if(strcmp(choice, "False")==0){
        printf("Your answer is wrong dennis ritchie made the C languge\n");scanf("%s", &choice);
    }
    else{printf("\nInvalid answer");}
}