#include <stdio.h>
#include <string.h>

int main(){
    char *name[5] = {"danica", "adamska", "john", "pliskin", "caseoh"};
    char input[20];
    
    printf("Choose who you wanna be partnered with:");
    printf("\ndanica\nadamska\njohn\npliskin\ncaseoh");
    printf("\nWrite it here: ");scanf("%s", &input);
    
    if(strcmp(input, "danica")==0){
        printf("You chose danica as your partner!");}
    else if(strcmp(input, "adamska")==0){
        printf("You chose adamska as your partner!");}
    else if(strcmp(input, "john")==0){
        printf("You chose john as your partner!");}
    else if(strcmp(input, "pliskin")==0){
        printf("You chose pliskin as your partner!");}
    else if(strcmp(input, "caseoh")==0){
        printf("You chose caseoh as your partner!");}
    else{printf("That person isn't on the group or invalid characters");}
}