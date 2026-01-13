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
 
void ReverseLL(Node *p)
{
    Node *q = NULL,*r = NULL;
    
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->Next;
        q->Next = r;
    }
    head = q;
}

void ReverseRecurse(Node *q, Node *p)
{
    if(p)
    {   
        ReverseRecurse(p,p->Next);
        p->Next = q;
    }
    else
        head = q;
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

int main(void)
{
    int A[] = {3,5,5,9,80};

    createLL(A,5);
    DisplayLL(head);

    ReverseRecurse(NULL, head);
    DisplayLL(head);
    return 0;
}
