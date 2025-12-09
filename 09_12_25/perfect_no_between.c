#include <stdio.h>

int main() {
    int start, end, num, i, sum;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("\nPerfect numbers between %d and %d are:\n", start, end);

    for (num = start; num <= end; num++) {
        sum = 0;

        for (i = 1; i < num; i++) {
            if (num % i == 0) {
                sum = sum + i;
            }
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
