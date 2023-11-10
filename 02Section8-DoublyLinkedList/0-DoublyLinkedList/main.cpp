#include<iostream>

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val = 0)
        : value{val}, next{}, prev{}{
    }
    // ~Node();
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;
public:
    DoublyLinkedList(int value = 0);
    ~DoublyLinkedList();
    void display();
    Node* getHead() {return head;}
    Node* getTail() {return tail;}
    int getLength() {return length;}

    void append(int value);
    void removeLast();
    void prepend(int value);
    void removeFirst();
    Node *getIndex(int index);
    bool setIndex(int index, int value);
    bool insert(int index, int val);
    void removeNode(int index);

};

DoublyLinkedList::DoublyLinkedList(int value){
    Node *newNode{new Node(value)};
    head = newNode;
    tail = newNode;
    length = 1;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node *temp{head};
    while (head){
        head = head->next;
        delete temp;
        temp = head;
        // --length;       // not necessary because default ctor will delete it
    }
}

void DoublyLinkedList::display()
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

void DoublyLinkedList::append(int value){
    Node *newNode{new Node(value)};
    if(!head)
        head = newNode;
    else{
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    ++length;
}

// O(1) :  if compare vector's pop_back(), vector Could be chosen as DS bec it is also O(1)
// it's Big O different from singly LL !
void DoublyLinkedList::removeLast(){
    if(!head){
        std::cout << "There is no list." << std::endl;
        return ;
    }
    Node *temp{tail};
    if(length == 1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    --length;
    std::cout << "Last Node deleted." << std::endl;
}
// O(1)

void DoublyLinkedList::prepend(int value){
    Node *newNode{new Node(value)};
    if(head){
        head->prev = newNode;
        newNode->next = head;
    }
    else
        tail = newNode;
    head = newNode;
    ++length;
}

void DoublyLinkedList::removeFirst(){
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
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    --length;
    std::cout << "First Node deleted." << std::endl;
}

// The most efficient way !!
Node *DoublyLinkedList::getIndex(int index){
    // if(!head) return nullptr;  // not necessary bec. below one checks...
    if(index < 0 || index > length - 1) return nullptr;
    if(index == length - 1) return tail;
    Node *ptr{head};
    if(index < length / 2){  // for the sake of efficiency
        for(size_t i{}; i < index; ++i){
            ptr = ptr->next;
        }
    }
    else{
        ptr = tail;
        for(size_t i{(size_t)length - 1}; i > index; --i){
            ptr = ptr->prev;
        }
    }
    return ptr;
}

bool DoublyLinkedList::setIndex(int index, int val){
    Node *ptr{getIndex(index)};
    if(ptr){
        ptr->value = val;
        return true;
    }
    return false;
}

bool DoublyLinkedList::insert(int index, int value){
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
    Node *newNode{new Node(value)};
    Node *ptr{getIndex(index)};
    Node *temp{ptr->prev};
    temp->next = newNode;
    newNode->next = ptr;
    newNode->prev = temp;
    ptr->prev = newNode;
    ++length;
    return true;
}

void DoublyLinkedList::removeNode(int index){
    if(!index) return removeFirst();
    if(index == length - 1) return removeLast();

    Node *ptr{getIndex(index)};
    if(!ptr) return ;
    // ptr->prev->next = ptr->next;
    // ptr->next->prev = ptr->prev;
    Node *before{ptr->prev};    //  // for the sake of readability
    Node *after{ptr->next};
    before->next = after;
    after->prev = before;
    delete ptr;
    --length;
}

int main()
{
    DoublyLinkedList *myDLLptr{new DoublyLinkedList(7)};
    myDLLptr->display();

    myDLLptr->append(4);
    myDLLptr->append(1);
    myDLLptr->display();

    myDLLptr->removeLast();
    myDLLptr->display();

    myDLLptr->removeLast();
    myDLLptr->removeLast();
    myDLLptr->removeLast();
    myDLLptr->display();

    myDLLptr->prepend(3);
    myDLLptr->display();
    myDLLptr->prepend(2);
    myDLLptr->display();

    myDLLptr->removeFirst();
    myDLLptr->display();

    myDLLptr->append(12);
    myDLLptr->append(20);
    myDLLptr->append(9);
    myDLLptr->display();

    int ind{};
    std::cout << "To get node enter index: ";
    std::cin >> ind;
    std::cout << "Index " << ind << ": " << myDLLptr->getIndex(ind) 
    << "\nValue: " << myDLLptr->getIndex(ind)->value << std::endl;

    myDLLptr->append(17);
    myDLLptr->append(25);
    myDLLptr->append(19);
    myDLLptr->display();

    std::cout << "To get node enter index" << std::endl;
    std::cout << "(This time enter close to tail): ";
    std::cin >> ind;
    std::cout << "Index " << ind << ": " << myDLLptr->getIndex(ind) 
    << "\nValue: " << myDLLptr->getIndex(ind)->value << std::endl;

    int value{};
    std::cout << "To set node enter index and value: ";
    std::cin >> ind >> value;
    myDLLptr->setIndex(ind, value);
    myDLLptr->display();

}















