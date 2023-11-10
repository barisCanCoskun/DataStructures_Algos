#include<iostream>
#include<unordered_map>
#include<unordered_set>

std::vector<int> findDuplicates(const std::vector<int> &nums);

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 4, 5, 5, 6, 7, 8};
    
    std::vector<int> vecDuplicate = findDuplicates(vec);
    for (const auto &i: vecDuplicate)
        std::cout << i << ", ";
    std::cout << std::endl;
    
}

//O(n)
std::vector<int> findDuplicates(const std::vector<int> &nums){
    std::vector<int> vec;
    // std::unordered_map<int, int> myMap;
    // for (const auto &i: nums)
    //     if(myMap[i]++)
    //         vec.emplace_back(i);

    // std::unordered_map<int, bool> myMap;
    // for (const auto &i: nums)
    //     if(myMap.find(i) != myMap.end())
    //         vec.emplace_back(i);
    //     else
    //         myMap.emplace(i, true);

    std::unordered_set<int> mySet;
    for (const auto &i: nums)
        if(mySet.find(i) != mySet.end())
            vec.emplace_back(i);
        else
            mySet.emplace(i);

    return vec;
}
//O(n)














