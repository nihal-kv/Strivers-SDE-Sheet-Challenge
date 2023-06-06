#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    int mini=p[0];
    int diff=p[1]-p[0];
    for(int i=1; i<p.size(); i++)
    {
        diff=max(diff, p[i]-mini);
        mini=min(mini, p[i]);
    }
    return diff<0?0:diff;
}