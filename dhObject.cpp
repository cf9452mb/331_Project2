//-------------------------------------------------------------
// dhObject.cpp
// This is the implementation file for the dhObject.h
// Author: Myint Aung, Jordan Hebler
//-------------------------------------------------------------
// This .cpp file contains the functions of the class dhObject
//
// This file makes use of the functions of the class dhObject which
// includes functions that will set the values of file structure
// type, primary key ordinal position, header record size, size format type,
// index file name, record count and count of fields per record
// and as well as functions to get those values after
// they are set
//-------------------------------------------------------------

#include <string>
#include <vector>
#include "dhObject.h"

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
// @post This is a constructor that sets valid values to fileversion, headersize, recordcount, fieldcount, primekey, filetype, sizeformat, indexfile, fieldpairs
dhObject::dhObject()
{
    fileversion = 0;
    headersize = 0;
    recordcount = 0;
    fieldcount = 0;
    primekey = 0;
    filetype = "";
    sizeformat = "";
    indexfile = "";
}
    
//
// Accessor for fileversion
//
// @param None
// @return This function returns the version of the file structure type
// @pre None
// @post This function returns the version of the file structure type
const int dhObject::getFileversion(){
    return fileversion;
}

//
//  Accessor for headersize
//
// @param None
// @return This function returns the header record size
// @pre None
// @post This function returns the header record size
const int dhObject::getHeadersize(){
    return headersize;
}

//
// Accessor for recordcount
//
// @param None
// @return This function returns the record count
// @pre None
// @post This function returns the record count
const int dhObject::getRecordcount(){
    return recordcount;
}

//
// Accessor for fieldcount
//
// @param None
// @return This function returns the count of fields per record
// @pre None
// @post This function returns the count of fields per record
const int dhObject::getFieldcount(){
    return fieldcount;
}

//
// Accessor for primekey
//
// @param None
// @return This function returns the ordinal position of primary key
// @pre None
// @post This function returns the ordinal position of primary key
const int dhObject::getPrimekey(){
    return primekey;
}

//
// Accessor for filetype
//
// @param None
// @return This function returns the file structure type
// @pre None
// @post This function returns the file structure type
 const std::string dhObject::getFiletype(){
     return filetype;
 }
 
//
// Accessor for sizeformat
//
// @param None
// @return This function returns the size format type (ASCII or binary)
// @pre None
// @post This function returns the size format type (ASCII or binary)
const std::string dhObject::getSizeformat(){
    return sizeformat;
}
    
//
// Accessor for indexfile
//
// @param None
// @return This function returns the index file name
// @pre None
// @post This function returns the index file name
const std::string dhObject::getIndexfile(){
    return indexfile;
}

//
// Accessor for fieldname vector
//
// @param None
// @return This function returns the vector containing field names
// @pre None
// @post This function returns the vector containing field names
const std::vector<field> dhObject::getFieldpairs(){
    return fieldpairs;
}

//
// Mutator for the fileversion
//
// @param Integer This function takes an int value called Fileversion as parameter to set the value of fileversion
// @return None
// @pre None
// @post This function sets the value of fileversion
void dhObject::setFileversion(int Fileversion){
    fileversion = Fileversion;
}

//
// Mutator for the headersize
//
// @param Integer This function takes an int value called Headersize as parameter to set the value of headersize
// @return None
// @pre None
// @post This function sets the value of headersize
void dhObject::setHeadersize(int Headersize){
    headersize = Headersize;
}

//
// Mutator for the recordcount
//
// @param Integer This function takes an int value called Recordcount as parameter to set the value of recordcount
// @return None
// @pre None
// @post This function sets the value of recordcount
void dhObject::setRecordcount(int Recordcount){
    recordcount = Recordcount;
}

//
// Mutator for the fieldcount
//
// @param Integer This function takes an int value called Fieldcount as parameter to set the value of fieldcount
// @return None
// @pre None
// @post This function sets the value of fieldcount
void dhObject::setFieldcount(int Fieldcount){
    fieldcount = Fieldcount;
}

//
// Mutator for the primekey
//
// @param Integer This function takes an int value called Primekey as parameter to set the value of primekey
// @return None
// @pre None
// @post This function sets the value of primekey
void dhObject::setPrimekey(int Primekey){
    primekey = Primekey;
}

//
// Mutator for the filetype
//
// @param String This function takes a string value called Filetype as parameter to set the value of filetype
// @return None
// @pre None
// @post This function sets the value of filetype
void dhObject::setFiletype(std::string Filetype){
    filetype = Filetype;
}

//
// Mutator for the sizeformat
//
// @param String This function takes a string value called Sizeformat as parameter to set the value of sizeformat
// @return None
// @pre None
// @post This function sets the value of sizeformat
void dhObject::setSizeformat(std::string Sizeformat){
    sizeformat = Sizeformat;
}

//
// Mutator for the indexfile
//
// @param String This function takes a string value called Indexfile as parameter to set the value of indexfile
// @return None
// @pre None
// @post This function sets the value of indexfile
void dhObject::setIndexfile(std::string Indexfile){
    indexfile = Indexfile;
}

//
// Mutator for the fieldpairs
//
// @param String This function takes two string values, first being name, second being type
// @return None
// @pre None
// @post This function sets field pair in the fieldpairs vector
void dhObject::setFieldpairs(std::string Name, std::string Type){
    int size = fieldpairs.size();
    field pair;
    pair.name = Name;
    pair.type = Type;
    fieldpairs.push_back(pair);
}
