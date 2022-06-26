#include <iostream>
#include "ProgramData.h"

int main()
{
	addItems();
	ListItem* a = list.find((ListItemData)4);
	ListItem* b = list.find((ListItemData)8);
	ListItem* c = list.find((ListItemData)16);
	ListItem* d = list.find((ListItemData)32);

	std::cout << a->get() << '\n';
	std::cout << b->get() << '\n';
	std::cout << c->get() << '\n';
	std::cout << d->get() << "\n";
	std::cout << "Length: " << list.length() << "\n\n";

	list.remove(1);

	a = list.find((ListItemData)4);
	b = list.find((ListItemData)8);
	c = list.find((ListItemData)16);
	d = list.find((ListItemData)32);

	if (a != NULL) std::cout << a->get() << '\n';
	if (b != NULL) std::cout << b->get() << '\n';
	if (c != NULL) std::cout << c->get() << '\n';
	if (d != NULL) std::cout << d->get() << "\n";
	std::cout << "Length: " << list.length() << "\n\n";

	list.insert(ab, 1);

	a = list.find((ListItemData)4);
	b = list.find((ListItemData)8);
	c = list.find((ListItemData)16);
	d = list.find((ListItemData)32);

	if (a != NULL) std::cout << a->get() << '\n';
	if (b != NULL) std::cout << b->get() << '\n';
	if (c != NULL) std::cout << c->get() << '\n';
	if (d != NULL) std::cout << d->get() << "\n";
	std::cout << "Length: " << list.length() << "\n\n";

	std::cout << "Popped: " << list.pop()->get() << "\n";
	std::cout << "Length: " << list.length() << "\n\n";

	std::cin.get();

	return 0;
}