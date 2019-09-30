// MediatorDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CScoreUpdater.h"
#include "CScoreKeeper.h"

int main()
{
	CNotificationMediator* notificationMediator = new CNotificationMediator();
	CScoreUpdater* scoreUpdater = new CScoreUpdater(notificationMediator);
	CScoreKeeper* scoreKeeper = new CScoreKeeper(notificationMediator, 0);
	
	while (true)
	{
		switch (std::cin.get())
		{
		case 'w':
			scoreUpdater->AddScore(10);
			break;
		case 's':
			scoreUpdater->SubtractScore(5);
			break;
		default:
			break;
		}
	}
}