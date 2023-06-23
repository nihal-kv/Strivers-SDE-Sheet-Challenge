#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int n=a.size();
    int m=b.size();
    int i=0, j=0;
    while(i<n || j<m)
    {
        long long int num1=0, num2=0;
        while(i<n && a[i]!='.')
        {
            num1=num1*10+(a[i]-'0');
            i++;
        }
        while(j<m && b[j]!='.')
        {
            num2=num2*10+(b[j]-'0');
            j++;
        }
        if(num1>num2) return 1;
        else if(num2>num1) return -1;
        i++;
        j++;
    }
    return 0;
}