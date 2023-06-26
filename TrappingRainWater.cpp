#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    if(n==0 || n==1) return 0;
    vector<long> pre(n, 0), post(n, 0);
    long maxi=0;
    for(int i=1; i<n-1; i++)
    {
        maxi=max(maxi, arr[i-1]);
        pre[i]=maxi;
    }
    maxi=0;
    for(int i=n-2; i>=0; i--)
    {
        maxi=max(maxi, arr[i+1]);
        post[i]=maxi;
    }
    long sum=0;
    for(int i=1; i<n-1; i++)
    {
        if(min(pre[i], post[i])-arr[i]>0)
        {
            sum+=min(pre[i], post[i])-arr[i];
        }
    }
    return sum;
}