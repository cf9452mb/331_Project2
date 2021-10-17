//------------------------------------------------------------------
// LIbuffer.h
// Buffer class which works with length indicated, delimited records
// Author: Jordan Hebler
//------------------------------------------------------------------
// This header file includes the LIbuffer class
// It includes methods to read, write, pack, and unpack
//------------------------------------------------------------------

#ifndef LIBUFFER_H
#define LIBUFFER_H

#include "zipCode.h"

/**
 * @file LIbuffer.h
 * @brief This is the header file for the LIbuffer class
 *
 * @author Jordan Hebler
 */


/**
 * @brief This class is used for working with length indicated, delimited records
 * @details It includes methods to read data from a string and unpack
 *          that string into a vector of strings
 * @author Jordan Hebler
 */
class LIbuffer
{   public:
/**
 * This is the constructor taking in the delimiter character as a parameter
 *
 * @param Char Takes in delimeter character
 * @return Creates an object
 * @pre None
 * @post The object is created with the delimiter character passed in
*/
LIbuffer(char c);
 
/**
 * This packs the fields vector with the data members from a zipCode record
 *
 * @param zipCode The record to "pack" the buffer with
 * @return This returns 1 if successful
 * @pre None
 * @post The fields member now contains the data members of the zipCode record
*/
int Pack(zipCode& record);
    
/**
 * This "unpacks" the buffer into a zipCode record
 *
 * @param zipCode The record to be "unpacked" into
 * @return This returns 1 if successful
 * @pre The buffer field has to contain a string obtained from Read()
 * @post The record passed in now contains all data members from buffer
*/
int Unpack(zipCode& record);
    
/**
 * Reads a length indicated record from an input file stream
 *
 * @param ifstream The file stream where the record is to be read from
 * @return 0 if no more records are to be read from file, 1 otherwise
 * @pre File must contain length indicated records where length is 2 bytes directly before record
 * @post The size and contents of the buffer are set
*/
int Read(std::ifstream& file);
    
/**
 * The size of the record and contents(with delimiter character) are written to the file
 *
 * @param fstream The file stream to be written too
 * @return This returns 1 on success
 * @pre The size and fields members must be set previously by Pack()
 * @post The record is written to the file with size at the beginning and delimiters between the fields
*/
int Write(std::fstream& file);
    
/**
 * accessor to the buffer size
 *
 * @param None
 * @return This function returns the buffer size
 * @pre None
 * @post This function returns the buffer size
*/
int getSize();
    
/**
 * Clear function
 *
 * @param None
 * @return None
 * @pre None
 * @post The size is set to 0, fields is cleared, and buffer is now the empty string
*/
void Clear();
    
private:
    int size;   // size of the buffer
    char delim;  // delimiter character
    std::vector<std::string> fields;    // vector to hold record fields
    std::string buffer;     // buffer string
};

#endif

