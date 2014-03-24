#include "vir.h"
#include "vir2.h"

int main(void)
{
	vir *pv1 = new vir2();
	pv1->DrawBackGround();
	pv1->DrawScore(2,"abc");
	pv1->DrawScore(1);
}
