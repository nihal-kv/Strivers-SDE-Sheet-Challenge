#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double, pair<double, double>>> v;
    for(int i=0; i<items.size(); i++)
    {
        v.push_back({double(items[i].second)/double(items[i].first), {items[i].first,
         items[i].second}});
    }
    sort(v.rbegin(), v.rend());
    double profit=0;
    for(int i=0; i<v.size(); i++)
    {        
        int wt=v[i].second.first;
        int val=v[i].second.second;
        if(wt<=w)
        {
            profit+=val;
            w-=wt;
        }
        else if(w>0)
        {
            profit+=double(w)/double(wt)*val;
            break;
        }
    }
    return profit;
}