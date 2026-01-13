#include<iostream>

struct Node
{
    int data;
    struct Node *Next;
}*head;

void createLL(int A[],int n)
{
    int i;
    
    Node *temp, *tail;
    head = new Node;
    head->data = A[0];
    head->Next = NULL;
    tail = head;
    
    for(i=1;i<n;i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->Next = NULL;
        tail->Next = temp;
        tail = temp;
    }
    
}

void DisplayLL(Node *p)
{
    while(p!=NULL)
    {
        std::cout<<p->data<<"->";
        p = p->Next;
    }
    std::cout << "NULL" << std::endl;
}

void DisplayRecursive(Node *p)
{
    if(p!=NULL)
    {
        std::cout<<p->data<<"->";
        DisplayRecursive(p->Next);
    }
    
    if (p == NULL)  // Only print "NULL" once, at the end of the recursion.
    {
            std::cout << "NULL" << std::endl;
    }
}

int main(void)
{
    int A[] = {3,5,6,9,80};
    
    createLL(A,5);
    DisplayLL(head);
    DisplayRecursive(head);
    
    return 0;
}
