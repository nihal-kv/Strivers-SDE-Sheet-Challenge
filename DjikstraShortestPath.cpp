#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int source) {
    // Write your code here.
    vector<pair<int, int>> adj[V];
    for(auto it: vec)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[source]=0;
    pq.push({0, source});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int node=it.second;
        for(auto it: adj[node])
        {
            int adjNode=it.first;
            int edgeWeight=it.second;
            if(dis+edgeWeight<dist[adjNode])
            {
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;

}
