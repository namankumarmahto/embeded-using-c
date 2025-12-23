#include<stdio.h>
void display_bin(unsigned int i){
    unsigned int cnt =32;
    unsigned int count = 1<<31;
    
    for (;cnt>0;cnt--) {
        (i&count)?printf("1"):printf("0");
        count=count>>1;
    }
}
int main(){
    unsigned int i =45;
    display_bin(i);
}