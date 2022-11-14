#include <stdint.h>
#include <stdio.h>

struct pixel_rgb_t {

  int8_t red;
  int8_t green;
  int8_t blue;

};

int main(void) {

    struct pixel_rgb_t pixel;

    printf("%lu\n", sizeof(pixel));
    printf("%lu\n", sizeof(int8_t));

    return 1;
}
