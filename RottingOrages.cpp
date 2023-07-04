#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int vis[n][m];
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i, j}, 0});
                vis[i][j]=2;
            }
            else
            {
                vis[i][j]=0;
            }
        }
    }
    int tm=0;
    int delRow[]={-1, 0, 1, 0};
    int delCol[]={0, 1, 0, -1};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm, t);
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
            {
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( vis[i][j]!=2 && grid[i][j]==1) return -1;
        }
    }
    return tm;

}