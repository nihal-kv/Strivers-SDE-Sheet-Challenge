/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     int count=1;
     Node* curr=head;
     while(curr->next)
     {
          curr=curr->next;
          count++;
     }
     k=k%count;
     curr->next=head;
     int a=count-k;
     int b=a-1;
     curr=head;
     while(a--)
     {
          curr=curr->next;
     }
     Node* temp=head;
     while(b--)
     {
          temp=temp->next;
     }
     temp->next=NULL;
     return curr;
}