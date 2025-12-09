#include <stdio.h>

int main() {
    int num, temp, i;
    int octal[20], hexa[20];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    /* -------- Decimal to Octal -------- */
    temp = num;
    i = 0;

    while (temp > 0) {
        octal[i] = temp % 8;   // remainder for base 8
        temp = temp / 8;
        i++;
    }

    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }

    /* -------- Decimal to Hexadecimal -------- */
    temp = num;
    i = 0;

    while (temp > 0) {
        hexa[i] = temp % 16;   // remainder for base 16
        temp = temp / 16;
        i++;
    }

    printf("\nHexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        if (hexa[j] < 10)
            printf("%d", hexa[j]);       // 0–9
        else
            printf("%c", hexa[j] + 55); // 10–15 → A–F
    }

    printf("\n");

    return 0;
}
