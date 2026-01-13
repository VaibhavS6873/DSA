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

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;

    return 0;
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
      return 0;
    else
        return 1;
}

char* infixToPostfix(const char *infix)
{
    int i = 0 , j = 0;
    char *postfix = nullptr;
    int len = strlen(infix);
    postfix = new char[len+1];

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            while (top != nullptr && pre(top->data) >= pre(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while(nullptr != top)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}


 int main(void)
 {
    const char *infix = "a+b*c-d/e";
    std::cout<<"Postfix is = "<<infixToPostfix(infix)<<std::endl;

    return 0;
 }