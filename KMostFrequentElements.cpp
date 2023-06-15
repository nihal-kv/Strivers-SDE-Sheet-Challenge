#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    map<int, int> mp;
    
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
        
    }
    priority_queue<pair<int, int>> pq;
    for(auto it: mp)
    {
        pq.push({it.second, it.first});
    }
    vector<int> v;
    while(k--)
    {
        auto it=pq.top();
        pq.pop();
        v.push_back(it.second);
    }
    sort(v.begin(), v.end());
    return v;
}