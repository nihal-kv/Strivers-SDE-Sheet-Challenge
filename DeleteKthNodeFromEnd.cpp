/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
Node* reverseList(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    while(curr)
    {
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    if(head==NULL) return NULL;
    head=reverseList(head);
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        
    }
    else
    {
        int t=k-2;
        Node* curr=head;
        while(t--)
        {
            curr=curr->next;
        }
        Node* temp=curr->next;
        curr->next=temp->next;
        delete temp;
        
    }
    head=reverseList(head);
    return head;

}
