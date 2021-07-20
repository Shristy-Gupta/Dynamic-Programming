#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
  
const int MAX = 100;

bool sumZero(int temp[], int* starti,
			int* endj, int n)
{
	// Map to store the previous sums
	map<int, int> presum;
	int sum = 0; // Initialize sum of elements

	// Initialize length of sub-array with sum 0
	int max_length = 0;

	// Traverse through the given array
	for (int i = 0; i < n; i++)
	{
		// Add current element to sum
		sum += temp[i];

		if (temp[i] == 0 && max_length == 0)
		{
			*starti = i;
			*endj = i;
			max_length = 1;
		}
		if (sum == 0)
		{
			if (max_length < i + 1)
			{
				*starti = 0;
				*endj = i;
			}
			max_length = i + 1;
		}

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end())
		{
			// store previous max_length so
			// that we can check max_length
			// is updated or not
			int old = max_length;

			// If this sum is seen before,
			// then update max_len
			max_length = max(max_length, i - presum[sum]);

			if (old < max_length)
			{
				// If max_length is updated then
				// enter and update start and end
				// point of array
				*endj = i;
				*starti = presum[sum] + 1;
			}
		}
		else

			// Else insert this sum with
			// index in hash table
			presum[sum] = i;
	}

	// Return true if max_length is non-zero
	return (max_length != 0);
};
void sumZeroMatrix(int a[][MAX], int row, int col)
{
    // Do from hashmap
    int temp[row];
    int finalup=0, finaldown=0, finalleft=0, finalright=0;
    int sum,up,down;
    int maxlength=INT_MIN;
    for(int left=0;left<col;left++){
        memset(temp,0,sizeof(temp));
        for(int right=left;right<col;right++){
            for(int i=0;i<row;i++){
                //Adding all the rows with the sum
                temp[i]+=a[i][right];
            }
            bool sum=sumZero(temp,&up,&down,row);
            int ele=(down-up+1)*(right-left+1);
            if(sum && ele>maxlength){
                maxlength=ele;
                finalleft=left;
                finalright=right;
                finaldown=down;
                finalup=up;
            }
        }
    }
    if (finalup == 0 && finaldown == 0 && finalleft == 0 &&
            finalright == 0 && a[0][0] != 0) {
        cout << "No zero-sum sub-matrix exists";
        return;
    }
  
    // Print final values
    for (int j = finalup; j <= finaldown; j++)
    {
        for (int i = finalleft; i <= finalright; i++)
            cout << a[j][i] << " ";
        cout << endl;
    }
    cout<<maxlength;
}

int main() {
	int a[][MAX] = { { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
                      { 1, 8, 7, 9 }, { 7, -2, 0, 10 } };
   
    int row = 4, col = 4;
    sumZeroMatrix(a, row, col);
    return 0;
	
}
