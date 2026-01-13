//
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
//    tail->Next = head;
//    head->Prev = tail;
//}
//
//void Display(Node *p)
//{
//    do
//    {
//        std::cout<<p->data<<"->";
//        p = p->Next;
//    } while (p!=head);
//    std::cout<<"continue";
//    std::cout<<std::endl;
//}
//
//int length(Node *p)
//{
//    int cnt = 0;
//    do {
//        cnt++;
//        p = p->Next;
//    } while (p!=head);
//    return  cnt;
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
