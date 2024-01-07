/*
 Your task is to implement the merge(LinkedList& otherList) method.
 This method merges two sorted linked lists into a single sorted linked list. 
 Constraints:
 The otherList will be empty after the merge operation.
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
    void merge(LinkedList &otherList);

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

// first try
// void merge(LinkedList &otherList){
//     if(!otherList.length) return ;
//     if(!length){
//         head = otherList.head;
//         tail = otherList.tail;
//         length = otherList.length;
//         otherList.head = nullptr;
//         otherList.tail = nullptr;
//         otherList.length = 0;
//         return ;
//     }
//     Node *currentOriginal{head};
//     Node *prevOriginal{};
//     Node *currentOther{otherList.head};
//     Node *nextOther{currentOther->next};

//     while(currentOriginal && currentOther){
//         if(currentOriginal->value <= currentOther->value){
//             prevOriginal = currentOriginal;
//             currentOriginal = currentOriginal->next;
//         }
//         else{
//             if(head == currentOriginal)
//                 head = currentOther;
//             else
//                 prevOriginal->next = currentOther;
//             currentOther->next = currentOriginal;
//             prevOriginal = currentOther;
//             currentOther = nextOther;
//             if(nextOther) nextOther = currentOther->next;
//         }
//     }
//     if(currentOther){
//         prevOriginal->next = currentOther;
//         tail = otherList.tail;
//     }
//     otherList.head = nullptr;
//     otherList.tail = nullptr;
//     otherList.length = 0;
// }

// second try
// void LinkedList::merge(LinkedList &otherList){
//     if(!otherList.length) return;
//     Node *currentOriginal{head};
//     Node *prevOriginal{};
//     Node *currentOther{otherList.head};
//     Node *newNode;
//     length = this->length + otherList.length;

//     while(currentOriginal && currentOther){
//         if(currentOriginal->value <= currentOther->value){
//             prevOriginal = currentOriginal;
//             currentOriginal = currentOriginal->next;
//         }
//         else{
//             newNode = new Node{currentOther->value};
//             if(head == currentOriginal)
//                 head = newNode;
//             else
//                 prevOriginal->next = newNode;
//             newNode->next = currentOriginal;
//             prevOriginal = newNode;
//             currentOther = currentOther->next;
//         }
//     }
//     while(currentOther){
//         newNode = new Node{currentOther->value};
//         if(prevOriginal) // length == 0 at first
//             prevOriginal->next = newNode;
//         else
//             head = newNode;
//         prevOriginal = newNode;
//         currentOther = currentOther->next;
//     }
//     tail = newNode;

//     // deleting otherList
//     while(otherList.head){
//         Node *temp{otherList.head};
//         otherList.head = otherList.head->next;
//         delete temp;
//     }

//     otherList.head = nullptr;
//     otherList.tail = nullptr;
//     otherList.length = 0;

// }

// third try
// void LinkedList::merge(LinkedList &otherList){
//     if(!otherList.length) return ;
//     Node dummy(0);
//     Node *currentNode{&dummy};
//     Node *otherHead{otherList.head};
//     while(head && otherHead){
//         if(head->value <= otherHead->value){
//             currentNode->next = head;
//             head = head->next;
//         }
//         else{
//             currentNode->next = otherHead;
//             otherHead = otherHead->next;
//         }
//         currentNode = currentNode->next;
//     }

//     while(head){
//         currentNode->next = head;
//         head = head->next;
//         currentNode = currentNode->next;
//     }
//     while(otherHead){
//         currentNode->next = otherHead;
//         otherHead = otherHead->next;
//         currentNode = currentNode->next;
//     }

//     head = dummy.next;
//     tail = currentNode;
//     length += otherList.length;

//     otherList.head = nullptr;
//     otherList.tail = nullptr;
//     otherList.length = 0;
// }

// fourth try
void LinkedList::merge(LinkedList &otherList){
    if(!otherList.length) return ;
    Node dummy(0);
    Node *currentNode{&dummy};
    Node *otherHead{otherList.head};
    while(head && otherHead){
        if(head->value <= otherHead->value){
            currentNode->next = head;
            head = head->next;
        }
        else{
            currentNode->next = otherHead;
            otherHead = otherHead->next;
        }
        currentNode = currentNode->next;
    }

    if(otherHead){
        currentNode->next = otherHead;
        tail = otherList.tail;
    }
    if(head){
        currentNode->next = head;
    }

    head = dummy.next;
    length += otherList.length;

    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.length = 0;
}

int main()
{
    LinkedList llOrigin{1};
    llOrigin.append(3);
    llOrigin.append(5);
    llOrigin.append(7);
    llOrigin.append(9);

    LinkedList llOther{2};
    llOther.append(4);
    llOther.append(6);
    llOther.append(8);
    llOther.append(10);

    std::cout << "\nBefore merge:" << std::endl;
    std::cout << "Original list:" ;
    llOrigin.display();
    std::cout << "Other list:" ;
    llOther.display();
    
    llOrigin.merge(llOther);
    std::cout << "\nAfter merge:" << std::endl;
    std::cout << "Original list:" ;
    llOrigin.display();
    std::cout << "Other list:" ;
    llOther.display();
    

}















