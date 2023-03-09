#include <stdio.h>
#include <string.h>
#include "string.c"



struct Employee
{
    char name[30];
    int age;
};

typedef struct Student
{
    char name[30];
    int age;
    char gender;
} stud;

void inputStudentData(stud students[]);
void printStudentData(stud students[], int no_of_student);
void printStudent(stud student);


int main(){
    struct Employee emp1={"jay", 22};
    stud student1;
    stud students[40];
    
    printf("%d \n", emp1.age);

    printf("struct address :- %p \n", &student1);
    printf("struct name addr :- %p \n", &student1.name);
    printf("struct age addr :- %p \n", &student1.age);

    inputStudentData(students);

    strcpy(student1.name, "jay");
    student1.age = 22;
    student1.gender = 'M';

    printStudent(student1);


    /* structure using pointers */
    // stud *student2;

    // // strcpy(student2->name, "jk");
    // student2->age = 24;
    // student2->gender = 'm';


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
        printf("Enter student gender :-");
        scanf("%c", &students[i].gender);
        // students[i].gender=getchar();
        // scanf("%c", &students->gender);
    }

    printStudentData(students, no_of_student);

}

void printStudent(stud student){
    printf("name :- %s \n", student.name);
    printf("age :- %d \n", student.age);

}

void printStudentData(stud students[], int no_of_student){
    for (int i=0; i<no_of_student; i++){
        printf("name :- %s \n", students[i].name);
        printf("age :- %d \n", students[i].age);
        // printf("gender :- %c \n", students[i].gender);
    }
}
