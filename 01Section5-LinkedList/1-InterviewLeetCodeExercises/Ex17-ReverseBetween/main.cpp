#include<iostream>

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

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - Reverse nodes between positions m and n            |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create a dummy node and set its next to head       |
    //   | - Use 'prev' pointer to go to m-th node              |
    //   | - Use 'current' pointer for m+1 to n nodes           |
    //   | - Loop to reverse m+1 to n nodes                     |
    //   | - Update original list's head                        |
    //   | - Free dummy node memory                             |
    //   +======================================================+
    
    
    
    
    
    
// first try    
// reverseBetween için ilk olarak bu kod yazılmıştı,
// nodeların yerlerini değiştir diye anlamıştım...
    void changeNodes(int m, int n){
        if(!head) return ;
        if(m == n) return ;
        Node *ptr{head}, *q{}, *temp{}, *tempPrev{}, *tempNext{};
        if(!m){
            temp = ptr;
            tempNext = temp->next;
            if(n == 1){
                ptr = ptr->next;
                q = ptr->next;
                head = ptr;
                head->next = temp;
                temp->next = q;
                return ;
            }
        }
        for(size_t i{}; i < n; ++i){
            if(i == m - 1){
                tempPrev = ptr;
                temp = ptr->next;
                tempNext = temp->next;
            }
            else if(i == n - 1){
                q = ptr;
                ptr = ptr->next;
                if(m == n - 1){
                    q = ptr->next;
                    tempPrev->next = ptr;
                    ptr->next = temp;
                    temp->next = q;
                    return ;
                }
                q->next = temp;
                temp->next = ptr->next;
                if(m){
                    tempPrev->next = ptr;
                    ptr->next = tempNext;
                }
                else{
                    head = ptr;
                    ptr->next = tempNext;
                }
            }
            ptr = ptr->next;
        }
    }
    
    void reverseBetween(int m, int n){
        if(!head) return ;
        if(m == n) return ; 
        Node *dummy{new Node};
        dummy->next = head;
        Node *prev{dummy};
        for (size_t i{}; i < m; ++i)
            prev = prev->next;
        
        Node *current{prev->next}, *temp{};
        for(size_t i{}; i < n - m; ++i){
            temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        head = dummy->next;     // if m == 0
        delete dummy;
    }
};

int main()
{
    
}















