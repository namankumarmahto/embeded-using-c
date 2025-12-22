#include <stdio.h>

#define SIZE 5

// set function: sets value at given position
void setValue(int arr[], int pos, int value) {
    if (pos >= 0 && pos < SIZE) {
        arr[pos] = value;
    } else {
        printf("Invalid position\n");
    }
}

// get function: returns value from given position
int getValue(int arr[], int pos) {
    if (pos >= 0 && pos < SIZE) {
        return arr[pos];
    } else {
        printf("Invalid position\n");
        return -1;
    }
}

int main() {
    int arr[SIZE] = {0};
    int pos, value;

    // set value
    printf("Enter position (0 to 4): ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &value);

    setValue(arr, pos, value);

    // get value
    printf("Value at position %d is %d\n", pos, getValue(arr, pos));

    return 0;
}
