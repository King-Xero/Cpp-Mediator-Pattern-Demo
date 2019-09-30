#include "CScoreUpdater.h"

void CScoreUpdater::AddScore( int score )
{
	m_pNotificationMediator->PublishScoreChange( score );
}

void CScoreUpdater::SubtractScore( int score )
{
	m_pNotificationMediator->PublishScoreChange( -score );
}
