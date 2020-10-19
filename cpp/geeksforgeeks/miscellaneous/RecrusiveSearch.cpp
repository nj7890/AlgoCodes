// Recursive program to linearly search an element in a given array

// Given an unsorted array and an element x, search x in given array. Write recursive C code for this. If element is not present, return -1.

#include <iostream>
using namespace std;

int linearSearch(int arr[], int l, int r, int e)
{
    if (l > r)
        return -1;

    if (arr[l] == e)
        return l;

    if (arr[r] == e)
        return r;

    return linearSearch(arr, l + 1, r - 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int ele;
    scanf("%d", &ele);

    int pos = linearSearch(arr, 0, n, ele);

    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at %d.", pos + 1);

    return 0;
}