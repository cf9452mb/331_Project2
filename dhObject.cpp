//-------------------------------------------------------------
// dhObject.cpp
// This is the implementation file for the dhObject.h
// Author: Myint Aung
//-------------------------------------------------------------
// This .cpp file contains the functions of the class dhObject
//
// This file makes use of the functions of the class dhObject which
// includes functions that will set the
// values of file structure type, header record size,
// number of bytes for each record size integer, size format type,
// index file name, record count and count of fields per record
// and as well as functions to get those values after
// they are set
//-------------------------------------------------------------

#include <string>
#include "dhObject.h"

//
// @file dhObject.cpp
// @brief This is the implementation file for the class dhObject
//
// @author Myint Aung
//

//  This is the constructor to set valid values to the data members of the class
//
// @param None
// @return None
// @pre None
// @post This is a constructor that sets valid values to fileversion, header_size, numofbytes, recordcount, fieldcount, filetype, sizeformat, indexfile, fieldname, fieldtype.
dhObject::dhObject()
{	
	fileversion = 0;
	header_size = 0;
	numofbytes = 0;
	recordcount = 0;
	fieldcount = 0;
	filetype = "";
	sizeformat = "";
	indexfile = "";
	fieldname = "";
	fieldtype = "";
}
    
//
// accessor for fileversion
//
// @param None
// @return This function returns the version of the file structure type
// @pre None
// @post This function returns the version of the file structure type
const int dhObject::getFileversion(){
	return fileversion;
}

//
//  accessor for header_size
//
// @param None
// @return This function returns the header record size
// @pre None
// @post This function returns the header record size
const int dhObject::getHeader_size(){
	return header_size;
}

//
// accessor for numofbytes
//
// @param None
// @return This function returns the number of bytes for each record size integer
// @pre None
// @post This function returns the number of bytes for each record size integer
const int dhObject::getNumofbytes(){
	return numofbytes;
}

//
// accessor for recordcount
//
// @param None
// @return This function returns the record count
// @pre None
// @post This function returns the record count
const int dhObject::getRecordcount(){
	return recordcount;
}

//
// accessor for fieldcount
//
// @param None
// @return This function returns the count of fields per record
// @pre None
// @post This function returns the count of fields per record
const int dhObject::getFieldcount(){
	return fieldcount;
}

//
// accessor for filetype
//
// @param None
// @return This function returns the file structure type
// @pre None
// @post This function returns the file structure type
 const std::string dhObject::getFiletype(){
	 return filetype;
 }
 
//
// accessor for sizeformat
//
// @param None
// @return This function returns the size format type (ASCII or binary)
// @pre None
// @post This function returns the size format type (ASCII or binary)
const std::string dhObject::getSizeformat(){
	return sizeformat;
}
    
//
// accessor for indexfile
//
// @param None
// @return This function returns the index file name
// @pre None
// @post This function returns the index file name
const std::string dhObject::getIndexfile(){
	return indexfile;
}

//
// accessor for fieldname
//
// @param None
// @return This function returns the name for each field
// @pre None
// @post This function returns the name for each field
const std::string dhObject::getFieldname(){
	return fieldname;
}

//
// accessor for fieldtype
//
// @param None
// @return This function returns the type for each field
// @pre None
// @post This function returns the type for each field
const std::string dhObject::getFieldtype(){
	return fieldtype;
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
// @param Integer This function takes an int value called Headersize as parameter to set the value of header_size
// @return None
// @pre None
// @post This function sets the value of header_size
void dhObject::setHeader_size(int Headersize){
	header_size = Headersize;
}

//
// Mutator for the numofbytes
//
// @param Integer This function takes an int value called Numofbytes as parameter to set the value of numofbytes
// @return None
// @pre None
// @post This function sets the value of numofbytes
void dhObject::setNumofbytes(int Numofbytes){
	numofbytes = Numofbytes;
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
// Mutator for the fieldname
//
// @param String This function takes a string value called Fieldname as parameter to set the value of fieldname
// @return None
// @pre None
// @post This function sets the value of fieldname
void dhObject::setFieldname(std::string Fieldname){
	fieldname = Fieldname;
}

//
// Mutator for the fieldtype
//
// @param String This function takes a string value called Fieldtype as parameter to set the value of fieldtype
// @return None
// @pre None
// @post This function sets the value of fieldtype
void dhObject::setFieldtype(std::string Fieldtype){
	fieldtype = Fieldtype;
}
