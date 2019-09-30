#pragma once
#include "IReceiveNotifications.h"
#include "CNotificationMediator.h"

class CScoreKeeper : IReceiveNotifications< int >
{
public:


	CScoreKeeper( CNotificationMediator* notification_mediator, int score )
		: m_pNotificationMediator( notification_mediator ),
		  m_iScore( score )
	{
		pNotificationHandler = m_pNotificationMediator->SubscribeToScoreChanges(*this);
	}

	~CScoreKeeper( )
	{
		//ToDo Dispose of pNotificationHandler
	}

	void OnNotificationReceived( int arg ) override;

private:
	CNotificationMediator* m_pNotificationMediator;
	void* pNotificationHandler;
	int m_iScore;
};
