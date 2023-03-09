#include <stdio.h>
#include <string.h>
#include "string.c"


typedef struct Student
{
    char name[30];
    int age;
} stud;

void inputStudentData(stud students[]);
void printStudentData(stud students[], int no_of_student);
void updateToAFile(stud students[], int no_of_student, char fileName[]);
void addStrInFile(FILE *fptr, char str[]);
void addIntInFile(FILE *fptr, int age);
void readFile(char fileName[]);


int main(){
    stud students[40];
    inputStudentData(students);

    return 0;
}

void inputStudentData(stud students[]){
    int no_of_student;
    printf("how many students data you wanna add :- ");
    scanf("%d", &no_of_student);

    for (int i=0; i<no_of_student; ++i){
        printf("Enter student name :-");
        scanf("%s", students[i].name);
        printf("Enter student age :-");
        scanf("%d", &students[i].age);
    }

    printStudentData(students, no_of_student);
    updateToAFile(students, no_of_student, "student_data.txt");
    readFile("student_data.txt");

}

void printStudentData(stud students[], int no_of_student){
    for (int i=0; i<no_of_student; i++){
        printf("name :- %s \n", students[i].name);
        printf("age :- %d \n", students[i].age);
    }
}


void updateToAFile(stud students[], int no_of_student, char fileName[]){
    FILE *fptr;
    fptr = fopen(fileName, "a");
    if (fptr==NULL){
        fptr = fopen(fileName, "w");
        fptr = fopen(fileName, "a");
    }
    for (int i=0; i<no_of_student; i++){
        addStrInFile(fptr, students[i].name);
        addIntInFile(fptr, students[i].age);
    }
}

void addStrInFile(FILE *fptr, char str[]){
    int i=0;
    while (str[i]!='\0')
    {
        // fprintf(fptr, "%c \t", str[i]);
        fputc(str[i], fptr);
        i++;
    }
    fputc('\t', fptr);
    
}

void addIntInFile(FILE *fptr, int age){
    fprintf(fptr, "%d\n", age);
}

void fetchFromFile(char fileName[]){
    FILE *fptr;
    fptr = fopen(fileName, "r");

}


// void readFile(char fileName[]){
//     FILE *fptr;
//     char ch;
//     fptr = fopen(fileName, "r");
//     ch = fgetc(fptr);

//     while (ch!=EOF)
//     {
//         printf("%c", ch);
//         ch = fgetc(fptr);
//     }
//     printf("\n");
//     fclose(fptr); 
// }

/*
printf - puts
scanf - gets
*/

void readFile(char fileName[]){
    char str[8];
    FILE *fptr;
    stud students[40];
    
    fptr = fopen(fileName, "r"); 

    // fgets(str, 50, fptr);
    // printf("%s", str);
    // fgets(str, 50, fptr);
    // printf("%s", str);
    // printf("%lu \n", strlen(str));

    // for (int i=0; str[i]!='\0'; i++){
    //     printf("%c \n", str[i]);
    // }

    int run=0;

    // while (str!=NULL)
    while (fgets(str, 8, fptr) != NULL)
    {
        printf("%lu \n", strlen(str));
        printf("%s", str);
        run++;
    }

    printf("loop runs count :- %d \n", run);
    

    
}