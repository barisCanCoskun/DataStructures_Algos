#include<iostream>

struct Node
{
    int value;
    Node *next;
    Node(int val = 0) : value{val}, next{} {}
};

class Queue
{
private:
    Node *first;
    Node *last;
    int length;
public:
    Queue(int val = 0);
    ~Queue();
    void display();

    void enqueue(int);
    int dequeue();
    Node* getFirst() {return first;}
    Node* getLast() {return last;}
    int getLength() {return length;}
};

Queue::Queue(int val){
    Node *newNode{new Node(val)};
    first = newNode;
    last = newNode;
    length = 1;
}

Queue::~Queue(){
    Node *ptr{first};
    while(ptr){
        first = first->next;
        delete ptr;
        ptr = first;
    }
}

void Queue::display()
{
    Node *ptr{first};
    std::cout << std::endl;

    while (ptr){
        std::cout << ptr->value << " -> ";
        ptr = ptr->next;
    }
    std::cout << "/0";
    std::cout << std::endl;
}

// like append in LL
void Queue::enqueue(int val){
    Node * newNode{new Node(val)};
    if(last)
        last->next = newNode;
    else    
        first = newNode;
    last = newNode;
    ++length;
}
// O(1)

// like removeFirst in LL
int Queue::dequeue(){
    if(!first) return INT_MIN;
    int valueDequeued{first->value};
    Node *ptr{first};
    first = first->next;
    if(!first)
        last = nullptr;
    delete ptr;
    --length;
    return valueDequeued;
}
// O(1)

int main()
{
    {
        std::cout << "\n----- Test: Non-Empty Queue -----\n";
        Queue queue(10);
        
        // Enqueue 20
        queue.enqueue(20);
        std::cout << "After enqueue 20 - First value: " << queue.getFirst()->value << " - EXPECTED: 10\n";
        std::cout << "Last value: " << queue.getLast()->value << " - EXPECTED: 20\n";
        std::cout << "Length: " << queue.getLength() << " - EXPECTED: 2\n";

        // Enqueue 30
        queue.enqueue(30);
        std::cout << "After enqueue 30 - First value: " << queue.getFirst()->value << " - EXPECTED: 10\n";
        std::cout << "Last value: " << queue.getLast()->value << " - EXPECTED: 30\n";
        std::cout << "Length: " << queue.getLength() << " - EXPECTED: 3\n";

        std::cout << ((queue.getFirst()->value == 10) && (queue.getLast()->value == 30) && 
                 (queue.getLength() == 3) ? "PASS\n" : "FAIL\n");
    }
}















