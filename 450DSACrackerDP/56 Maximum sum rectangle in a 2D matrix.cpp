// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int kadane(int* arr, int* start, int* finish, int n)
    {
       int sum=0,maxsum=INT_MIN,i;
       *finish=-1;
       int local_start=0;
       for(i=0;i<n;i++){
           sum+=arr[i];
           if(sum<0){
               sum=0;
               local_start=i+1;
           }
           else if(sum>maxsum){
               maxsum=sum;
               *start=local_start;
               *finish=i;
           }
       }
       if(*finish!=-1){
           return maxsum;
       }
       maxsum=arr[0];
       *start=*finish=0;
       for(int i=1;i<n;i++){
           if(arr[i]>maxsum){
               maxsum=arr[i];
               *start=*finish=i;
           }
       }
       return maxsum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxsum=INT_MIN,finalleft,finalright,finaltop,finalbottom;
        int left,right,i;
        int temp[R], sum , start, finish;
        for(left=0;left<C;left++){
            memset(temp,0,sizeof(temp));
            for(right=left;right<C;right++){
                for(i=0;i<R;i++){
                    temp[i]+=M[i][right];
                }
                sum=kadane(temp,&start,&finish,R);
                if(sum>maxsum){
                    maxsum=sum;
                    finalleft=left;
                    finalright=right;
                    finaltop=start;
                    finalbottom=finish;
                }
            }
        }
        return maxsum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
