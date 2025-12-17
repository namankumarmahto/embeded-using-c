#include <stdio.h>

union Data {
    int i;
    float f;
    double d;
    char str[20];
};

int main() {
    union Data u;

    printf("Size of int        : %lu bytes\n", sizeof(u.i));
    printf("Size of float      : %lu bytes\n", sizeof(u.f));
    printf("Size of double     : %lu bytes\n", sizeof(u.d));
    printf("Size of char[20]   : %lu bytes\n", sizeof(u.str));

    printf("\nSize of union Data : %lu bytes\n", sizeof(u));

    return 0;
}
