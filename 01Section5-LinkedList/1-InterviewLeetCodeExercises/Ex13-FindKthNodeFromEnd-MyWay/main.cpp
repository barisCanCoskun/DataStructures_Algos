#include<iostream>
#include "linkedList.h"

int main()
{
    LinkedList ll;
    ll.append(7);
    ll.append(3);
    ll.append(11);
    ll.append(4);
    ll.append(20);
    ll.append(2);
    ll.append(10);
    
    Node* middle = ll.findKthFromEnd(ll.getHead(), 3);
    std::cout << "Value of middle node: " << middle->value << std::endl;
}

