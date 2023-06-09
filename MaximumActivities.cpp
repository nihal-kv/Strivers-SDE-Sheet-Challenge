#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int, int>> v;
    for(int i=0; i<start.size(); i++)
    {
        v.push_back({finish[i], start[i]});
    }
    sort(v.begin(), v.end());
    int count=1;
    int ending=v[0].first;
    for(int i=1; i<v.size(); i++)
    {
        int st=v[i].second;
        int ed=v[i].first;
        if(st>=ending)
        {
            count++;
            ending=ed;
        }
    }
    return count;
}