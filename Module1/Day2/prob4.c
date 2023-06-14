#include <stdio.h>

int countSetBits(int num) {
    int count = 0;

    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int main() {
    int arr[50];
    int size, totalSetBits = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        totalSetBits += countSetBits(arr[i]);
    }

    printf("Total set bits in the array: %d\n", totalSetBits);

    return 0;
}
