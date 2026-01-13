#include<iostream>

class Node
{
public:
    int data;
    Node *Next;
};

class LinkedList
{
private:
    Node *head;
    
public:
    LinkedList():head(nullptr){}
    LinkedList(int A[], int n);
    ~LinkedList();
    
    void Insert(int pos , int data);
    int Delete(int pos);
    void Display();
    int Length();
};

LinkedList::LinkedList(int A[],int n)
{
    int i;

    Node *temp, *tail;
    head = new Node;
    head->data = A[0];
    head->Next = nullptr;
    tail = head;

    for(i=1;i<n;i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->Next = nullptr;
        tail->Next = temp;
        tail = temp;
    }
}

LinkedList::~LinkedList()
{
    Node *p=head;
    while(head)
    {
        head=head->Next;
        delete p;
        p=head;
    }
    p = nullptr;
    head = nullptr;
}

void LinkedList::Display()
{
    Node *p  = head;
    while(p!=NULL)
       {
           std::cout<<p->data<<"->";
           p = p->Next;
       }
       std::cout << "NULL" << std::endl;
}

int LinkedList::Length()
{
    Node *p = head;
    int cnt = 0;
    while(p!=NULL)
    {
        cnt++;
        p = p->Next;
    }
    return cnt;
}

void LinkedList::Insert(int pos, int Num)
{
    Node *p = head;
    Node *temp;
    if(pos < 1 || pos > Length() + 1)
        return;
    temp = new Node;
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

int LinkedList::Delete(int pos)
{
    Node *p = head;
    Node *q = NULL;
      int x = -1;
  
    if(pos < 1 || pos > Length())
      {
          return -1;
      }
  
      if (pos == 1)
      {
          q = p;
          x = p->data;
          head = p->Next;
          delete q;
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

int main(void)
{
    int A[] = {1,3,4,6,8,9};
    LinkedList l(A,6);
    
    l.Display();
    std::cout<<l.Delete(3)<<std::endl;
    
    l.Insert(4,10);
    l.Display();
    return 0;
}
