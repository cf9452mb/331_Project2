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
#include "indexObject.h"

/**
 * @file DHbuffer.h
 * @brief This is the header file for the DataHeaderBuffer class
 *
 * @author Anuja Modi
 * @author Jordan Hebler
 */


class DataHeaderBuffer
{   public:

    /**
    * Default constructor
    *
    * @param None
    * @return None
    * @pre None
    * @post
    */
    DataHeaderBuffer();
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int Pack(dhObject& object);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int Pack(indexObject& object);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int Unpack(dhObject& object);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int Unpack(indexObject& object);

    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int readDataHeader(std::ifstream& file);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int readIndexHeader(std::ifstream& file);

    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int writeDataHeader(std::fstream& file);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    int writeIndexHeader(std::fstream& file);

    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    void setFieldpairs(std::vector<field> pairs);
    
    /**
    *
    *
    * @param
    * @return
    * @pre
    * @post
    */
    void Clear();

private:
    std::vector<std::string> headerinfo; // vector of strings to hold the header information
    std::vector<field> fieldpairs; // vector of field structures to hold each fields (name,type) pairs
};

#endif
