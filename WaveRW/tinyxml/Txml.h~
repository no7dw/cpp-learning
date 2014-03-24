#ifndef __T_XML_H
#define __T_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"

#include "XXml.h"

class Txml : public XXml
{
public:
	Txml();
	~Txml();
private:
 
	QuestionItem QuestionItemArray[ExamNum];
	int QuestionItemArraySize;

	
public:

	int LoadXml(const char *XmlFilePath);
	QuestionItem QueryQuestionbyID(const char *ID);
	QuestionItem* QueryQuestionArray();
	bool IsImage(const char *ID = NULL);
};
#endif