#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n=input.size();
    int ans=0;
    int left=0, right=0;
    map<int, int> mp;
    while(right<n)
    {
        if(mp.find(input[right])!=mp.end())
        {
            left=max(left, mp[input[right]]+1);
        }
        mp[input[right]]=right;
        ans=max(ans, right-left+1);
        right++;
    }
    return ans;
}