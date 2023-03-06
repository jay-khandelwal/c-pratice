#include <stdio.h>

void createFile(char str[]);
void readFile(char fileName[]);
void WriteToFile(char fileName[]);
void AppendToFile(char fileName[]);
void addLine(FILE *fptr);

int main(){
    char ch;
    char fileName[] = "jay.txt";
    createFile(fileName);
    // readFile(fileName);
    AppendToFile(fileName);
    readFile(fileName);
    
    return 0;
}

void createFile(char fileName[]){
    FILE *fptr;
    fptr = fopen(fileName, "a");
    if (fptr == NULL){
        fptr = fopen(fileName, "w");
    }
    fclose(fptr);
}

void readFile(char fileName[]){
    FILE *fptr;
    char ch;
    fptr = fopen(fileName, "r");
    ch = fgetc(fptr);

    while (ch!=EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
    
}

void WriteToFile(char fileName[]){
    FILE *fptr;
    char ch;
    fptr = fopen(fileName, "w");
    addLine(fptr);
    
}

void AppendToFile(char fileName[]){
    FILE *fptr;
    char ch;
    fptr = fopen(fileName, "a");
    addLine(fptr);
}

void addLine(FILE *fptr){
    char ch;
    while (ch!='\n'){
        scanf("%c", &ch);
        fputc(ch, fptr);
    }
}