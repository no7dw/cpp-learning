#ifndef _V_H
#define _V_H

class vir
{
public:
	virtual void DrawBackGround(  ) =0;
	/*virtual*/ void DrawScore( int index );
	virtual void DrawScore( int index, const char *text_head );

};
#endif

