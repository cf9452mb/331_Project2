/--------------------------------------------------
// DHbuffer.h
// Class for a buffer which reads, writes, packs and unpacks data
// Author: Anuja Modi
//--------------------------------------------------
// This header file includes a class DataHeaderBuffer
//--------------------------------------------------

#ifndef DHBUFFER_H
#define DHBUFFER_H

/**
 * @file DHbuffer.h
 * @brief This is the header file for the DataHeaderBuffer class
 *
 * @author Anuja Modi
 */

class DataHeaderBuffer
{   public:

DataHeaderBuffer();

int ReadHeader(istream &);

int WriteHeader(ostream &) const;


std::string getBuffer();

private:
char Delim;         
std::string Buffer;       // string to hold field values
};

#endif
