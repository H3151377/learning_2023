#include<stdio.h>

int fun(int i, int j) {
    int z;
    (i > j) ? (z = i) : (z = j);
    return z;
}

int main() {
    int a, b;
    printf("Value of A: ");
    scanf("%d", &a);
    printf("Value of B: ");
    scanf("%d", &b);
    int x = fun(a, b);
    printf("Greater number is: %d", x);
    return 0;
}
