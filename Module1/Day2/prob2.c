#include<stdio.h>

void fun(int* ptr1, int* ptr2){
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int a,b;
    printf("Enter A and B: ");
    scanf("%d %d",&a,&b);
    fun(&a,&b);
    printf("After swaping\nA = %d \nB = %d ",a,b);
}