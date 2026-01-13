#include<stdio.h>    //h'(x) = (h(i) + f(i))%SIZE where f(i) = i for linear probing and i = 0,1,2...
#define SIZE 10;                                       //f(i) = i*i for quadratic probing

int hash(int key)
{
    return(key%10);
}

int probe(int *H,int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(index+i)%SIZE]!=0)  //for quadratic probing (index+i*i)%SIZE
        i++;
    return (index+i)%SIZE;
}
void insert(int *H,int key)
{
    int index = hash(key);

    if(H[index]!=0)
    {
        index = probe(H,key);
    }
    H[index] = key;
}

int search(int *h,int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(index+i)%SIZE]!=key)
        i++;

    return (index+i)%SIZE;

}
int main(void)
{
    int Ht[10] = {0};
    insert(Ht,12)
    insert(Ht,35);
    insert(Ht,23);
    insert(ht,22);    
    return 0;

}