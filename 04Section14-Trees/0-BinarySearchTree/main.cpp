#include<iostream>

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val = 0) :value{val}, left{}, right{} {}
};

class BinarySearchTree
{
private:
    Node *root;
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool insert(int);
    bool contains(int);
    Node *getRoot(){ return root;}
};

BinarySearchTree::BinarySearchTree() : root{} {}
BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::insert(int val){
    Node *newNode{new Node(val)};
    if(!root){
        root = newNode;
        return true;
    }
    Node *ptr{root};
    // while(true)
    while(ptr){
        if(ptr->value == val) return false;
        else if(ptr->value < val){
            if(!ptr->right){
                ptr->right = newNode;
                return true;
            }
            ptr = ptr->right;
        }
        else{
            if(!ptr->left){
                ptr->left = newNode;
                return true;
            }
            ptr = ptr->left;
        }
    }
    return false;
}

bool BinarySearchTree::contains(int val){
    // if(!root) return false;
    Node *ptr{root};
    while(ptr){
        if(ptr->value == val) return true;
        else if(ptr->value < val)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return false;
}

int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    
    myBST->insert(27);

    std::cout << "New value: " 
    << myBST->getRoot()->left->right->value << std::endl;
    
    std::cout << std::boolalpha << std::endl;
    std::cout << "Value 29 is contained: " 
    << myBST->contains(29) << std::endl;

    std::cout << "Value 52 is contained: " 
    << myBST->contains(52) << std::endl;
}















