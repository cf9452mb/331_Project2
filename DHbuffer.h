//--------------------------------------------------
// DHbuffer.h
// Class for a buffer which reads, writes, packs and unpacks data
// Author: Anuja Modi, Jordan Hebler
//--------------------------------------------------
// This header file includes a class DataHeaderBuffer
//--------------------------------------------------

#ifndef DHBUFFER_H
#define DHBUFFER_H

#include "dhObject.h"

/**
 * @file DHbuffer.h
 * @brief This is the header file for the DataHeaderBuffer class
 *
 * @author Anuja Modi
 * @author Jordan Hebler
 */


class DataHeaderBuffer
{   public:

    DataHeaderBuffer();
    
    int Pack(dhObject& object);
    
    int Unpack(dhObject& object);

    int readDataHeader(std::ifstream& file);

    int writeDataHeader(std::fstream& file);

    void setFieldpairs(std::vector<field> pairs);
    
    void Clear();

private:
    std::vector<std::string> headerinfo; // vector of strings to hold the header information
    std::vector<field> fieldpairs; // vector of field structures to hold each fields (name,type) pairs
};

#endif
