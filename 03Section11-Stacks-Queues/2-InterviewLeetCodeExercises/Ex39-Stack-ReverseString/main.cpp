#include<iostream>
#include<stack>

std::string reverseString(const std::string& str);

int main()
{
    std::string myString{"Ahmet"};
    std::cout << "Before reversing string: " << myString << std::endl;
    std::string reversedStr{reverseString(myString)};
    std::cout << "After reversing string: " << reversedStr << std::endl;
    
}


std::string reverseString(const std::string &str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    
    std::stack<char> myStack;
    // auto it{str.begin()};
    // while(it != str.end())
    //     myStack.emplace(*(it++));
    for (const auto &c : str)
        myStack.emplace(c);
    
    std::string reversedString;
    // while(!myStack.empty()){
    //     char elem{myStack.top()};
    //     myStack.pop();
    //     reversedString.push_back(elem);
    // }
    while(!myStack.empty()){
        reversedString += myStack.top();
        myStack.pop();
    }
    return reversedString;
}














