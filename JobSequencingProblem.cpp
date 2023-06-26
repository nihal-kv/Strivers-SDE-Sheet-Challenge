#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    vector<pair<int, int>> v;
    int maxi=0;
    for(int i=0; i<n; i++)
    {
        v.push_back({jobs[i][1], jobs[i][0]});
        maxi=max(maxi, jobs[i][0]);
    }
    sort(v.rbegin(), v.rend());
    
    vector<int> temp(maxi+1, -1);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=v[i].second; j>0; j--)
        {
            if(temp[j]==-1)
            {
                sum+=v[i].first;
                temp[j]=v[i].first;
                break;
            }
        }
    }
    return sum;
}
