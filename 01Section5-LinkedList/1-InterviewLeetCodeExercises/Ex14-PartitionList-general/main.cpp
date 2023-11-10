#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value = 0) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int length;
    
public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        length = 1;
    }

    ~LinkedList() {
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
            cout << "empty";
        } else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    int getLength() {
        return length;
    }
    
    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        length = 0;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
        length++;
    }

    //   +======================================================+   
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - Partition list around value x                      |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create two dummy nodes for two new lists           |
    //   | - One list for nodes less than x                     |
    //   | - Another list for nodes greater or equal to x       |
    //   | - Loop through original list                         |
    //   | - Assign nodes to new lists based on value           |
    //   | - Merge the two new lists                            |
    //   | - Update the original list's head                    |
    //   +======================================================+ 
    
    
    
    
    
    
    
    
    
// every value smaller than "value" will be part of left side of nodes
    void partitionList(int value){
        // if(!head) return ;
        if(length < 2) return ;
        Node dummy1;
        Node dummy2;
        Node *prev1{&dummy1};
        Node *prev2{&dummy2};
        Node *ptr{head};
        while(ptr){
            if(ptr->value < value){
                prev1->next = ptr;
                prev1 = ptr;
            }
            else{
                prev2->next = ptr;
                prev2 = ptr;
            }
            ptr = ptr->next;
        }
        if(dummy1.next)
            head = dummy1.next;
        else
            head = dummy2.next;
        prev1->next = dummy2.next;
        prev2->next = nullptr;
    }

};

int main()
{
    
}















