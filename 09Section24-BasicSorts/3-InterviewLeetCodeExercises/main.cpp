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
    bool check();

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

bool check(){
    return true;
}

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

// first try insert
// O(n) :  if compare vector: myVect.insert(myVect.begin() + 2, 10), vector Could also be chosen bec it is O(n)
// int LinkedList::insert(int index, int value){
//     if((index < 0) || (index > length)){       // bound check
//         std::cout << "Out of bound." << std::endl;
//         return -1;
//     }
//     if(!head){
//         prepend(value);
//         return value;
//     }
// 
//     Node *ptr{head};
//     Node *temp{new Node(value)};
//
//     if(index == 0){
//         temp->next = head;
//         head = temp;
//     }
//     else{
//         for (size_t i{1}; i < index; i++){
//             ptr = ptr->next;
//         }
//         temp->next = ptr->next;
//         ptr->next = temp;
//     }
//     tail = temp;
//     ++length;
//     return value;
// }
// // O(n)

// second try insert
// O(n) :  if compare vector: myVect.insert(myVect.begin() + 2, 10), vector Could also be chosen bec it is O(n)
// bool LinkedList::insert(int index, int value){
//     if(!index){
//         prepend(value);
//         return true;
//     }
//     Node *temp{get_index(index)};
//     if(!temp){
//         if(index == length){
//             append(value);
//             return true;
//         }
//         return false;
//     }
//     Node *ptr{head};
//     Node *newNode{new Node(value)};
//     while (ptr->next != temp){
//         ptr = ptr->next;
//     }
//     ptr->next = newNode;
//     newNode->next = temp;
//     ++length;
//     return true;
// }
// // O(n)

// third try insert
// O(n) :  if compare vector: myVect.insert(myVect.begin() + 2, 10), vector Could also be chosen bec it is O(n)
// bool LinkedList::insert(int index, int value){
//     if(!index){
//         prepend(value);
//         return true;
//     }
//     if(index == length){
//         append(value);
//         return true;
//     }
//     if(!get_index(index)){
//         return false;
//     }
//     Node *ptr{head};
//     Node *newNode{new Node(value)};
//     for(size_t i{0}; i < index - 1; ++i)
//         ptr = ptr->next;
//     newNode->next = ptr->next;
//     ptr->next = newNode;
//     ++length;
//     return true;
// }
// // O(n)

// last try insert
// O(n) :  if compare vector: myVect.insert(myVect.begin() + 2, 10), vector Could also be chosen bec it is O(n)
bool LinkedList::insert(int index, int value){
    if((index < 0) || (index > length)){
        std::cout << "Out of bound" << std::endl;
        return false;
    }
    if(!index){
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

// first try remove
// O(n) :  if compare vector's myVect.erase(myVect.begin() + 3), vector Could also be chosen as DS bec it is O(n)
// int LinkedList::remove(int index){
//     if(head){
//         if(index < 1 || index > length){
//             std::cout << "Out of bound" << std::endl;
//             return -1;
//         }
//         else if (index == 1){
//             removeFirst();
//             return 1;
//         }
//         else if (index == length){
//             removeLast();
//             return 1;
//         }
//        
//         Node *temp{head}, *following{nullptr};
//         for (size_t i{1}; i < index; ++i){
//             following = temp;
//             temp = temp->next;
//         }
//         following->next = temp->next;
//         delete temp;
//         --length;
//         return 1;
//     }
//     std::cout << "There is no list." << std::endl;
//     return -1;
// }
// // O(n)

// second try remove
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

bool LinkedList::check(){
    return true;
}

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

int main()
{
    LinkedList l{7};
    int value{};
    int index{};
    std::cout << "Enter the index and value to be inserted: ";
    std::cin >> index >> value;
    value = l.insert(index, value);
    if(value != -1){
        std::cout << "Index " << index << " with value " << value << " inserted." << std::endl;
    }
    l.display();
    std::cout << "Length of list: " << l.getLength() << std::endl;

    l.append(5);
    l.append(1);
    l.append(12);
    l.display();
    index = 3;
    // Node *n{l.get_index(index)};
    std::cout << "Value of index: " << index << " : " << l.get_index(index)->value << std::endl;
    
}

/*
Why Node* instead of smart pointer ?
Why dont we use smart pointers to avoid managing the lifecycle ourselves ?

Despite their usefulness in managing memory, there are a few reasons to not use smart pointers in a course like this:

Focus on core concepts: The primary objective of a course like this is to teach students the fundamentals 
of data structures and algorithms. The focus is on understanding how these data structures work, 
their time and space complexity, and how to implement and use them effectively. 
Introducing smart pointers may add an extra layer of complexity that could distract from the main learning objectives.

Manual memory management: In many cases, courses are designed to teach students how to manage memory manually 
using raw pointers. This allows them to understand the inner workings of memory allocation, deallocation, 
and the problems that can arise, such as memory leaks and dangling pointers. 
While smart pointers help to mitigate these issues, understanding the raw pointers' behavior is essential 
in developing a deep understanding of memory management in C++.

Performance considerations: While smart pointers provide convenience and safety, 
they can also introduce some overhead due to reference counting and other features. 
In performance-critical scenarios, this overhead may not be acceptable. 
Therefore, teaching the efficient use of raw pointers helps students to maximize performance.

Legacy code and libraries: Many C++ projects and libraries have a long history and might not use smart pointers 
due to the time they were developed or compatibility reasons. 
It's essential for students to learn how to work with raw pointers to be able to understand and maintain such codebases.

*/

// it can be done so the node makes the linkedlist class its own friend class
// to have friend class LinkedList; in the Node class













