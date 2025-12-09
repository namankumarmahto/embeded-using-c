#include <stdio.h>

// Method 5: Using Function (Call by Reference)
void swapByFunction(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b, temp;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    //  Method 1: Using Temporary Variable
    printf("\n1. Swapping using Temporary Variable:\n");
    temp = a;
    a = b;
    b = temp;
    printf("a = %d, b = %d\n", a, b);

    // Reset values
    scanf("%d %d", &a, &b);

    //  Method 2: Using Addition & Subtraction
    printf("\n2. Swapping without Temp (Using + and -):\n");
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d, b = %d\n", a, b);

    // Reset values
    scanf("%d %d", &a, &b);

    //  Method 3: Using Multiplication & Division
    printf("\n3. Swapping without Temp (Using * and /):\n");
    a = a * b;
    b = a / b;
    a = a / b;
    printf("a = %d, b = %d\n", a, b);

    // Reset values
    scanf("%d %d", &a, &b);

    //  Method 4: Using XOR
    printf("\n4. Swapping using XOR:\n");
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);

    // Reset values
    scanf("%d %d", &a, &b);

    //  Method 5: Using Function
    printf("\n5. Swapping using Function:\n");
    swapByFunction(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
