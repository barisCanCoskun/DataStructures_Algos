#include<iostream>
#include<vector>

class Stack
{
private:
    std::vector<int> stackVector;
public:
    void push(int);
    void pop();
    bool isEmpty();
    void printStack();
    int peek();
    int size();
    std::vector<int> &getStackVector();
};    

void Stack::push(int value){
    stackVector.emplace_back(value);
}

void Stack::pop(){
    // Calling pop_back on an empty container results in undefined behavior.
    if(!isEmpty())  
        stackVector.pop_back();
}

bool Stack::isEmpty(){
    if(stackVector.size()) return false;
    else return true;
}

void Stack::printStack(){
    std::cout << "[ ";
    std::for_each(stackVector.begin(), std::end(stackVector),
        [] (int x){
            std::cout << x << " ";
        }
    );
    std::cout << "]" << std::endl;
}

int Stack::peek(){
    return stackVector.at(stackVector.size() - 1);
}

int Stack::size(){
    return stackVector.size();
}

std::vector<int> &Stack::getStackVector(){
    return stackVector;
}

int main()
{
    Stack myStack;
    myStack.push(3);
    myStack.push(1);
    myStack.push(9);
    myStack.push(4);
    myStack.push(15);
    myStack.printStack();

    std::reverse(myStack.getStackVector().begin(), myStack.getStackVector().end());
    std::cout << "After reversing" << std::endl;
    myStack.printStack();
}















