#include <stdio.h>
int main()
{
    int i, sumEven = 0, sumOdd = 0;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sumEven += arr[i];
        }
        else
        {
            sumOdd += arr[i];
        }
    }
    int difference = sumEven - sumOdd;
    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Difference between even and odd elements: %d\n", difference);
    return 0;
}