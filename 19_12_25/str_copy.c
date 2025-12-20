#include <stdio.h>

int main() {
    char str1[20];
    char str2[20] = "Hello";

    char *src = str2;   // pointer to source
    char *dest = str1; // pointer to destination

    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';   // end string1

    printf("String1: %s\n", str1);
    return 0;
}
