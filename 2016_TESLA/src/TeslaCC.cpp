#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


// Definition of data structure used
#include "var_struct.h"

// Definitions of helper, string processing function
#include "str_func.h"

// Definitions of function of main problem solution
#include "functions.h"


// Main function
int main( int argc, char * argv[] )
{
	// Checking if one argument is given
	if(argc != 2)
	{
		std::cout << "Specify ONE input file" << std::endl << "exiting..." << std::endl << std::endl;
		return 0;
	}

	// Reading input file into vector of variables
	std::vector <var> variables = read_input(argv[1]); 

	// Processing equations until solved
	solve_equations(variables);

	// Printing the result
	print_result(variables);
	

	return 0;
}