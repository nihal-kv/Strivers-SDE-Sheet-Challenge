#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<pair<int, int>, int>> v;
    int n=start.size();
    for(int i=0; i<n; i++)
    {
        v.push_back({{end[i], i+1}, start[i]});
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    int e=-1;
    for(int i=0; i<n; i++)
    {
        if(v[i].second>e)
        {
            ans.push_back(v[i].first.second);
            e=v[i].first.first;
        }
    }
    return ans;
}