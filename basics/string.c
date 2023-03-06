#include <stdio.h>

void strPrinter1(char str[]);
void strInput(char str[]);

int main(){
    // string can be declared & initiate in following ways :-

    // declare
    char str[30];

    // declare & initiate together using []
    char str1[] = "jay khandelwal";

    // declare & initiate together using pointer(*)
    char *str2 = "hello world";
    //reinitializing
    str2 = "hello universe";


    /*
    Note| we cannot reinitiate string if we declare it using `[]`
    */
   /*-------XX-------XX-------*/


   // we can print string in following ways :-

   // way 1
   printf("printing str2 :- %s \n", str1);

   //way 2
   puts(str2);

   // way 3
   strPrinter1(str1);
   strPrinter1(str2);

    /*-------XX-------XX-------*/


    // we can take input in following ways :- 

    // way 1
    // scanf("%s", str1);

    // way 2; now obsolute, dangours to use; security issue
    // gets(str1);  

    // way 3
    // fgets(str, 30, stdin);

    //way 4
    // strInput(str);
    
    // strPrinter1(str);

    return 0;
}



void strPrinter1(char str[]){
    printf("str printer 1 :- ");
    // for (int i=0; str[i]!='\0'; i++){
    for (int i=0; str[i]!='\0'; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}

void strInput(char str[]){
    char temp;
    int i=0;
    while (temp!='\n')
    {
        scanf("%c", &temp);
        str[i] = temp;
        i++;
    }
    str[i] = '\0';
    strPrinter1(str);
}