#include<iostream>

class Node
{
    public:
        int data;
        int height; //to check imbalance tree
        Node *left;
        Node *right;
};

class BST
{
    private:
        Node *root = nullptr;

    public:

    void insert1(int key)
    {
        root = Insert(root, key);
    }
    
    int NodeHeight(Node* p)
    {
        int hl,hr;
        hl = p && p->left?p->left->height:0;
        hr = p && p->right?p->right->height:0;

        return hl>hr?hl+1:hr+1;

    }

    int balancedFactor(Node *p)
    {
        int hl,hr;
        hl = p && p->left?p->left->height:0;
        hr = p && p->right?p->right->height:0;

        return hl-hr;
    }

    Node* LLRotation(Node* p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;        /*A = p
                                      B = pl
                                        C = plr*/

        pl->right = p;
        p->left = plr;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);

        if(root == p)
            root = pl;

        return pl;
    }

    Node* LRRotation(Node* p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;

        pl->right = plr->left;
        p->left = plr->right;

        plr->left = pl;
        plr->right = p;

        pl->height = NodeHeight(pl);
        p->height = NodeHeight(p);
        plr->height = NodeHeight(plr);

        if(root == p)
            root = plr  ;
        return plr;
    }

    Node* Insert(Node* _root, int key)
    { 
        if(nullptr == _root)
         {
             _root = new Node;
             _root->data = key;
             _root->height = 1;
             _root->left = root->right = nullptr;                                                                    
            return _root;
        }

        if(key<_root->data)
            _root->left = Insert(_root->left, key);
        else if(key>root->data)
            _root->right = Insert(_root->right,key);


            _root->height = NodeHeight(_root);

        if(balancedFactor(_root) == 2 && balancedFactor(_root->left) == 1)
            return LLRotation(_root);
        // else if(balancedFactor(root) == 2 && balancedFactor(root->left) == -1)
        //    return LRRotation(_root);
        // else if(balancedFactor(_root) == -2 && balancedFactor(root->right) == -1)
        //     return RRRotation(_root);
        // else if(balancedFactor(_root) == -2 && balancedFactor(root->right) == 1)
        //     return RLRotation(_root);

            
        return root;
    }

    void Inorder(Node *_root)
    {
        if(nullptr == _root)
            return;

        Inorder(_root->left);
        std::cout<<_root->data<<" ";
        Inorder(_root->right);
    };

    void printInorder()
    {
        std::cout<<"Inorder of AVL is = ";
        Inorder(root);
        std::cout<<std::endl;
    }
};

int main(void)
{
    BST obj;
    obj.insert1(10);
    obj.insert1(5);
    obj.insert1(2);

    
    return 0;
}