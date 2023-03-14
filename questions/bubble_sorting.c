#include <stdio.h>

#define num 10

void bubble_sort(int arr[]);
void swap(int *a, int *b);
void print_arr(int arr[]);


int main(){
    int arr[num];

    for (int i=0; i<num; i++){
        printf("Enter no. %d :- ", i+1);
        scanf("%i", &arr[i]);
    }

    print_arr(arr);

    bubble_sort(arr);

    print_arr(arr);



    return 0;
}

void bubble_sort(int arr[]){
    int sz = num;
    for (int i=sz; i>0; i--){
        for (int j=0; j<i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void print_arr(int arr[]){
    int sz = num;
    printf("[");
    for (int i=0; i<sz; i++){
        printf("%d, ", arr[i]);
    }
    printf("] \n");
}