#include <bits/stdc++.h> 
int romanToInt(string s) {
    // Write your code here
    int i=0;
    int value=0;
    map<int, int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    for(int i=0; i<s.size(); i++)
    {
        if(mp[s[i]]<mp[s[i+1]])
        {
            value-=mp[s[i]];
        }
        else
        {
            value+=mp[s[i]];
        }
    }
    return value;
}
