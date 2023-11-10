#include<iostream>
#include<unordered_set>
#include<unordered_map>

bool itemInCommon(std::vector<int>, std::vector<int>);

int main()
{
    std::vector<int> vector1{1, 3, 5};
    std::vector<int> vector2{2, 4, 5};

    std::cout << std::boolalpha << "There is an item in common: " << itemInCommon(vector1, vector2) << std::endl;

}

// O(n)
bool itemInCommon(std::vector<int> vec1, std::vector<int> vec2){
    std::unordered_set<int> mySet(vec1.begin(), vec1.end());
    // std::unordered_set<int> mySet;
    // for (const auto &i : vec1)
    //     mySet.emplace(i);
   
    for (const auto &i : vec2)
        if(mySet.find(i) != mySet.end())
            return true;
   
    return false;
}
// O(n)

// O(n)
// bool itemInCommon(std::vector<int> vec1, std::vector<int> vec2){
//     std::unordered_map<int, bool> myMap;
//     for (const auto &i : vec1)
//         myMap.emplace(i, true);
    
//     for (const auto &i : vec2)
//         if(myMap[i])
//             return true;
    
//     return false;
// }
// O(n)



















