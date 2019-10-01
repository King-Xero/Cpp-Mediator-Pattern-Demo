#include "CScoreUpdater.h"

void CScoreUpdater::AddScore( int score ) const
{
	m_pNotificationMediator->PublishScoreChange( score );
}

void CScoreUpdater::SubtractScore( int score ) const
{
	m_pNotificationMediator->PublishScoreChange( -score );
}
