#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    map<int, int> mp;
	for(int i=0; i<n; i++)
	{
		mp[arr[i]]++;
	}
    vector<int> v;
	for(auto it: mp)
	{
		if(it.second>(n/3)) v.push_back(it.first);
	}
	return v;

}