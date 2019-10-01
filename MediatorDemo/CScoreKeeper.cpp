#include "CScoreKeeper.h"
#include <iostream>

CScoreKeeper::CScoreKeeper( CNotificationMediator* notification_mediator, int score ):
	m_pNotificationMediator( notification_mediator ),
	m_iScore( score )
{
	pNotificationHandler = m_pNotificationMediator->SubscribeToScoreChanges( *this );
}

CScoreKeeper::~CScoreKeeper( )
{
	pNotificationHandler->Destroy( );
}

void CScoreKeeper::OnNotificationReceived( int arg )
{
	std::lock_guard<std::mutex> lock(m_mtxScoreLock);

	m_iScore += arg;

	std::cout << "Current score is: " << m_iScore << std::endl;
}
