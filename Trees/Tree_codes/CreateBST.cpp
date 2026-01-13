#include<iostream>

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
};

class BST
{
    private:
        Node *root = nullptr;

    public:
        void Insert(int key)
        {
            Node* p = root , *temp = nullptr , *r = nullptr;

            if(nullptr == root)
            {
                temp = new Node;
                temp->data = key;
                temp->left = temp->right = nullptr;
                root = temp;                                                                                    
                return;
            }

            while(p!=nullptr)
            {
                r = p;
                if(key<p->data)
                    p = p->left;
                else if(key>p->data)
                    p = p->right;
                else    
                    return;
            }

            temp = new Node;
            temp->data = key;
            temp->left = temp->right = nullptr;
            
            if(key<r->data)
                r->left = temp;
            else
                r->right = temp;
        }

    void insert1(int key)
    {
        root = insertRecursive(root, key);
    }
    Node* insertRecursive(Node* root , int key)
    {
         if(nullptr == root)
            {
                root = new Node;
                root->data = key;
                root->left = root->right = nullptr;                                                                    
                return root;
            }

            if(key<root->data)
                root->left = insertRecursive(root->left, key);
            else if(key>root->data)
                root->right = insertRecursive(root->right,key);

            return root;
    }

    void Inorder(Node *root)
    {
        if(nullptr == root)
            return;

        Inorder(root->left);
        std::cout<<root->data<<" ";
        Inorder(root->right);
    };

    Node* search(int key)
    {
        Node *t = root;
        while(nullptr!=t)
        {
            if(key == t->data)
                return t;
            else if(key < t->data)
                t = t->left;
            else
                t = t->right;
        }
        return nullptr;
    }

    int Height(Node *p)
    {
        if(nullptr == p)
            return -1;

        int leftHeight = Height(p->left);
        int rightHeight = Height(p->right);

        return leftHeight > rightHeight?leftHeight + 1:rightHeight + 1;
    }

    Node* InPre(Node *p)
    {
        while(p && p->right!=nullptr)
            p = p->right;

        return p;
    }

    Node* InSucc(Node *p)
    {
        while(p && p->left!=nullptr)
            p = p->left;

        return p;
    }

    Node* Delete(Node *p , int key)
    {
        if(nullptr == p)
            return nullptr;

        if(nullptr == p->left && nullptr == p->right)
        {
            if(p == root)
                root = nullptr;

            delete(p);
            p = nullptr;
            return p;
        }

        if(key < p->data)
            p->left = Delete(p->left,key);
        else if(key > p->data)
            p->right = Delete(p->right, key);

        else
        {
            if(Height(p->left) > Height(p->right))
            {
                Node* q = InPre(p->left);
                p->data = q->data;
                p->left = Delete(p->left, q->data);
            }
            else
            {
                Node* q = InSucc(p->right);
                p->data = q->data;
                p->right = Delete(p->right, q->data);
            }
        }

        return p;
    }

    void printInorder()
    {
        std::cout<<"Inorder of BST is = ";
        Inorder(root);
        std::cout<<std::endl;
    }

    void DeleteNode(int key)
    {
        std::cout<<"Deleted node is = ";
        std::cout<<Delete(root,key)<<std::endl;       
    }
};


int main(void)
{
    BST obj;
    // obj.Insert(10);
    // obj.Insert(5);
    // obj.Insert(20);
    // obj.Insert(30);
    // obj.Insert(15);
    // obj.Insert(25);
    // obj.printInorder();

    obj.insert1(10);
    obj.insert1(5);
    obj.insert1(20);
    obj.insert1(30);
    obj.insert1(15);
    obj.insert1(25);
    obj.printInorder();
    std::cout<<std::endl;
    // Node *ST = obj.search(15);  
    // if(ST)
    // {
    //     std::cout<<"element is found";
    // }
    // else
    // {
    //     std::cout<<"element is not found";
    // }
    obj.DeleteNode(20);
    std::cout<<"after delete: ";
    obj.printInorder();
    return 0;
}