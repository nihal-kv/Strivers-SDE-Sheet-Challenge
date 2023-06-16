/****************************************************************

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

*****************************************************************/

int findIntersection(Node *first, Node *second)
{
    //Write your code here
    Node* l1=first;
    Node* l2=second;
    while(l1!=l2)
    {
        if(l1==NULL) l1=second;
        else l1=l1->next;
        if(l2==NULL) l2=first;
        else l2=l2->next;
    }
    if(l1==NULL) return -1;
    return l1->data;
}