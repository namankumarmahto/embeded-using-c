#include <stdio.h>

int main() {
    int num;

    printf("Enter a number (1 to 3000): ");
    scanf("%d", &num);

    if (num <= 0 || num > 3000) {
        printf("Invalid input! Enter number between 1 and 3000.\n");
        return 0;
    }

    while (num >= 1000) {
        printf("M");
        num -= 1000;
    }

    while (num >= 500) {
        printf("D");
        num -= 500;
    }

    while (num >= 100) {
        printf("C");
        num -= 100;
    }

    while (num >= 50) {
        printf("L");
        num -= 50;
    }

    while (num >= 10) {
        printf("X");
        num -= 10;
    }

    while (num >= 5) {
        printf("V");
        num -= 5;
    }

    while (num >= 1) {
        printf("I");
        num -= 1;
    }

    printf("\n");
    return 0;
}
