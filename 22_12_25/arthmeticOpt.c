#include<stdio.h>

int add(int num1, int num2){
    return num1 + num2;
}

int subs(int num1, int num2){
    return num1 - num2;
}

int multipy(int num1, int num2){
    return num1 * num2;
}


int main(){
    int num1, num2;
    int choise;
    
    printf("enter 1st no. : ");
    scanf("%d",&num1);

    printf("enter 2nd no. : ");
    scanf("%d",&num2);
    
    printf("enter arthemetic choice\n 1.addition\n2.substraction\n3.multiplication\n : ");
    scanf("%d",&choise);
    // int (*add)(int num1,int num2) addptr;
    // addptr = &add(num1,num2);

    // printf("%d",addptr(4,5));
    
    int (*addptr)(int,int);
    int (*subsptr)(int,int);
    int (*multipyptr)(int,int);
    
    addptr= add;
    subsptr=subs;
    multipyptr=multipy;
    
    switch (choise) {
        
        case 1:{
             printf("addition: %d\n",addptr(num1,num2));
             break;
        }
        case 2:{
            printf("substraction: %d\n",subsptr(num1,num2));
            break;
        }
        case 3:{
            printf("multiplication: %d\n",multipyptr(num1,num2));
            break;
        }
        default:{
            printf("Invalid ");
        }
    
    }
   
    return 0;

}
