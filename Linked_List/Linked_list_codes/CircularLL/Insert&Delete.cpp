#include<iostream>

struct Node
{
    int data;
    Node *Next;
}*head;

int CountNode(Node *p)
{
    int cnt = 0;
    do {
        cnt++;
        p = p->Next;
    } while (p!=head);
    return  cnt;
}

void InserAtPosition(Node *p , int pos , int Num)
{
    Node *temp;
    if(pos < 1 || pos > CountNode(p) + 1)
        return;
    temp = new  Node;
    temp->data = Num;

    if(pos == 1)
    {
        if(NULL == head)
        {
            head = temp;
            head->Next = head;
        }
        else
        {
            while(p->Next!=head)
            {
                p = p->Next;
            }
            p->Next = temp;
            temp->Next = head;
            
        }
    }
    else
    {
        for(int i = 1;i<pos-1;i++)
            p = p->Next;
        temp->Next = p->Next;
        p->Next = temp;
    }

}


void createLL(int A[],int n)
{
    int i;

    Node *temp, *tail;
    head = new Node;
    head->data = A[0];
    head->Next = head;
    tail = head;

    for(i=1;i<n;i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->Next = tail->Next;
        tail->Next = temp;
        tail = temp;
    }

}

int Delete(Node *p , int pos)
{
    Node *q = NULL;
    int x = -1;

    if(pos < 1 || pos > CountNode(p))
    {
        return -1;
    }

    if (pos == 1)
    {
        while(p->Next!=head)
        {
            p = p->Next;
        }
        
        if(p == head)
        {
            delete head;
            head = nullptr;
        }
        p->Next = head->Next;
        x = head->data;
        delete head;
        head = p->Next;
    }
    else
    {
        for(int i = 1; i<pos; i++)
        {
            q = p;
            p = p->Next;
        }

        q->Next = p->Next;
        x = p->data;
        delete p;

    }
    return x;
}

void DisplayCircularLL(Node *p)
{
    do {
        std::cout<<p->data<<"->";
        p = p->Next;
    } while (p!=head);
    std::cout<<"continue";
    std::cout<<std::endl;
}

void DisplayCircularLLRecursive(Node *p)
{
    static int flag = 0;
    
    if(p!=head || flag == 0)
    {
        flag = 1;
        std::cout<<p->data<<"->";
        DisplayCircularLLRecursive(p->Next);
    }
  
    flag = 0;
}
    
int main(void)
{
    int A[] = {3,5,6,9,80};
    
    createLL(A,5);
    DisplayCircularLL(head);

    InserAtPosition(head, 3, 98);
    DisplayCircularLL(head);
    
    Delete(head, 3);
    DisplayCircularLL(head);
    return 0;
}
