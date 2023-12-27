#include<iostream>
#include<queue>

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
    void destroy(Node* currentNode);

    bool insert(int);
    bool contains(int);
    Node *getRoot(){ return root;}
    void BFS();
};

BinarySearchTree::BinarySearchTree() : root{} {}
BinarySearchTree::~BinarySearchTree() { destroy(root); }

void BinarySearchTree::destroy(Node* currentNode) {
    if (currentNode == nullptr) return;
    if (currentNode->left) destroy(currentNode->left);
    if (currentNode->right) destroy(currentNode->right);
    delete currentNode;
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

void BinarySearchTree::BFS(){    
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *currentNode{q.front()};
        q.pop();
        std::cout << currentNode->value << " ";
        if(currentNode->left)
            q.push(currentNode->left);
        if(currentNode->right)
            q.push(currentNode->right);
    }
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
    
    myBST->BFS();

}















