#include "CNotificationMediator.h"

void* CNotificationMediator::SubscribeToScoreChanges( IReceiveNotifications< int >& handler )
{
	return m_ScoreUpdateChannel.AddSubscriber(handler);
}

void CNotificationMediator::PublishScoreChange( int scoreDelta )
{
	m_ScoreUpdateChannel.PublishNotification(scoreDelta);
}
