//#include<iostream>
//
//struct Node
//{
//    int data;
//    struct Node *Next;
//}*head;
//
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
//struct Node* LSearch(Node *p, int key)
//{
//    Node *q = NULL;
//    while(p!=NULL)
//    {
//        if(p->data == key)
//        {
//            q->Next = p->Next;
//            p ->Next = head;
//            head = p;
//            return p;
//        }
//        q = p;
//        p = p->Next;
//    }
//    return NULL;
//    
//}
//
//struct Node* LSearchRecurse(Node *p, int key)
//{
//    if(NULL == p)
//        return NULL;
//    
//    if(p->data == key)
//        return p;
//
//    return LSearchRecurse(p->Next,key);
//    
//}
//
//int main(void)
//{
//    int A[] = {3,5,6,9,80};
//    Node *temp;
//    createLL(A,5);
//
//    temp = LSearch(head,80);
//    
//    if(temp)
//        std::cout<<"Key is found"<<std::endl;
//    else
//        std::cout<<"key is not found"<<std::endl;
//    return 0;
//}
