//--------------------------------------------------
// main.cpp
// This main.cpp utilizes the functions from the other classes to go through the indexes and find the specific zipcodes.
// Author: Anuja Modi, Jordan Hebler
//--------------------------------------------------
// This main.cpp makes use of all the other classes to go through all the indexes and find the specific zipcodes.
//--------------------------------------------------

/**
 * @file main.cpp
 * @brief This is the main program that reads the flags from the user on the command line.
 *
 * @author Anuja Modi
 * @author Jordan Hebler
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "zipCode.h"
#include "LIbuffer.h"
#include "dhObject.h"
#include "indexObject.h"
#include "DHbuffer.h"

using namespace std;


ifstream finIndex, finData;

map< int, int > createContainer(string dataFile);
void searchContainer(map< int, int > m, vector<int> v);

int main(int argc, char* argv[])
{
    if(argc < 2){         //Check to make sure if an argument is given for the file or not
        cerr << "Invalid number of arguments!" << endl;
        cerr << "Format = ./test data.txt [-Z<ZipCode>]" << endl;
        exit(1);
    }
    
    
    string filename = argv[0];
    string dataFile = argv[1];
    
    vector<int> zipcodes;
    int number;
    
    //this while loop is looping through the command line
    while ((argc > 2) && (argv[2][0] == '-')) {
        
        switch (argv [2] [1]) {
            //We will be searching for Z     
            case 'Z':
                number =  atoi(&argv[2][2]);
                zipcodes.push_back(number);
                break;
                
            //Default arguement 
            default:
                cerr << "Invalid argument: " << argv[2] << "\n";
            }
        
        ++argv;
        --argc;
    }
    
    
    
    map< int, int > m = createContainer(dataFile);
    
    searchContainer(m, zipcodes);
    
    finIndex.close();
    finData.close();
    
    return 0;
}

//***********************************************************************************************************

/**
* It creates a map container from the given data files and its corresponding index files.
*
* @param string The parameters we will be using is a string called dataFile
* @return This returns a map with all of the indexes and contents from indexobject and datafile.
* @pre None 
* @post None
*/
map< int, int > createContainer(string dataFile){
    
    DataHeaderBuffer DH;            //make use of the functions from the DataHeaderBuffer class
    
    dhObject data;                  //make use of the functions from the dhObject class
    indexObject index;              //make use of the functions from the indexObject class
    
    map< int, int > m;
        
    finData.open(dataFile);
    if(finData.fail()){
        cout << "Failed to open Data file! Exiting program" << endl;
        exit(1);
    }
    
    DH.readDataHeader(finData);
    DH.Unpack(data);
    
    finIndex.open(data.getIndexfile());
    if(finIndex.fail()){
        cout << "Failed to open Index file! Exiting program" << endl;
        exit(2);
    }
    
    
    DH.readIndexHeader(finIndex);
    DH.Unpack(index);
        
    finIndex.seekg(index.getHeadersize());
    
    string line;
    
    while (getline(finIndex, line)) {               //while there are still indexes found, add the indexes into the map
        
        string delim = ",";
        string key = line.substr(0, line.find(delim));
        string ref = line.erase(0, line.find(delim) + delim.length());
    
        m.insert(pair<int,int>(stoi(key), stoi(ref)));
        
    }
    
    return m;
    
}

/**
* This is the function used to search through the map and sees if the integers are on the map. 
*
* @param map<int, int> vector<int> The parameters we will be using for this function is the map and a vector defined as v
* @return This returns if a particular zip code is found in the container or not
* @pre None
* @post None
*/
void searchContainer(map< int, int > m, vector<int> v){
    
    LIbuffer LI(',');
    
    cout << setw(10) << "Zip Code" << "|" << setw(25) << "Place Name" << "|" << setw(8) << "State" << "|" << setw(12) << "County" << "|" << setw(10) << "Latitude" << "|" << setw(10) << "Longitude" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    for (int zip : v) {
        
        if (m.count(zip) > 0){                      //if the zip code is greater than 0, go through the map to find the specific zipcode
            zipCode record;
            
            map< int, int >::iterator it = m.find(zip);
             
            finData.seekg(it->second);
             
            LI.Read(finData);
             
            LI.Unpack(record);
            
            cout << setw(10) << record.getZip() << "|" << setw(25) << record.getPlacename() << "|"  << setw(8) << record.getState() << "|" << setw(12) << record.getCounty() << "|" << setw(10) << record.getLat() << "|" << setw(10) << record.getLon() << endl;
        }
        else{
            cout <<  zip << " is not in the index file!" << endl;
        }
        
        
    }
    
    
}
