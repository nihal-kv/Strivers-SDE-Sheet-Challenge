#include<bits/stdc++.h>
bool check(int node, vector<int> adj[], vector<int>& vis)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node]=1;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int curr=it.first;
        int parent=it.second;
        for(auto ad: adj[curr])
        {
            if(!vis[ad])
            {
                vis[ad]=1;
                q.push({ad, curr});
            }
            else if(ad!=parent) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(check(i, adj, vis)) return "Yes";
        }
    }
    return "No";
}
