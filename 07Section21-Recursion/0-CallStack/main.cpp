#include<iostream>

void funcThree(){
    std::cout << "Three" << std::endl;
}

void funcTwo(){
    funcThree();
    std::cout << "Two" << std::endl;
}

void funcOne(){
    funcTwo();
    std::cout << "One" << std::endl;
}

int main()
{
    funcOne();
}















