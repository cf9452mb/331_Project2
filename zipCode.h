//-------------------------------------------------------------
// zipCode.h
// Class for storing the data for a zip code record
// Author: Myint Aung
//-------------------------------------------------------------
// This header file includes a class called zipCode.
//
// This zipCode class includes functions that will set the
// values of zipcode, state, latitude and longitude and as well
// as functions to get those values after they are set
//-------------------------------------------------------------

#ifndef ZIPCODE_H
#define ZIPCODE_H

/**
 * @file zipCode.h
 * @brief This is the header file for the zipCode record class
 *
 * @author Myint Aung
 */

/**
 * @brief This class is used to store the data that we extract from the CSV file
 * @details This zipCode class includes of functions that will set the values of zipcode, state, latitude and longitude
 *          and as well as functions to get those values after they are set
 * @author Myint Aung
*/
class zipCode
{
private: int zipcode;
std::string state;
double latitude, longitude;

public:
    
    
/**
 *  This is the constructor to set valid values to the data members of the class
 *
 * @param None
 * @return None
 * @pre None
 * @post This is a constructor that sets valid values to zipcode, state, longitude and latitude
*/
zipCode();
    
/**
 *  accessor for zipcode in file zipcode
 *
 * @param None
 * @return This function returns the zipcode
 * @pre None
 * @post This function returns the zipcode
*/
const int getZip();

/**
 *  accessor for state in file zipcode
 *
 * @param None
 * @return This function returns the state
 * @pre None
 * @post This function returns the state
*/
const std::string getState();

/**
 *  accessor for latitude in file zipcode
 *
 * @param None
 * @return This function returns the latitude
 * @pre None
 * @post This function returns the latitude
*/
const double getLat();

/**
 *  accessor for longitude in file zipcode
 *
 * @param None
 * @return This function returns the longitude
 * @pre None
 * @post This function returns the longitude
*/
const double getLon();

/**
 *  Mutator for the zipcode
 *
 * @param Integer This function takes an int value called Zipcode as parameter to set the value of zipcode
 * @return None
 * @pre None
 * @post This function sets the value of zipcode
*/
void setZip(int Zipcode);

/**
 *  Mutator for the state
 *
 * @param String This function takes a string value called State as parameter to set the value of state
 * @return None
 * @pre None
 * @post This function sets the value of state
*/
void setState(std::string State);

/**
 *  Mutator for the latitude
 *
 * @param Double This function takes a double value called Latitude as parameter to set the value of latitude
 * @return None
 * @pre None
 * @post This function sets the value of latitude
*/
void setLat(double Latitude);

/**
 *  Mutator for the longitude
 *
 * @param Double This function takes a double value called Longitude as parameter to set the value of longitude
 * @return None
 * @pre None
 * @post This function sets the value of longitude
*/
void setLon(double Longitude);
};
    
#endif
