#include<bits/stdc++.h>

bool check(int node, vector<int>& color, vector<int> adj[])
{
	color[node]=1;
	queue<int> q;
	q.push(node);
        while (!q.empty()) 
		{
          int curr = q.front();
          q.pop();
          for(auto it: adj[curr])
		  {
			  if(color[it]==-1)
			  {
				  color[it]=!color[curr];
				  q.push(it);
			  }
			  else if(color[it]==color[curr]) return false;
		  }
        }
		return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int V=edges.size();
	vector<int> adj[V];
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			if(edges[i][j]==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int> color(V, -1);
	for(int i=0; i<V; i++)
	{
		if(color[i]==-1)
		{
			if(!check(i, color, adj)) return false;
		}
	}
	return true;
}