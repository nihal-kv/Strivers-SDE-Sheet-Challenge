#include <bits/stdc++.h> 

struct Node
{
    Node* child[26];
    bool isEnd;
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Node* root=new Node();
    int count=0;
    int n=word.size();
    for(int i=0; i<n; i++)
    {
        Node* curr=root;
        for(int j=i; j<n; j++)
        {
            int index=word[j]-'a';
            if(curr->child[index]==NULL)
            {
                count++;
                curr->child[index]=new Node();
            }
            curr=curr->child[index];
        }
    }
    return count;
}
