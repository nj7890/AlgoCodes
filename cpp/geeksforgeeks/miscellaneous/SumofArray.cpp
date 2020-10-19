/*
Program to find sum of elements in a given array

    Given an array of integers, find sum of its elements.

    Examples :

    Input : arr[] = {1, 2, 3}
    Output : 6
    1 + 2 + 3 = 6

    Input : arr[] = {15, 12, 13, 10}
    Output : 50
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    
    int sum = 0;

    for(int i=0;i<n;++i){
        sum += a[i];        
    }

    printf("Sum: %d",sum);

    return 0;
}
