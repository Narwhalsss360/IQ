#include "YouTube.h"

YouTubeChannel::YouTubeChannel(std::string _name_)
	: Node(Node<YouTubeChannel>()), videos(LinkedList<YouTubeVideo>()), name(_name_), subscribers(0), views(0)
{
}

void YouTubeChannel::newVideo(YouTubeVideo* video)
{
	videos.append(video);
}

std::string YouTubeChannel::getName()
{
	return name;
}

Subscribers YouTubeChannel::getSubscribers()
{
	return subscribers;
}

ViewCount YouTubeChannel::getViews()
{
	return views;
}

YouTubeVideo* YouTubeChannel::getVideo(std::string title)
{
	for (auto& video : videos)
	{
		if (video.title == title) return &video;
	}
	return nullptr;
}

void YouTubeChannel::deleteVideo(YouTubeVideo* video)
{
}

YouTubeChannel::~YouTubeChannel()
{
}