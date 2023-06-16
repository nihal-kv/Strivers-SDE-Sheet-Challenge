#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> denominations={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n=denominations.size();
    int count=0;
    for(int i=n-1; i>=0; i--)
    {
        if(denominations[i]<=amount)
        {
          while (denominations[i] <= amount) 
          {
            count++;
            amount -= denominations[i];
          }
        }
        else if(amount<=0) break;
    }
    return count;
}
