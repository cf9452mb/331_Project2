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

int DataHeaderBuffer::writeHeader(std::fstream& file){
    
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

void DataHeaderBuffer::setFieldpairs(std::vector<field> pairs){
    this->fieldpairs = pairs;
}

void DataHeaderBuffer::Clear(){
    this->headerinfo.clear();
    this->fieldpairs.clear();
}
