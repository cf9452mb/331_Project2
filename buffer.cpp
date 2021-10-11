//------------------------------------------------------------------
// buffer.cpp
// Implementation file
// Author: Jordan hebler, Justine Canlas,
//         Mariah Coughlin
//-------------------------------------------------------------------
// This .cpp file implements the functions in DelimTextBuffer class
//
// This file implements the functions Read(), Unpack(), getBuffer(),
// and the constructor. Read() takes a string which is then the
// buffer. Unpack() takes a vector<string> which holds the various
// fields of the record. getBuffer() simply returns the buffer and
// the constructor takes a character which is the delim character
//------------------------------------------------------------------

/**
 * @file buffer.cpp
 * @brief This is the implementation file for the DelimTextBuffer class
 *
 * @author Jordan Hebler
 * @author Justine Canlas
 * @author Mariah Coughlin
 */

#include <string>
#include <sstream>
#include <vector>
#include "buffer.h"

// Constructor taking in the delimiter character as parameter
//
// @param: Character used as the delimiter
// @return: None
// @pre: None
// @post: Delimiter character gets taken in as parameter
DelimTextBuffer::DelimTextBuffer(char c)
{
    this->Delim = c;
    this->Buffer = "";
}

// Reads the string passed in
//
// @pre: string must be directly from getline()
// @post: String is read in and the buffer is set equal to that string.
// @param str String read in from getLine()
// @return: 1 on success
int DelimTextBuffer::Read(std::string str)
{
    this->Buffer = str;
    
    return 1;

}

// Unpacks the buffer into the vector of strings passed in as parameter.
//
// @param: Vector of strings
// @pre: Vector of strings must be passed in as parameter
// @post: Vector passed in now contains the 6 fields in their respective order
// @return: 1 on success
int DelimTextBuffer::Unpack(std::vector<std::string> &vec)
{
        std::stringstream check1(this->Buffer);
          
        std::string intermediate;
          
        while(getline(check1, intermediate, this->Delim))
        {
            vec.push_back(intermediate);
        }

    return 1;
}

// Accessor to the Buffer field
//
// @param: None
// @pre: None
// @post: Gets the buffer
// @return: Buffer string
std::string DelimTextBuffer::getBuffer()
{
    return this->Buffer;
}
