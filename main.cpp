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
    if(argc < 2){
        cerr << "Invalid number of arguments!" << endl;
        cerr << "Format = ./test data.txt [-Z<ZipCode>]" << endl;
        exit(1);
    }
    
    string filename = argv[0];
    string dataFile = argv[1];
    
    vector<int> zipcodes;
    int number;
    
    while ((argc > 2) && (argv[2][0] == '-')) {
        
        switch (argv [2] [1]) {
                
            case 'Z':
                number =  atoi(&argv[2][2]);
                zipcodes.push_back(number);
                break;
                
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
* Map is created as a container and is used by the function searchContainer to see if the integers are in the map. 
*
* @param The parameters we will be using is a string called dataFile
* @return
* @pre None 
* @post
*/
map< int, int > createContainer(string dataFile){
    
    DataHeaderBuffer DH;
    
    dhObject data;
    indexObject index;
    
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
    
    while (getline(finIndex, line)) {
        
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
* @param The parameters we will be using for this function is the map and a vector defined as v
* @return 
* @pre None
* @post 
*/
void searchContainer(map< int, int > m, vector<int> v){
    
    LIbuffer LI(',');
    
    cout << setw(10) << "Zip Code" << "|" << setw(25) << "Place Name" << "|" << setw(8) << "State" << "|" << setw(12) << "County" << "|" << setw(10) << "Latitude" << "|" << setw(10) << "Longitude" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    for (int zip : v) {
        
        if (m.count(zip) > 0){
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
