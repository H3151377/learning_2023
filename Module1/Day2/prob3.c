#include<stdio.h>
int main(){
    int i,n,a[50],sum=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter the Array values: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    printf("Alternate Sum = ");
    for(i=0;i<n;i+=2)
    sum = sum + a[i];

    printf("%d",sum);
    return 0;

}