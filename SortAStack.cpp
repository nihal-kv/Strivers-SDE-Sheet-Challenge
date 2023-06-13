#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	// Write your code here
	vector<int> v;
	while(!st.empty())
	{
		v.push_back(st.top());
		st.pop();
	}
	sort(v.begin(), v.end());
	int n=v.size();
	int i=0;
	while(n--)
	{
		st.push(v[i]);
		i++;
	}
	
}