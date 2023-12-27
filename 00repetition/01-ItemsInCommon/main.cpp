#include<iostream>
#include<unordered_set>

std::vector<int> commonItemsMap(const std::vector<int> &vec1, const std::vector<int> &vec2){
    std::unordered_map<int, bool> myMap;
    for (const auto &i: vec1){
        myMap[i] = true;
    }

    std::vector<int> commonVec;
    for (const auto &i: vec2){
        if(myMap[i])
            commonVec.push_back(i);
    }
    return commonVec;
}

std::vector<int> commonItemsSet(const std::vector<int> &vec1, const std::vector<int> &vec2){
    std::unordered_set<int> mySet(vec1.begin(), std::end(vec1));

    std::vector<int> commonVec;
    for (const auto &i: vec2){
        if(mySet.find(i) != mySet.end())
            commonVec.push_back(i);
    }
    return commonVec;
}

int main()
{
    std::vector<int> vector1{1, 3, 5, 7, 9, 11, 13};
    std::vector<int> vector2{2, 4, 5, 6, 8, 9, 10, 11};
    std::vector<int> commonVectorMap{commonItemsMap(vector1, vector2)};
    std::vector<int> commonVectorSet{commonItemsSet(vector1, vector2)};

    std::cout << "Common items with map:";
    for(const auto &i: commonVectorMap)
        std::cout << i << " ";
    
    std::cout << "\nCommon items with set:";
    for(const auto &i: commonVectorSet)
        std::cout << i << " ";

}















