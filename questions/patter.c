#include <stdio.h>

int main(){
    int i;
    printf("enter the number :- ");
    scanf("%i", &i);

    for (int n=0; n<i; n++){
        for (int m=0; m<=n; m++){
            printf("%i", m+1);
        }
        printf("\n");
    }

    return 0;
}