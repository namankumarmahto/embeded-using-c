#include <stdio.h>

int main() {
    int num = 10;

    printf("Original number: %d\n", num);

    num |= (1 << 4);
    printf("After setting 5th bit: %d\n", num);

    num &= ~(1 << 4);
    printf("After resetting 5th bit: %d\n", num);

    return 0;
}


/*
#Algorithm
1.Start
2.Initialize an integer number with the value 10.
3.Display the original value of the number.
4.Set the 5th bit of the number:
     ->Consider the bit position numbering starting from 0 (rightmost bit).
     ->Create a mask that has only the 5th bit set.
     ->Perform a bitwise OR operation between the number and the mask.
     ->This ensures the 5th bit becomes 1, while all other bits remain unchanged.
5.Display the value of the number after setting the 5th bit.
6.Reset the 5th bit of the number:
     ->Use the same mask for the 5th bit.
     ->Invert the mask so that the 5th bit becomes 0 and all others become 1.
     ->Perform a bitwise AND operation between the number and the inverted mask.
     ->This ensures the 5th bit becomes 0, while all other bits remain unchanged.
7.Display the value of the number after resetting the 5th bit.
8.End
 */
