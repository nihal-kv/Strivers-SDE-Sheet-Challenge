#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int ans=INT_MIN, pro=1;
	for(int i=0; i<n; i++)
	{
		pro*=arr[i];
		ans=max(ans, pro);
		if(pro==0) pro=1;
	}
	pro=1;
	for(int i=n-1; i>=0; i--)
	{
		pro*=arr[i];
		ans=max(ans, pro);
		if(pro==0) pro=1;
	}
	return ans;
}
