#include <stdio.h>
int del(int n) {
    int l=0;
    int num=n;
    int div=1;
    while (div<=num) {
        int rem= (num/(div*10))*div+ (num% div);
        if (rem> l) {
            l = rem;
        }
        div *= 10;
    }

    return l;
}
int main() {
    int n,l,Lar;
    printf("Enter a n value: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("\nEnter 4 digit numbers:");
    scanf("%d",&l);
    if (l<1000||l>9999) {
    printf("\nNot a 4 digit number");
    }
    else{
        Lar=del(l);
        printf("\nafter deleting: %d",Lar);
    }
    }
    return 0;
}