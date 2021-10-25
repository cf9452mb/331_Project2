//-------------------------------------------------------------
// indexObject.h
// Class for storing the data for index header object
// Author: Myint Aung, Jordan Hebler
//-------------------------------------------------------------
// This header file includes a class called indexObject.
//
// This indexObject class includes functions that will set the
// values of keytype, reference type, primary key, keylength, 
// reference length and header size.
//-------------------------------------------------------------
#ifndef INDEXOBJECT_H
#define INDEXOBJECT_H

/**
 * @file indexObject.h
 * @brief This is the header file for the index header object
 *
 * @author Myint Aung
 * @author Jordan Hebler
 */
 
 /**
 * @brief This class is used to set and get the values for the index header.
 * @details This dhObject class includes functions that will set the values of keytype,
 *	reference type, primary key, keylength, reference length and header size.
*/
class indexObject
{
private:
    std::string keytype, reftype, pkey, ref;
    int keylength, reflength, headersize;

public:
/**
 *  This is the constructor to set valid values to the data members of the class
 *
 * @param None
 * @return None
 * @pre None
 * @post This is a constructor that sets valid values to the keytype, reference type, primary key, key length, reference length and header size.
*/
    indexObject();
	
/**
 *  accessor for keylength
 *
 * @param None
 * @return This function returns the length of the key.
 * @pre None
 * @post This function returns the length of the key.
*/
    const int getKeylength();
	
/**
 *  accessor for reference length
 *
 * @param None
 * @return This function returns the length of the reference.
 * @pre None
 * @post This function returns the length of the reference.
*/
    const int getReflength();
	
/**
 *  accessor for header size
 *
 * @param None
 * @return This function returns the size of the header.
 * @pre None
 * @post This function returns the size of the header.
*/
    const int getHeadersize();
	
/**
 *  accessor for reference type
 *
 * @param None
 * @return This function returns the type of the reference.
 * @pre None
 * @post This function returns the type of the reference.
*/
    const std::string getReftype();
	
/**
 *  accessor for key type
 *
 * @param None
 * @return This function returns the type of the key.
 * @pre None
 * @post This function returns type of the key.
*/
    const std::string getKeytype();
	
/**
 *  accessor for primary key
 *
 * @param None
 * @return This function returns the primary key.
 * @pre None
 * @post This function returns the primary key.
*/
    const std::string getPkey();
	
/**
 *  accessor for reference
 *
 * @param None
 * @return This function returns the reference.
 * @pre None
 * @post This function returns the reference.
*/
    const std::string getRef();

/**
 *  Mutator for the keylength
 *
 * @param Integer This function takes an int value called Length as parameter to set the value of the key length.
 * @return None
 * @pre None
 * @post This function sets the value of the key length.
*/
    void setKeylength(int Length);
	
/**
 *  Mutator for the reflength
 *
 * @param Integer This function takes an int value called refLength as parameter to set the value of the reference length.
 * @return None
 * @pre None
 * @post This function sets the value of the reference length.
*/
    void setReflength(int refLength);

/**
 *  Mutator for the headersize
 *
 * @param Integer This function takes an int value called size as parameter to set the value of the header size.
 * @return None
 * @pre None
 * @post This function sets the value of the header size.
*/
    void setHeadersize(int size);
	
/**
 *  Mutator for the keylength
 *
 * @param Integer This function takes a string value called keyType as parameter to set the type of the key.
 * @return None
 * @pre None
 * @post This function sets the value of the key type.
*/
    void setKeytype(std::string keyType);
	
/**
 *  Mutator for the reftype
 *
 * @param Integer This function takes a string value called refType as parameter to set the value of the reference type.
 * @return None
 * @pre None
 * @post This function sets the value of the type of the reference.
*/
    void setReftype(std::string refType);
	
/**
 *  Mutator for the primary key
 *
 * @param Integer This function takes a string value called Pkey as parameter to set the value of the primary key.
 * @return None
 * @pre None
 * @post This function sets the value of the primary key.
*/
    void setPkey(std::string Pkey);
	
/**
 *  Mutator for the reference
 *
 * @param Integer This function takes a string value called Ref as parameter to set the value of the reference.
 * @return None
 * @pre None
 * @post This function sets the value of the reference.
*/
    void setRef(std::string Ref);
};
    
#endif
