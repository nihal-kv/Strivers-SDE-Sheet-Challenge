
#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[v+1];
    for(auto it: edges)
    {
        adj[it.first].push_back(it.second);
    }
    vector<int> indegree(v+1);
    for(int i=1; i<=v; i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1; i<=v; i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return count!=v;
}