//---------------------------------------------------------------------
// fileCreation.cpp
// Program used to create the Length Indicated data files with headers
// Author: Jordan Hebler
//---------------------------------------------------------------------
// Specify the Data header object members before writing the header,
// and specify the output stream to write the header/data too and the
// input file stream to read the CSV data from
//---------------------------------------------------------------------

/**
 * @file fileCreation.cpp
 * @brief This is the program to create a Length Indicated file with a header record
 *
 * @author Jordan Hebler
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "dhObject.h"
#include "DHbuffer.h"
#include "buffer.h"
#include "LIbuffer.h"

using namespace std;

void parseHeader(vector<string>& v, string s);
void setFields(vector<string> tokens, vector<string> header, zipCode& record);

int main (int argc, char* argv[]) {
    ifstream fin;
    fstream fout;
    string line;
    string header = "";
    vector<string> headerInfo;
    int count = 0;
    
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
    object.setIndexfile("ZipCodePKI.txt");
    
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
   
    fout.open("ZipCodeLI.txt");
    
    DHbuffer.writeDataHeader(fout);
    
    fin.open("zipcode.csv");
    
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
