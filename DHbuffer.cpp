//--------------------------------------------------
// DHbuffer.cpp
// Class for a buffer which reads, writes, packs and unpacks data
// Author: Anuja Modi, Jordan Hebler
//--------------------------------------------------
// This implementation file includes a class DataHeaderBuffer
//--------------------------------------------------
#include <vector>
#include <string>
#include <fstream>

#include "DHbuffer.h"

std::string parseLine(std::string line);
std::vector<field> parseFields(std::string line);

/**
 * @file DHbuffer.cpp
 * @brief This is the implementation file for the DataHeaderBuffer class
 *
 * @author Anuja Modi
 * @author Jordan Hebler
 */

DataHeaderBuffer::DataHeaderBuffer(){
    //Empty for now
}

int DataHeaderBuffer::Pack(dhObject& object){
    
    this->Clear();
    
    headerinfo.push_back(object.getFiletype());
    headerinfo.push_back(std::to_string(object.getFileversion()));
    headerinfo.push_back(std::to_string(object.getHeadersize()));
    headerinfo.push_back(object.getSizeformat());
    headerinfo.push_back(object.getIndexfile());
    headerinfo.push_back(std::to_string(object.getRecordcount()));
    headerinfo.push_back(std::to_string(object.getFieldcount()));
    this->setFieldpairs(object.getFieldpairs());
    headerinfo.push_back(std::to_string(object.getPrimekey()));
    
    return 1;
    
}

int DataHeaderBuffer::Pack(indexObject& object){
    
    this->Clear();
    
    headerinfo.push_back(object.getPkey());
    headerinfo.push_back(object.getKeytype());
    headerinfo.push_back(std::to_string(object.getKeylength()));
    headerinfo.push_back(object.getRef());
    headerinfo.push_back(object.getReftype());
    headerinfo.push_back(std::to_string(object.getReflength()));
    headerinfo.push_back(std::to_string(object.getHeadersize()));
    
    return 1;
}

int DataHeaderBuffer::Unpack(dhObject& object){
    object.setFiletype(headerinfo[0]);
    object.setFileversion(stoi(headerinfo[1]));
    object.setHeadersize(stoi(headerinfo[2]));
    object.setSizeformat(headerinfo[3]);
    object.setIndexfile(headerinfo[4]);
    object.setRecordcount(stoi(headerinfo[5]));
    object.setFieldcount(stoi(headerinfo[6]));
    for (field i : fieldpairs) {
        object.setFieldpairs(i.name, i.type);
    }
    object.setPrimekey(stoi(headerinfo[7]));
    
    return 1;
    
}

int DataHeaderBuffer::Unpack(indexObject& object){
    object.setPkey(headerinfo[0]);
    object.setKeytype(headerinfo[1]);
    object.setKeylength(stoi(headerinfo[2]));
    object.setRef(headerinfo[3]);
    object.setReftype(headerinfo[4]);
    object.setReflength(stoi(headerinfo[5]));
    object.setHeadersize(stoi(headerinfo[6]));
    
    return 1;
}

int DataHeaderBuffer::readDataHeader(std::ifstream& file){
    
    this->Clear();
    
    file.seekg(0, std::ios::beg);
    std::string line;
    int count = 0;
    while(count < 7){
        getline(file, line);
        headerinfo.push_back(parseLine(line));
        count++;
    }

    getline(file, line);
    this->fieldpairs = parseFields(parseLine(line));
    
    getline(file, line);
    headerinfo.push_back(parseLine(line));
    
    return 1;
    
}

int DataHeaderBuffer::readIndexHeader(std::ifstream& file){
    
    this->Clear();
    
    file.seekg(0, std::ios::beg);
    std::string line;
    int count = 0;
    while(count < 7){
        getline(file, line);
        headerinfo.push_back(parseLine(line));
        count++;
    }
    
    return 1;
    
}


int DataHeaderBuffer::writeDataHeader(std::fstream& file){
    
    file.seekp(0, std::ios::beg);
    file << "FSTYPE  = " << headerinfo[0] << std::endl;
    file << "V_FSTYPE= " << headerinfo[1] << std::endl;
    file << "HDR_SIZE= " << headerinfo[2] << std::endl;
    file << "S_FORMAT= " << headerinfo[3] << std::endl;
    file << "INDX_FIL= " << headerinfo[4] << std::endl;
    file << "RECCOUNT= " << headerinfo[5] << std::endl;
    file << "FLDS/REC= " << headerinfo[6] << std::endl;
    file << "NAME/TYP= ";
    for (field i : fieldpairs) {
        file << '(' << i.name << ',' << i.type << ')';
    }
    file << std::endl;
    file << "PRIM/KEY= " << headerinfo[7] << std::endl;
   
    return 1;
}

int DataHeaderBuffer::writeIndexHeader(std::fstream& file){
    
    file.seekp(0, std::ios::beg);
    file << "PRIMEKEY= " << headerinfo[0] << std::endl;
    file << "KEY_TYPE= " << headerinfo[1] << std::endl;
    file << "KEY_LEN = " << headerinfo[2] << std::endl;
    file << "REFERENC= " << headerinfo[3] << std::endl;
    file << "REF_TYPE= " << headerinfo[4] << std::endl;
    file << "REF_LEN = " << headerinfo[5] << std::endl;
    file << "HDR_SIZE= " << headerinfo[6] << std::endl;
    
    return 1;
    
}

void DataHeaderBuffer::setFieldpairs(std::vector<field> pairs){
    this->fieldpairs = pairs;
}

void DataHeaderBuffer::Clear(){
    this->headerinfo.clear();
    this->fieldpairs.clear();
}

//Parses the keywords in the header file
std::string parseLine(std::string line){
    std::string delim("= ");
    size_t start = line.find(delim);
    line.erase(0, start + delim.length());
    return line;
}

//Takes the (name,type) pairs line and parses it
std::vector<field> parseFields(std::string line){
    std::vector<std::string> words;
    std::vector<field> fields;
    std::string delim(")");
    std::string delim2(",");
    size_t pos = 0;
    while ((pos = line.find(delim)) != std::string::npos) {
            words.push_back(line.substr(0, pos + 1));
            line.erase(0, pos + delim.length());
    }
    for (std::string s : words) {
        field pair;
        size_t p = s.find(delim2);
        pair.name = s.substr(1, p - delim2.length());
        s.erase(0, p + delim2.length());
        p = s.find(delim);
        pair.type = s.substr(0, p);
        fields.push_back(pair);
    }
    
    return fields;
}
