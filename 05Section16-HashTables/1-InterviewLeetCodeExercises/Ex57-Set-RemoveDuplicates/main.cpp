#include<iostream>
#include <vector>
#include <unordered_set>
#include<set>

std::vector<int> removeDuplicates(const std::vector<int>& myList) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function removes duplicate integers from a   |
    //   |   given vector 'myList'.                            |
    //   | - It uses an unordered_set for quick look-up and    |
    //   |   elimination of duplicates.                        |
    //   | - Returns a vector of unique integers.              |
    //   |                                                     |
    //   | Return type: vector<int>                            |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'uniqueSet' stores unique numbers from 'myList'.  |
    //   | - Use 'begin()' and 'end()' to copy elements back   |
    //   |   to a vector.                                      |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    
    
    std::set<int> mySet;
    for(const auto &i: myList){
        if(mySet.find(i) == mySet.end())
            mySet.emplace(i);
    }
    
    std::vector<int> myVector{mySet.begin(), mySet.end()};
    return myVector;    
}

int main()
{
    std::vector<int> myVector{1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    std::vector<int> myVec{removeDuplicates(myVector)};

    for (const auto &i: myVec){
        std::cout << i << ", ";
    }
    
    
}















