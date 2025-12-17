#include <stdio.h>
#include <stdint.h>

struct Register {
    uint16_t error_flag   : 1;
    uint16_t warning_flag : 1;
    uint16_t mode         : 2;
    uint16_t command      : 4;
    uint16_t data_ready   : 1;
    uint16_t checksum     : 7;
};

union RegData {
    uint16_t value;        // full 16-bit register
    struct Register bits;  // individual fields
};

int main() {
    union RegData reg;

    // Example 16-bit value
    reg.value = 0xA5B3;   // any 16-bit data

    printf("Register value = 0x%X\n\n", reg.value);

    printf("Error Flag   : %u\n", reg.bits.error_flag);
    printf("Warning Flag : %u\n", reg.bits.warning_flag);
    printf("Mode         : %u\n", reg.bits.mode);
    printf("Command      : %u\n", reg.bits.command);
    printf("Data Ready   : %u\n", reg.bits.data_ready);
    printf("Checksum     : %u\n", reg.bits.checksum);

    return 0;
}
