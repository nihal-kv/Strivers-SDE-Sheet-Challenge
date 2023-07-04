#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
	vector<int> dp(arr.begin(), arr.end());
	int maxi=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i])
			{
				dp[i]=max(dp[i], arr[i]+dp[j]);
			}
		}
		maxi=max(maxi, dp[i]);
	}
	return maxi;
}