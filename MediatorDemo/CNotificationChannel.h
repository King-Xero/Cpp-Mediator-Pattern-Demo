#pragma once
#include <vector>

#include "IReceiveNotifications.h"
#include "HelperFunctions.h"

template < typename T >
class CNotificationChannel
{
public:
	CNotificationChannel( )
	{
		m_aNotificationThreads.reserve( 10 );
	}

	/// <summary>
	/// Add an object to the list of subscribers that receive notifications via this channel.
	/// </summary>
	/// <param name="handler"></param>
	void* AddSubscriber( IReceiveNotifications< T >& handler );
	/// <summary>
	/// Publish a notification to all subscribers of this channel.
	/// </summary>
	/// <param name="argument"></param>
	void PublishNotification( T& argument );
private:
	std::vector< IReceiveNotifications< T >* > m_NotificationHandlers;
	std::vector< std::thread >                 m_aNotificationThreads;
};

template < typename T >
void* CNotificationChannel< T >::AddSubscriber( IReceiveNotifications< T >& handler )
{
	if ( HelperFunctions::Contains( m_NotificationHandlers, &handler ) )
	{
		//Object is already receiving notifications
	}

	m_NotificationHandlers.push_back( &handler );

	return nullptr;
	//ToDo return ActionOnDispose
}

template < typename T >
void CNotificationChannel< T >::PublishNotification( T& argument )
{
	const size_t iNumNotificationHandlers = m_NotificationHandlers.size( );

	for ( int i = 0; i < iNumNotificationHandlers; ++i )
	{
		m_aNotificationThreads.push_back( std::thread( [&]( )
		{
			m_NotificationHandlers[ i ]->OnNotificationReceived( argument );
		} ) );
	}
	for ( int i = 0; i < iNumNotificationHandlers; ++i )
	{
		m_aNotificationThreads[ i ].join( );
	}

	m_aNotificationThreads.clear( );
}
