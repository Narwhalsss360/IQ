#include <iostream>
#include "DataLib.h"

DataController dataList = DataController(); //Linked list manager.

//Items to add to linked list.
DataType abstracta = DataType(1, 4);
DataType abstractb = DataType(2, 581);
DataType abstractc = DataType(3, 530354);

int main()
{
    //Adding items to list manager.
    dataList.addData(abstracta);
    dataList.addData(abstractb);
    dataList.addData(abstractc);

    //Getting pointers to the items by ID that were added to the list.
    DataType* a = dataList.search(1);
    DataType* b = dataList.search(2);
    DataType* c = dataList.search(3);

    //Printing the data in the list.
    std::cout << a->get() << '\n';
    std::cout << b->get() << '\n';
    std::cout << c->get() << '\n';

    std::cin.get();
    return 0;
}