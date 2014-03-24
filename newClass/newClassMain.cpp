#include "newClass.h"

int main(void)
{
	newCT *pnCT =  new newCT();
	cout << "sizeof pnCT " << sizeof(pnCT) <<endl;
//	newCT::count++;
	pnCT->Init(1 , "dengwei");
	pnCT->printout();
	pnCT->printcount();
	delete pnCT;

	newCT nCT ;
	cout << "sizeof nCT " << sizeof(nCT) <<endl;
//	nCT.count++;
	nCT.Init(2 , "dengwei2");
	nCT.printout();
	newCT::printcount();
/*
	newCT nCT2 =  new newCT();//error: conversion from ‘newCT*’ to non-scalar type ‘newCT’ requested

	cout << "sizeof pnCT " << sizeof(nCT2) <<endl;
	nCT2.Init(3 , "dengwei3");
	nCT2.printout();
*/
}
