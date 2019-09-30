#pragma once
#include "CNotificationMediator.h"

class CScoreUpdater
{
public:
	explicit CScoreUpdater( CNotificationMediator* notification_mediator )
		: m_pNotificationMediator( notification_mediator )
	{
	}

	void AddScore( int score );
	void SubtractScore( int score );

private:
	CNotificationMediator* m_pNotificationMediator;
};
