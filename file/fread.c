#include <stdio.h>
#include <stdlib.h>

int main(){
    char *buffer;
    FILE *fptr;
    long file_size;

    fptr = fopen("test.txt", "rb");

    fseek(fptr, SEEK_SET, SEEK_END);
    file_size = ftell(fptr);
    rewind(fptr);

    printf("%lu \n", file_size);

    buffer = (char*) malloc(sizeof(char)*file_size);

    fread(buffer, 1, file_size, fptr);

    fclose(fptr);

    printf("%s \n", buffer);

    return 0;
}