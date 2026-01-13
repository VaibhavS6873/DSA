//#include<iostream>
//
//struct Node
//{
//    int data;
//    Node *Next;
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
//    head->Next = head;
//    tail = head;
//
//    for(i=1;i<n;i++)
//    {
//        temp = new Node;
//        temp->data = A[i];
//        temp->Next = tail->Next;
//        tail->Next = temp;
//        tail = temp;
//    }
//
//}
//
//void DisplayCircularLL(Node *p)
//{
//    do {
//        std::cout<<p->data<<"->";
//        p = p->Next;
//    } while (p!=head);
//    std::cout<<"continue";
//    std::cout<<std::endl;
//}
//
//void DisplayCircularLLRecursive(Node *p)
//{
//    static int flag = 0;
//    
//    if(p!=head || flag == 0)
//    {
//        flag = 1;
//        std::cout<<p->data<<"->";
//        DisplayCircularLLRecursive(p->Next);
//    }
//  
//    flag = 0;
//}
//    
//int main(void)
//{
//    int A[] = {3,5,6,9,80};
//    
//    createLL(A,5);
//    DisplayCircularLL(head);
//
//    DisplayCircularLLRecursive(head);
//    std::cout<<"continue";
//    std::cout<<std::endl;
//    
//    return 0;
//}
