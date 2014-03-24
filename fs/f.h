#ifndef __F__H__
#define __F__H__

#include <stdio.h>
class f
{
public:
	 f();
	virtual ~f();
/*
virtual void	fun();
virtual void	fun2();
virtual void	fun3();
*/

virtual void draw();
	static int istatic;
protected:
	virtual void fun4();
	
public:
	char su_name[255];
	
private:
	char mid_name[255];
	
protected:
	char last_name[255];
	
// void	fun2();
};
#endif
