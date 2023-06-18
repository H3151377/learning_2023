#include <stdio.h>

void bits(unsigned int num) {
    int i;
    unsigned int m= 1<<31;
    for(i=0;i<32;i++){
        if ((num&m)!=0)
            printf("1");
        else
            printf("0");
        m>>=1;
    }
    printf("\n");
}
int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d",&num);
    printf("Bits of the 32-bit integer is: ");
    bits(num);
    return 0;
}
