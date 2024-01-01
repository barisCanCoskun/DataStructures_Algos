/*
 In this exercise, you will implement the bubbleSort() method 
 to sort a singly linked list using the Bubble Sort algorithm. 
 The goal is to sort the linked list in ascending order 
 without creating any new nodes. 
 You will only rearrange the value fields of the existing nodes.
*/
#include<iostream>

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
        : value{val}, next{nullptr}{}
    // The node class doesn't have a default destructor.
    // Because the node class does not contain any other objects that are created from other classes.
    // The LL class does have objects from another class which are nodes.
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList(int value = 0);
    ~LinkedList();
    void display();

    void append(int value);                         // O(1)
    void removeLast();                              // O(n)
    void prepend(int value);                        // O(1)
    void removeFirst();                             // O(1)
    bool insert(int index, int value);               // O(n)
    void remove(int index);                          // O(n)
    int find_by_index(int index);                   // O(n)
    int find_by_value(int index);                   // O(n)
    Node *get_index(int index);                     // O(n)
    bool set_index(int index, int value);           // O(n)
    void reverse();
    Node* getHead() {return head;}
    Node* getTail() {return tail;}
    int getLength() {return length;}
    void bubbleSort();  // O(n^2)
    void selectionSort();  // O(n^2)
    void insertionSort();  // O(n^2)

};

LinkedList::LinkedList(int value){
    Node *newNode{new Node(value)};
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node *temp{head};
    while (head){
        head = head->next;
        delete temp;
        temp = head;
    }
    // head, length and tail will get deleted by default Destructor 
    // tail = nullptr;      // not necessary
    // length = 0;          // not necessary
    // default Destructor get called even after creating the custom Destructor
}

void LinkedList::display()
{
    Node *ptr{head};
    std::cout << std::endl;

    while (ptr){
        std::cout << ptr->value << " -> ";
        ptr = ptr->next;
    }
    std::cout << "/0";
    std::cout << std::endl;
}

// O(1) :  if compare vector's push_back or emplace_back: vector Could also be chosen bec it is O(1)
void LinkedList::append(int value){
    Node *newNode{new Node(value)};
    if(!head)
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
    ++length;
}
// O(1)

// O(n) :  if compare vector's pop_back(), vector Would be chosen as data structure bec it is O(1)
void LinkedList::removeLast(){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return ;
    }
    Node *temp{head};
    if(length == 1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        while (temp->next != tail)
            temp = temp->next;
        tail = temp;
        temp = temp->next;
        tail->next = nullptr;
    }
    delete temp;
    --length;
    std::cout << "Last Node deleted." << std::endl;
}
// O(n)

// O(1) :  if compare vector: myVect.insert(myVect.begin(), 10), vector Would NOT be chosen bec it is O(n)
void LinkedList::prepend(int value){
    Node *newNode{new Node(value)};
    newNode->next = head;
    head = newNode;
    if(!tail)
        tail = newNode;
    ++length;
}
// O(1)

// O(1) :  if compare vector's myVect.erase(myVect.begin()), vector Would NOT be chosen as DS bec it is O(n)
void LinkedList::removeFirst(){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return ;
    }
    Node *temp{head};
    head = head->next;
    if(!head)
        tail = nullptr;
    delete temp;
    --length;
    std::cout << "First Node deleted." << std::endl;
}
// O(1)

// O(n) :  if compare vector: myVect.insert(myVect.begin() + 2, 10), vector Could also be chosen bec it is O(n)
bool LinkedList::insert(int index, int value){
    if((index < 0) || (index > length)){
        std::cout << "Out of bound" << std::endl;
        return false;
    }
    if(!index){  // index == 0
        prepend(value);
        return true;
    }
    if(index == length){
        append(value);
        return true;
    }
    Node *ptr{get_index(index - 1)};
    Node *newNode{new Node(value)};
    newNode->next = ptr->next;
    ptr->next = newNode;
    ++length;
    return true;
}
// O(n)

// O(n) :  if compare vector's myVect.erase(myVect.begin() + 3), vector Could also be chosen as DS bec it is O(n)
void LinkedList::remove(int index){
    if(!index) return removeFirst();
    if(index == length - 1) return removeLast();

    if((index < 0) || (index > length - 1)){
        std::cout << "Out of bound" << std::endl;
        return ;
    }
    Node *ptr{get_index(index - 1)};
    Node *temp{ptr->next};
    if(temp->next){
        ptr->next = temp->next;
        delete temp;
        --length;
    }
}
// O(n)

