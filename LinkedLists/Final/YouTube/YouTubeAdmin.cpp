#include "YouTube.h"

using std::string;

YouTubeAdmin::YouTubeAdmin()
{
}

YouTubeVideo* YouTubeAdmin::newVideo(YouTubeChannel* _channel_, time_t _timeOfUpload_, string _title, string _description_, string _url_, ViewCount _views_, Likes _likes_, Dislikes _dislikes_)
{
	return new YouTubeVideo(_channel_, _timeOfUpload_, _title, _description_, _url_, _views_, _likes_, _dislikes_);
}

void YouTubeAdmin::setViews(YouTubeChannel* channel, ViewCount views)
{
	channel->views = views;
}

void YouTubeAdmin::setSubscribers(YouTubeChannel* channel, Subscribers subscribers)
{
	channel->subscribers = subscribers;
}

void YouTubeAdmin::setViews(YouTubeVideo* video, ViewCount views)
{
	video->views = views;
}

void YouTubeAdmin::setLikes(YouTubeVideo* video, Likes likes)
{
	video->likes = likes;
}

void YouTubeAdmin::setDislikes(YouTubeVideo* video, Dislikes dislikes)
{
	video->dislikes = dislikes;
}

YouTubeAdmin::~YouTubeAdmin()
{
}