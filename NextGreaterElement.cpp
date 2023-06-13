#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> v;
    st.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        int ng=st.empty()?-1: st.top();
        v.push_back(ng);
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}