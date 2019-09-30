#pragma once
#include "INotificationMediator.h"
#include "CNotificationChannel.h"

class CNotificationMediator : INotificationMediator
{
public:
	void* SubscribeToScoreChanges( IReceiveNotifications< int >& handler ) override;
	void  PublishScoreChange( int scoreDelta ) override;
private:
	CNotificationChannel< int > m_ScoreUpdateChannel;
};
