#include<iostream>
#include <set>
#include <vector>
#include <algorithm>

// method1
int longestConsecutiveSequence1(const std::vector<int>& nums) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest consecutive       |
    //   |   sequence of integers in a given array.            |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - Loop through each unique number in the set.       |
    //   | - For each number, check its sequence length.       |
    //   | - Update 'longestStreak' if a longer sequence is    |
    //   |   found.                                            |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numSet' stores unique numbers from 'nums'.       |
    //   | - 'longestStreak' keeps track of the longest        |
    //   |   sequence found so far.                            |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    if(nums.empty()) return 0;
    
    std::vector<int> myVec{nums};
    std::sort(std::begin(myVec), myVec.end());
    int length{1}, longest{1};
    for(size_t i{0}; i < myVec.size() - 1; ++i){
        if(myVec[i + 1] == myVec[i] + 1){
            ++length;
            if(length > longest)
                longest = length;
        }
        else
            length = 1;
    }
    
    return longest;
}

// method2
int longestConsecutiveSequence2(const std::vector<int>& nums) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function finds the longest consecutive       |
    //   |   sequence of integers in a given array.            |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - Loop through each unique number in the set.       |
    //   | - For each number, check its sequence length.       |
    //   | - Update 'longestStreak' if a longer sequence is    |
    //   |   found.                                            |
    //   |                                                     |
    //   | Return type: int                                    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'numSet' stores unique numbers from 'nums'.       |
    //   | - 'longestStreak' keeps track of the longest        |
    //   |   sequence found so far.                            |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
    if(nums.empty()) return 0;

    std::set<int> mySet{nums.begin(), nums.end()};
    size_t longest{1}, length{1};
    std::set<int>::iterator it = mySet.begin();

    while(it != mySet.end()){
        if(*it + 1 == *(++it)){
            ++length;
            if(length > longest)
                longest = length;
        }
        else
            length = 1;
    }

    return longest;
}

int main()
{
    std::vector<int> vec{2, 1, 6, 9, 4, 3, 7, 10, 11, 12, 13};

    std::cout << "Longest consecutive sequence: " << 
    longestConsecutiveSequence2(vec) << std::endl;
    
}















