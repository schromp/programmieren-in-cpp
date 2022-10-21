#include <stdio.h>

int getLengthWithCounter();
int getLengthOnlyPointers();

/**
 * @brief main method calling the length methods with the parameters from the command line
 *
 * @param argc the amount of parameters provided by the user calling the problem
 * @param argv the parameters provided
 * @return int exit code
 */
int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        printf("%d\n", getLengthWithCounter(argv[1]));
        printf("%d\n", getLengthOnlyPointers(argv[1]));
        return 0;
    }
    else
    {
        printf("wrong input\n");
        return -1;
    }
}

/**
 * @brief get the length of the String while using a integer as a counter
 *
 * the method takes a pointer as input because copying the string would be unnecessary
 *
 * This method only works with standard ascii characters as they are 1 byte long
 * Non standard ascii characters are longer than 1 byte
 *
 * @param input a pointer to the string that is being input
 * @return int the length of the input
 */
int getLengthWithCounter(char *input)
{
    int sum = 0;
    while (*input != '\0')
    {
        sum++;
        input++;
    }
    return sum;
}

/**
 * @brief get the length of the String while only using pointer arithmetics
 *
 * the method takes a pointer as input because copying the string would be unnecessary
 *
 * This method only works with standard ascii characters as they are 1 byte long
 * Non standard ascii characters are longer than 1 byte
 *
 * at the return there the value is being multiplied by -1 because the subtracting the pointers returns a negative number due to how the stack works
 * 
 * @param input a pointer to the string that is being input
 * @return int the length of the input
 */
int getLengthOnlyPointers(char *input)
{
    char *pointer2 = input;

    while (*input != '\0')
    {
        input++;
    }

    return (pointer2 - input) * -1;
}