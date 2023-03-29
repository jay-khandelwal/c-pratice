#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *buffer = malloc(50);
    char *buffer2 = malloc(10);

    char *c1, *c2;


    strcpy(buffer, "jay khandelwa sizeof’ on array functwit]");

    for (int i = 0; i < strlen(buffer); i++)
    {
        printf("%d - %c \n", i, buffer[i]);
    }
    

    c1 = buffer+10;
    c2 = buffer+15;

    // printf("%s \n", c2-c1);

    strncpy(buffer2, c1, c2-c1);

    buffer2[c2-c1] = '\0';

    puts(buffer2);

    printf("%c \n", *(c1+2));

    return 0;
}