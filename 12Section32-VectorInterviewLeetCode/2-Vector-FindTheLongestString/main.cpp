#include<iostream>
#include<map>
#include<string>

std::string findTheLongestString(const std::vector<std::string> vec){
    if(vec.empty()) return "";
    std::map<int, std::string> myMap;
    for(const auto &s: vec)
        if(myMap[s.length()].empty())
            myMap[s.length()] = s;
    
    std::cout << "\nThe length of strings and strings in vector in ascending order:" << std::endl;
    for(const auto &p:myMap)
        std::cout << p.first << " " << p.second << std::endl;
    std::cout << "\n";
    
    return myMap.rbegin()->second;
}

int main()
{
    std::vector<std::string> myVector{"abc", "defg", "a", "Turkey", "Germany",
    "NewZeland", "Australia", "Galatasaray", "Manchester", "Munich"};

    std::string resultStr{findTheLongestString(myVector)};
    std::cout << "The longest string in vector: " << resultStr << std::endl;

    myVector = {};
    resultStr = findTheLongestString(myVector);
    std::cout << "The longest string in vector: " << resultStr << std::endl;
    
}















