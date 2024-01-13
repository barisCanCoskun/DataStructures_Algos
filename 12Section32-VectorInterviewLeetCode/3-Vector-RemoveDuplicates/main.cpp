#include<iostream>

int removeDuplicates(std::vector<int> &vec);

int main()
{
    std::vector<int> nums{1,2,3,3,3,4,5,6,6,7,7,7,7,8};
    std::cout << "Before removing duplicates:" << std::endl;
    std::for_each(nums.begin(), nums.end(), 
                [](const int n) { std::cout << n << ' '; });
    std::cout << "\n";

    std::cout << "\nsize of vec: " << removeDuplicates(nums);
    std::cout << "\nAfter removing duplicates:" << std::endl;
    std::for_each(nums.begin(), nums.end(), 
                [](const int n) { std::cout << n << ' '; });
    std::cout << "\n";
    
}

int removeDuplicates(std::vector<int> &vec){
    if(vec.empty()) return 0;
    std::vector<int>::iterator itPrev{vec.begin()};
    std::vector<int>::iterator itNext{++vec.begin()};
    while(itNext != vec.end()){
        if(*itPrev == *itNext)
            vec.erase(itNext);
        else{
            ++itNext;
            ++itPrev;
        }
    }
    // vec.shrink_to_fit();
    return vec.size();
}














