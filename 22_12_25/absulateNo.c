#include <stdio.h>
int absolute(int n) {
    if (n < 0)
        return -n;
    else
        return n;
}
int main() {
    int no, result;

    printf("Enter a number: ");
    scanf("%d", &no);
    result = absolute(no);   
    printf("The absolute value of %d is %d\n", no, result);
    return 0;
}
