#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr = malloc(3*sizeof(int));

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;

    for (int i=0; i<3; i++){
        printf("%d \n", ptr[i]);
    }

    ptr = realloc(ptr, 6*sizeof(int));

    ptr[3] = 4;
    ptr[4] = 5;
    ptr[5] = 6;

    for (int i=0; i<6; i++){
        printf("%d \n", ptr[i]);
    }

    free(ptr);
    return 0;
}

