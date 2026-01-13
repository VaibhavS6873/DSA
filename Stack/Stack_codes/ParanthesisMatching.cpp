 #include<iostream>

 struct Node
 {
    char data;
    Node* Next;
 }*top;


void push(char num)
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

char pop()
{
    char x;
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

bool isBalanced(const char *exp)
{
    for(int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(nullptr == top)
                return 0;
            pop();
        }
    }

    if(nullptr == top)
        return 1;
    else
        return 0;
}

 int main(void)
 {
   const char *exp = "((a+b) * (c-d))";
    std::cout<<"Expression is balanced or not = "<<isBalanced(exp);
    return 0;
 }