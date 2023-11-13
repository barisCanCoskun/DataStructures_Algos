#include<iostream>
#include <string>
#include <unordered_set>

bool hasUniqueChars(const std::string& str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if a string 'str' has unique |
    //   |   characters.                                       |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - It returns a boolean value.                       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'charSet' stores characters we've seen.           |
    //   | - Loop through 'str' to populate 'charSet'.         |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - If a duplicate is found, return false.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    
    
    
    
    // std::unordered_set<char> mySet{str.begin(), str.end()};
    // std::string myString{mySet.begin(), mySet.end()};
    
    // if(str == myString)
    //     return true;
    // else
    //     return false;

    std::unordered_set<char> mySet;
    for (const auto &c: str){
        if(mySet.find(c) == mySet.end())
            mySet.emplace(c);
        else
            return false;
    }
    return true;
}

int main()
{
    std::string str{"apple"};
    if(hasUniqueChars(str))
        std::cout << str << " has unique chars" << std::endl;
    else
        std::cout << str << " has NOT unique chars" << std::endl;

    str = "orange";
    if(hasUniqueChars(str))
        std::cout << str << " has unique chars" << std::endl;
    else
        std::cout << str << " has NOT unique chars" << std::endl;
    
}















