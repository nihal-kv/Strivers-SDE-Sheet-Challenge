#include <bits/stdc++.h> 
void bfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& v)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        v.push_back(curr);
        for(auto it: adj[curr])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[V];
    for(auto it: edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    for(int i=0; i<V; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> vis(V, 0);
    vector<int> v;
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            bfs(i, adj, vis, v);
        }
    }
    return v;
}