#pragma once
#include <functional>

class CActionOnDestroy
{
public:

	CActionOnDestroy( std::function<void()> destroy_function )
		: fDestroyFunction( destroy_function )
	{
	}

	void Destroy( );

private:
	std::function< void()> fDestroyFunction;
};
