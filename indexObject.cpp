#include <string>
#include "indexObject.h"


indexObject::indexObject()
{
	keytype = "";
	reftype = "";
	keylength = 0;
	reflength = 0;
}

const int indexObject::getkeylength(){
	return keylength;
}
const int indexObject::getreftype(){
	return reflength;
}

const std::string indexObject::getkeytype(){
	return keytype;
}

const std::string indexObject::getreflength(){
	return reftype;
}

const std::string indexObject::getPkey(){
	return pkey;
}

void indexObject::setkeyLength(int Length){
	keylength = Length;
}

void indexObject::setrefLength(int refLength){
	reflength = refLength;
}

void indexObject::setkeyType(std::string keyType){
	keytype = keyType;
}

void indexObject::setrefType(std::string refType){
	reftype = refType;
}

void indexObject::setpkey(std::string Pkey){
	pkey = Pkey;
}
