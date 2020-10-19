/*
Given an array A[] and a number x, check for pair in A[] with sum as x

    Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x. 
    
    Examples:       
        Input: arr[] = {0, -1, 2, -3, 1}
            sum = -2
        Output: Yes
            If we calculate the sum of the output,
            1 + (-3) = -2

        Input: arr[] = {1, -2, 1, 0, 5}
               sum = 0
        Output: No
            No valid pair exists.
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool pairExists(int arr[], int l, int r, int sum)
{
    while (l < r)
    {
        if (arr[l] + arr[r] == sum)
            return 1;
        else if (arr[l] + arr[r] > sum)
            --r;
        else if (arr[l] + arr[r] < sum)
            ++l;
    }

    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        int num;
        scanf("%d", &num);

        sort(arr, arr + n);

        if (pairExists(arr, 0, n - 1, num))
        {
            printf("Pair Exists in Array\n");
        }
        else
        {
            printf("Pair doesn't Exists in Array\n");
        }
    }

    return 0;
}
