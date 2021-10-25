//-------------------------------------------------------------
// indexObject.cpp
// This is the implementation file for the indexObject.h
// Author: Myint Aung, Jordan Hebler
//-------------------------------------------------------------
// This .cpp file contains the functions of the class indexObject
//
// This file makes use of the functions of the class indexObject which
// includes functions that will set the values of keytype, reference type, primary key, keylength, 
// reference length and header size and as well as functions
// to get those values after they are set
//-------------------------------------------------------------
#include <string>
#include "indexObject.h"
//
// @file dhObject.cpp
// @brief This is the implementation file for the class dhObject
//
// @author Myint Aung, Jordan Hebler
//

//  This is the constructor to set valid values to the data members of the class
//
// @param None
// @return None
// @pre None
// @post This is a constructor that sets valid values to the keytype, reference type, primary key, key length, reference length and header size.
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
//
//  accessor for keylength
//
// @param None
// @return This function returns the length of the key.
// @pre None
// @post This function returns the length of the key.
//
const int indexObject::getKeylength(){
    return keylength;
}
//
//  accessor for reference type
//
// @param None
// @return This function returns the type of the reference.
// @pre None
// @post This function returns the type of the reference.
//
const std::string indexObject::getReftype(){
    return reftype;
}
//
//  accessor for key type
//
// @param None
// @return This function returns the type of the key.
// @pre None
// @post This function returns type of the key.
//
const std::string indexObject::getKeytype(){
    return keytype;
}
//
//  accessor for reference length
//
// @param None
// @return This function returns the length of the reference.
// @pre None
// @post This function returns the length of the reference.
//
const int indexObject::getReflength(){
    return reflength;
}
//
//  accessor for header size
//
// @param None
// @return This function returns the size of the header.
// @pre None
// @post This function returns the size of the header.
//
const int indexObject::getHeadersize(){
    return headersize;
}
//
//  accessor for primary key
//
// @param None
// @return This function returns the primary key.
// @pre None
// @post This function returns the primary key.
//
const std::string indexObject::getPkey(){
    return pkey;
}
//
//  accessor for reference
//
// @param None
// @return This function returns the reference.
// @pre None
// @post This function returns the reference.
//
const std::string indexObject::getRef(){
    return ref;
}
//
//  Mutator for the keylength
//
// @param Integer This function takes an int value called Length as parameter to set the value of the key length.
// @return None
// @pre None
// @post This function sets the value of the key length.
//
void indexObject::setKeylength(int Length){
    keylength = Length;
}
//
//  Mutator for the reflength
//
// @param Integer This function takes an int value called refLength as parameter to set the value of the reference length.
// @return None
// @pre None
// @post This function sets the value of the reference length.
//
void indexObject::setReflength(int refLength){
    reflength = refLength;
}
//
//  Mutator for the headersize
//
// @param Integer This function takes an int value called size as parameter to set the value of the header size.
// @return None
// @pre None
// @post This function sets the value of the header size.
//
void indexObject::setHeadersize(int size){
    headersize = size;
}
//
//  Mutator for the keylength
//
// @param Integer This function takes a string value called keyType as parameter to set the type of the key.
// @return None
// @pre None
// @post This function sets the value of the key type.
//
void indexObject::setKeytype(std::string keyType){
    keytype = keyType;
}
//
//  Mutator for the reftype
//
// @param Integer This function takes a string value called refType as parameter to set the value of the reference type.
// @return None
// @pre None
// @post This function sets the value of the type of the reference.
//
void indexObject::setReftype(std::string refType){
    reftype = refType;
}
//
//  Mutator for the primary key
//
// @param Integer This function takes a string value called Pkey as parameter to set the value of the primary key.
// @return None
// @pre None
// @post This function sets the value of the primary key.
//
void indexObject::setPkey(std::string Pkey){
    pkey = Pkey;
}
//
//  Mutator for the reference
//
// @param Integer This function takes a string value called Ref as parameter to set the value of the reference.
// @return None
// @pre None
// @post This function sets the value of the reference.
//
void indexObject::setRef(std::string Ref){
    ref = Ref;
}
