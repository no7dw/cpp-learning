#ifndef  _V_2_H
#define _V_2_H

#include "vir.h"

class vir2:public vir
{
public:
	virtual void DrawBackGround(  ) ;
	void DrawScore( int index, const char *text_head );
	void DrawScore( int index );
};
#endif


