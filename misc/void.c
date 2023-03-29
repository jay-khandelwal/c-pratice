#include <stdio.h>

void abc(int *a);
void pqr(float *a);

int main(){

    int a = 10;
    int *ptr = &a;

    pqr(abc(ptr));

    return 0;
}


void abc(int *a){
    return (void *)a;
}


void pqr(float *a){
    printf("float value is :- %f", *a);
}