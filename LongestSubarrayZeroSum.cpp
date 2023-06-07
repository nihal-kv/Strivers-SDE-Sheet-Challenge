#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  vector<int> pre;
  int sum=0;
  for(int i=0; i<arr.size(); i++)
  {
    sum+=arr[i];
    pre.push_back(sum);
  }
  int ans=0;
  for(int i=0; i<arr.size()-1; i++)
  {
    for(int j=i+1; j<pre.size(); j++)
    {
      if(pre[j]==pre[i])
      {
        ans=max(ans, j-i);
      }
      if(pre[i]==0) ans=max(ans, i+1);
      if(pre[j]==0) ans=max(ans, j+1);
    }
  }
  return ans;

}