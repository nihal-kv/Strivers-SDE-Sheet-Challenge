#include <bits/stdc++.h> 
void merge(vector<int>& arr, int l, int mid, int r, int& count)
{
	int n1=mid-l+1;
	int n2=r-mid;
	int a1[n1];
	int a2[n2];
	int k=l;
	for(int i=0; i<n1; i++)
	{
		a1[i]=arr[k];
		k++;
	}
	for(int i=0; i<n2; i++)
	{
		a2[i]=arr[k];
		k++;
	}
	int i=0, j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			arr[k]=a1[i];
			k++;
			i++;
		}
		else
		{
			arr[k]=a2[j];
			k++;
			j++;
		}
	}
	while(i<n1)
	{
		arr[k]=a1[i];
			k++;
			i++;
	}
	while(j<n2)
	{
		arr[k]=a2[j];
			k++;
			j++;
	}
}
void countPairs(vector<int>& arr, int l, int mid, int r, int& count)
{
	int right=mid+1;
	for(int i=l; i<=mid; i++)
	{
		while(right<=r && arr[i]>2*arr[right]) right++;
		count+=right-(mid+1);
	}
}
void mergeSort(vector<int>& arr, int l, int r, int& count)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergeSort(arr, l, mid, count);
		mergeSort(arr, mid+1, r, count);
		countPairs(arr, l, mid, r, count);
		merge(arr, l, mid, r, count);
	}
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	int count=0;
	mergeSort(arr,0, n-1, count);	
	return count;
}