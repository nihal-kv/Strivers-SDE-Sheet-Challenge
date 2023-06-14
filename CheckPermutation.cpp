#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    map<int, int> mp;
    for(auto it: str1)
    {
        mp[it]++;
    }
    for(auto it: str2)
    {
        mp[it]--;
    }
    for(auto it: mp)
    {
        if(it.second!=0) return false;
    }
    return true;
}