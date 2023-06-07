#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   sort(arr.begin(), arr.end());
   vector<vector<int>> ans;
   int diff;
   for(int i = 0 ; i < arr.size() ; i++)
   {
      diff = s - arr[i];
      if(diff < arr[i + 1]) break;
      for(int j = i + 1 ; j < arr.size() ; j++)
      {
         if(arr[i] + arr[j] == s)
         {
            vector<int> pair(2);
            pair[0] = arr[i];
            pair[1] = arr[j];
            ans.push_back(pair);
         }
      }
   }
   return ans;
}