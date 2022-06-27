#include <iostream>
#include "PgmData.h"
#include "Rearrengments.h"

void printList(DataController* list)
{
    list->current = list->firstInList;
    uint32_t i = 0;

    while (list->current)
    {
        std::cout << "list[" << i << ']' << ": " << list->current->data << '\n';
        list->current = list->current->next;
        i++;
    }
}

int main()
{
    //Adding items to list manager.
    dataList.addData(abstracta);
    dataList.addData(abstractc);
    dataList.addData(abstractb);

    printList(&dataList);
    reverseLinkedList(&dataList);
    printList(&dataList);

    //Getting pointers to the items by ID that were added to the list.
    DataType* i0 = dataList.search(1);
    DataType* i1 = dataList.search(3);
    DataType* i2 = dataList.search(2);

    //Printing the data in the list.
    std::cout << i0->get() << '\n';
    std::cout << i1->get() << '\n';
    std::cout << i2->get() << '\n';

    std::cin.get();
    return 0;
}