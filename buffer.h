//--------------------------------------------------
// buffer.h
// Class for a buffer which reads and unpacks data
// Author: Jordan hebler, Justine Canlas,
//         Mariah Coughlin
//--------------------------------------------------
// This header file includes a class DelimTextBuffer
// It includes methods to read data from a string
// and unpack that string into a vector of strings
//--------------------------------------------------

#ifndef BUFFER_H
#define BUFFER_H

/**
 * @file buffer.h
 * @brief This is the header file for the DelimTextBuffer class
 *
 * @author Jordan Hebler
 * @author Justine Canlas
 * @author Mariah Coughlin
 */


/**
 * @brief This class is used for the delimited text buffer for this project
 * @details It includes methods to read data from a string and unpack
 *          that string into a vector of strings
 * @author Jordan Hebler
 * @author Justine Canlas
 * @author Mariah Coughlin
*/
class DelimTextBuffer
{   public:
 /**
  * This is the constructor taking in the delimiter character as a parameter
  *
  * @param Char Takes in delimeter character
  * @return Creates an object
  * @pre None
  * @post The delimeter character is taken in as a character
 */
    DelimTextBuffer(char);
 
  /**
   * This reads the string that is passed in and sets the buffer equal to the string.
   *
   * @param String Sets the buffer equal to string
   * @return This returns 1 if successful
   * @pre None
   * @post The string is read
  */
    int Read(std::string);
 
  /**
   * Unpacks the buffer into the vector of strings that is passed in as a parameter. Returns 1 if successful.
   *
   * @param Vector The vector of strings is passed in as a parameter
   * @return This returns 1 if it all the conditions are met
   * @pre None
   * @post The vector is passed in and contains 6 fields in their respective order
  */
    int Unpack(std::vector<std::string>&);
 
  /**
   * accessor to the Buffer field
   *
   * @param None
   * @return This function returns the buffer
   * @pre None
   * @post This function returns the buffer
 */
    std::string getBuffer();
    
private:
    char Delim;         // delimiter character
    std::string Buffer;       // string to hold field values
};

#endif
