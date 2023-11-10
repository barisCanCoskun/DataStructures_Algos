#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    static int count;
    
public:
    LinkedList(int value = 0);
    ~LinkedList();

    void printList();
    Node* getHead() {return head; }
    Node* getTail() {return tail; }
    void makeEmpty();
    void append(int value);

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - Find the k-th node from the end of the list        |
    //   | - Return type: Node*                                 |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Use two pointers: 'slow' and 'fast'                |
    //   | - Move 'fast' k nodes ahead first                    |
    //   | - If 'fast' reaches null, k is too large             |
    //   | - Then move both 'slow' and 'fast' until end         |
    //   | - Return 'slow' as the k-th node from the end        |
    //   +======================================================+
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    Node *findKthFromEnd(Node *ptr, int index);
    
};














