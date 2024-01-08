#include<iostream>
#include<vector>
// #include<algorithm>

void removeElement(std::vector<int> &nums, int val){
    // auto it{nums.begin()};
    std::vector<int>::iterator it{nums.begin()};
    while(it != nums.end()){
        if(*it == val)
            nums.erase(it);
        else
            ++it;
    }
}

int main()
{
    std::vector<int> numbers{2, 5, 1, 7, 3, 8, 1, 4, 1, 9, 1};
    std::cout << "\nBefore removing the element vector size:" << numbers.size() << std::endl;
    for(const auto &i: numbers)
        std::cout << i << " ";
    std::cout << "\n";
    std::cout << "\nEnter the element to be removed: ";
    int value{};
    std::cin >> value;

    removeElement(numbers, value);
    std::cout << "\nAfter removing the element vector size:" << numbers.size() << std::endl;
    for(const auto &i: numbers)
        std::cout << i << " ";
    std::cout << "\n";

    numbers = {2, 5, 1, 7, 3, 8, 1, 4, 1, 9, 1};
    std::cout << "\nAlternatively it can be done with std::remove and erase";
    std::cout << "\nBefore removing the same element vector size:" << numbers.size() << std::endl;
    for(const auto &i: numbers)
        std::cout << i << " ";
    std::cout << "\n";
    
    // auto noNumbersEnd = std::remove(numbers.begin(), std::end(numbers), value);
    std::vector<int>::iterator noNumbersEnd = std::remove(numbers.begin(), std::end(numbers), value);
    numbers.erase(noNumbersEnd, numbers.end());
    std::cout << "\nAfter removing the same element vector size:" << numbers.size() << std::endl;
    for(const auto &i: numbers)
        std::cout << i << " ";
    std::cout << "\n";
}















