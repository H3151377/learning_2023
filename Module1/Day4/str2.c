#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cvtcb(char* str[], int size) {
    int digit = 0;
    
    for (int i = 0; i < size; i++) {
        int num = atoi(str[i]);
        digit = digit * 10 + num;
    }
    
    return digit;
}

int main() {
    char* str[] = {"1", "2", "3", "4"};
    int size = sizeof(str) / sizeof(str[0]);
    
    int digit = cvtcb(str, size);
    printf("%d\n", digit);
    
    return 0;
}
