#ifndef __CDEQ_FINISH_H
#define __CDEQ_FINISH_H
#include "CDeqFinish.h"

class Deq;

class CDeqFinish: public BookListXml
{
public:
	static CDeqFinish* Instance();
protected:
	CDeqFinish();
	~CDeqFinish();
	
private:
	static CDeqFinish* _instance;

	
protected:
	
	int BookListSize;
	DQCI m_QCI;
	DQCI m_DUnReadyCI;
};
#endif
