#include <stdio.h>

int main() {
    int num = 10;

    printf("Original number: %d\n", num);

    num |= (1 << 4);
    printf("After setting 5th bit: %d\n", num);

    num &= ~(1 << 4);
    printf("After resetting 5th bit: %d\n", num);

    return 0;
}
