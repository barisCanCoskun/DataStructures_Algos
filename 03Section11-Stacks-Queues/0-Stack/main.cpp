#include<iostream>

struct Node
{
    int value;
    Node *next;
    Node(int val = 0)
        :value{val}, next{} {}
};

class Stack
{
private:
    Node *top;
    int height;
public:
    Stack(int val = 0);
    ~Stack();
    void display();

    void push(int);
    int pop();
    Node* getTop() {return top;}
    int getHeight() {return height;}

};

Stack::Stack(int val){
    Node *newNode{new Node(val)};
    top = newNode;
    height = 1;
}

Stack::~Stack(){
    Node *ptr{top};
    while(ptr){
        top = top->next;
        delete ptr;
        ptr = top;
    }
}

void Stack::display()
{
    Node *ptr{top};
    std::cout << std::endl;

    while (ptr){
        std::cout << ptr->value << " -> ";
        ptr = ptr->next;
    }
    std::cout << "/0";
    std::cout << std::endl;
}

// like prepend in LL
void Stack::push(int value){
    Node *ptr{new Node(value)};
    ptr->next = top;
    top = ptr;
    ++height;
}
// O(1)

// like removeFirst in LL
int Stack::pop(){
    if(!top) return INT_MIN;
    int valuePopped{top->value};
    Node *ptr{top};
    top = top->next;
    delete ptr;
    --height;
    return valuePopped;
}
// O(1)

int main()
{
    Stack myStack{2};
    // myStack.push(7);
    // myStack.push(3);
    // myStack.push(1);
    std::cout << "After pushing: ";
    myStack.display();

    std::cout << "\nPopped value: " << myStack.pop();
    myStack.display();
    std::cout << "\nPopped value: " << myStack.pop();
    myStack.display();

}