// O(n) :  if compare vector's myVect.at(3), vector Would be chosen as DS bec it is O(1)
int LinkedList::find_by_index(int index){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return -1;
    }
    if((index < 0) || (index > length - 1)){
        std::cout << "Out of bound" << std::endl;
        return -1;
    }
    else if (index == length - 1){
        return tail->value;
    }
    Node *temp{head};
    for (size_t i{0}; i < index; ++i){
        temp = temp->next;
    }
    return temp->value;
}
// O(n)

// O(n) :  if compare vector, vector Could also be chosen as DS bec it is O(n)
int LinkedList::find_by_value(int value){
    if(head){
        Node *temp{head};
        int index{1};
        while(temp->value != value)
            temp = temp->next;
        return index;
    }
    std::cout << "There is no list." << std::endl;
    return -1;
}
// O(n)

// O(n) :  if compare vector's myVect.at(3), vector Would be chosen as DS bec it is O(1)
Node *LinkedList::get_index(int index){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return nullptr;
    }
    if((index < 0) || (index > length - 1)){
        std::cout << "Out of bound" << std::endl;
        return nullptr;
    }
    if (index == length - 1){
        return tail;
    }
    Node *temp{head};
    for (size_t i{0}; i < index; ++i){
        temp = temp->next;
    }
    return temp;
}
// O(n)

// O(n)
bool LinkedList::set_index(int index, int value){
    Node *temp{get_index(index)};
    if(!temp)
        return false;
    temp->value = value;
    return true;
}
// O(n)

void LinkedList::reverse(){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return ;
    }
    Node *before{}, *temp{}, *after{head};
    for(size_t i{}; i < length; ++i){
        before = temp;
        temp = after;
        after = after->next;
        temp->next = before;
    }
    temp = head;
    head = tail;
    tail = temp;
}

void LinkedList::bubbleSort(){
    if(length < 2) return ;
    for (size_t i = length - 1; i > 0; --i){
        Node *ptr{head->next}, *prev{head};
        for(size_t j{}; j < i; ++j){
            if(prev->value > ptr->value){
                int temp{prev->value};
                prev->value = ptr->value;
                ptr->value = temp;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }   
}

void LinkedList::selectionSort(){
    if(length < 2) return ;
    Node *currentNode{head};
    while(currentNode->next){
        Node *searchNode{currentNode->next};
        Node *minNode{currentNode};
        while(searchNode){
            if(searchNode->value < minNode->value)
                minNode = searchNode;
            searchNode = searchNode->next;
        }
        if(minNode != currentNode){
            int temp = currentNode->value;
            currentNode->value = minNode->value;
            minNode->value = temp;
        }
        currentNode = currentNode->next;
    }
}

void LinkedList::insertionSort(){
    if(length < 2) return ;
    Node *sortedListHead{head};
    Node *unsortedListHead{head->next};

    sortedListHead->next = nullptr;  // detach from the list
    
    while(unsortedListHead){
        Node *currentNode{unsortedListHead};
        unsortedListHead = unsortedListHead->next;
        if(currentNode->value < sortedListHead->value){
            currentNode->next = sortedListHead;
            sortedListHead = currentNode;
        }
        else{
            Node *searchPointer{sortedListHead};
            while(searchPointer->next && (currentNode->value > searchPointer->next->value)){
                searchPointer = searchPointer->next;
            }
            currentNode->next = searchPointer->next;
            searchPointer->next = currentNode;
        }
    }
    head = sortedListHead;
    while(sortedListHead->next) 
        sortedListHead = sortedListHead->next;
    tail = sortedListHead;

}

int main()
{
    LinkedList ll{7};
    ll.append(5);
    ll.append(2);
    ll.append(9);
    ll.append(1);
    ll.append(6);
    ll.append(5);
    
    std::cout << "\nBefore insertion sort:" ;
    ll.display();
    
    ll.insertionSort();
    std::cout << "\nAfter insertion sort:";
    ll.display();
    

}















