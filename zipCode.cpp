//----------------------------------------------------------------
// zipCode.cpp
// Implementation file
// Author: Myint Aung, Jordan Hebler
//----------------------------------------------------------------
// This .cpp file implements the functions of the class zipCode
//
// This file make uses of the functions of the class zipcode
// which includes the functions that will set the values of
// zipcode, placename, state, county, latitude and longitude and
// as well as functions to get those values after they are set
//----------------------------------------------------------------

#include <string>
#include "zipCode.h"

/**
 * @file zipCode.cpp
 * @brief This is the implementation file for the zipCode record class
 *
 * @author Myint Aung
 * @author Jordan Hebler
 */


// This is the constructor to set valid values to the data members of the class
//
// @param None
// @return None
// @pre None
// @post This is a constructor that sets valid values to zipcode, placename, state, county, longitude and latitude
zipCode::zipCode()
{
    zipcode= 0;
    placename = "";
    state = "";
    county = "";
    latitude = 0;
    longitude = 0;
}


// accessor for zipcode in file zipcode
//
// @param None
// @return This function returns the zipcode
// @pre None
// @post This function returns the zipcode
const int zipCode::getZip(){
    return zipcode;
}

// accessor for placename in file zipcode
//
// @param None
// @return This function returns the placename
// @pre None
// @post This function returns the placename
const std::string zipCode::getPlacename(){
    return placename;
}

// accessor for state in file zipcode
//
// @param None
// @return This function returns the state
// @pre None
// @post This function returns the state
const std::string zipCode::getState(){
    return state;
}

// accessor for county in file zipcode
//
// @param None
// @return This function returns the county
// @pre None
// @post This function returns the county
const std::string zipCode::getCounty(){
    return county;
}


// accessor for latitude in file zipcode
//
// @param None
// @return This function returns the latitude
// @pre None
// @post This function returns the latitude
const double zipCode::getLat(){
    return latitude;
}


// accessor for longitude in file zipcode
//
// @param None
// @return This function returns the longitude
// @pre None
// @post This function returns the longitude
const double zipCode::getLon(){
    return longitude;
}

// Mutator for the zipcode
//
// @param Integer This function takes an int value called Zipcode as parameter to set the value of zipcode
// @return None
// @pre None
// @post This function sets the value of zipcode
void zipCode::setZip(int Zipcode){
    zipcode = Zipcode;
}

// Mutator for the placename
//
// @param String This function takes a string value called Placename as parameter to set the value of placename
// @return None
// @pre None
// @post This function sets the value of placename
void zipCode::setState(std::string Placename){
    placename = Placename;
}

// Mutator for the state
//
// @param String This function takes a string value called State as parameter to set the value of state
// @return None
// @pre None
// @post This function sets the value of state
void zipCode::setState(std::string State){
    state = State;
}

// Mutator for the county
//
// @param String This function takes a string value called County as parameter to set the value of county
// @return None
// @pre None
// @post This function sets the value of county
void zipCode::setState(std::string County){
    county = County;
}

// Mutator for latitude
//
// @param Double This function takes a double value called Latitude as parameter to set the value of latitude
// @return None
// @pre None
// @post This function sets the value of latitude
void zipCode::setLat(double Latitude){
    latitude = Latitude;
}

// Mutator for longitude
//
// @param Double This function takes a double value called Longitude as parameter to set the value of longitude
// @return None
// @pre None
// @post This function sets the value of longitude
void zipCode::setLon(double Longitude){
    longitude = Longitude;
}
