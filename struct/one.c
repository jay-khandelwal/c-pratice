#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student *get_std_prt();

struct student
{
    char name[10];
    int age;
};

int main()
{
    struct student *student;
    student = get_std_prt();
    puts(student->name);
    return 0;
}

struct student *get_std_prt()
{
    struct student *student1 = malloc(sizeof(struct student));
    student1->age = 20;
    strcpy(student1->name, "jay");
    return student1;
}



/*

we cannot do this belos thing as we are returnig the struct pointer
bcz after returning from this fuction we cannot use this struct `student1`
bvz it is a local varaible.
thats why if we have to pass any pointer to another we must have to use malloc or calloc 
so that dynamical memorty get allocated and event after exiting from this function data won't get deleted.

struct student *get_std_prt()
{
    struct student student1 = {"jay", 22};
    return &student1;
}
*/