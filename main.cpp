//*************************************************************
/**
@file main.cpp
@author Anuja Modi
@brief This is the main program that read the flags from users during execution to demonstrate the desired task.
*/
//*************************************************************

#include "DHbuffer.h"
int main(int argc, const char* argv[])
{
	// Retrieve argv
	// The first argv is a.out
	// The second argv is the file name
	string filename = argv[1];
	
	// Initialize file name & header
	convert(filename);
	LengthIndicatedFile<Location> aFile(filename);
	// Retrieve flags
	for (int i = 2; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			
      
      
      
      
		}
		else
		{
			cout << "Invalid argument, exit..." << endl;
			return 0;
		}
	}
}
