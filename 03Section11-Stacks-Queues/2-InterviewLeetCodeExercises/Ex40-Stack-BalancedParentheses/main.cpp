#include<iostream>
#include<stack>

bool isBalancedParentheses(const std::string& str);

int main()
{
    std::cout << std::boolalpha;
    std::string myString{"((Ahm).(et)"};
    std::cout << myString << " is balanced parentheses: " << isBalancedParentheses(myString) << std::endl;
    
}


bool isBalancedParentheses(const std::string &str) {
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
    for (const auto &s : str){
        if(s == '(')
            myStack.emplace(s);
        else if (s == ')'){
            if(myStack.empty()) 
                return false;
            else
                myStack.pop();
        }
    }
    return myStack.empty();
}














