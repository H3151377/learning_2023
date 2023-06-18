#include <stdio.h>
int delete(int n) {
    int l=0;
    int num=n;
    int divisor=1;
    while (divisor<=num) {
        int rem= (num/(divisor*10))*divisor+ (num% divisor);
        if (rem> l) {
            l = rem;
        }
        divisor *= 10;
    }

    return l;
}
int main() {
    int n,l,large;
    printf("Enter a n value: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("\nEnter 4 digit numbers:");
    scanf("%d",&l);
    if (l<1000||l>9999) {
    printf("\nNot a 4 digit number");
    }
    else{
        large=delete(l);
        printf("\nafter deleting: %d",large);
    }
    }
    return 0;
}