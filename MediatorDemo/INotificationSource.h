#pragma once
#include "IReceiveNotifications.h"

class INotificationSource
{
public:
	virtual void* SubscribeToScoreChanges( IReceiveNotifications< int >& handler ) = 0;
};
