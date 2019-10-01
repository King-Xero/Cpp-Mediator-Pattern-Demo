#pragma once

template < typename T >
class IReceiveNotifications
{
public:
	virtual ~IReceiveNotifications( ) = default;

	/// <summary>
	/// Functionality to be executed when the object receives a notification from the mediator
	/// </summary>
	/// <param name="arg"></param>
	virtual void OnNotificationReceived( T arg ) = 0;
};
