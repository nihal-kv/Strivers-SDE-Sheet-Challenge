#include <bits/stdc++.h>

void bfs(int row, int col, vector<vector<int>>& vis, int** arr, int n, int m)
{
   vis[row][col]=1;
   queue<pair<int, int>> q;
   q.push({row, col});
   while(!q.empty())
   {
      auto it=q.front();
      q.pop();
      int r=it.first;
      int c=it.second;
      for(int i=-1; i<=1; i++)
      {
         for(int j=-1; j<=1; j++)
         {
            int nrow=r+i;
            int ncol=c+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
             && arr[nrow][ncol]==1)
            {
               vis[nrow][ncol]=1;
               q.push({nrow, ncol});
            }
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int count=0;
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         if(!vis[i][j] && arr[i][j]==1)
         {
            count++;
            bfs(i, j, vis, arr, n, m);
         }
      }
   }
   return count;
}
