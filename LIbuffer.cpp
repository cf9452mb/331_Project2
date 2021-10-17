//---------------------------------------------------------------------
// LIbuffer.cpp
// Implementation file
// Author: Jordan Hebler
//---------------------------------------------------------------------
// This .cpp file implements the functions in LIbuffer class
//
// This file implements the functions Pack(), Unpack(), Read(), Write(),
// getSize(), Clear(), and the constructor. 
//---------------------------------------------------------------------

/**
 * @file LIbuffer.cpp
 * @brief This is the implementation file for the LIbuffer class
 *
 * @author Jordan Hebler
 */

#include <string>
#include <fstream>
#include <sstream>
#include <vector>


#include "LIbuffer.h"

// This is the constructor taking in the delimiter character as a parameter
//
// @param Char Takes in delimeter character
// @return Creates an object
// @pre None
// @post The object is created with the delimiter character passed in, size is 0,
//       and buffer is the empty string
LIbuffer::LIbuffer(char c)
{
    this->size = 0;
    this->delim = c;
    this->buffer = "";
}

// This packs the fields vector with the data members from a zipCode record
//
// @param zipCode The record to "pack" the buffer with
// @return This returns 1 if successful
// @pre None
// @post The fields member now contains the data members of the zipCode record
int LIbuffer::Pack(zipCode& record)
{
    fields.push_back(std::to_string(record.getZip()));
    size += std::to_string(record.getZip()).length() + 1;
    
    fields.push_back(record.getPlacename());
    size += record.getPlacename().length() + 1;
    
    fields.push_back(record.getState());
    size += record.getState().length() + 1;
    
    fields.push_back(record.getCounty());
    size += record.getCounty().length() + 1;
    
    fields.push_back(std::to_string(record.getLat()));
    size += std::to_string(record.getLat()).length() + 1;
    
    fields.push_back(std::to_string(record.getLon()));
    size += std::to_string(record.getLon()).length();
    
    return 1;

}


// This "unpacks" the buffer into a zipCode record
//
// @param zipCode The record to be "unpacked" into
// @return This returns 1 if successful
// @pre The buffer field has to contain a string obtained from Read()
// @post The record passed in now contains all data members from buffer
int LIbuffer::Unpack(zipCode& record){
    std::vector<std::string> vec;
    
    std::stringstream check1(this->buffer);
      
    std::string intermediate;
      
    while(getline(check1, intermediate, this->delim))
    {
        vec.push_back(intermediate);
    }
    
    record.setZip(stoi(vec[0]));
    record.setPlacename(vec[1]);
    record.setState(vec[2]);
    record.setCounty(vec[3]);
    record.setLat(stod(vec[4]));
    record.setLon(stod(vec[5]));
    
    return 1;
}


// Reads a length indicated record from an input file stream
//
// @param ifstream The file stream where the record is to be read from
// @return 0 if no more records are to be read from file, 1 otherwise
// @pre File must contain length indicated records where length is 2 bytes directly before record
// @post The size and contents of the buffer are set
int LIbuffer::Read(std::ifstream& file){
    
    this->Clear();
    
    char * length = new char [2];
      
    file.read(length, 2);
    this->size = atoi(length);
    
    if (this->size == 0) {      // When size is 0, indicates no more records to read
        return 0;
    }
    
    char * buff = new char [this->size];
    file.read(buff, this->size);
    this->buffer = std::string(buff);
    
    delete[] length;
    delete[] buff;
    
    return file.good();
      
}

// The size of the record and contents(with delimiter character) are written to the file
//
// @param fstream The file stream to be written too
// @return This returns 1 on success
// @pre The size and fields members must be set previously by Pack()
// @post The record is written to the file with size at the beginning and delimiters between the fields
int LIbuffer::Write(std::fstream& file)
{
    file << this->getSize();
    
    for (int i = 0; i < this->fields.size(); i++) {
        if(i != this->fields.size() - 1){
            file << this->fields[i] << delim;
        }
        else{
            file << this->fields[i];
        }
    }

    return 1;
}

// accessor to the buffer size
//
// @param None
// @return This function returns the buffer size
// @pre None
// @post This function returns the buffer size
int LIbuffer::getSize()
{
    return this->size;
}

// Clear function
//
// @param None
// @return None
// @pre None
// @post The size is set to 0, fields is cleared, and buffer is now the empty string
void LIbuffer::Clear()
{
    this->size = 0;
    this->fields.clear();
    this->buffer = "";
}
