#include <stdio.h>
#define bitset(byte,nbit)    ((byte) |= (1<<(nbit)))
#define bitclear(byte,nbit)    ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)    ((byte) ^= (1<<(nbit)))
#define bitcheck(byte,nbit)    ((byte) & (1<<(nbit)))



int main(){
    
    int result;
    int i = 255;
    display_binary(i);
    result=bitclear(i,2);
    display_binary(result);
    printf("result =%d\n",result);
}