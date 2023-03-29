#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student *get_std_prt(char name[10], int age, struct student *parent);
void struct_printer(struct student *std);
struct student *get_parent(struct student *curr);

struct student
{
    char name[10];
    int age;
    struct student *parent;
};

int main()
{
    struct student *student_curr;
    student_curr = get_std_prt("jay", 22, NULL);
    student_curr = get_std_prt("jay kh1", 22.5, student_curr);
    struct_printer(student_curr);
    student_curr = get_parent(student_curr);
    struct_printer(student_curr);
    // struct_printer(student_curr.);
    free(student_curr);
    return 0;
}

struct student *get_std_prt(char name[10], int age, struct student *parent)
{
    struct student *student1 = malloc(sizeof(struct student));
    if (parent!=NULL){
    student1->age = parent->age+10;
    }else{
    student1->age = age;

    }
    strcpy(student1->name, name);
    student1->parent = parent;
    return student1;
}

void struct_printer(struct student *std){
    if (std->parent!=NULL){
        struct_printer(std->parent);
    }
    puts(std->name);
    printf("%d \n", std->age);
}

struct student *get_parent(struct student *curr){
    struct student *student1 = curr->parent;
    free(curr);
    return student1;
}