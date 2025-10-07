#include <stdio.h>
#include <string.h>

int main(){
    char *characters[3] = {"Peter", "Jean", "Diavolo"};
    char input[20];
    
    printf("Choose your characters from the 3:");
    printf("\nPeter");
    printf("\nJean");
    printf("\nDiavolo");
    printf("\nInput: ");scanf("%s", &input);
    
    if(strcmp(input, "Peter")==0){
        printf("You've chosen Peter\n");
    }
    else if(strcmp(input, "Jean")==0){
        printf("You've chosen Jean\n");
    }
    else if(strcmp(input, "Diavolo")==0){
        printf("You've chosen Diavolo\n");
    }
    else{
        printf("Invalid choice\n");
    }
    return 0;
}   