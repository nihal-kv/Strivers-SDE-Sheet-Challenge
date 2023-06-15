#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }
    for(int j=1; j<=k; j++)
    {
        dp[0][j]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i-1]<=j)
            {
                take=dp[i-1][j-arr[i-1]];
            }
            dp[i][j]=take+notTake;
        }
    }
    return dp[n][k]>0;
}