#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "LIbuffer.h"
#include "zipCode.h"

using namespace std;

///Local function declarations
/**
 *  This sets the fields used for the program
 *
 * @param Vector A vector of strings  to "unpack" into object
 * @param zipCode A zipCode object to copy fields into
 * @return None
 * @pre None
 * @post This sets the fields for Zipcode, State, Latitude and Longitude used for the program
*/
void setFields(vector<string> tokens, zipCode& record);

/**
 *  This is the iterator used to categorize the latitudes and longitudes into the northernmost, southermost, easternmost and westernmost of each state.
 *
 * @param Map::iterator  Uses a map<string, zipCode*> interator to place records in correct position in map
 * @param zipCode zipCode object used to place into map
 * @return None
 * @pre None
 * @post Sets the values of the 4 zipcodes for each state
*/
void setValues(map<string,zipCode*>::iterator it, zipCode& record);

/**
 *  This outputs the values that are needed to be shown for each state
 *
 * @param Map Uses a map<string, zipCode*> as a parameter to output all the values in the map
 * @return This returns the northernmost, southernmost, easternmost and westernmost zipcodes for each state
 * @pre None
 * @post Returns state and 4 zipcodes for each state
*/
void outputValues(map< string, zipCode* > m);

/**
 *  This function is used to delete objects from the memory
 *
 * @param Map Uses map<string, zipCode*> as a parameter to go through map and delete allocated memory
 * @return None
 * @pre None
 * @post Memory is deallocated
*/
void deleteX(map< string, zipCode* > m);

int main(int argc, char* argv[])
{

    // File pointer
    ifstream fin;
    string line;
    int count = 0;;
    
    //This creates a buffer
    LIbuffer buffer(',');
    
    //Initializes map with string data type and zipCode as the value data type with m as the map name
    map< string, zipCode* > m;
    
    //If there isn't a command line argument for the file, exit program
    if(argc != 2){
        cout << "Enter the LI file on the command line!" << endl;
        exit(0);
      }
    
    //Opens the csv file passed in on the command line
    fin.open(argv[1], ios::in);
    
    //If the given file on the command line isn't a valid file, exit program
    if(fin.fail()){
        cout << "Failed to open file! Exiting program" << endl;
        exit(1);
    }
    
    //Skips over the header record in the file
    fin.seekg(256);
    
    //While loop designed to go through file
    while (buffer.Read(fin)) {
           
        zipCode record;
        
        buffer.Unpack(record);
                
        //Calls in zipCode class and allocates memory for values using new
        zipCode* z = new zipCode[4];
                
        //If entry already exists for that state, delete allocated memory
        if(m.insert(pair<string, zipCode*>(record.getState(), z)).second == false)
        {
            delete[] z;
        }
                
                
        map<string,zipCode*>::iterator it = m.find(record.getState());
                
        //Calls in local setValues class to categorize data
        setValues(it, record);
            
    }
    
    //Closes .csv file
    fin.close();
    
    //Calls local output function to display values
    outputValues(m);
    
    //Calls local function to delete objects from memory
    deleteX(m);
    
    return 0;
}

//*****************************************************************************************
//This sets the fields of each record object used for the program
void setFields(vector<string> tokens, zipCode& record){
    
    for(int i = 0; i < tokens.size(); i++)
    {
        if (i == 0 ) {
            //Zipcode
            record.setZip(stoi(tokens[i]));
        }
        if (i == 2 ) {
            //State
            record.setState(tokens[i]);
        }
        if (i == 4 ) {
            //Latitude
            record.setLat(stod(tokens[i]));
        }
        if (i == 5 ) {
            //Longitude
            record.setLon(stod(tokens[i]));
        }
    }
}

//This is the iterator used to categorize the latitudes and longitudes into the northernmost, southermost, easternmost and westernmost of each state.
void setValues(map<string,zipCode*>::iterator it, zipCode& record){
    
    //If else statement for the southernmost zipcode
    if (it->second[0].getLat() == 0) {          //Indicates first record being placed in the map
        it->second[0].setLat(record.getLat());
        it->second[0].setZip(record.getZip());
    }
    else if(it->second[0].getLat() < record.getLat()){
        it->second[0].setLat(record.getLat());
        it->second[0].setZip(record.getZip());
    }

    //If else statement for the northernmost zipcode
    if (it->second[1].getLat() == 0) {          //Indicates first record being placed in the map
        it->second[1].setLat(record.getLat());
        it->second[1].setZip(record.getZip());
    }
    else if(it->second[1].getLat() > record.getLat()){
        it->second[1].setLat(record.getLat());
        it->second[1].setZip(record.getZip());
    }

    //If else statement for the easternmost zipcode
    if (it->second[2].getLon() == 0) {          //Indicates first record being placed in the map
        it->second[2].setLon(record.getLon());
        it->second[2].setZip(record.getZip());
    }
    else if(it->second[2].getLon() < record.getLon()){
        it->second[2].setLon(record.getLon());
        it->second[2].setZip(record.getZip());
    }

    //If else statement for the westernmost zipcode
    if (it->second[3].getLon() == 0) {          //Indicates first record being placed in the map
        it->second[3].setLon(record.getLon());
        it->second[3].setZip(record.getZip());
    }
    else if(it->second[3].getLon() > record.getLon()){
        it->second[3].setLon(record.getLon());
        it->second[3].setZip(record.getZip());
    }
    
}

//This outputs the values that are needed to be shown for each state
void outputValues(map< string, zipCode* > m){
    
    //Outputs each key value(State) then each of the 4 corresponding values(Zipcode)
    map<string, zipCode*>::iterator itr1;
        cout << "\tSTATE\tNORTH\tSOUTH\tEAST\tWEST\n";
        for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
            cout << '\t' << itr1->first;
            
            for(int i = 0; i < 4; i++){
                cout << '\t' << itr1->second[i].getZip();
            }
            cout << endl;
        }
        cout << endl;
}

//This function is used to delete objects from the memory
void deleteX(map< string, zipCode* > m){
    
    map<string, zipCode*>::iterator itr1;
    
    //Goes through map and deletes allocated memory
    for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
        delete[] itr1->second;
    }
}

