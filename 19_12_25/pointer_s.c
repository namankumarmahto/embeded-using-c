#include <stdio.h>

size_t strlen_u(const char *str) {
    const char *ptr = str;

    while (*ptr != '\0') {
        ptr++;
    }

    return ptr - str;
}

int main() {
    char s[] = "Hello World";
    printf("Length = %zu\n", strlen_u(s));
    return 0;
}
