#include <stdio.h>

int search(int arr[], int N, int x)
{
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void)
{
	int size,x,i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

	
    printf("Enter the elements to search: ");
    scanf("%d", &x);

	int result = search(arr, size, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}