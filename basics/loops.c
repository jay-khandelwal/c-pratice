#include <stdio.h>

int main(){
    int n = 5;
    int arry[n];

    // for loop
    for (int i=0; i<n; i++){
        printf("Enter value for index %d :- ", i);
        scanf("%d", &arry[i]);
    };

    for (int i=0; i<n; i++){
        printf("%d", arry[i]);
    };
    printf("\n");


    // while loop
    while(0<n){
        --n;
        printf("%d", arry[n]);
    };
    printf("\n");

    return 0;
};