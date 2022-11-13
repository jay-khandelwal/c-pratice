#include <stdio.h>

#define PI = 3.14;

/*
Need to know :-
    unsigned means the variable can hold only a positive value
    sizeof() returns of type unsigned long int
*/

int main()
{
    int int_a = 10;
    printf("int_a value is %d\n", int_a);
    printf("int_a value sizeis %lu\n", sizeof(int_a));

    float float_b = 2.17;
    printf("float_b value is %f\n", float_b);
    printf("float_b value is %0.2f\n", float_b);
    printf("float_b value sizeis %lu\n", sizeof(float_b));

    char char_c = 'j';
    printf("char_c value is %c\n", char_c);
    printf("char_c value sizeis %lu\n", sizeof(char_c));

    char string_d[] = "hello world";
    printf("string_d value is %s\n", string_d);
    printf("string_d value size is %lu\n", sizeof(string_d));
    for (int i=0; i<12; i++){
        printf("%c", string_d[i]);
    };
    printf("\n");

    long int lint_e = 2343464;
    printf("long int value is %ld\n", lint_e);

    long long int llint_e = 234354464;
    printf("long long int value is %lld\n", llint_e);

    double double_f = 2343464.3432;
    printf("double float value is %lf\n", double_f);
    printf("double float value is %0.4lf\n", double_f);

    long double long_double_f = 642343464.3432;
    printf("long double float value is %LF\n", long_double_f);

    unsigned int uint_g = 39223; // can only be a positive integer
    printf("unsigned int value is %u\n", uint_g);

    // other unsigned datatypes:-
    // unsigned long int
    // unsigned long long int
    // unsigned char

    return 0;
}