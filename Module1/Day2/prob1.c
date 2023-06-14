#include <stdio.h>

int main() {
    double x;
    printf("Enter a double value: ");
    scanf("%lf", &x);

    unsigned long long* ptr = (unsigned long long*)&x; 

    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52;

    printf("Exponent (Hex): 0x%llX\n", exponent);

    printf("Exponent (Binary): 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");

    return 0;
}
