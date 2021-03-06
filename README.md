# 331_Project2
Zip Code Group Project 2

User Guide for Zip Code Group Project 2.0

Step 1: Compiling fileCreation.cpp program
    g++ -std=c++11 -o create fileCreation.cpp zipCode.cpp dhObject.cpp indexObject.cpp DHbuffer.cpp buffer.cpp LIbuffer.cpp
    
Step 2: Running the program to create the LI file and corresponding Primary Key Index file
    ./create zipcode.csv ZipCodeLI.txt ZipCodePKI.txt
    
    * zipcode.csv    = the CSV file to create the Length Indicated data file from
    * ZipCodeLI.txt  = the data file to write the Length Indicated data too including its header
    * ZipCodePKI.txt = the index file that is created with a header, corresponding too ZipCodeLI.txt
    
    NOTE: The data members for the Data Header Object (dhObject class) are explicitly set prior to execution
          The data members for the Index Object (indexObject class) are explicitly set prior to execution
          
Step 3: Compiling main.cpp program
    g++ -std=c++11 -o run main.cpp zipCode.cpp LIbuffer.cpp dhObject.cpp indexObject.cpp DHbuffer.cpp
    
Step 4: Running the main program
    ./run ZipCodeLI.txt [-Z<ZipCode>]
    
    * ZipCodeLI.txt   = the data file which will be used to search its Index file for the given Zip Codes
    * [-Z<ZipCode>]   = format to use on command line for searching (EX. -Z54311 will search for the Zip Code 54311)
    
    
Example Output:
    ./run ZipCodeLI.txt -Z98110 -Z42374 -Z19733
    
    Will Give:
    
        Zip Code|               Place Name|   State|      County|  Latitude| Longitude
        --------------------------------------------------------------------------------
           98110|        Bainbridge Island|      WA|      Kitsap|   47.6478|  -122.538
           42374|         South Carrollton|      KY|  Muhlenberg|   37.3375|  -87.1419
           19733|            Saint Georges|      DE|  New Castle|   39.5555|  -75.6505
