#include "DataLib.h"

void reverseLinkedList(DataController* list)
{
	list->current = list->firstInList;
	DataType* nextToReverse = NULL; //Next one to reverse.
	DataType* previous = NULL; //The one we JUST reversed.

	while (list->current)
	{
		nextToReverse = list->current->next; //Save the next one to reverse.

		list->current->next = previous; //Setting the next of { current } as the one that was reversed last loop.

		previous = list->current; //Saving { current } as one we just reversed.

		list->current = nextToReverse;
	}
	list->firstInList = previous;
}