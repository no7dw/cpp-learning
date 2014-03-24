#include "CDeqFinish.h"

CDeqFinish* CDeqFinish::_instance = 0;



CDeqFinish* CDeqFinish::Instance()
{
	if(_instance == 0)
	{
		_instance = new CDeqFinish();
	}
	return _instance;
}
