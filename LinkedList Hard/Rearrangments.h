#pragma once
#include "LinkedList.h"

void reverseDoublyLinkedList(DoublyLinkedList* list)
{
	DoublyLinkedListItem* current = list->head; //Starting at head.
	DoublyLinkedListItem* nextToReverse = NULL;

	while (true)
	{
		nextToReverse = current->nextItem; //Save the next item to reverse.
		
		//Swap the prev and next
		DoublyLinkedListItem* nextTemp = current->nextItem;
		current->nextItem = current->previousItem;
		current->previousItem = nextTemp;

		//Calculate new index y = -x + i (y = new index, x = old index, i = highest index).
		current->index = ((-1 * current->index) + (list->itemCount - 1));

		if (nextToReverse == NULL) //if next is nothing, change the head to the current item and we are done.
		{
			list->head = current;
			return;
		}
		current = nextToReverse;
	}
}