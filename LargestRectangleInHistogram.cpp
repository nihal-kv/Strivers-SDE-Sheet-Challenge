 #include<bits/stdc++.h>
 
  vector<int> prevSmaller(vector<int> arr)
 {
   int n=arr.size();
   stack<int> st;
   vector<int> v;
   st.push(0);
   v.push_back(-1);
   for(int i=1; i<n; i++)
   {
     while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i]) st.pop();
     int ns=st.empty()?-1: st.top();
     v.push_back(ns);
     st.push(i);
   }
   
   return v;
 }
 vector<int> nextSmaller(vector<int> arr)
 {
   int n=arr.size();
   stack<int> st;
   vector<int> v;
   st.push(n-1);
   v.push_back(-1);
   for(int i=n-2; i>=0; i--)
   {
     while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i]) st.pop();
     int ns=st.empty()?-1: st.top();
     v.push_back(ns);
     st.push(i);
   }
   reverse(v.begin(), v.end());
   return v;
 }
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   vector<int> next=nextSmaller(heights);
   vector<int> prev=prevSmaller(heights);
   int n=next.size();
   int area=INT_MIN;
   for(int i=0; i<n; i++)
   {
     if(next[i]==-1) next[i]=n;
     int l=heights[i];
     int b=next[i]-prev[i]-1;
     int newArea=l*b;
     area=max(area, newArea);
   }
   return area;
 }