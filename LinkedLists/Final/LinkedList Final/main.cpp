#include <iostream>

#define TEST
#ifdef TEST
#include "LinkedList.h"
#else
#include "YouTube.h"
#endif

#ifdef TEST
#pragma region Testing
class Int : public Node<Int>
{
public:
	Int()
		: Int(0)
	{
	}

	Int(int num)
		: Node(Node<Int>()), integer(num)
	{
	}

	int get() { return integer; }
	void set(int num) { integer = num; }

private:
	int integer;
};

void listTest()
{
	auto list = LinkedList<Int>();
	Int a(10);
	Int b(20);
	Int c(30);
	Int d(40);
	Int e(50);
	Int f(60);
	Int g(70);
	Int h(80);

	list.append(&a);
	list += b;
	list.prepend(&c);
	list.append(&d);
	list.append(&e);
	list.append(&f);
	list.append(&g);

	list.swap(&g, &c);

	list.insert(&h, 4);

	list -= b;

	Int third = list[2];

	try
	{
		Node<Int>* i = list.get(8);
	}
	catch (const std::out_of_range&)
	{
		std::cout << "Given index was out of range!\n";
	}

	for (auto& i : list)
	{
		std::cout << '[' << (int)i.getNodeIndex() << "]: " << i.get() << '\n';
	}

	std::cin.get();
}
#pragma endregion
#endif

int main()
{
#ifdef TEST
	listTest();
	return 0;
#endif
}