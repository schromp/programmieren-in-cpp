#include <stdio.h>

/**
 * @brief prints the size of the specified datatypes
 * 
 * @return int exit code for the main function
 */
int main(void)
{
    printf("char %lu\n", sizeof(char));
    printf("short %lu\n", sizeof(short));
    printf("int %lu\n", sizeof(int));
    printf("long %lu\n", sizeof(long));
    printf("long long %lu\n", sizeof(long long));
    printf("float %lu\n", sizeof(float));
    printf("double %lu\n", sizeof(double));
    printf("long double %lu\n", sizeof(long double));
    printf("pointer %lu\n", sizeof(char *));
    return 0;
}