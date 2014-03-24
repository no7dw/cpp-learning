#include "Vxml.h"
#include "Convert.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

	if(argc<2)
	{
		cout<< "Usage: Video filename" << endl;
		return -1;
	}
	Vxml *VxmlObj= new Vxml();
	VxmlObj->LoadXml(argv[1]);
	
// 	StartTimeArray[0]="00:00:00:00";
// 	StartTimeArray[1]="00:00:07:11";
// 	StartTimeArray[2]="00:00:12:07";
// 	StartTimeArray[3]="00:01:10:07";
// 	StartTimeArray[4]="00:20:12:07";
	
	
	cout<< "00:00:00:00 QueryNextStartPointbyTime should be : 00:00:07:11 =? "<< VxmlObj->QueryNextStartPointbyTime("00:00:00:00") << endl;
	cout<< "00:00:00:00 QueryPrevStartPointbyTime should be : 00:00:00:00 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:00:00:00") << endl << endl;
	
	cout<< "00:00:07:11 QueryNextStartPointbyTime should be : 00:00:12:07 =? "<< VxmlObj->QueryNextStartPointbyTime("00:00:07:11") << endl;
	cout<< "00:00:07:11 QueryPrevStartPointbyTime should be : 00:00:00:00 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:00:07:11") << endl << endl;
	cout<< "\n###\n" << endl;
	cout<< "00:00:06:11 QueryPrevStartPointbyTime should be : 00:00:00:00 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:00:06:11") << endl << endl;
	
	cout<< "\n###\n" << endl;
	cout<< "00:00:05:10 QueryPrevStartPointbyTime should be : 00:00:00:00 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:00:05:10") << endl << endl;
	
	cout<< "00:00:12:07 QueryNextStartPointbyTime should be : 00:00:25:00 =? "<< VxmlObj->QueryNextStartPointbyTime("00:00:12:07") << endl;
	cout<< "00:00:12:07 QueryPrevStartPointbyTime should be : 00:00:07:11 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:00:12:07") << endl << endl;
		
	cout<< "00:01:03:10 QueryNextStartPointbyTime should be : 00:01:19:09 =? "<< VxmlObj->QueryNextStartPointbyTime("00:01:03:10") << endl;
	cout<< "00:01:03:10 QueryPrevStartPointbyTime should be : 00:00:55:17 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:01:03:10") << endl << endl;
	
	cout<< "00:03:05:02 QueryNextStartPointbyTime should be : -1 =? "<< VxmlObj->QueryNextStartPointbyTime("00:03:05:04") << endl;
	cout<< "00:03:05:02 QueryPrevStartPointbyTime should be : 00:02:59:23 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:03:05:02") << endl << endl;
	cout << "\n###\n" << endl;
	
	cout<< "00:03:05:05 QueryPrevStartPointbyTime should be : 00:02:59:23 =? "<< VxmlObj->QueryPrevStartPointbyTime("00:03:05:05") << endl << endl;
			
	//cout << Convert::ToCharTime(75,17)<< endl;//(3705,07)
	cout << Convert::ToCharTime(0,0) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryNextStartPointbyTime(0,0) << endl;
	cout << Convert::ToCharTime(7,11) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryNextStartPointbyTime(7,11) << endl;
	cout << Convert::ToCharTime(12,7) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryNextStartPointbyTime(12,7) << endl;
	cout << Convert::ToCharTime(63,10) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryNextStartPointbyTime(63,10) << endl;
	cout << Convert::ToCharTime(185,2) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryNextStartPointbyTime(185,2) << endl;
	
	cout << Convert::ToCharTime(0,0) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryPrevStartPointbyTime(0,0) << endl;
	cout << Convert::ToCharTime(7,11) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryPrevStartPointbyTime(7,11) << endl;
	cout << Convert::ToCharTime(12,7) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryPrevStartPointbyTime(12,7) << endl;
	cout << Convert::ToCharTime(63,10) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryPrevStartPointbyTime(63,10) << endl;
	cout << Convert::ToCharTime(185,2) <<" QueryPrevStartPointbyTime " << VxmlObj->QueryPrevStartPointbyTime(185,2) << endl;
	
	for (int i=0 ;i<10; i++)
	  cout << VxmlObj->QueryStartPointbyID(i) << endl;
	
	delete VxmlObj;
	VxmlObj = NULL;
	
	return 0;
	
}
