#include<iostream>
#include<queue>

struct Node
{
    public:
        Node *left;
        Node *right;
        int data;

        Node(int val)
        {
            this->data = val;
            this->left = this->right = nullptr;
        }
};

class BinaryTree
{
    private:
       Node *root = nullptr;

    public:
        void insert(int val)
        {
            if(nullptr == root)
            {
                root = new Node(val); /// If tree is empty, insert the root node
                return;
             }

             std::queue<Node*>q;
            q.push(root);  // Push the root node to the queue

             while(!q.empty())
            {
                  Node *temp = q.front();
                 q.pop();

                 if(nullptr == temp->left)
                 {
                       temp->left = new Node(val);
                       break;
                 }
                 else
                    q.push(temp->left);

                  if(nullptr == temp->right)
                 {
                    temp->right = new Node(val);
                     break;
                }
               else
                  q.push(temp->right);
             }
        }

        void preorder(Node* root)
        {
            if(nullptr == root)
            {
                 return;
            }

            std::cout<<root->data<<"->";
            preorder(root->left);
            preorder(root->right);
        }

        void postorder(Node *root)
        {
             if(nullptr == root)
            {
                return;
            }

            postorder(root->left);
            postorder(root->right);
            std::cout<<root->data<<"->";
        }

        void Inorder(Node *root)
        {
            if(nullptr == root)
            {
                return;
             }

            Inorder(root->left);
            std::cout<<root->data<<"->";
            Inorder(root->right);
        }

        void printPreorder()
        {
             std::cout << "Preorder is = ";
             preorder(root); // Call private recursive function
             std::cout << std::endl;
        }

         void printInorder()
         {
             std::cout << "Inorder is = ";
             Inorder(root); // Call private recursive function
            std::cout << std::endl;
         }

         void printPostorder()
         {
             std::cout << "Postorder is = ";
            postorder(root); // Call private recursive function
            std::cout << std::endl;
        }
};

int main(void)
{
    BinaryTree BT;
    BT.insert(10);
    BT.insert(20);
    BT.insert(30);
    BT.insert(40);
    BT.insert(50);

    std::cout<<"Preorder is = ";
    BT.printPreorder();
    std::cout<<std::endl;
    std::cout<<"Postorder is  = ";
    BT.printPostorder();
    std::cout<<std::endl;
    std::cout<<"Inorder is =";
    BT.printInorder();
    return 0;
}