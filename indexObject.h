#ifndef INDEXOBJECT_H
#define INDEXOBJECT_H
#include <string>
/**
* @brief
* @details
*
* @author Myint Aung
*/
class indexObject
{
private: 
std:: string keytype, reftype, pkey;
int keylength, reflength;

public:
indexObject();
const int getkeylength();
const int getreftype();
const std::string getkeytype();
const std::string getreflength();
const std::string getPkey();

void setkeyLength(int Length);
void setrefLength(int refLength);
void setkeyType(std::string keyType);
void setrefType(std::string refType);
void setpkey(std::string Pkey);
};
	
#endif
