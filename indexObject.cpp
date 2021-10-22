#include <string>

#include "indexObject.h"

indexObject::indexObject()
{
    pkey = "";
    ref = "";
    keytype = "";
    reftype = "";
    keylength = 0;
    reflength = 0;
    headersize = 0;
}

const int indexObject::getKeylength(){
    return keylength;
}
const std::string indexObject::getReftype(){
    return reftype;
}

const std::string indexObject::getKeytype(){
    return keytype;
}

const int indexObject::getReflength(){
    return reflength;
}

const int indexObject::getHeadersize(){
    return headersize;
}

const std::string indexObject::getPkey(){
    return pkey;
}

const std::string indexObject::getRef(){
    return ref;
}

void indexObject::setKeylength(int Length){
    keylength = Length;
}

void indexObject::setReflength(int refLength){
    reflength = refLength;
}

void indexObject::setHeadersize(int size){
    headersize = size;
}

void indexObject::setKeytype(std::string keyType){
    keytype = keyType;
}

void indexObject::setReftype(std::string refType){
    reftype = refType;
}

void indexObject::setPkey(std::string Pkey){
    pkey = Pkey;
}

void indexObject::setRef(std::string Ref){
    ref = Ref;
}
