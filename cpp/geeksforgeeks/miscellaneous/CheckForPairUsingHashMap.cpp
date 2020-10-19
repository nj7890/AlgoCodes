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
// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;

bool pairExists(int arr[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(sum - arr[i]) != s.end())
            return 1;
        s.insert(arr[i]);
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

        if (pairExists(arr, n, num))
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
