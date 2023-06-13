#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(v);
    for(int i=0; i<v; i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return ans;
}