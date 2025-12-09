#include <stdio.h>

int main() {
    int num, i, flag = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        flag = 0;   // Not prime
    } 
    else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                flag = 0;   // Not prime
                break;
            }
        }
    }

    if (flag == 1)
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is NOT a Prime Number\n", num);

    return 0;
}
