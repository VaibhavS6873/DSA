#include<iostream>

struct Node
{
    int data;
    struct Node *Next;
}*head, *last;


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

int CountNode(Node *p)
{
    int cnt = 0;
    while(p!=NULL)
    {
        cnt++;
        p = p->Next;
    }
    return cnt;
    // std::cout<<"Count of nodes is = "<<cnt<<std::endl;
}

void InsertLast(int Num)
{
    Node *temp = new Node;
    temp->data = Num;
    temp->Next = NULL;

    if(NULL == head)
    {
        head = last = temp;
    }
    else{
        last->Next = temp;
        last = temp;
    }
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
        temp->Next = head;
        head = temp;
    }
    else
    {
        for(int i = 1;i<pos-1;i++)
            p = p->Next;
        temp->Next = p->Next;
        p->Next = temp;
    }

}

void InsertInSortedLL(Node *p,int Num)
{
    Node *q = NULL;
    Node *temp = new Node;
    temp->data = Num;
    temp->Next = NULL;

    if(NULL == head)
    {
        head = temp;
    }
    else
    {
        while(p!=NULL && p->data < Num)
        {
            q = p;
            p = p->Next;
        }
        if(p == head)
        {
            temp->Next = head;
            head = temp;
        }

        q->Next = temp ;
        temp ->Next = p;
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
        x = p->data;
        head = p->Next; //or head->Next
        delete p;
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
//        int A[] = {3,5,6,9,80};
//
//        createLL(A,5);

        InserAtPosition(head, 1, 10);
        InserAtPosition(head, 2, 100);
        InserAtPosition(head, 3, 30);
        InserAtPosition(head, 4, 12);
        //InserAtPosition(head, 2, 14);

//        InsertLast(10);
//        InsertLast(20);
//        InsertLast(34);
//        InsertLast(67);
//        InsertLast(73);
//        InsertLast(88);
//        InsertLast(91);
//
//   InsertInSortedLL(head, 93);

    Delete(head, 5);

    DisplayLL(head);
    return 0;
}
