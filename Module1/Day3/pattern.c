#include <stdio.h>
void RTriangle(int l){
    for(int j=l;j>=1;j--)
    {
        printf("%d",j);  
    }
    printf("\n"); 
}
void spaces(int i){
    for(int k=1;k<=2*(i-1);k++)
    {
        printf(" ");
    }
    
}
void Ltriangle(int n){
    int l=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            printf("%d",n-j+1);
        }
        spaces(i);
        RTriangle(l--);
    }
}
int main()
{
    int n;
    printf("\n Enter value:");
    scanf("%d",&n);
    Ltriangle(n);
    return 0;
}