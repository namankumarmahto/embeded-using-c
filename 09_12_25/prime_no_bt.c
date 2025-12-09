#include <stdio.h>

int main() {
    int start, end, num, i, isPrime;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (num = start; num <= end; num++) {
        if (num <= 1)
            continue;

        isPrime = 1;

        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1)
            printf("%d ", num);
    }

    printf("\n");
    return 0;
}
