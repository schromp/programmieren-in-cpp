#include <stdio.h>

int globalvar = 1;

void modtest(void);

int main() {
    modtest();
    printf("globalvar = %d\n", globalvar);
}