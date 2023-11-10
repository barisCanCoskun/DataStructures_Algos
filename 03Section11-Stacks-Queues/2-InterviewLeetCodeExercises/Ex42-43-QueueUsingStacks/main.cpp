#include<iostream>
#include <stack>
#include <climits>

void displayQueue(std::stack<int> stack1, std::stack<int> stack2);

class QueueUsingTwoStacks {
private:
    std::stack<int> stack1, stack2;
public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            return INT_MIN;
        }
        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    
    
    void enqueue(int value){
        stack1.push(value);
    }
    
    void dequeue(){
        if(!stack2.empty()){
            stack2.pop();
            return ;
        }
        if(stack1.empty()) return;
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.pop();
    }

    std::stack<int> getStack1() {return stack1;}
    std::stack<int> getStack2() {return stack2;}

};

int main()
{
    QueueUsingTwoStacks obj;
    obj.enqueue(7);
    obj.enqueue(10);
    obj.enqueue(18);
    obj.enqueue(12);
    displayQueue(obj.getStack1(), obj.getStack2());
    std::cout << "Front of obj: " << obj.front();

    obj.enqueue(1);
    obj.enqueue(8);
    obj.enqueue(3);
    obj.enqueue(2);
    displayQueue(obj.getStack1(), obj.getStack2());

}

void displayQueue(std::stack<int> stack1, std::stack<int> stack2){
    std::cout << std::endl;
    while(!stack2.empty()){
        std::cout << stack2.top() << "->";
        stack2.pop();
    }
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
    }
    while(!stack2.empty()){
        std::cout << stack2.top() << "->";
        stack2.pop();
    }
    std::cout << "/0" << std::endl;
}














