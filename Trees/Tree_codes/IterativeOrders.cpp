 #include<iostream>
#include<queue>
#include<stack>

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

        void Iterativepreorder(Node* root)
        {
            std::stack<Node*>st;

            while(root != nullptr || !st.empty())
            {
                if(nullptr != root)
                {
                    std::cout<<root->data<<"->";
                    st.push(root);
                    root = root->left;
                }
                else
                {
                    root = st.top();
                    st.pop();
                    root = root->right;
                }
            }
        }

        void Iterativepostorder(Node *root)
        {
            if(!root)
              return;

            std::stack<Node*>st1, st2;
            st1.push(root);

            while(!st1.empty())
            {
                Node* temp = st1.top();
                st1.pop();
                st2.push(temp);

                if(temp->left)
                  st1.push(temp->left);
                if(temp->right)
                    st1.push(temp->right);
            }

            while(!st2.empty())
            {
                std::cout<<st2.top()->data<<"->";
                st2.pop();
            }

        }

        void Iterativeinorderorder(Node *root)
        {
            std::stack<Node*>st;

            while(root != nullptr || !st.empty())
            {
                if(nullptr != root)
                {
                    st.push(root);
                    root = root->left;
                }
                else
                {
                    root = st.top();
                    st.pop();
                    std::cout<<root->data<<"->";
                    root = root->right;
                }
             }
        }

        void levelOrder(Node* root)
        {
            if(nullptr == root)
                return;

            std::queue<Node*> q;
            q.push(root);
        
            while(!q.empty())                 
            {
                Node* temp = q.front();
                q.pop();
                std::cout<<temp->data<<"->";

                if(temp->left)
                  q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }   

        }

        int countNodes(Node* root)
        {
            if(nullptr == root)
                return 0;

    
             // Recursively count nodes in left and right subtrees
            int x = countNodes(root->left);
            int y = countNodes(root->right);

            return x + y + 1; // Count the current node + left + right

                // if(root->left && root->right)
                //     return x+y+1;
                // else    
                //     x+y;
        }

        int Height(Node* root)
        {
            if(nullptr == root)
                return -1;

            // Recursively calculate the heights of left and right subtrees
            int leftHeight = Height(root->left);
            int rightHeight = Height(root->right);

              // Return the greater of the two heights + 1 (for the current node)
              return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
        }

        int minHeight(Node *root)
        {
            if(nullptr == root)
                return -1;

            int leftHeight = minHeight(root->left);
            int rightHeight = minHeight(root->right);

            if(root->left == nullptr)
                minHeight(root->right);
            
            if(root->right == nullptr)
                minHeight(root->left);

            return (leftHeight < rightHeight) ? leftHeight + 1 : rightHeight + 1;

        }
        void printPreorder()
        {
             std::cout << "Preorder is = ";
             Iterativepreorder(root); // Call private recursive function
             std::cout << std::endl;
        }

         void printInorder()
         {
             std::cout << "Inorder is = ";
             Iterativeinorderorder(root); // Call private recursive function
            std::cout << std::endl;
         }

         void printPostorder()
         {
             std::cout << "Postorder is = ";
            Iterativepostorder(root); // Call private recursive function
            std::cout << std::endl;
        }

          void printLevelorder()
         {
            std::cout << "LevelOrder is = ";
            levelOrder(root); // Call private recursive function
            std::cout << std::endl;
        }

        void printCnt()
        {
            std::cout << "Count of nodes is = " << countNodes(root);
            std::cout << std::endl;
        }

         void printHeight()
        {
            std::cout << "Height of tree is = "<< Height(root);
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

    BT.printPreorder();
    std::cout<<std::endl;
    BT.printPostorder();
    std::cout<<std::endl;
    BT.printInorder();
    std::cout<<std::endl;
    BT.printLevelorder();

    BT.printCnt();
    BT.printHeight();
    return 0;
}
