#include<iostream>
class Node
{
    public:
        int data;
        Node* Next;
    
        Node(int _data)
        {
            data = _data;
            Next = nullptr;
        }
};

class LL
{
    public:
        void SortedInsert(Node **H,int key)
        {
            Node *p = *H;
            Node* q = nullptr;
            Node* temp = new Node(key);

            if(nullptr == *H)
            {
                *H = temp;
            }
            else
            {
                while(p!=NULL && p->data<key)
                {
                    q = p;
                    p = p->Next;
                }
                if(q == nullptr)
                {
                    temp->Next = p;
                    *H = temp;
                }
                else
                {
                     q->Next = temp;
                     temp->Next = p;
                }
            }
        }

        Node* search(Node* p,int key)
        {
            while(p!=nullptr)
            {
                if(key == p->data)
                {
                    return p;
                }
                p = p->Next;
            }
            return nullptr;                 
        }
    };
    