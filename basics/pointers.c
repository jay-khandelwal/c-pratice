#include <stdio.h>

void printer(int* arr, int len){

    for (int i=0; i<len; i++){
        printf("%p\n", (arr+i));
    }

    printf("[");
    for (int i=0; i<len; i++){
        printf("%d, ", *arr+i);
    }
    printf("]\n");
}

int main()
{
    int i = 5;
    int* ip = &i;
    int** ipp = &ip;
    int*** ipp2 = &ipp;
    // and so on ....

    printf("i ki value %d :-\n", i);
    printf("i ki value %d :-\n", *ip);
    printf("i ka address %p :-\n", ip);
    printf("i ka address %p :-\n", &i);

    printf("ip ka address %p :-\n", &ip);
    printf("ip ka address %p :-\n", ipp);
    printf("ipp ka address %p :-\n", ipp2);

    int arr1[] = {3,5,74,3,5,7,5};

    int arr1_len = sizeof(arr1)/sizeof(int);
    printer(arr1, arr1_len);

    // timepass
    printf("%d\n",*(ip+sizeof(int)));

    return 0;
}