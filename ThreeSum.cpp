#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> v;
	set<vector<int>> st;
	sort(arr.begin(), arr.end());
	for(int i=0; i<n-2; i++)
	{
		int l=i+1, r=n-1;
		while(l<r)
		{
			if(arr[i]+arr[l]+arr[r]==K)
			{
				st.insert({arr[i], arr[l], arr[r]});
				l++;
				r--;
			}
			else if(arr[i]+arr[l]+arr[r]>K) r--;
			else l++;
		} 
	}
	for(auto it: st)
	{
		v.push_back(it);
	}
	return v;
}