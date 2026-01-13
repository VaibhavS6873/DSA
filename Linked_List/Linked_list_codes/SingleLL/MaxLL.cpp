//#include<iostream>
//
//struct Node
//{
//    int data;
//    struct Node *Next;
//}*head;
//
//void createLL(int A[],int n)
//{
//    int i;
//
//    Node *temp, *tail;
//    head = new Node;
//    head->data = A[0];
//    head->Next = NULL;
//    tail = head;
//
//    for(i=1;i<n;i++)
//    {
//        temp = new Node;
//        temp->data = A[i];
//        temp->Next = NULL;
//        tail->Next = temp;
//        tail = temp;
//    }
//
//}
//
//int Max(Node *p)
//{
//    int Max = INT_MIN;
//    
//    while(p!=NULL)
//    {
//        if(Max < p->data)
//        {
//            Max = p->data;
//        }
//        p = p->Next;
//    }
//    return Max;
//}
//
//int MaxRecurse(Node *p)
//{
//    int Max = 0;
//    
//    if(NULL == p)
//    {
//        return INT_MIN;
//    }
//    else
//    {
//        Max = MaxRecurse(p->Next);
//        if(Max > p->data)
//            return Max;
//        else
//            return p->data;
//    }
//}
//
//int main(void)
//{
//    int A[] = {3,5,6,9,80};
//
//    createLL(A,5);
//    
//    std::cout<<"Max in LL is = "<<MaxRecurse(head)<<std::endl;
//    return 0;
//}
