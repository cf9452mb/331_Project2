//-----------------------------------------------------------------------
// fileCreation.cpp
// Program used to create a Length Indicated data file given a CSV file
// and a corresponding Index file
// Author: Jordan Hebler, Justine Canlas
//-----------------------------------------------------------------------
// Specify the Data header object members before writing the header,
// and specify the Index header object members before writing it's header.
// Format for running program: ./test csvFile.csv data.txt index.txt
// ** csvFile.csv will be the CSV file used to create the LI data file
// ** data.txt will be the file the LI data with header is written too
// ** index.txt is the Index file created that corresponds to data.txt
//-----------------------------------------------------------------------

/**
 * @file fileCreation.cpp
 * @brief This is the program to create a Length Indicated file with a header record and a corresponding Index file with header record
 *
 * @author Jordan Hebler
 * @author Justine Canlas
 */

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <string>

#include "dhObject.h"
#include "indexObject.h"
#include "DHbuffer.h"
#include "buffer.h"
#include "LIbuffer.h"

using namespace std;

void parseHeader(vector<string>& v, string s);
void setFields(vector<string> tokens, vector<string> header, zipCode& record);

int main (int argc, char* argv[]) {
    
    // Ensures the correst number of arguments is given
    if (argc != 4) {
        cerr << "Invalid arguments on command line!" << endl;
        cerr << "Format = ./test csvFile.csv dataFile.txt indexFile.txt" << endl;
        exit(1);
    }
    
    string csvFile = argv[1];
    string dataFile = argv[2];
    string indexFile = argv[3];
    
    ifstream fin;
    fstream fout;
    string line;
    string header = "";
    vector<string> headerInfo;
    int count = 0;
    
    fin.open(csvFile);
    
    //If the CSV file given on command line does not exist, output message and exit program
    if(fin.fail()){
        cerr << "Failed to open CSV file!" << endl;
        cerr << "Exiting program" << endl;
        exit(2);
    }
    
    //Sets object as dhObject object
    dhObject object;
    
    //Calls mutator to set the value of the Filetype
    object.setFiletype("Length Indicated");
    
    //Calls mutator to set the value of the Fileversion
    object.setFileversion(1);
    
    //Calls mutator to set the value of the Headersize
    object.setHeadersize(256);
    
    //Calls mutator to set the Size format
    object.setSizeformat("ASCII");
    
    //Calls mutator to set the value of the Indexfile
    object.setIndexfile(indexFile);
    
    //Calls mutator to set the value of the Recordcount
    object.setRecordcount(0);
    
    //Calls mutator to set the value of the Fieldcount
    object.setFieldcount(6);
    
    //Calls mutator to set the values for the fieldpairs vector
    object.setFieldpairs("ZipCode", "int");
    object.setFieldpairs("Placename", "string");
    object.setFieldpairs("State", "string");
    object.setFieldpairs("County", "string");
    object.setFieldpairs("Latitude", "double");
    object.setFieldpairs("Longitude", "double");
    
    //Calls mutator to set the value of the Primekey
    object.setPrimekey(0);
    
    //Sets DHbuffer as a DataHeaderBuffer object
    DataHeaderBuffer DHbuffer;
    DelimTextBuffer buffer(',');
    LIbuffer LI(',');
    
    //Calls Pack function from the DHbuffer to pack the object
    DHbuffer.Pack(object);
   
    //Open/create the data file, if it already exists, erase previous version
    fout.open(dataFile, fstream::out | fstream::trunc);
    
    DHbuffer.writeDataHeader(fout);
    
    //Sets the ofstream pointer to be placed just after the header
    fout.seekp(object.getHeadersize());
    
    while (getline(fin, line)) {
        count++;
        
        //Takes the header info from the CSV file and concatenates it into a single string
        if(count <= 3){
            header += line;
        }
        
        //Header is fully read, time to extract each field and put into the headerInfo vector
        if(count == 3){
            parseHeader(headerInfo, header);
        }
        
        //Header has been read, now at the data in the file
        if(count > 3){
            buffer.Read(line);
        
            //Creates a vector string tokens
            vector<string> tokens;
            
            //Calls in Unpack function from the buffer file to unpack the buffer into the vector of strings that is passed as a parameter.
            buffer.Unpack(tokens);
            
            //Constricts record
            zipCode record;
        
            //Calls in setFields function from this file and sets the field of each record object used for the program.
            setFields(tokens, headerInfo, record);
        
            //Calls the Pack function from the LIbuffer and is used to pack the fields vector with the data members from a zipCode record.
            LI.Pack(record);
        
            //Calls in write function from the LIbuffer which writes the size of the record and the contents to the file.
            LI.Write(fout);
            
            //Calls in Clear function function and will set the size to 0. The fields will be cleared.
            LI.Clear();
            
            object.setRecordcount(object.getRecordcount() + 1);
        }
        
        
    }
    //Calls DHbuffer Pack function to pack from the header
    DHbuffer.Pack(object);
    //Calls DHbuffer writeDataHeader function to write to the header
    DHbuffer.writeDataHeader(fout);
    
    
    fin.close();
    fout.close();
    
//**************************************************************
// Data File created, now time to create the Index File
//**************************************************************
    
    
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
 
    
    //Calls the Pack function from the DHbuffer to pack index object
    DHbuffer.Pack(index);
    
    //Open/create the index file, if it already exists, erase previous version
    fout.open(indexFile, fstream::out | fstream::trunc);
    
    //Calls the writeIndexHeader function from the DHbuffer to write ZipCodePKI.txt
    DHbuffer.writeIndexHeader(fout);
    
    fin.open(dataFile);
    
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
    
    //For loop to output
    for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
        
        fout << itr1->first << ',' << itr1->second << "\n";
        
    }
    
    //Closes .txt files
    fin.close();
    fout.close();
  return 0;
}

//*****************************************************************************************
/**
*This sets the field of each record object used for the program
*It compares each field with the header record to ensure correct data is set
*
* @param Vector string of tokens, a vector string of header and call zipCode record class.
* @return None
* @pre None
* @post Compared all of the fields with the header record
*/
void setFields(vector<string> tokens, vector<string> header, zipCode& record){
    
    for(int i = 0; i < tokens.size(); i++)
    {
        if (header[i] ==  "\"ZipCode\"") {
            //Compare Zipcode
            record.setZip(stoi(tokens[i]));
        }
        if (header[i] == "\"PlaceName\"" ) {
            //Compare Placename
            record.setPlacename(tokens[i]);
        }
        if (header[i] == "State" ) {
            //Compare State
            record.setState(tokens[i]);
        }
        if (header[i] == "County" ) {
            //Compare County
            record.setCounty(tokens[i]);
        }
        if (header[i] == "Lat" ) {
            //Compare Latitude
            record.setLat(stod(tokens[i]));
        }
        if (header[i] == "Long" ) {
            //Compare Longitude
            record.setLon(stod(tokens[i]));
        }
    }
}

/**
*Parses the header string and puts each field into a vector
*
* @param Vector string of v and string of s
* @return None
* @pre None
* @post parse header and puts each field into a vector
*/
void parseHeader(vector<string>& v, string s){
    
    stringstream check1(s);
  
    string intermediate;
  
    while(getline(check1, intermediate, ','))
    {
        v.push_back(intermediate);
    }
}
