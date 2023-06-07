#include <bits/stdc++.h> 
void merge(long long* arr, int l, int mid, int r, long long int& ans)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    int k=l;
    for(int i=0; i<n1; i++)
    {
        a[i]=arr[k];
        k++;
    }
    for(int i=0; i<n2; i++)
    {
        b[i]=arr[k];
        k++;
    }
    k=l;
    int i=0, j=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            ans+=n1-i;
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        
            arr[k]=a[i];
            k++;
            i++;
        
    }
    while(j<n2)
    {
        arr[k]=b[j];
            k++;
            j++;
    }
}
void mergeSort(long long* arr, int l, int r, long long int& ans)
{
    if(l<r)
    {
        long long int mid=l+(r-l)/2;
        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid+1, r, ans);
        merge(arr, l, mid, r, ans);
    }
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans=0;
    mergeSort(arr, 0, n-1, ans);
    return ans;
}