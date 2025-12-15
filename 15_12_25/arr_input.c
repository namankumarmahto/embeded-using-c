// Q: Write a C program to take 5 integer inputs, store them in an array, and print them.

#include <stdio.h>

int main() {
    int a[5];

    // Taking input
    printf("Enter 5 integers:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    // Printing array elements
    printf("Array elements are:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}