#pragma once
#include <stdint.h>
#include <string>
#include <time.h>
#include "LinkedList.h"

typedef uint64_t ViewCount;
typedef uint64_t Likes;
typedef uint64_t Dislikes;
typedef uint64_t Subscribers;

class YouTubeAdmin;
class YouTubeVideo;

class YouTubeChannel : public Node<YouTubeChannel>
{
public:
	YouTubeChannel(std::string);
	~YouTubeChannel();
	void newVideo(YouTubeVideo*);
	void deleteVideo(YouTubeVideo*);
	YouTubeVideo* getVideo(std::string);
	std::string getName();
	Subscribers getSubscribers();
	ViewCount getViews();
	friend class YouTubeAdmin;
	LinkedList<YouTubeVideo> videos;

private:
	std::string name;
	Subscribers subscribers;
	ViewCount views;
};

class YouTubeVideo : public Node<YouTubeVideo>
{
public:
	YouTubeVideo(YouTubeChannel*, time_t, std::string, std::string, std::string);
	void newView();
	void liked();
	void unLiked();
	void disliked();
	void unDisliked();

	time_t getTimeOfUpload();
	std::string getTitle();
	std::string getDescription();
	std::string getURL();
	ViewCount getViews();
	Likes getLikes();
	Dislikes getDislikes();
	~YouTubeVideo();
	friend class YouTubeAdmin;
	friend class YouTubeChannel;

private:
	YouTubeVideo(YouTubeChannel*, time_t, std::string, std::string, std::string, ViewCount, Likes, Dislikes);
	YouTubeChannel* channel;
	time_t timeOfUpload;
	std::string title, description, url;
	ViewCount views;
	Likes likes;
	Dislikes dislikes;
};

YouTubeAdmin* authenticate(int64_t);

class YouTubeAdmin
{
public:
	friend YouTubeAdmin* authenticate(int64_t);

	YouTubeVideo* newVideo(YouTubeChannel*, time_t, std::string, std::string, std::string, ViewCount, Likes, Dislikes);

	void setViews(YouTubeChannel*, ViewCount);
	void setSubscribers(YouTubeChannel*, Subscribers);

	void setViews(YouTubeVideo*, ViewCount);
	void setLikes(YouTubeVideo*, Likes);
	void setDislikes(YouTubeVideo*, Dislikes);

	~YouTubeAdmin();
private:
	YouTubeAdmin();
};