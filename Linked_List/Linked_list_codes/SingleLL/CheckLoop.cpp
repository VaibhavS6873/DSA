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
//bool isLoop(Node *p)
//{
//    Node *q = NULL;
//    p = q = head;
//    
//    do
//    {
//        p = p->Next;
//        q = q->Next;
//        q = q?q->Next:q;//i.e q = q!=NULL?q->Next:NULL
//    } while (p && q && p!=q);
//    
//    if(p == q)
//        return 1;
//    else return 0;
//}
//
//void DisplayLL(Node *p)
//{
//    while(p!=nullptr)
//    {
//        std::cout<<p->data<<"->";
//        p = p->Next;
//    }
//    std::cout << "NULL" << std::endl;
//}
//
//
//int main(void)
//{
//    Node *t1=NULL, *t2=NULL;
//    int A[] = {3,5,6,9,80};
//    
//    createLL(A,5);
//    
////    t1 = head->Next->Next;
////    t2 = head->Next->Next->Next;
////    t2->Next = t1;
//    
//    std::cout<<"Is loop:"<<isLoop(head)<<std::endl;
//   // DisplayLL(head);
//    
//
//    return 0;
//}
