#pragma once
#include <future>

class INotificationPublisher
{
public:
	virtual                     ~INotificationPublisher( ) = default;
	virtual void PublishScoreChange( int scoreDelta ) = 0;
};
