#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Job{
    int start, finish, profit;
};
int latestNonConflict(Job arr[], int n){
    for(int i=n-1;i>=0;i--){
        if(arr[n-1].start>=arr[i].finish){
            return i;
        }
    }
    return -1;
}

int findMaxProfitrecc(Job arr[], int n){
    if(n==1){return arr[n-1].profit;}
    //Include the profit or not include the profit;
    int include_profit=arr[n-1].profit;
    int latestnonconflictjob=latestNonConflict(arr,n);
    if(latestnonconflictjob!=-1){
        include_profit+=findMaxProfitrecc(arr,latestnonconflictjob+1);
    }
    int exclude_profit=findMaxProfitrecc(arr,n-1);
    return max(include_profit,exclude_profit);
}
int findMaxProfitDp(Job arr[], int n){
    //Top to Bottom
    int *table=new int[n];
    table[0]=arr[0].profit;
    for(int i=1;i<n;i++){
        int include_profit=arr[i].profit;
        int latestnonconflictjob=latestNonConflict(arr,i);
        if(latestnonconflictjob!=-1){
        include_profit+=table[latestnonconflictjob];
        }
        table[i]=max(include_profit,table[i-1]);
    }
    int result=table[n-1];
    delete[] table;
    return result;
    
}

bool jobComparator(Job s1,Job s2){
    return s1.finish<s2.finish;
}
int findMaxProfit(Job arr[], int n){
    sort(arr,arr+n,jobComparator);
    return findMaxProfitrecc(arr,n);
}
int main() {
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
