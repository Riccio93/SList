#include <iostream>
#include "SList.h"

int main()
{
    SList<int> list;   

    std::cout << "Is the list empty? " << list.empty() << std::endl;

    std::cout << list.front() << std::endl;

    //Push front test
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    int num = list.front();
    std::cout << num << std::endl;

    std::cout << "Is the list empty? " << list.empty() << std::endl;    
}