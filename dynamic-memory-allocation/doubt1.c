#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
conclusion

if we create 1 pointer and dynamically allocate it a memory 
and the create another pointer and dynamically allocate it a memory
and then copy some value of pointer 1 to pointer to may be using strncpy
and then free the pointer 1 . then also we would able to use pointer 2  as 
its value gets copy from pointer 1 not just an address.

*/

int main() {
    char *buffer = malloc(50); // allocate memory for buffer pointer
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    char *char1 = buffer + 10; // assign char1 to buffer + 10
    char *char2 = buffer + 30; // assign char2 to buffer + 30

    // initialize buffer with data
    // for (int i = 0; i < 50; i++) {
    //     buffer[i] = 'a' + i % 26;
    // }

    strcpy(buffer, "jay khandelwa sizeof’ on array functwit]");

    char *newstr = malloc(char2 - char1 + 1); // allocate memory for new string
    if (newstr == NULL) {
        printf("Error: Failed to allocate memory.\n");
        free(buffer);
        return 1;
    }

    strncpy(newstr, char1, char2 - char1); // copy data between char1 and char2 to new string
    newstr[char2 - char1] = '\0'; // null-terminate the new string

    for (int i=0; i<50; i++){
        printf("%lu \n", &buffer[i]);
    }

    free(buffer);
    printf("New string: %s\n", newstr);

    for (int i=0; i<char2 - char1 + 10; i++){
        printf("%lu \n", &newstr[i]);
    }

    free(newstr);

    // free the memory allocated to buffer and newstr

    return 0;
}
