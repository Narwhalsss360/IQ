#include <iostream>

//#define TEST
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
#else
typedef PrimitiveNode<int> int_node;
typedef LinkedList<int_node> int_list;
typedef ListUtility<int_node> int_list_utility;

int_node a(20);
int_node b(10);
int_node c(30);

int_list intList = int_list();
int_list_utility intUtil = int_list_utility(&intList);

LinkedList<YouTubeChannel> channels = LinkedList<YouTubeChannel>();

#pragma region Channels
YouTubeChannel channel_ArranStewart = YouTubeChannel("Arran Stewart");
YouTubeChannel channel_PaulDavids = YouTubeChannel("Paul Davids");
YouTubeChannel channel_PolarBear = YouTubeChannel("PolarBear");
#pragma endregion

YouTubeAdmin* admin;
#endif

#ifndef TEST
void addChannels()
{
	channels += channel_PaulDavids;
	channels += channel_PolarBear;
	channels += channel_ArranStewart;
}

void addVideos()
{
	channel_ArranStewart.newVideo(	admin->newVideo(&channel_ArranStewart,
									14,
									"New York Subway 6",
									"Part 4 From 1980`s to 1990`s",
									"https://www.youtube.com/watch?v=SDP628jQ41w&ab_channel=ArranStewart",
									96454,
									346,
									0));

	channel_ArranStewart.newVideo(	admin->newVideo(&channel_ArranStewart,
									14,
									"Subway Were Preservation Or Scrap",
									"this  movie  about   Subway Were   Preservation or  Scraps",
									"https://www.youtube.com/watch?v=SDP628jQ41w&ab_channel=ArranStewart",
									22408,
									92,
									0));

	channel_ArranStewart.newVideo(	admin->newVideo(&channel_ArranStewart,
									14,
									"ttc subways",
									"ttc  history  of  subway  in Toronto",
									"https://www.youtube.com/watch?v=CyVkyEClc00&ab_channel=ArranStewart",
									73041,
									270,
									0));

	channel_PolarBear.newVideo(	admin->newVideo(&channel_PolarBear,
								3,
								"Volvo is mad at pizza hut",
								"",
								"https://www.youtube.com/watch?v=wOA4lW5Qycw&ab_channel=PolarBear",
								189,
								5,
								0));

	channel_PolarBear.newVideo(	admin->newVideo(&channel_PolarBear,
								5,
								"4k Deagle Dust 2 Edit",
								"",
								"https://www.youtube.com/watch?v=S8riWI419fE&ab_channel=PolarBear",
								152,
								4,
								0));

	channel_PolarBear.newVideo(	admin->newVideo(&channel_PolarBear,
								5,
								"Elemental Knives -Karambit 2.0 Unboxing/ Review-",
								"",
								"https://www.youtube.com/watch?v=wHSKxCfgvGU&t=93s&ab_channel=PolarBear",
								5433,
								81,
								0));

	channel_PolarBear.newVideo(	admin->newVideo(&channel_PolarBear,
								5,
								"Elemental Knives -Karambit 2.0 Unboxing/ Review-",
								"",
								"https://www.youtube.com/watch?v=wHSKxCfgvGU&t=93s&ab_channel=PolarBear",
								5433,
								81,
								0));

	channel_PaulDavids.newVideo(admin->newVideo(&channel_PaulDavids,
								1,
								"How Paul Simon wrote the PERFECT chord progression",
								"We take a look at a wonderful Paul Simon track and gradually increase the complexity of the chords used. Tabs are available at my Patreon page!",
								"https://www.youtube.com/watch?v=SjPAeTrF1zg&ab_channel=PaulDavids",
								2402639,
								43000,
								0));

	channel_PaulDavids.newVideo(admin->newVideo(&channel_PaulDavids,
								1,
								"I can't believe I finally played this guitar | Extremely RARE Fender Stratocaster",
								"Join me on a guitar hunt in Los Angeles! We're visiting Norman's Rare Guitars and we play the most amazing guitars I've ever seen!",
								"https://www.youtube.com/watch?v=zZxd7UmEd7M&ab_channel=PaulDavids",
								1702689,
								49000,
								0));

	channel_PaulDavids.newVideo(admin->newVideo(&channel_PaulDavids,
								1,
								"THE STAIRWAY CHORD (and why nobody knows it's name...)",
								"This is the story about a mysterious chord that after 5 decades still hasn't been discovered... What is it's name? Thanks to @Adam Neely and @Rick Beato  for helping out!",
								"https://www.youtube.com/watch?v=eXqNyWehVEQ&ab_channel=PaulDavids",
								570010,
								28000,
								0));
}

void setData()
{
	admin->setSubscribers(&channel_ArranStewart, 625);
	admin->setViews(&channel_ArranStewart, 629059);
	admin->setSubscribers(&channel_PolarBear, 610);
	admin->setViews(&channel_PolarBear, 22429);
	admin->setSubscribers(&channel_PaulDavids, 2830000);
	admin->setViews(&channel_PaulDavids, 334240199);
}
#endif

static int compareChannelName(YouTubeChannel* a, YouTubeChannel* b)
{
	return strcmp(a->getName().c_str(), b->getName().c_str());
}

void sortChannelByName(LinkedList<YouTubeChannel>* list)
{
	for (NodeIndex outer = 0; outer < list->length() - 1; outer++)
	{
		for (NodeIndex inner = 0; inner < list->length() - outer - 1; inner++)
		{
			YouTubeChannel* a = (YouTubeChannel*)list->get(inner);
			YouTubeChannel* b = (YouTubeChannel*)list->get(inner + 1);
			if (compareChannelName(a, b) > 0)
				list->swap(a, b);
		}
	}
}

int compareNumbers(int_node* a, int_node* b)
{
	if (a->get() > b->get())
	{
		return 1;
	}
	return 0;
}

int main()
{
#ifdef TEST
	listTest();
	return 0;
#else
	admin = authenticate(69);
	if (admin == nullptr) throw std::exception("Authentication Error");
	addChannels();
	addVideos();
	setData();

	for (auto& channel : channels)
	{
		std::cout << '[' << channel.getName() << " Subscribers:" << channel.getSubscribers() << " Views:" << channel.getViews() << "]:\n";
		for (auto& video : channel.videos)
		{
			if (video.getNodeIndex() != 0) std::cout << "-----------------------------------------\n\n";
			std::cout << "  Title:" << video.getTitle() << '\n';
			std::cout << "  Years Ago:" << video.getTimeOfUpload() << '\n';
			std::cout << "  Views:" << video.getViews() << '\n';
			std::cout << "  Description:" << video.getDescription() << '\n';
			std::cout << "  Likes:" << video.getLikes() << '\n';
			std::cout << "  Dislikes:" << video.getDislikes() << "\n";
			std::cout << "  URL:" << video.getURL() << "\n\n";
		}

		if (!(channel.getNodeIndex() == channels.length() - 1)) std::cout << "=========================================\n\n";
	}

	sortChannelByName(&channels);

	intList += a;
	intList += b;
	intList += c;

	for (auto& num : intList)
	{
		std::cout << num.get() << '\n';
	}

	intUtil.bubbleSort(compareNumbers);

	for (auto& num : intList)
	{
		std::cout << num.get() << '\n';
	}

	std::cin.get();
#endif
}