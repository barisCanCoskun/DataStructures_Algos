#include<iostream>
#include<unordered_map>
#include<unordered_set>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strings);
void printAnagrams(const std::vector<std::vector<std::string>> &myVector);

int main()
{
    std::vector<std::string> strings{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> myVector = groupAnagrams(strings);
    printAnagrams(myVector);

}

void printAnagrams(const std::vector<std::vector<std::string>> &myVector){
    std::cout << "{" << std::endl;
    for (const auto &myV: myVector){
        std::cout << " {";
        for (const auto &s: myV){
            std::cout << "\"" << s << "\"";
            if(auto it = myV.end() - 1; *it != s)
                std::cout << ",";
        }
        std::cout << "}";
        if(auto it = myVector.end() - 1; *it != myV)
            std::cout << ",";
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strings){
    std::unordered_map<std::string, std::vector<std::string>> myMap;
    for (const auto &str: strings){
        std::string s{str};
        std::sort(s.begin(), s.end());
        // if(myMap[s].empty())
        myMap[s].emplace_back(str);
    }
    // return (std::vector<std::vector<std::string>>)(myMap.begin(), myMap.end());

    std::vector<std::vector<std::string>> myVector;
    for (const auto &group: myMap){
        myVector.emplace_back(group.second);
    }
    return myVector;
}















