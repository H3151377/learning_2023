#include<stdio.h>
int fun(int i, int j){
    if (i>j)
    return i;
    else
    return j;
}

int main(){
    int a,b;
    printf("Value of A: ");
    scanf("%d",&a);
    printf("Value of B: ");
    scanf("%d",&b);
    int x=fun(a,b);
    printf("Greaters number is: %d",x);
}