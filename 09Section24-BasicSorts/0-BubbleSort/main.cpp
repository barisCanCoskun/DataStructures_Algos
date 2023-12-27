#include<iostream>

// O(n^2)
// space complexity: O(1)
void bubbleSort(int array[], int size){
    for(uint8_t i = size - 1; i > 0; --i){
        for(uint8_t j = 0; j < i; ++j){
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
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

    bubbleSort(array, sizeof(array) / sizeof(array[0]));
    std::cout << "\nAfter sorting:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;
}















