#include <stdint.h>
#include <stdio.h>



int main(){
    //2d array
    char arr[3][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
     
    //declare pointer
    char (*ptr)[3] = arr;
    
    //print array using pointer
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
    
    
    
}