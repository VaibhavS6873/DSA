
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
    tail->Next = head;
    head->Prev = tail;
}

void Display(Node *p)
{
    do
    {
        std::cout<<p->data<<"->";
        p = p->Next;
    } while (p!=head);
    std::cout<<"continue";
    std::cout<<std::endl;
}

int length(Node *p)
{
    int cnt = 0;
    do {
        cnt++;
        p = p->Next;
    } while (p!=head);
    return  cnt;
}

void InsertAtPosition(Node *p, int pos, int Num)
{
    Node* temp = nullptr;
    
    if(pos < 1 || pos > length(p)+1)
    {
        return;
    }
    
    temp = new Node;
    temp->data = Num;
    temp->Next = nullptr;
    temp->Prev = nullptr;
    
    if(pos == 1)
    {
        if(NULL == head)
        {
            head = temp;
            head->Next = head;
            head->Prev = head;
        }
        else
        {
            temp->Next = head;
            temp->Prev = head->Prev;
            head->Prev->Next = temp;
            head->Prev = temp;
            head = temp;
        }
    }
    else
    {
        for(int i = 1; i<pos-1; i++)
        {
            p = p->Next;
        }
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
        return(-1);
    }
    
    if(pos == 1)
    {
        x = head->data;
        head = p->Next;
        head->Prev = p->Prev;
        head->Prev->Next = head;
        delete p ;
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
    
    InsertAtPosition(head, 4, 10);
    Display(head);
    
    Delete(head, 2);
    Display(head);

    return 0;
}
