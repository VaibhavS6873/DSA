#include<iostream>
#include "Chains.h"

int Hash(int key)
{
    return(key%10);
}

void Insert(Node *H[], int key)
{
    static LL obj; //to improve efficiency
    int index = Hash(key);
    obj.SortedInsert(&H[index], key);

}
int main(void)
{
    Node *Ht[10];

    for(int i = 0;i<10;i++)
    {
        Ht[i] = nullptr;
    }

    Insert(Ht,12);
    Insert(Ht,22);
    Insert(Ht,42);
}
