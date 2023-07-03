#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key, int _val)
            {
                key=_key;
                val=_val;
                
            }

    };

    Node* head=new Node(-1, -1);
    Node* tail=new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int cap;

    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* node)
    {
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }

    void deleteNode(Node* node)
    {
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        // delete node;
    }

    int get(int key_)
    {
        // Write your code here
        if(mp.find(key_)!=mp.end())
        {
            Node* resNode=mp[key_];
            int res=resNode->val;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        // Write your code here
        if(mp.find(key_)!=mp.end())
        {
            Node* resNode=mp[key_];
            mp.erase(key_);
            deleteNode(resNode);
        }
        if(mp.size()==cap)
        {
            
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key_, value));
        mp[key_]=head->next;
    }
};
