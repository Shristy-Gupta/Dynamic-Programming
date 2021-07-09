#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSumWO3Consec(int arr[], int n)
{
    int sum[n];
    //Base case to target first three elements
    /*
    sum[i] : Stores result for subarray arr[0..i], i.e.,
         maximum possible sum in subarray arr[0..i]
         such that no three elements are consecutive.

sum[0] = arr[0]

// Note : All elements are positive
sum[1] = arr[0] + arr[1]

// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] 
sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
sum[i] = max(sum[i-1], sum[i-2] + arr[i],
             sum[i-3] + arr[i] + arr[i-1])
    */
    if(n>=1){
        sum[0]=arr[0];
    }
    if(n>=2){
        sum[1]=arr[0]+arr[1];
    }
    if(n>=3){
        sum[2]=max(arr[0]+arr[2],max(arr[1]+arr[2],arr[0]+arr[1]));
    }
    for(int i=3;i<n;i++){
        sum[i]=max(sum[i-1],arr[i]+max(sum[i-2],arr[i-1]+sum[i-3]));
    }
return sum[n-1];
}

// Driver code
int main()
{
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}
