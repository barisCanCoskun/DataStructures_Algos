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
    //   | - This is the isPalindrome method.                  |
    //   | - It checks if the list is a palindrome or not.     |
    //   | - Return type: bool                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - A list with 0 or 1 node is a palindrome.          |
    //   | - Create two pointers: forwardNode and backwardNode.|
    //   | - Loop from the start to the middle of the list.    |
    //   | - Compare forwardNode and backwardNode values.      |
    //   | - If any pair is not equal, return false.           |
    //   | - Otherwise, return true.                           |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    
    
    
    
    
// my way
    bool isPalindrome(){
        if(length < 2) return true;
        if(length == 2){
            if(head->value == tail->value)
                return true;
            else
                return false;
        }
        Node *p{head}, *q{tail};
        while((p != q) && (p->next != q)){
            if(p->value != q->value) 
                return false;
            p = p->next,
            q = q->prev;
        }
        return true;
    }

// instructor solution
    // bool isPalindrome() {
    //     if (length <= 1) return true;
    //     Node* forwardNode = head;
    //     Node* backwardNode = tail;
    //     for (int i = 0; i < length / 2; i++) {
    //         if (forwardNode->value != backwardNode->value) 
    //             return false;
    //         forwardNode = forwardNode->next;
    //         backwardNode = backwardNode->prev;
    //     }
    //     return true;
    // }
};

int main()
{
    
}















