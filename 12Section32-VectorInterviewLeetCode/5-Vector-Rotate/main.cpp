#include<iostream>

void rotate(std::vector<int> & ,int);
void rotateEfficient(std::vector<int> & ,int);

int main()
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7};
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int &n){std::cout << n << " ";});
    std::cout << "\n\n";
    std::cout << "\nEnter the number to rotate: ";
    int rot{};
    std::cin >> rot;
    
    rotateEfficient(numbers, rot);
    std::cout << "\nAfter rotating:" << std::endl;
    std::for_each(numbers.begin(), std::end(numbers), 
                [](const int &n){std::cout << n << " ";});
    std::cout << "\n\n";

}

// 1st try: O(n * (k % nums.size()))
void rotate(std::vector<int> &nums, int k){
    if(nums.empty()) return;
    k %= nums.size();
    while(k--){
        int temp{nums.back()};
        nums.pop_back();
        nums.insert(nums.begin(), temp);  // O(n)
    }
}

// 2nd try: O(n)  : more efficient
void rotateEfficient(std::vector<int> &nums, int k){
    if(nums.empty()) return;
    k %= nums.size();

    // first part of vector : O((nums.size() - k) / 2)
    for(size_t start{0}, end{nums.size() - k - 1}; start < end; ++start, --end){
        int temp{nums[start]};
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // second part of vector : O(k / 2)
    for(size_t start{nums.size() - k}, end{nums.size() - 1}; start < end; ++start, --end){
        int temp{nums[start]};
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // whole of vector : O(nums.size() / 2)
    for(size_t start{0}, end{nums.size() - 1}; start < end; ++start, --end){
        int temp{nums[start]};
        nums[start] = nums[end];
        nums[end] = temp;
    }
}















