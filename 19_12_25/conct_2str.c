#include <stdio.h>

int main() {
    char str1[20], str2[20];
    int i, j;

    printf("enter first string: ");
    scanf("%s", str1);

    printf("enter second string: ");
    scanf("%s", str2);

    // find end of first string
    for(i = 0; str1[i] != '\0'; i++);

    // add space
    str1[i] = ' ';
    i++;

    // copy second string
    for(j = 0; str2[j] != '\0'; j++, i++) {
        str1[i] = str2[j];
    }

    // add null terminator
    str1[i] = '\0';

    printf("concatenated string: %s\n", str1);
    return 0;
}
