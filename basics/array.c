#include <stdio.h>
#include <stdlib.h>

void printer(int* arr, int len){

    for (int i=0; i<len; i++){
        printf("%p, ", (arr+i));
    }

    printf("[");
    for (int i=0; i<len; i++){
        printf("%d, ", *arr+i);
    }
    printf("]\n");
}

int main()
{
    int arr1[] = {3,5,74,3,5,7,5};

    int arr1_len = sizeof(arr1)/sizeof(int);
    printer(arr1, arr1_len);

    int arr2[5];
    int arr2_len = sizeof(arr2)/sizeof(int);

    for (int i=0; i<arr2_len; i++){
        arr2[i] =  rand();
    }

    printer(arr2, arr2_len);

    return 0;
}