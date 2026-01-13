 #include<iostream>

 struct Node
 {
    int data;
    Node* Next;
 }*top;


void push(int num)
{
    Node *temp = new Node;

    if(NULL == temp)
        std::cout<<"stack is full"<<std::endl;

    else
    {
        temp->data = num;
        temp->Next = top;
        top = temp;
    }
}

int pop()
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

void Display(Node *p)
{
    while(p!=NULL)
    {
        std::cout<<p->data<<std::endl;
        p = p->Next;
    }
}



 int main(void)
 {
    push(10);
    push(56);
    push(87);
    push(45);
    push(54);

    Display(top);

    std::cout<<"Pop item is = "<<pop()<<std::endl;

    Display(top);
    return 0;
 }