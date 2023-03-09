#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>
#include "lib.h"

#define FileNameSize 31
#define ActionRead 'r'
#define ActionWrite 'w'
#define ActionReadChar 'c'
#define ActionReadStr 's'
#define ActionWriteLine 'l'
#define ActionWritePara 'p'
#define ActionWriteString 's'

const char ActionARR[] = {ActionRead, ActionWrite};
const char ActionReadARR[] = {ActionReadChar, ActionReadStr};
const char ActionWriteARR[] = {ActionWriteLine, ActionWritePara, ActionWriteString};

char ask_choice(char choice_arr[]);
void readAction(FILE *fptr);
void writeAction(FILE *fptr);
void readFileByChar(FILE *fptr);
void readFileByString(FILE *fptr, int str_at_a_time);
void writeByLine(FILE *fptr);
void writeByParagraph(FILE *fptr);

int main()
{
    FILE *fptr;
    char quit;
    char action;
    char file_name[FileNameSize] = "jk.html";

    printf("Enter file name (max name length %d) :- ", FileNameSize - 1);
    scanf("%s", file_name);

    /*
    fgets(file_name, FileNameSize, stdin);

    we cannot use this above func. for taking input from user.
    As this is adding some spaces in the end (or may be something else)
    to the string.
    As a result, file gets created with name something like `test.html ` (space in the last)
    which is diffrent from `test.html`
    */

    // creating file
    createFile(file_name); 

    while (quit != 'q')
    {
        printf("want to read or write to a file (r/w) \n");
        action = ask_choice(ActionARR);

        switch (action)
        {
        case ActionRead:
            fptr = fopen(file_name, "r");
            readAction(fptr);
            fclose(fptr);
            break;
        case ActionWrite:
            fptr = fopen(file_name, "a");
            writeAction(fptr);
            fclose(fptr);
            break;
        default:
            break;
        }
        printf("press c to continue & q to quit :-");
        scanf(" %c", &quit);
    }

    // system("cat jk.html");
    // system("PAUSE");

    return 0;
}

char ask_choice(char choice_arr[])
{
    char choice;
    int arr_len;
    int choice_exits_flat = 0;

    printf("Enter :- ");
    scanf(" %c", &choice);

    arr_len = sizeof(choice_arr) / sizeof(char);

    for (int i = 0; i < arr_len; i++)
    {
        if (choice == choice_arr[i])
        {
            choice_exits_flat = 1;
            break;
        }
    }

    if (choice_exits_flat != 1)
    {
        ask_choice(choice_arr);
    }

    return choice;
}

void readAction(FILE *fptr)
{
    char read_action;
    int str_at_a_time;

    printf("read by character or by string (c/s) \n");
    read_action = ask_choice(ActionReadARR);
    switch (read_action)
    {
    case ActionReadChar:
        readFileByChar(fptr);
        break;
    case ActionReadStr:
        printf("Enter max number of character you want to fetch at a time :- ");
        scanf(" %d", &str_at_a_time);
        readFileByString(fptr, str_at_a_time);
        break;
    default:
        printf("the action is :- %c \n", read_action);
        break;
    }
}

void writeAction(FILE *fptr)
{
    char write_action;
    int str_at_a_time;

    printf("read in line or in paragraph (l/p) \n");
    write_action = ask_choice(ActionWriteARR);
    switch (write_action)
    {
    case ActionWriteLine:
        writeByLine(fptr);
        break;
    case ActionWritePara:
        writeByParagraph(fptr);
        break;
    default:
        printf("the action is :- %c \n", write_action);
        break;
    }
}

void readFileByChar(FILE *fptr)
{
    char ch;
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fptr);
    }
    printf("\n");
}

void readFileByString(FILE *fptr, int str_at_a_time)
{
    char str[str_at_a_time];
    char loop_count = 0;

    while (fgets(str, str_at_a_time, fptr) != NULL)
    {
        printf("%s", str);
        loop_count++;
    }
    printf("\n");

    printf("total %d iteration needed to fetch this file data, %d string at a time. \n", loop_count, str_at_a_time);
}

void writeByLine(FILE *fptr)
{
    char str[100];
    printf("Enter the line :- ");
    fgets(str, 100, stdin);
    fgets(str, 100, stdin);
    fputs(str, fptr);
}

void writeByParagraph(FILE *fptr)
{
    char ch;
    int get_null = 0;
    printf("Enter the paragraph :- ");
    scanf("%c", &ch);
    ch = getchar();

    while (get_null != 2)
    {
        fputc(ch, fptr);
        if (ch == '\n')
        {
            if (get_null == 1)
            {
                break;
            }
            get_null++;
        }
        else
        {
            get_null = 0;
        }
        ch = getchar();
    }
}