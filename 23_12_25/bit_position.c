#include<stdio.h>

void set_btw_pos(unsigned int i,int pos1,int pos2){
    unsigned int cnt=32;
    unsigned count = 1<<31;
    for(;cnt!=0;cnt--){
        if ((cnt<=pos1) && (cnt>=pos2)) {
            i= i|(1<<cnt);
        }
    }
    cnt=32;
    for (;cnt>0;cnt--) {
        (i&count)?printf("1"):printf("0");
        count=count>>1;
    }
    printf("\n");
}

int main(){
    unsigned int i =45;
    set_btw_pos(i,11,5);
}