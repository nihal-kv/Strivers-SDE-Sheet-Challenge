#include<bits/stdc++.h>


long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long>(value+1, 0));
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }
    for(int j=1; j<=value; j++)
    {
        dp[0][j]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=value; j++)
        {
            long notTake=dp[i-1][j];
            long take=0;
            if(denominations[i-1]<=j)
            {
                take=dp[i][j-denominations[i-1]];
            }
            dp[i][j]=take+notTake;
        }
    }
    return dp[n][value];

}