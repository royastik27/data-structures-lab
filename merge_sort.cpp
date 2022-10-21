#include <iostream>

using namespace std;

int arr[] = { 3, 4, 2, 1, 5 };
const int n = sizeof(arr) / sizeof(arr[0]);

void print()
{
    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    return;
}

void merge(int low, int mid, int high)
{
    int b[high - low + 1], i = low, j = mid+1, k = -1;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            b[++k] = arr[i];
            ++i;
        }
        else
        {
            b[++k] = arr[j];
            ++j;
        }
    }

    while(i <= mid)
    {
        b[++k] = arr[i];
        ++i;
    }
    while(j <= high)
    {
        b[++k] = arr[j];
        ++j;
    }

    for(i = 0; i <= k; ++i)
        arr[low + i] = b[i];

    return;
}

void merge_sort(int low, int high)
{
    if(low == high) return;

    int mid = (low+high) / 2;

    merge_sort(low, mid);
    merge_sort(mid+1, high);

    merge(low, mid, high);
    print();

    return;
}

int main()
{
    merge_sort(0, n-1);

    return 0;
}
