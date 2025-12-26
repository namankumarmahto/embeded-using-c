#include <stdio.h>

int main() {

    int i = 4;
    int *ptr = &i;
    //%p,u,x,X
    printf("Address of i: %p\n", &i);
    printf("Address of ptr: %p\n", &ptr);
    printf("Value of i: %d\n", i);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
}
//write a  code to set 5th bit of a number without effecting other bits