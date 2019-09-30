#include "CScoreKeeper.h"
#include <iostream>

void CScoreKeeper::OnNotificationReceived( int arg )
{
	m_iScore += arg;
}
