#pragma once
#include <vector>

#include "IReceiveNotifications.h"
#include "HelperFunctions.h"

template < typename T >
class CNotificationChannel
{
public:
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
};

template < typename T >
void* CNotificationChannel< T >::AddSubscriber(IReceiveNotifications< T >& handler)
{
	if (HelperFunctions::Contains(m_NotificationHandlers, &handler))
	{
		//Object is already receiving notifications
	}

	m_NotificationHandlers.push_back( &handler);

	return nullptr;
	//ToDo return ActionOnDispose
}

template < typename T >
void CNotificationChannel< T >::PublishNotification(T& argument)
{
	for (auto kHandler : m_NotificationHandlers)
	{
		kHandler->OnNotificationReceived(argument);
	}
}