#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+k);
	for(int i=k; i<size; i++)
	{
		if(arr[i]>pq.top())
		{
			pq.push(arr[i]);
			pq.pop();
		}
	}
	return pq.top();

}