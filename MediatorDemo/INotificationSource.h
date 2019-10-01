#pragma once
#include "IReceiveNotifications.h"
#include "CActionOnDestroy.h"

class INotificationSource
{
public:
	virtual CActionOnDestroy* SubscribeToScoreChanges( IReceiveNotifications< int >& handler ) = 0;
};
