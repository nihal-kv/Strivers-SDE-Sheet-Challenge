#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	if(n==1) return "1";
	if(n==2) return "11";
	string s="11";
	for(int i=3; i<=n; i++)
	{
		int count=1;
		string temp="";
		s+="$";
		for(int j=1; j<s.size(); j++)
		{
			if(s[j]==s[j-1]) count++;
			else
			{
				temp+=to_string(count);
				temp+=s[j-1];
				count=1;
			}
		}
		s=temp;
	}
	return s;
		
}