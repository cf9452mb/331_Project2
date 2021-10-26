//--------------------------------------------------
// DHbuffer.h
// Class for a buffer which reads, writes, packs and unpacks data
// Author: Anuja Modi, Jordan Hebler, Myint Aung
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
 * @author Myint Aung
 */
/**
 * @brief This class is used to read, write, pack and unpack data.
 * @details This DataHeaderBuffer class includes functions that will read, write, pack and unpack data to
 * make it into a single record. This class functions will go through untill all the records are gone through.
*/

class DataHeaderBuffer
{   public:

    /**
    * Default constructor
    *
    * @param None
    * @return None
    * @pre None
    * @post This is a default constructor that sets default values.
    */
    DataHeaderBuffer();
    
    /**
    * This packs the fields vectors with the data members from a dhObject record.
    *
    * @param dhObject The object to "pack" the buffer with
    * @return This returns 1 if successful
    * @pre The data members for the object passed in has to be set
    * @post The field members now contains the data members of the dhObject record.
    */
    int Pack(dhObject& object);
    
    /**
    * This packs the fields vectors with the data members from a indexObject record.
    *
    * @param indexObject The object to "pack" the buffer with
    * @return This returns 1 if successful
    * @pre The data members for the object passed in has to be set
    * @post The field members now contains the data members of the indexObject record.
    */
    int Pack(indexObject& object);
    
    /**
    * This "unpacks" the buffer into a dhObject record
    *
    * @param dhObject The object to "unpack" the buffer with
    * @return This returns 1 if successful
    * @pre The header info vector needs to be set previously from Read()
    * @post The record passed in now contains all data members from buffer
    */
    int Unpack(dhObject& object);
    
    /**
    * This "unpacks" the buffer into a indexObject record
    *
    * @param indexObject The object to "unpack" the buffer with
    * @return This returns 1 if successful
    * @pre The header info vector needs to be set previously from Read()
    * @post The record passed in now contains all data members from buffer
    */
    int Unpack(indexObject& object);

    /**
    *This reads the lines from the Data Header
    *
    * @param The file stream where the record is to be read from
    * @return This returns 1 on success
    * @pre The strings has to be indicated in the data header files
    * @post The size and contents of the Data Header are set.
    */
    int readDataHeader(std::ifstream& file);
    
    /**
    *This reads the lines from the Index Header
    *
    * @param The file stream where the record is to be read from
    * @return This returns 1 on success
    * @pre The strings has to be indicated in the index header files
    * @post The size and contents of the index header are set.
    */
    int readIndexHeader(std::ifstream& file);

    /**
    *This size and contents of the data header are written into the file
    *
    * @param The file stream where the record is to be written to
    * @return This returns 1 on success
    * @pre The size and field members must be indicated by Pack(dhObject)
    * @post The record is written to the file with contents of the Data Header
    */
    int writeDataHeader(std::fstream& file);
    
    /**
    *This size and contents of the data header are written into the file
    *
    * @param The file stream where the record is to be written to
    * @return This returns 1 on success
    * @pre The size and field members must be indicated by Pack(indexObject)
    * @post The record is written to the file with contents of the Index Object
    */
    int writeIndexHeader(std::fstream& file);

    /**
    *The contents of Fieldpairs are stored into Pairs.
    *
    * @param "pairs" have to be already indicated
    * @return This returns the contents of fieldpairs in pairs
    * @pre "pairs" have to be already indicated
    * @post The contents of fieldpairs will be stored in pairs
    */
    void setFieldpairs(std::vector<field> pairs);
    
    /**
    *This function clears the data
    *
    * @param None
    * @return None
    * @pre None
    * @post This function clears the data
    */
    void Clear();

private:
    std::vector<std::string> headerinfo; // vector of strings to hold the header information
    std::vector<field> fieldpairs; // vector of field structures to hold each fields (name,type) pairs
};

#endif
