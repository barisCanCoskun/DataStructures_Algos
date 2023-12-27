#include<iostream>
#include<vector>
#include<unordered_map>

std::vector<int> twoSum(std::vector<int> nums, int target){
    std::unordered_map<int, int> myMap;

    int i{};
    for(const auto &v: nums){
        if(myMap.find(target - v) != myMap.end())
            return {myMap.at(target - v), i++};
        myMap[v] = i++;
    }

    return {};
}

int main()
{
    std::vector<int> numbers{1, 3, 5, 2, 4};
    // std::vector<int> numbers{1, 3, 7, 2, 4};
    // std::vector<int> numbers{1, 3, 5, 2, 4};
    int target{6};
    std::vector<int> result{twoSum(numbers, target)};
    std::cout << "Two sum of 6 indices are:";
    for(const auto &v: result)
        std::cout << v << " ";
    std::cout << std::endl;
}















