#include  "deq.h"

int main(void)
{
	INTDEQUE dequetest;
	CourseItem CI1,CI2,CI3;

	CI1.ID="001";
	CI1.Name="Course1Name";
	CI1.Level=8;
	CI1.Path="\\tmp\\8\\001";
	CI2.ID="002";
	CI2.Name="Course2Name";
	CI2.Level=4;
	CI2.Path="\\tmp\\4\\002";
	CI3.ID="003";
	CI3.Name="Course3Name";
	CI3.Level=5;
	CI3.Path="\\tmp\\5\\003";

	Deq *dq = new Deq();
	
	dq->AddItem(CI1);
	dq->AddItem(CI2);
	dq->AddItem(CI3);

	
		
	printcontents(dq);
	dq->RemoveItem();
	dq->printcontents(dq);
	dq->RemoveItem("003");
	dq->printcontents(dq);

	delete dq;
}
