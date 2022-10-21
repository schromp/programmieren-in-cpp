#include <stdio.h>

void printsizes();

/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    int cube1[3][2][4] = {{{1, 2, 3, 4}}, {{2, 3}, {4, 6, 8, 10}}, {{3, 4, 5, 6}, {6, 8, 10}}};

    printf("char %lu\n", sizeof(cube1));

    printf("Big Steps: \n");

    printf("ptr=%d\n", &cube1[0][0][0]);
    printf("ptr=%d\n", &cube1[1][0][0]);
    printf("ptr=%d\n", &cube1[2][0][0]);

    printf("Medium Steps: \n");

    printf("ptr=%d\n", &cube1[0][0][0]);
    printf("ptr=%d\n", &cube1[0][1][0]);
    printf("ptr=%d\n", &cube1[0][2][0]);
    printf("ptr=%d\n", &cube1[0][3][0]);

    printf("Small: Steps: \n");

    printf("First \n");
    
    printf("ptr=%d\n", &cube1[0][0][0]);
    printf("ptr=%d\n", &cube1[0][0][1]);
    printf("ptr=%d\n", &cube1[0][0][2]);
    printf("ptr=%d\n", &cube1[0][0][3]);

    printf("Second: \n");

    printf("ptr=%d\n", &cube1[1][0][0]);
    printf("ptr=%d\n", &cube1[1][0][1]);
    printf("ptr=%d\n", &cube1[1][1][0]);
    printf("ptr=%d\n", &cube1[1][1][1]);
    printf("ptr=%d\n", &cube1[1][1][2]);
    printf("ptr=%d\n", &cube1[1][1][3]);

    printf("Third \n");

    printf("ptr=%d\n", &cube1[2][0][0]);
    printf("ptr=%d\n", &cube1[2][0][1]);
    printf("ptr=%d\n", &cube1[2][0][2]);
    printf("ptr=%d\n", &cube1[2][0][3]);
    printf("ptr=%d\n", &cube1[2][1][0]);
    printf("ptr=%d\n", &cube1[2][1][1]);
    printf("ptr=%d\n", &cube1[2][1][2]);

    return 0;
}