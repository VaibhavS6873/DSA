#include<iostream>

struct Node
{
    int data;
    Node *Prev , *Next;
}*head = nullptr;



void create(int A[], int n)
{
    Node *temp = nullptr, *tail = nullptr;
    
    head = new Node;
    head->data = A[0];
    head->Prev = head->Next = nullptr;
    tail = head;
    
    for(int i = 1 ; i<n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->Prev = tail;
        temp->Next = nullptr;
        tail->Next = temp;
        tail = temp;
    }
}

void Display(Node *p)
{
    while(p!=nullptr)
    {
        std::cout<<p->data<<"->";
        p = p->Next;
    }
    std::cout<<"NULL"<<std::endl;
}

int length(Node *p)
{
    int cnt = 0;
    while(p)
    {
        cnt++;
        p = p->Next;
    }
    return cnt;
}

void InserAtPosition(Node *p , int pos , int Num)
{
    Node *temp;
    if(pos < 1 || pos > length(p) + 1)
        return;
    temp = new  Node;
    temp->data = Num;
    temp->Next = NULL;
    temp->Prev = NULL;
    
    if(pos == 1)
    {
        temp->Next = head;
        head->Prev = temp;
        temp->Prev = NULL;
        head = temp;
    }
    else
    {
        for(int i = 1;i<pos-1;i++)
            p = p->Next;
        temp->Next = p->Next;
        temp->Prev = p;
        
        if(p->Next)
            p->Next->Prev = temp;
        p->Next = temp;
    }

}

int Delete(Node *p , int pos)
{
    int x = -1;

    if(pos < 1 || pos > length(p))
    {
        return -1;
    }

    if (pos == 1)
    {
        x = p->data;
        head = p->Next; //or head->Next
        head->Prev = nullptr;
        delete p;
    }
    else
    {
        for(int i = 1; i<pos; i++)
            p = p->Next;

        p->Prev->Next = p->Next;
       
        if(p->Next)
            p->Next->Prev = p->Prev;
        
        x = p->data;
        delete p;

    }
    return x;
}


int main(void)
{
    int A[] = {3,4,5,6,7};
    create(A, 5);
    Display(head);
    
    InserAtPosition(head, 4, 89);
    Display(head);
    
    Delete(head, 5);
    Display(head);
    return 0;
}
