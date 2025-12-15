// Q: Write a C program to multiply two 3x3 matrices and display the result.

#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3];
    int i, j, k;

    // Input first matrix
    printf("Enter elements of first 3x3 matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second 3x3 matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Multiply matrices
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            c[i][j] = 0;
            for(k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print result matrix
    printf("Resultant matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}