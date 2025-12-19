// concatenate two strings with comments and withou function
#include <stdio.h>

int main() {
    char str1[20], str2[20];
    int i, j;

    printf("enter first string: ");
    scanf("%s", str1);

    printf("enter second string: ");
    scanf("%s", str2);

    // find the end of the first string
    for(i=0; str1[i]!='\0'; i++);

    // append a space between the two strings
    str1[i] = ' ';
    i++;

    // append the second string to the first
    for(j=0; str2[j]!='\0'; j++, i++);
    str1[i] = '\0';

    printf("concatenated string: %s\n", str1);

    return 0;
}