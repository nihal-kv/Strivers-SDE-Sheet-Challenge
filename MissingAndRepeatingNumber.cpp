#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	 sort(arr.begin(), arr.end());
	 pair<int, int> p;
	 if(arr[0]!=1) p.first=1;
	 for(int i=1; i<n; i++)
	 {
		 if(arr[i]==arr[i-1])
		 {
			 p.second=arr[i];
		 }
		 if(arr[i]!=arr[i-1] && arr[i]!=arr[i-1]+1) p.first=arr[i-1]+1;
	 }
	 if(p.first==0) p.first=n;
	 return p;
	
}
