#include <stdio.h>

int globalvar = 1;

void modtest(void);

/**
 * @brief Main method changing globalvar and printing globalvar
 * 
 * @return int 
 */
int main() {
    modtest();
    printf("globalvar = %d\n", globalvar);
}