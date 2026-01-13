#include<iostream>

class Node
{
    public:
        int data;
        Node *Next;
};


class Stack
{
    private:
    Node *top;

    public:
    Stack():top(nullptr){};
    ~Stack();
    void push(int Num);
    int pop();
    void Display();
};

void Stack::push(int Num)
{
     Node *temp = new Node;

    if(NULL == temp)
        std::cout<<"stack is full"<<std::endl;

    else
    {
        temp->data = Num;
        temp->Next = top;
        top = temp;
    }
}

int Stack::pop()
{
     int x = -1;
    Node *p = nullptr;
    if(NULL == top)
        std::cout<<"Stack is empty";

    else
    {
        p = top;
        top = top->Next;
        x = p->data;
        delete(p);
    }
    return x;
}

void Stack::Display()
{
    Node *p = top;
     while(p!=NULL)
    {
        std::cout<<p->data<<std::endl;
        p = p->Next;
    }
}

Stack::~Stack()
{
    Node *p = top;
    while(top)
    {
        top = top->Next;
        delete p;
        p = top;
    }
    p = nullptr;
    top = nullptr;
}
int main(void)
{
    Stack st;
    st.push(10);
    st.push(50);
    st.push(60);
    st.push(67);
    st.push(89);
    st.Display();
    st.pop();
    st.Display();
    return 0;
}