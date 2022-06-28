#include "YouTube.h"

using std::string;

YouTubeVideo::YouTubeVideo(YouTubeChannel* _channel_, time_t _timeOfUpload_, string _title, string _description_, string _url_)
	: channel(_channel_), timeOfUpload(_timeOfUpload_), title(_title), description(_description_), url(_url_), views(0), likes(0), dislikes(0)
{
}

YouTubeVideo::YouTubeVideo(YouTubeChannel* _channel_, time_t _timeOfUpload_, string _title, string _description_, string _url_, ViewCount _views_, Likes _likes_, Dislikes _dislikes_)
	: channel(_channel_), timeOfUpload(_timeOfUpload_), title(_title), description(_description_), url(_url_), views(_views_), likes(_likes_), dislikes(_dislikes_)
{

}

void YouTubeVideo::newView()
{
	views++;
}

void YouTubeVideo::liked()
{
	likes++;
}

void YouTubeVideo::disliked()
{
	dislikes++;
}

void YouTubeVideo::unLiked()
{
	likes--;
}

void YouTubeVideo::unDisliked()
{
	dislikes--;
}

time_t YouTubeVideo::getTimeOfUpload()
{
	return timeOfUpload;
}

string YouTubeVideo::getTitle()
{
	return title;
}

string YouTubeVideo::getDescription()
{
	return description;
}

string YouTubeVideo::getURL()
{
	return url;
}

ViewCount YouTubeVideo::getViews()
{
	return views;
}

Likes YouTubeVideo::getLikes()
{
	return likes;
}

Dislikes YouTubeVideo::getDislikes()
{
	return dislikes;
}

YouTubeVideo::~YouTubeVideo()
{

}