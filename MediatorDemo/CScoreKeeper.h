#pragma once
#include "IReceiveNotifications.h"
#include "CNotificationMediator.h"

class CScoreKeeper : IReceiveNotifications< int >
{
public:
	
	CScoreKeeper( CNotificationMediator* notification_mediator, int score );

	virtual ~CScoreKeeper( );

	void OnNotificationReceived( int arg ) override;

private:
	CNotificationMediator* m_pNotificationMediator;
	void* pNotificationHandler;
	std::mutex m_mtxScoreLock;
	int m_iScore;
};
