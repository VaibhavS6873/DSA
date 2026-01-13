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
//bool isSorted(Node *p)
//{
//    int x = INT_MIN;
//    
//    while(p!=NULL)
//    {
//        if(p->data < x)
//        {
//            return false;
//        }
//        x = p->data;
//        p = p->Next;
//    }
//    return true;
//}
//
//void removeDuplicate(Node *p)
//{
//    Node *q = p->Next;
//    
//    if(p->data != q->data)
//    {
//        p = p->Next;
//        q = q->Next;
//    }
//    p->Next = q->Next;
//    delete(q);
//    q = p->Next;
//    
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
//    int A[] = {3,5,5,9,80};
//
//    createLL(A,5);
//    DisplayLL(head);
//    
//    std::cout << std::boolalpha;
//    std::cout<<"Sorted list = "<<isSorted(head)<<std::endl;
//    
//    removeDuplicate(head);
//    DisplayLL(head);
//    
//
//    return 0;
//}
