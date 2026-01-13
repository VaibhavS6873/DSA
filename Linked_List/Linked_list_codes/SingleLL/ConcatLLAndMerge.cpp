//
//#include<iostream>
//
//struct Node
//{
//    int data;
//    struct Node *Next;
//}*head = NULL , *sHead = NULL, *tHead = NULL;
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
//void createLL2(int A[],int n)
//{
//    int i;
//
//    Node *temp, *tail;
//    sHead = new Node;
//    sHead->data = A[0];
//    sHead->Next = NULL;
//    tail = sHead;
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
//void concatLL(Node *p, Node *q)
//{
//    tHead = p;
//    
//    while(p->Next != NULL)
//    {
//        p = p->Next;
//    }
//    p->Next = q;
//}
//
//void MergeLL(Node *p , Node *q)
//{
//    Node *tail = NULL;
//    if(p->data < q->data)
//    {
//        tHead = tail = p;
//        p = p->Next;
//        tHead->Next = NULL;
//    }
//    else
//    {
//        tHead = tail = q;
//        q = q->Next;
//        tHead->Next = NULL;
//    }
//    
//    while(p && q)
//    {
//        if(p->data < q->data)
//        {
//            tail->Next = p;
//            tail = p;
//            p = p->Next;
//            tail->Next = NULL;
//        }
//        else
//        {
//            tail->Next = q;
//            tail = q;
//            q = q->Next;
//            tail->Next = NULL;
//        }
//    }
//    
//    if(p){
//        tail->Next = p;
//    }
//    
//    if(q){
//        tail->Next = q;
//    }
//}
//
//void DisplayLL(Node *p)
//{
//    while(p!=NULL)
//    {
//        std::cout<<p->data<<"->";
//        p = p->Next;
//    }
//    std::cout << "NULL" << std::endl;
//}
//
//int main(void)
//{
//    int A[] = {3,5,6,9,80};
//    int B[] = {1,2,3,4,6};
//    
//    createLL(A,5);
//    createLL2(B,5);
//
//
////    concatLL(head, sHead);
////    DisplayLL(tHead);
//    
//    MergeLL(head, sHead);
//    DisplayLL(tHead);
//    return 0;
//}
