#include <stdio.h>

//best way
#include "way1.h"

// Not good as way 1, but good
extern int way2_counter;

/*
Not a good way.
It is not a good pratice to include `.c` file directly
bcz let suppose we need `way3_counter` in 3 `.c` files.
then if we use this way (of directly including `.c` file), then in eact of 3 `.c` files 
that included `.c` file get attached, which lead to larger object files and longer compilation times, because the implementation code will be compiled multiple times.  

`check docs/header_vs_c_file.md for more detail`
*/
#include "way3.c"


int main(){
    printf("way 1 counter before increment :- %d \n", way1_counter);
    way1_counter++;
    printf("way 1 counter after increment :- %d \n", way1_counter);

    printf("way 2 counter before increment :- %d \n", way2_counter);
    way2_counter++;
    printf("way 2 counter after increment :- %d \n", way2_counter);

    printf("way 3 counter before increment :- %d \n", way3_counter);
    way3_counter++;
    printf("way 3 counter after increment :- %d \n", way3_counter);

    return 0;
}