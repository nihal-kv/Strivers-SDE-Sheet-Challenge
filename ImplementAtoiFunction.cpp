#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    string s;
    for(auto it: str)
    {
        if(int(it)>=48 && int(it)<=57) s+=it;
    }
    if(s.size()==0) return 0;
    int place=1;
    int num=0;
    for(int i=s.size()-1; i>=0; i--)
    {
        num+=place*(s[i]-'0');
        place*=10;
    }
    if(str[0]=='-') return (-1)*num;
    return num;
}