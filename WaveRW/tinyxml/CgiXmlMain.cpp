#include "CgiXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
		cout<< "Usage: CgiXML filename" << endl;

	CgiXML *CgiXMLObj= new CgiXML();
	CgiXMLObj->LoadXml(argv[1]);
	
	JobInfo *pJI;
	char cid[3]={0};
	for(int index =0; index<5;index++ )
	{
		sprintf(cid, "%d", index);
		pJI = CgiXMLObj->GetJobInfo(cid);
		//pJI = CgiXMLObj->GetInfo("1");
		if (pJI != NULL)
		{
		  cout<< pJI->ID << endl;
		  cout<< pJI->Priority << endl;
		  cout<< pJI->Partition << endl;
		  cout<< pJI->Space << endl;
		  cout<< pJI->Name << endl;
		  cout<<"sub :"<< (pJI->Name).substr(0,2) << endl;
		  cout<< pJI->Status << endl;
		  
		  cout<< pJI->Size << endl;
		  cout<< pJI->Downloaded << endl;
		  cout<< pJI->TimeLeft << endl;
		  cout<< pJI->Percent << endl;
		  cout<< pJI->DwRate << " kB/s"<< endl;

		  cout<< pJI->UpRate << " kB/s"<< endl;
		  cout<< pJI->Npeers << endl;
		 
		  
		}
		else
		  cout << "null" << endl;
	}
	delete CgiXMLObj;
	CgiXMLObj = NULL;
	
	return 1;
	
}
