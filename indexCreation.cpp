//---------------------------------------------------------------------
// indexCreation.cpp
// Program used to create a Primary Key Index file with a header record
// from a specified Length Indicated Data file
// Author: Jordan Hebler
//---------------------------------------------------------------------
// Specify the Index header object members before writing the header.
// You want to specify the output file stream to write the header and
// index data to and the input file stream to read the Length Indicated
// data from
//---------------------------------------------------------------------

/**
 * @file indexCreation.cpp
 * @brief This is the program to create a Primary Key Index file with a header record
 *
 * @author Jordan Hebler
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "dhObject.h"
#include "indexObject.h"
#include "DHbuffer.h"
#include "LIbuffer.h"

using namespace std;

void outputValues(map<int,int> m);

int main (int argc, char* argv[]) {
    ifstream fin;
    fstream fout;
    string line;
    
    //Creates indexObject object called index
    indexObject index;
    
    //Creates dhObject object called data
    dhObject data;
    
    //Calls in mutator to set the value of the Pkey
    index.setPkey("ZipCode");
    
    //Calls in mutator to set the value of the ketType
    index.setKeytype("int");
    
    //Calls in mutator to set the value of the Length
    index.setKeylength(5);
    
    //Calls in mutator to set the value of of the Ref
    index.setRef("Byte Offset");
    
    //Calls in mutator to set the value for the refType
    index.setReftype("int");
    
    //Calls in mutator to set the value for the refLength
    index.setReflength(7);
    
    //Calls in mutator to set the value for the size of the header
    index.setHeadersize(128);
 
    
    //Creates DHbuffer object from DataHeaderBuffer class
    DataHeaderBuffer DHbuffer;
    LIbuffer LI(',');
    
    //Calls the Pack function from the DHbuffer to pack index object
    DHbuffer.Pack(index);
    
    fout.open("ZipCodePKI.txt");
    
    //Calls the writeIndexHeader function from the DHbuffer to write ZipCodePKI.txt
    DHbuffer.writeIndexHeader(fout);
    
    fin.open("ZipCodeLI.txt");
    
    //Calls in readDataHeader function fron the DHbuffer to read ZipCodeLI.txt
    DHbuffer.readDataHeader(fin);
    
    //Calls in Unpack function from the DHbuffer to unpack data object.
    DHbuffer.Unpack(data);
    
    //Creates map container
    map< int, int > m;
    
    fin.seekg(data.getHeadersize());
    
    int position = fin.tellg();
    
    while (LI.Read(fin)) {
           
        //Calls zipCode class and declares record as a value
        zipCode record;
        
        //Calls in Unpack from LI to unpack record object.
        LI.Unpack(record);
                
        m.insert(pair<int,int>(record.getZip(), position));
        
        position = fin.tellg();
            
    }
    
    fout.seekp(index.getHeadersize());
    
    map<int,int>::iterator itr1;
    
    for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
        
        fout << itr1->first << ',' << itr1->second << "\n";
        
    }
    
    //Closes .txt files
    fin.close();
    fout.close();
  return 0;
}

/**
* Function used to see what's in the map before writing to the file 
*
* @param map with 2 integers called m
* @return See if the value is in the map
* @pre None
* @post Goes through and sees what's in the map
*/
void outputValues(map<int,int> m){
    
    map<int,int>::iterator itr1;
        cout << "\tKEY\tOffset\n";
        for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
            cout << '\t' << itr1->first;
            
            cout << '\t' << itr1->second << endl;
        }
        cout << endl;
}
