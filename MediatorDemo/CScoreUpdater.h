#pragma once
#include "CNotificationMediator.h"

class CScoreUpdater
{
public:
	explicit CScoreUpdater( CNotificationMediator* notification_mediator )
		: m_pNotificationMediator( notification_mediator )
	{
	}

	void AddScore( int score ) const;
	void SubtractScore( int score ) const;

private:
	CNotificationMediator* m_pNotificationMediator;
};
