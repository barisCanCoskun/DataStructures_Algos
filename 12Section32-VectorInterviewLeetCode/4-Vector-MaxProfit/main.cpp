#include<iostream>

int maxProfit(const std::vector<int> &nums);

int main()
{
    std::vector<int> numbers{7, 1, 5, 3, 6, 4};
    std::cout << "numbers:" << std::endl;
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int v) {std::cout << v << " ";});
    std::cout << "\n";

    std::cout << "\nMax profit: " << maxProfit(numbers) << "\n\n";

    numbers = {7, 2, 8, 1, 4, 6, 5};
    std::cout << "numbers:" << std::endl;
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int v) {std::cout << v << " ";});
    std::cout << "\n";

    std::cout << "\nMax profit: " << maxProfit(numbers) << "\n\n";

    numbers = {7, 6, 4, 3, 1};
    std::cout << "numbers:" << std::endl;
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int v) {std::cout << v << " ";});
    std::cout << "\n";

    std::cout << "\nMax profit: " << maxProfit(numbers) << "\n\n";

    numbers = {};
    std::cout << "numbers:" << std::endl;
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int v) {std::cout << v << " ";});
    std::cout << "\n";

    std::cout << "\nMax profit: " << maxProfit(numbers) << "\n\n";
    
}

int maxProfit(const std::vector<int> &nums){
    if(nums.empty()) return 0;
    int min{nums[0]};
    int maxPro{};
    for(int i{1}; i < nums.size(); ++i){
        if(nums[i] < min)
            min = nums[i];
        else{
            if((nums[i] - min) > maxPro)
                maxPro = nums[i] - min;
        }
    }
    return maxPro;
}















