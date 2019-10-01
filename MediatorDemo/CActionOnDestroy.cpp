#include "CActionOnDestroy.h"

void CActionOnDestroy::Destroy( )
{
	if (fDestroyFunction)
	{
		fDestroyFunction();
	}	
	fDestroyFunction = nullptr;
}
