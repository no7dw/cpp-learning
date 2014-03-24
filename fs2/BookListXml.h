#ifndef __BOOK_LIST_XML_H
#define __BOOK_LIST_XML_H

typedef deque<CourseInfo> DQCI;
//same BookList 3 obj
//no static
class BookListXml 
{
//protected:
public:
	BookListXml();
	
	~BookListXml();
private:
	DQCI QCI;
	int BookListSize;
	deque<CourseInfo> DUnReadyCI;  
	

//protected:	
public:
	
	
	DQCI* GetBookListQueue();
	CourseInfo *GetCourseInfo(const string &CourseID, bool bis9x = false);
	
	
	int GetListSize();
	deque<CourseInfo>* GetUnReadyCourseInfo();
 
	
};

#endif
