#include<iostream>

// O(n^2)
// space complexity: O(1)
void insertionSort(int array[], int size){
    for(int i = 1; i < size; ++i){
        int j{i - 1};
        int temp{array[i]};
        while(temp < array[j]){
            array[j + 1] = array[j];
            array[j] = temp;
            if(j) --j;
        }
    }
}

int main()
{
    int array[]{4, 2, 6, 5, 1, 3};
    std::cout << "Before sorting:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;

    insertionSort(array, sizeof(array) / sizeof(array[0]));
    std::cout << "\nAfter sorting:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;
}















