#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t data = 123456789;  // packed data

    uint32_t red, green, blue;
    uint32_t flag1, flag2;

    // Extract 10-bit RGB values
    red   =  data        & 0x3FF;
    green = (data >> 10) & 0x3FF;
    blue  = (data >> 20) & 0x3FF;

    // Extract flags
    flag1 = (data >> 30) & 0x01;
    flag2 = (data >> 31) & 0x01;

    printf("Red   = %u\n", red);
    printf("Green = %u\n", green);
    printf("Blue  = %u\n", blue);
    printf("Flag1 = %u\n", flag1);
    printf("Flag2 = %u\n", flag2);

    return 0;
}
