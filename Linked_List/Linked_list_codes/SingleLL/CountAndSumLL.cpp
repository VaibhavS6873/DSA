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
//void CountNode(Node *p)
//{
//    int cnt = 0;
//    while(p!=NULL)
//    {
//        cnt++;
//        p = p->Next;
//    }
//    std::cout<<"Count of nodes is = "<<cnt<<std::endl;
//}
//
//int CountRecurse(Node *p)
//{
//    if(p!=NULL)
//    {
//        return CountRecurse(p->Next)+1;
//    }
//    else{
//        return 0;
//    }
//}
//
//int Sum(Node *p)
//{
//    int sum = 0;
//    while(p!=NULL)
//    {
//        sum += p->data;
//        p = p->Next;
//    }
//    
//    return sum;
//}
//
//int SumRecurse(Node *p)
//{
//    if(NULL == p)
//    {
//        return 0;
//    }
//    else
//    {
//        return SumRecurse(p->Next)+p->data;
//    }
//}
//int main(void)
//{
//    int A[] = {3,5,6,9,80};
//    
//    createLL(A,5);
//    CountNode(head);
//    
//    std::cout<<"Count recurse is = "<<CountRecurse(head)<<std::endl;
//    std::cout<<"Sum of all LL data is = "<<SumRecurse(head)<<std::endl;
//    return 0;
//}
//
