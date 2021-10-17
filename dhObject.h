//-------------------------------------------------------------
// dhObject.h
// Class for storing the data for data header object
// Author: Myint Aung
//-------------------------------------------------------------
// This header file includes a class called dhObject.
//
// This dhObject class includes functions that will set the
// values of file structure type, header record size,
// number of bytes for each record size integer, size format type,
// index file name, record count and count of fields per record
// and as well as functions to get those values after
// they are set
//-------------------------------------------------------------

#ifndef DHOBJECT_H
#define DHOBJECT_H

/**
 * @file dhObject.h
 * @brief This is the header file for the data header object class
 *
 * @author Myint Aung
 */

/**
 * @brief This class is used to store the data that we extract from the CSV file
 * @details This dhObject class includes functions that will set the values of file structure type, 
 *	header record size, number of bytes for each record size integer, size format type,
 *	index file name, record count and count of fields per record and as well as functions to get those values after they are set
 * @author Myint Aung
*/
class dhObject
{
private: int fileversion, header_size, numofbytes, recordcount, fieldcount;
std::string filetype, sizeformat, indexfile, fieldname, fieldtype;

public:
/**
 *  This is the constructor to set valid values to the data members of the class
 *
 * @param None
 * @return None
 * @pre None
 * @post This is a constructor that sets valid values to fileversion, header_size, numofbytes, recordcount, fieldcount, filetype, sizeformat, indexfile, fieldname, fieldtype.
*/
dhObject();
    
/**
 *  accessor for fileversion
 *
 * @param None
 * @return This function returns the version of the file structure type
 * @pre None
 * @post This function returns the version of the file structure type
*/
const int getFileversion();
    
/**
 *  accessor for header_size
 *
 * @param None
 * @return This function returns the header record size
 * @pre None
 * @post This function returns the header record size
*/
const int getHeader_size();

/**
 *  accessor for numofbytes
 *
 * @param None
 * @return This function returns the number of bytes for each record size integer
 * @pre None
 * @post This function returns the number of bytes for each record size integer
*/
const int getNumofbytes();

/**
 *  accessor for recordcount
 *
 * @param None
 * @return This function returns the record count
 * @pre None
 * @post This function returns the record count
*/
const int getRecordcount();

/**
 *  accessor for fieldcount
 *
 * @param None
 * @return This function returns the count of fields per record
 * @pre None
 * @post This function returns the count of fields per record
*/
const int getFieldcount();

/**
 *  accessor for filetype
 *
 * @param None
 * @return This function returns the file structure type
 * @pre None
 * @post This function returns the file structure type
*/
 const std::string getFiletype();


/**
 *  accessor for sizeformat
 *
 * @param None
 * @return This function returns the size format type (ASCII or binary)
 * @pre None
 * @post This function returns the size format type (ASCII or binary)
*/
const std::string getSizeformat();
    
/**
 *  accessor for indexfile
 *
 * @param None
 * @return This function returns the index file name
 * @pre None
 * @post This function returns the index file name
*/
const std::string getIndexfile();

/**
 *  accessor for fieldname
 *
 * @param None
 * @return This function returns the name for each field
 * @pre None
 * @post This function returns the name for each field
*/
const std::string getFieldname();

/**
 *  accessor for fieldtype
 *
 * @param None
 * @return This function returns the type for each field
 * @pre None
 * @post This function returns the type for each field
*/
const std::string getFieldtype();


/**
 *  Mutator for the fileversion
 *
 * @param Integer This function takes an int value called Fileversion as parameter to set the value of fileversion
 * @return None
 * @pre None
 * @post This function sets the value of fileversion
*/
void setFileversion(int Fileversion);

/**
 *  Mutator for the headersize
 *
 * @param Integer This function takes an int value called Headersize as parameter to set the value of header_size
 * @return None
 * @pre None
 * @post This function sets the value of header_size
*/
void setHeader_size(int Headersize);

/**
 *  Mutator for the numofbytes
 *
 * @param Integer This function takes an int value called Numofbytes as parameter to set the value of numofbytes
 * @return None
 * @pre None
 * @post This function sets the value of numofbytes
*/
void setNumofbytes(int Numofbytes);

/**
 *  Mutator for the recordcount
 *
 * @param Integer This function takes an int value called Recordcount as parameter to set the value of recordcount
 * @return None
 * @pre None
 * @post This function sets the value of recordcount
*/
void setRecordcount(int Recordcount);

/**
 *  Mutator for the fieldcount
 *
 * @param Integer This function takes an int value called Fieldcount as parameter to set the value of fieldcount
 * @return None
 * @pre None
 * @post This function sets the value of fieldcount
*/
void setFieldcount(int Fieldcount);

/**
 *  Mutator for the filetype
 *
 * @param String This function takes a string value called Filetype as parameter to set the value of filetype
 * @return None
 * @pre None
 * @post This function sets the value of filetype
*/
void setFiletype(std::string Filetype);

/**
 *  Mutator for the sizeformat
 *
 * @param String This function takes a string value called Sizeformat as parameter to set the value of sizeformat
 * @return None
 * @pre None
 * @post This function sets the value of sizeformat
*/
void setSizeformat(std::string Sizeformat);

/**
 *  Mutator for the indexfile
 *
 * @param String This function takes a string value called Indexfile as parameter to set the value of indexfile
 * @return None
 * @pre None
 * @post This function sets the value of indexfile
*/
void setIndexfile(std::string Indexfile);

/**
 *  Mutator for the fieldname
 *
 * @param String This function takes a string value called Fieldname as parameter to set the value of fieldname
 * @return None
 * @pre None
 * @post This function sets the value of fieldname
*/
void setFieldname(std::string Fieldname);

/**
 *  Mutator for the fieldtype
 *
 * @param String This function takes a string value called Fieldtype as parameter to set the value of fieldtype
 * @return None
 * @pre None
 * @post This function sets the value of fieldtype
*/
void setFieldtype(std::string Fieldtype);

};
#endif
