#include<iostream>
#include <set>
#include <map>

void mergeSort(int arr[], int size){
    if(size == 1) return ;
    int size1{size / 2};
    int size2{size - size1};
    int arr1[size1];
    int arr2[size2];

    for(int i{}; i < size1; ++i)
        arr1[i] = arr[i];
    for(int i{}; i < size2; ++i)
        arr2[i] = arr[size1 + i];

    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    
    int index1{}, index2{}, index{};
    while(index1 < size1 && index2 < size2){
        if(arr1[index1] <= arr2[index2]){
            arr[index++] = arr1[index1++];
        }
        else{
            arr[index++] = arr2[index2++];
        }
    }

    while(index1 < size1){
        arr[index++] = arr1[index1++];
    }
    while(index2 < size2){
        arr[index++] = arr2[index2++];
    }
}

void sortSet(int arr[], int size){
    std::set<int> mySet(arr, arr + size);
    for(const auto &s: mySet){
        int i{};
        arr[i++] = s;
    }
}

template<size_t N>
void sortMap(int (&arr)[N], int size){
    std::map<int, int> myMap;
    // in C++ a function parameter such as int arr[] is adjusted to int* arr and 
    // the range based loops cannot deal with a pointer.
    // One solution is to pass the array by reference. 
    // C++ does not allow you to pass plain arrays by value. 
    for(const auto &a: arr)  
        myMap[a]++;

    // ilk başta böyle yazmıştım
    // for(size_t i{}; i < size; ++i)
    //     myMap[a[i]]++;
    
    size_t i{};
    for(const auto &pair: myMap){
        int freq = pair.second;
        while(freq--) arr[i++] = pair.first;
    }

}

int main()
{
    int array[]{5, 3, 7, 1, 8, 2, 4, 6};
    std::cout << "\nBefore merge sorting:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;
    
    mergeSort(array, (sizeof(array) / sizeof(array[0])));
    std::cout << "\nAfter merge sorting:" << std::endl;;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << "\n" << std::endl;

    int array1[]{5, 3, 7, 1, 3, 8, 2, 4, 4, 3, 6};
    std::cout << "\nBefore map sorting:" << std::endl;
    for(const auto &i: array1)
        std::cout << i << " ";
    std::cout << std::endl;
    
    sortMap(array1, (sizeof(array1) / sizeof(array1[0])));
    std::cout << "\nAfter map sorting:" << std::endl;;
    for(const auto &i: array1)
        std::cout << i << " ";
    std::cout << "\n" << std::endl;

}















