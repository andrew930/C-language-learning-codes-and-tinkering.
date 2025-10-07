#include <stdio.h>

int main() {
    int A;

    printf("Enter a number: ");
    scanf("%d", &A);
    if (A > 15)
    printf("Number is greater than 15");
    else if (A < 15){
        printf("Number is less than 15");
    }
    else{
        printf("Number is 15 or equal to 15");
    }

    return 0;
}