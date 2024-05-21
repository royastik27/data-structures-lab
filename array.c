/**
 * Processing Arrays
 * AUTHOR: Astik Roy
 * DATE:  
**/

#include <stdio.h>

void insert(int arr[], int * n, int k, int item)
{
    int i;

    for(i = *n - 1; i >= k; --i)
        arr[i + 1] = arr[i];

    arr[k] = item;

    *n = *n + 1;

    return;
}

int delete(int arr[], int * n, int k)
{
    int i, item;

    item = arr[k];

    for(i = k; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    *n = *n - 1;

    printf("Deleted element %d from position %d\n", item, k);

    return item;
}

int linear(int arr[], int n, int item)
{
    int loc;

    arr[n] = item;

    for(loc = 0; arr[loc] != item; ++loc);
    
    if(loc == n) return -1;

    return loc;
}

int binary(int arr[], int upperBound, int lowerBound, int item)
{
    int loc, beg = upperBound, end = lowerBound, mid = (beg + end) / 2;
    
    while(beg <= end && arr[mid] != item)
    {
        if(item < arr[mid])
            end = mid - 1;
        else
            beg = mid + 1;

        mid = (beg + end) / 2;
    }

    if(arr[mid] == item)
        loc = mid;
    else loc = -1;

    return loc;
}

void traverse(int arr[], int lowerBound, int upperBound)
{
    int k;

    printf("The array: ");

    for(k = lowerBound; k <= upperBound; k++)
        printf("%d ", arr[k]);

    printf("\n");

    return;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    traverse(arr, 0, n - 1);

    int item = 40, loc = binary(arr, 0, n-1, item);
    printf("Location of %d is %d\n", item, loc);

    return 0;
}