/*
Program to find largest element in an array

    Given an array, find the largest element in it.

    Example:

    Input : arr[] = {10, 20, 4}
    Output : 20

    Input : arr[] = {20, 10, 20, 4, 100}
    Output : 100
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i =0;i<n;++i){
        scanf("%d",&arr[i]);        
    }
    int max = 0;
    for(int i=0;i<n;++i){
        if(max < arr[i])
            max = arr[i];            
    }

    printf("Max: %d",max);

    return 0;
}
