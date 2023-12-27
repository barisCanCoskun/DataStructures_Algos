#include<iostream>

int factorial(int num){
    if(num == 1 || num == 0)
        return 1;
    return factorial(num - 1) * num;
}

int main()
{
    std::cout << "Enter a number to calculate of factorial:" << std::endl;
    int number;
    std::cin >> number;
    std::cout << number << "! = " << factorial(number) << std::endl;
}



















