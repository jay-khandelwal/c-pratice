#include <stdio.h>

int main()
{
    int i = 1;

    // normal if else
    if (i == 0)
    {
        printf("varible i is 0\n");
    }
    else if (i = 1)
    {
        printf("varible i is 1\n");
    }
    else
    {
        printf("variable i is not 0 neither 1\n");
    }

    // Ternary Operator
    (i==0) ? printf("varible i is 0\n") : printf("variable i is not 0\n");

    return 0;
};