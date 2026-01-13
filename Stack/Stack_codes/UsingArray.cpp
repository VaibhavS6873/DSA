#include<iostream>

struct Stack
{
    int size;
    int top;
    int *s;
}*st = nullptr;

void create(Stack *st)
{
    
    std::cout<<"Enter the size of stack := ";
    std::cin>>st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void Display(Stack *st)
{
    int i;
    for(i = st->top; i>=0; i--)
        std::cout<< st->s[i]<<std::endl;

    std::cout<<std::endl;
}

void push(Stack *st, int num)
{
    if(st->top == st->size-1)
    {
        std::cout<<"Stack is full";
    }
    else
    {
        st->top++;
        st->s[st->top] = num;
    }
}

void pop(Stack *st)
{
    int x = -1;
    if(st->top == -1)
    {
        std::cout<<"Stack is underflow";
    }
    else
    {
        x= st->s[st->top--];
    }
}


int main(void)
{
    st = new Stack;
    create(st);
   
    push(st,3);
    push(st,5);
    push(st,8);
    push(st,9);
    push(st,5);

    Display(st);
    pop(st);
    Display(st);
    return 0;
}