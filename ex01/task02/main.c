#include <stdio.h>

int sum2nd();

/**
 * @brief this is the main function which initializes cube1 and cube2 aswell as prints the results for both in sum2ndk
 * 
 * @return int 
 */
int main(void)
{
    int cube1[3][2][4] = {{{1, 2, 3, 4}},
                          {{2, 3}, {4, 6, 8, 10}},
                          {{3, 4, 5, 6}, {6, 8, 10}}};

    int cube2[2][3][3] = {{{9, 8, 7}, {6}, {5, 4}},
                          {{3, 2}, {1, 2, 3}, {4}}};

    printf("%d\n", sum2nd(&cube1[0][0][0], 3, 2, 4));
    printf("%d\n", sum2nd(&cube2[0][0][0], 2, 3, 3));

    return 0;
}

/**
 * @brief the method takes a pointer to a 3 dimensional array aswell as the dimesions of that array and returns the sum of all seconds in the third dimension
 * 
 * at the beginning the pointer is being put +1 because we want the second values of the third dimension
 * This method loops as long as the length of the array.
 * i only put x+y in the for loop because we are already skipping the z values inside of the loop
 * 
 * @param pointer the pointer to the array
 * @param x the length of the first dimension
 * @param y the length of the second dimension
 * @param z the length of the third dimension
 * @return int the sum of the values
 */
int sum2nd(int *pointer, int x, int y, int z)
{

    int sum = 0;

    pointer++;

    for (int i = 0; i <= (x + y); i++)
    {
        sum += *pointer;
        pointer += z;
    }

    return sum;
}