#include<iostream>
#include<unordered_set>

struct Node
{
    int value;
    Node *next;
    Node(int val = 0): value{val}, next{} {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList(int val = 0);
    ~LinkedList();
    void append(int val);
    void display();
    void removeDuplicates();
};

LinkedList::LinkedList(int val){
    Node *newNode{new Node(val)};
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList(){
    Node *ptr{head};
    while (ptr){
        head = head->next;
        delete ptr;
        ptr = head;
        --length;
    }
}

void LinkedList::append(int val){
    Node *newNode{new Node{val}};
    if(!head) 
        head = newNode;
    else 
        tail->next = newNode;
    tail = newNode;
    ++length;
}

void LinkedList::display(){
    std::cout << std::endl;
    std::cout << "[ ";
    Node *ptr{head};
    while (ptr){
        std::cout << ptr->value << " -> ";
        ptr = ptr->next;
    }
    std::cout << "/0 ]";
    std::cout << std::endl;
}

void LinkedList::removeDuplicates(){
    Node *ptr{head}, *temp{};
    std::unordered_set<int> mySet;
    while (ptr){
        if(mySet.emplace(ptr->value).second){
        // if(mySet.find(ptr->value) != mySet.end()){
        //     mySet.emplace(ptr->value);
            temp = ptr;
            ptr = ptr->next;
        }
        else{
            temp->next = ptr->next;
            delete ptr;
            --length;
            ptr = temp->next;
            if(temp == tail)
                tail = temp;
        }
    }
}

int main()
{
    LinkedList ll{4};
    ll.append(3);
    ll.append(5);
    ll.append(7);
    ll.append(3);
    ll.append(4);
    ll.append(8);
    ll.append(3);

    ll.display();
    ll.removeDuplicates();
    ll.display();
}















