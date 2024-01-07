#include<iostream>

void quickSort(int a[], int leftIndex, int rightIndex);
int pivot(int a[], int pivotIndex, int endIndex);
void quickSortSingleFunc(int a[], int leftIndex, int rightIndex);

int main()
{
    int array[]{4, 6, 1, 7, 3, 2, 5};
    std::cout << "\nBefore quick sort:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;

    quickSortSingleFunc(array, 0, sizeof(array) / sizeof(array[0] - 1));
    std::cout << "\nAfter quick sort:" << std::endl;
    for(const auto &i: array)
        std::cout << i << " ";
    std::cout << std::endl;

}

void quickSort(int a[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return;

    int pivotIndex = pivot(a, leftIndex, rightIndex);
    quickSort(a, leftIndex, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, rightIndex);
}

int pivot(int a[], int pivotIndex, int endIndex){
    int swapIndex{pivotIndex};
    for(int i{pivotIndex + 1}; i <= endIndex; ++i){
        if(a[i] < a[pivotIndex]){
            ++swapIndex;
            if(i != swapIndex) std::swap(a[swapIndex], a[i]);
        }
    }

    if(swapIndex != pivotIndex) std::swap(a[pivotIndex], a[swapIndex]);
    return swapIndex;
}

void quickSortSingleFunc(int a[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return ;
    int swapIndex{leftIndex};   // pivotIndex = leftIndex

    for(int i{leftIndex + 1}; i <= rightIndex; ++i){
        if(a[i] < a[leftIndex]){
            ++swapIndex;
            if(swapIndex != i) std::swap(a[swapIndex], a[i]);
        }
    }
    if(swapIndex != leftIndex) std::swap(a[swapIndex], a[leftIndex]);

    quickSortSingleFunc(a, leftIndex, swapIndex - 1);
    quickSortSingleFunc(a, swapIndex + 1, rightIndex);

}















