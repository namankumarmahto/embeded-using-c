#include <stdio.h>
#define bitset(byte,nbit)    ((byte) |= (1<<(nbit)))
#define bitclear(byte,nbit)    ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)    ((byte) ^= (1<<(nbit)))
#define bitcheck(byte,nbit)    ((byte) & (1<<(nbit)))

void display_binary(unsigned int i){
    unsigned int cnt =32;
    unsigned int count = 1<<31;
    
    for (;cnt>0;cnt--) {
        (i&count)?printf("1"):printf("0");
        count=count>>1;
    }
    printf("\n");
}

int main(){
    int result;
    int i = 255;
    display_binary(i);
    
    result=bitclear(i,2);
    display_binary(result);

    printf("result =%d\n",result);
}