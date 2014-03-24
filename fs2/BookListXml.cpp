 
#include "BookListXml.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


BookListXml::BookListXml()
{
	BookListSize = 2;
}

BookListXml::~BookListXml()
{
   
}


int BookListXml::GetListSize()
{
	return BookListSize;
}

