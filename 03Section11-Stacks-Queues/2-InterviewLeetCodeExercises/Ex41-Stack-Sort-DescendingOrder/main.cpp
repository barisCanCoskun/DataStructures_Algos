#include<iostream>
#include<stack>


void display(std::stack<int> sta);
void sortStackDescending(std::stack<int>& inputStack) {
    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+
    
    
    
    
    std::stack<int> additionalStack;
    int temp;
    while(!inputStack.empty()){
        temp = inputStack.top();
        inputStack.pop();
        while(!additionalStack.empty() && temp > additionalStack.top()){
            inputStack.emplace(additionalStack.top());
            additionalStack.pop();
        }
        additionalStack.emplace(temp);
    }
    while (!additionalStack.empty()){
        inputStack.emplace(additionalStack.top());
        additionalStack.pop();
    }
}

int main()
{
    std::stack<int> myStack;
    for(const int &i: {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10})
        myStack.emplace(i);
    std::cout << "Before sorting:" << std::endl;
    display(myStack);
    sortStackDescending(myStack);
    std::cout << "After sorting:" << std::endl;
    display(myStack);
}

void display(std::stack<int> sta){
    while (!sta.empty()){
        std::cout << sta.top() << " -> ";
        sta.pop();
    }
    std::cout << "/0";
    std::cout << std::endl;
}














