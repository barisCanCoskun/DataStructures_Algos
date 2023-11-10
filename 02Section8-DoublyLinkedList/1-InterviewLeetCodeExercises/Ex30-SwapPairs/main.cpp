#include <iostream>

using namespace std;

class Node { 
public: 
    int value;
    Node* next;
    Node* prev;

    Node(int value = 0) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr) {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getLength() {
        return length;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - The swapPairs function swaps adjacent pairs       |
    //   |   of nodes in a doubly linked list.                 |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Utilizes a dummyNode to simplify edge cases.      |
    //   | - Uses pointers to navigate and swap nodes.         |
    //   | - Pay close attention to the 'next' and 'prev'      |
    //   |   pointers of the nodes.                            |
    //   | - Works in-place; doesn't create new nodes.         |
    //   | - Always checks if the list is empty or has only    |
    //   |   one node.                                         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
        
        
        
        
        
        
        
        
        
    void swapPairs(){
        if(length < 2) return ;
        Node *p{head};
        Node *q{head->next};
        head = head->next;
        while(p && q){
            if(p->prev)
                p->prev->next = q;
            q->prev = p->prev;
            p->next = q->next;
            p->prev = q;
            q->next = p;
            if(p->next)
                p->next->prev = p;
            p = p->next;
            if(p)
                q = p->next;
            else
                tail = q->next;
        }
        if(p)
            tail = p;
    }
        
};

int main()
{
    cout << "\n----- Test: Swap Pairs with Multiple Nodes -----\n";
    DoublyLinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    cout << "DLL before swapping pairs:\n";
    list.printList();
    list.swapPairs();
    cout << "\nDLL after swapping pairs:\n";
    list.printList();
    //cout << "PASS/FAIL test: ";
    cout << (list.getHead()->value == 2 && 
                list.getHead()->next->value == 1 && 
                list.getHead()->next->next->value == 4 &&
                list.getHead()->next->next->next->value == 3 ? "PASS\n" : "FAIL\n");
}















