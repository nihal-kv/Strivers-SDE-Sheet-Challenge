#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int maxi=1;
    int curr=1;
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++)
    {
        if(arr[i-1]==arr[i]) continue;
        else if(arr[i]==arr[i-1]+1) 
        {
            curr++;
            maxi=max(maxi, curr);
        }
        else curr=1;
    }
    return maxi;
}