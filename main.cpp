//*************************************************************
/**
@file main.cpp
@author Anuja Modi
@brief This is the main program that read the flags from users during execution to demonstrate the desired task.
*/
//*************************************************************

#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	string filename = argv[0];
  	vector<int> zipcodes;
	int number;
        while ((argc > 1) && (argv[1][0] == '-')) {
			switch (argv [1] [1]) {
				case 'Z':
					number =  atoi(argv[1][2]);
            		zipcodes.push_back(number);
    			default:
					cerr << "Invalid argument" << argv[1] << '';
			}
		++argv;
		--argc;
	}
}
