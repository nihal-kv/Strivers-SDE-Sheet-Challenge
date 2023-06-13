#include<bits/stdc++.h>

bool check(char a, char b)
{
  return (a == '(' && b == ')') || (a == '{' && b == '}') || (a=='[' && b==']');
}

bool isValidParenthesis(string exp)
{
    // Write your code here.
    stack<int> st;
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') st.push(exp[i]);
        else
        {
            if(st.empty()) return false;
            if(!check(st.top(), exp[i])) return false;
            st.pop(); 
        }
    }
    return st.empty();
}