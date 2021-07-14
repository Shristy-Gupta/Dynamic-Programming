#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int smallestSumSubarr(int arr[], int n){
    //Kadane algorithm
    int finalans=INT_MAX;
    int smallans=0;
    for(int i=0;i<n;i++){
        if(smallans>0){
            smallans=arr[i];
        }
        else{
            smallans+=arr[i];
        }
        finalans=min(finalans,smallans);
        
    }
    return finalans;
}
int main() {
    /*
Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
Output : -6
Subarray is {-4, 2, -3, -1} = -6

Input : arr = {2, 6, 8, 1, 4}
Output : 1
    */
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << smallestSumSubarr(arr, n);
    return 0;  

    return 0;
}
