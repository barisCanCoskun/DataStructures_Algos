#include<iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findPairs(const std::vector<int>& arr1, 
                                        const std::vector<int>& arr2, int target) {
    //   +=========================================================+
    //   |                 WRITE YOUR CODE HERE                    |
    //   | Description:                                            |
    //   | - This function finds all pairs of integers from        |
    //   |   'arr1' and 'arr2' that sum up to 'target'.            |
    //   | - It uses an unordered_set for quick look-up.           |
    //   | - It returns a 2D vector containing the pairs.          |
    //   |                                                         |
    //   | Return type: vector<vector<int>>                        |
    //   |                                                         |
    //   | Tips:                                                   |
    //   | - 'mySet' stores numbers from 'arr1'.                   |
    //   | - 'pairs' will store the pairs that meet the target.    |
    //   | - Loop through 'arr1' to populate 'mySet'.              |
    //   | - Loop through 'arr2' to find pairs.                    |
    //   | - Use 'find' method for quick look-up in set.           |
    //   | - Check output from Test.cpp in "User logs".            |
    //   +=========================================================+
    
    
    
    std::vector<std::vector<int>> myVector;
    std::unordered_set<int> mySet{arr1.begin(), std::end(arr1)};
    for(const auto &i: arr2){
        if(mySet.find(target - i) != mySet.end())
            myVector.emplace_back((std::vector<int>){target - i, i});
            // myVector.push_back({target - i, i});
    }
    return myVector;

}

int main()
{
    std::vector<int> vector1{1, 2, 3};
    std::vector<int> vector2{4, 5, 6};
    int target{8};
    std::vector<std::vector<int>> vectorResult{findPairs(vector1, vector2, target)};
    std::cout << "[";
    for(const auto &v: vectorResult){
        std::cout << "(" << v[0] << ", " << v[1] << "), "; 
    }
    std::cout << "]" << std::endl;

    vector1 = {1, 2, 3};
    vector2 = {7, 7, 8, 9};
    target = 10;
    vectorResult = findPairs(vector1, vector2, target);
    std::cout << "[";
    for(const auto &v: vectorResult){
        std::cout << "(" << v[0] << ", " << v[1] << "), "; 
    }
    std::cout << "]" << std::endl; 
}















