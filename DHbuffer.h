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

    //int readHeader(std::ifstream& file);

    int writeHeader(std::fstream& file);


    void setFieldpairs(std::vector<field> pairs);
    
    void Clear();

private:
    std::vector<std::string> headerinfo;
    std::vector<field> fieldpairs; // string to hold field values
};

#endif
