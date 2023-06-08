#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> * reverseList(LinkedListNode<int> * head)
{
    LinkedListNode<int> * curr=head;
    LinkedListNode<int> * prev=NULL;
    while(curr)
    {
        LinkedListNode<int> * next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    
    // Write your code here.
    if(head==NULL || head->next==NULL) return true;
    LinkedListNode<int> * slow=head;
    LinkedListNode<int> * fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

    }
    LinkedListNode<int> * rev=reverseList(slow->next);
    LinkedListNode<int> * curr=head;
    while(rev)
    {
        if(curr->data!=rev->data) return false;
        curr=curr->next;
        rev=rev->next;
    }
    return true;

}