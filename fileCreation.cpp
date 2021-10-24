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
    
    dhObject object;
    object.setFiletype("Length Indicated");
    object.setFileversion(1);
    object.setHeadersize(256);
    object.setSizeformat("ASCII");
    object.setIndexfile("ZipCodePKI.txt");
    object.setRecordcount(0);
    object.setFieldcount(6);
    
    object.setFieldpairs("ZipCode", "int");
    object.setFieldpairs("Placename", "string");
    object.setFieldpairs("State", "string");
    object.setFieldpairs("County", "string");
    object.setFieldpairs("Latitude", "double");
    object.setFieldpairs("Longitude", "double");
    
    object.setPrimekey(0);
    
    DataHeaderBuffer DHbuffer;
    DelimTextBuffer buffer(',');
    LIbuffer LI(',');
    
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
        
            vector<string> tokens;
        
            buffer.Unpack(tokens);
        
            zipCode record;
        
            setFields(tokens, headerInfo, record);
        
            LI.Pack(record);
        
            LI.Write(fout);
        
            LI.Clear();
            
            object.setRecordcount(object.getRecordcount() + 1);
        }
        
        
    }
    
    DHbuffer.Pack(object);
    DHbuffer.writeDataHeader(fout);
    
    
    fin.close();
    fout.close();
  return 0;
}

//*****************************************************************************************
//This sets the fields of each record object used for the program
//Compares each field with the header record to ensure correct data is set
void setFields(vector<string> tokens, vector<string> header, zipCode& record){
    
    for(int i = 0; i < tokens.size(); i++)
    {
        if (header[i] ==  "\"ZipCode\"") {
            //Zipcode
            record.setZip(stoi(tokens[i]));
        }
        if (header[i] == "\"PlaceName\"" ) {
            //Placename
            record.setPlacename(tokens[i]);
        }
        if (header[i] == "State" ) {
            //State
            record.setState(tokens[i]);
        }
        if (header[i] == "County" ) {
            //County
            record.setCounty(tokens[i]);
        }
        if (header[i] == "Lat" ) {
            //Latitude
            record.setLat(stod(tokens[i]));
        }
        if (header[i] == "Long" ) {
            //Longitude
            record.setLon(stod(tokens[i]));
        }
    }
}

//Parses the header string and puts each field into a vector
void parseHeader(vector<string>& v, string s){
    
    stringstream check1(s);
  
    string intermediate;
  
    while(getline(check1, intermediate, ','))
    {
        v.push_back(intermediate);
    }
}
