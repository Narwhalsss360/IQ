#include "DataLib.h"

void reverseLinkedList(DataController* list)
{
	list->current = list->firstInList;
	DataType* nextToReverse = NULL;
	DataType* previous = NULL;

	while (list->current)
	{
		nextToReverse = list->current->next;
		list->current->next = previous;
		previous = list->current;
		list->current = nextToReverse;
	}
	list->firstInList = previous;
}