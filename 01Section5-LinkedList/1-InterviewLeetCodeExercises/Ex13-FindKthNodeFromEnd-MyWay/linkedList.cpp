#include "linkedList.h"

int LinkedList::count{};

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
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

void LinkedList::makeEmpty() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node * LinkedList::findKthFromEnd(Node *ptr, int index){
    if(!ptr)
        return nullptr;
    Node *temp = findKthFromEnd(ptr->next, index);
    if(count++ == index)
        return ptr;
    return temp;
    
}













