//#include<iostream>
//
//struct Node
//{
//    int data;
//    Node *Prev , *Next;
//}*head = nullptr;
//
//
//
//void create(int A[], int n)
//{
//    Node *temp = nullptr, *tail = nullptr;
//    
//    head = new Node;
//    head->data = A[0];
//    head->Prev = head->Next = nullptr;
//    tail = head;
//    
//    for(int i = 1 ; i<n; i++)
//    {
//        temp = new Node;
//        temp->data = A[i];
//        temp->Prev = tail;
//        temp->Next = nullptr;
//        tail->Next = temp;
//        tail = temp;
//    }
//}
//
//void Display(Node *p)
//{
//    while(p!=nullptr)
//    {
//        std::cout<<p->data<<"->";
//        p = p->Next;
//    }
//    std::cout<<"NULL"<<std::endl;
//}
//
//int length(Node *p)
//{
//    int cnt = 0;
//    while(p)
//    {
//        cnt++;
//        p = p->Next;
//    }
//    return cnt;
//}
//
//
//int main(void)
//{    
//    int A[] = {3,4,5,6,7};
//    create(A, 5);
//    Display(head);
//    
//    return 0;
//}
