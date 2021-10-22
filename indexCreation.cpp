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
    
    indexObject index;
    dhObject data;
    
    index.setPkey("ZipCode");
    index.setKeytype("int");
    index.setKeylength(5);
    index.setRef("Byte Offset");
    index.setReftype("int");
    index.setReflength(7);
    index.setHeadersize(128);
 
    
    DataHeaderBuffer DHbuffer;
    LIbuffer LI(',');
    
    DHbuffer.Pack(index);
    
    fout.open("ZipCodePKI.txt");
    
    DHbuffer.writeIndexHeader(fout);
    
    fin.open("ZipCodeLI.txt");
    
    DHbuffer.readDataHeader(fin);
    
    DHbuffer.Unpack(data);
    
    map< int, int > m;
    
    fin.seekg(data.getHeadersize());
    
    int position = fin.tellg();
    
    while (LI.Read(fin)) {
           
        zipCode record;
        
        LI.Unpack(record);
                
        m.insert(pair<int,int>(record.getZip(), position));
        
        position = fin.tellg();
            
    }
    
    fout.seekp(index.getHeadersize());
    
    map<int,int>::iterator itr1;
    
    for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
        
        fout << itr1->first << ',' << itr1->second << "\n";
        
    }
    
    fin.close();
    fout.close();
  return 0;
}

//Function used to see what's in the map before writing to the file
void outputValues(map<int,int> m){
    
    map<int,int>::iterator itr1;
        cout << "\tKEY\tOffset\n";
        for (itr1 = m.begin(); itr1 != m.end(); ++itr1) {
            cout << '\t' << itr1->first;
            
            cout << '\t' << itr1->second << endl;
        }
        cout << endl;
}
