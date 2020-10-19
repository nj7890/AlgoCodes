/*
Majority Element
    
    Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”. A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

    Examples : 
    
    Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
    
    Output : 4

    Explanation: The frequency of 4 is 5 which is greater
        than the half of the size of the array size. 

    Input : {3, 3, 4, 2, 4, 4, 2, 4}
    
    Output : No Majority Element
    
    Explanation: There is no element whose frequency is
         greater than the half of the size of the array size.  
*/

#include <iostream>
using namespace std;

void majorityElement(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;

    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
            if (arr[i] == arr[j])
                ++count;

        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }

    if ((index == -1) || (maxCount < (n / 2 + 1)))
        printf("No Element has majority!!\n");
    else
        printf("Majority Element is %d withfrquency %d\n", arr[index], maxCount);
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

        majorityElement(arr, n);
    }

    return 0;
}
