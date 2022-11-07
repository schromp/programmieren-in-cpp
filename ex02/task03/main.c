#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute(char *str);

/**
 * @brief main method which runs in a loop until compute exits. every loop promts for a input and gives params to compute
 *
 * @return int
 */
int main(void)
{

    while (1)
    {
        int x;
        int y;
        char op;

        printf("Enter <int> <op> <int>, single '0' to exit: ");
        char input[128];
        fgets(input, 16, stdin);
        compute(input);
    }
}

/**
 * @brief converts the input string into values, checks if input has valid format and then prints the result or exits the program
 *
 * @param str the input string
 */
void compute(char *str)
{

    int x;
    int y;
    char op;
    char additional_input;

    int ret = sscanf(str, "%d %c %d %s", &x, &op, &y, &additional_input);

    if (ret == 1 && x == 0)
    {
        printf("Goodbye\n");
        exit(0);
    }
    else if (ret == 3)
    {
        switch (op)
        {
        case '+':
            printf("%d %c %d = %d\n", x, op, y, x + y);
            break;
        case '-':
            printf("%d %c %d = %d\n", x, op, y, x - y);
            break;
        case '*':
            printf("%d %c %d = %d\n", x, op, y, x * y);
            break;
        case '/':
            if (y == 0)
            {
                printf("invalid input\n");
            }
            else
            {
                printf("%d %c %d = %d\n", x, op, y, x / y);
            }
            break;
        default:
            printf("invalid input\n");
        }
    }
    else
    {
        printf("invalid input\n");
    }
}