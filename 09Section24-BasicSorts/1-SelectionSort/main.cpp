#include<iostream>

// O(n^2)
// space complexity: O(1)
void selectionSort(int array[], int size){
    for(uint8_t i = 0; i < size - 1; ++i){
        int minVal{i};
        for(uint8_t j = i + 1; j < size; ++j){
            if(array[j] < array[minVal])
                minVal = j;
        }
        if(minVal != i){
            int temp = array[i];
            array[i] = array[minVal];
            array[minVal] = temp;
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

    selectionSort(array, sizeof(array) / sizeof(array[0]));
    std::cout << "\nAfter sorting:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;
}















