#include <stdio.h>
// #include <json-c/json.h>

#define num 8

void selection_sort(int arr[]);
void swap(int *a, int *b);
void print_arr(int arr[]);


int main(){
    int arr[num];

    for (int i=0; i<num; i++){
        printf("Enter no. %d :- ", i+1);
        scanf("%i", &arr[i]);
    }

    print_arr(arr);

    selection_sort(arr);

    print_arr(arr);



    return 0;
}

void selection_sort(int arr[]){
    for (int i=0; i<num; i++){
        for (int j=i+1; j<num-1; j++){
            if (arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
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