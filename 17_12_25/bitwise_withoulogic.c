#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t data = 123456789;  // example packed data

    int red, green, blue;

    // Extract 10-bit values
    red   = data % 1024;
    green = (data / 1024) % 1024;
    blue  = (data / (1024 * 1024)) % 1024;

    printf("Red   = %d\n", red);
    printf("Green = %d\n", green);
    printf("Blue  = %d\n", blue);

    return 0;
}
