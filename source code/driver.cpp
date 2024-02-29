// -------------------------------------------------------------------------------------------
// Start the program, get the program test result 
// -------------------------------------------------------------------------------------------



#include <iostream>
#include "business.h"


int main(int argc, const char* argv[])
{
	Business business;
	business.processMovieFile();
	business.processCustomerFile();
	business.processCommandsFile();

	return 0;
}