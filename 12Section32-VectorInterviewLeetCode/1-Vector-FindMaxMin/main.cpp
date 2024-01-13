#include<iostream>
#include<set>

std::vector<int> findMaxMin(const std::vector<int> &);

int main()
{
    std::vector<int> vector{16,3,4,1,5,2,9,7};
    std::vector<int> vecMaxMin{findMaxMin(vector)};
    std::cout << "\nVector:" << std::endl;
    for(const auto &i: vector)
        std::cout << i << " ";
    std::cout << "\n\n"; 
    std::cout << "Max and min values of vector: ";
    for(const auto &i: vecMaxMin)
        std::cout << i << " ";
    std::cout << "\n\n"; 

    vector = {5};
    vecMaxMin = findMaxMin(vector);
    std::cout << "\nVector:" << std::endl;
    for(const auto &i: vector)
        std::cout << i << " ";
    std::cout << "\n\n"; 
    std::cout << "Max and min values of vector: ";
    for(const auto &i: vecMaxMin)
        std::cout << i << " ";
    std::cout << "\n\n"; 

    
}

std::vector<int> findMaxMin(const std::vector<int> &vec){
    std::set<int> mySet(vec.begin(), std::end(vec));
    return {*mySet.rbegin(), *mySet.begin()};
}














