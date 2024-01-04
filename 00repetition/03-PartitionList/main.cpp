/* 
   Implement the partitionList member function for the LinkedList class, 
   which partitions the list such that all nodes with values 
   less than x come before nodes with values greater than or equal to x.
*/

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
    void partitionList(int target){
        if(length < 2) return ;
        Node dummy1;  // for less than values
        Node dummy2;  // for greater than values
        Node *less{&dummy1};
        Node *greater{&dummy2};
        Node *current{head};
        
        while(current){
            if(current->value < target){
                less->next = current;
                less = current;
            }
            else{
                greater->next = current;
                greater = current;
            }
            current = current->next;
        }
        less->next = dummy2.next;
        greater->next = nullptr;
        head = dummy1.next;
    }

};

int main()
{
    LinkedList ll{3};
    ll.append(8);
    ll.append(5);
    ll.append(10);
    ll.append(2);
    ll.append(1);

    std::cout << "\nBefore partition:" << std::endl;
    ll.printList();
    
    std::cout << "Enter a target value from the list for partition: ";
    int target{};
    std::cin >> target;
    ll.partitionList(target);
    std::cout << "\nAfter partition:" << std::endl;
    ll.printList();
    
    std::cout << "\nSecond try:\n" << std::endl;

    LinkedList ll1{1};
    ll1.append(4);
    ll1.append(3);
    ll1.append(2);
    ll1.append(5);
    ll1.append(2);

    std::cout << "\nBefore partition:" << std::endl;
    ll1.printList();
    
    std::cout << "Enter a target value from the list for partition: ";
    std::cin >> target;
    ll1.partitionList(target);
    std::cout << "\nAfter partition:" << std::endl;
    ll1.printList();
}















