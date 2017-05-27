#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "var_struct.h"
#include "str_func.h"

// Comparison function for alphabetical sorting
bool name_cmp(const var &a, const var &b)
{
    return  a.name < b.name;
}


// Helper function for determinig if valu of given variable name is alraedy known
int find_value(const std::vector <var> variables, std::string varname)
{
	for( size_t i = 0; i < variables.size(); i++ )
	{
		if(variables[i].name.compare(varname) == 0)
		{
			if(variables[i].done)
			{
				return variables[i].value;
			}
		}
	}
	// If there is no known value, negative value is returned
	return -1;
}

// Main solving function
void solve_equations(std::vector <var> &variables)
{
	// Step 1: parsing name and dependencies 
	for( size_t i = 0; i < variables.size(); i++ )
	{
		// name of variable is taken as all characters before equal sign, and trimmed
		variables[i].name = trim(variables[i].definition.substr(0, variables[i].definition.find("=")));

		// definition of variable is taken as all characters after equal sign, and trimmed
        variables[i].definition = trim(variables[i].definition.substr(variables[i].definition.find("=") + 1));

        // definition is split into parts
        variables[i].dependencies = split(variables[i].definition, '+');

        // each part or definition is trimmed
        for( size_t j = 0; j < variables[i].dependencies.size(); j++ )
	    {
	       	variables[i].dependencies[j] = trim(variables[i].dependencies[j]);
	    }
    }

    // Step 2: solving untill all variables are solved
    int numer_of_done = 0;
    while(numer_of_done < variables.size())
    {
    	// loop foreach variable
	    for( size_t i = 0; i < variables.size(); i++ )
		{
			int numerics = 0; // helper cariable for checkig if all dependencies are numeric
			// loop foreach dependencies of variable
			// the goal is to conver all names into values
	        for( size_t j = 0; j < variables[i].dependencies.size(); j++ )
	        {
	        	if(is_number(variables[i].dependencies[j]))
	        	{
					numerics++;
	        	}
	        	else
	        	{
	        		// if givien dependency is not numeric, check if it has known value
	        		int x = find_value(variables, variables[i].dependencies[j]);

	        		// if there is known value add it to current variable and prevent processing again
	        		if(x > 0)
	        		{	
	        			//cout << "--- found: " << variables[i].dependencies[j] << " : " << x << endl;
	        			variables[i].dependencies[j] = "0";
	        			variables[i].value += x;
	        		}
	        	}
	        }
	        // if all dependencies are numeric, calculate variable value
	        if(numerics == variables[i].dependencies.size())
	        {
	        	for( size_t j = 0; j < variables[i].dependencies.size(); j++ )
	        	{
	        		variables[i].value += atoi(variables[i].dependencies[j].c_str());
	        		// when value of variable is calculated, its dependencies are changed to "0", so they wont be calculated again
	        		variables[i].dependencies[j] = "0";
	        	}

	        	// mark variable as done (with calculatet knwon value)
	        	if(variables[i].done == false) // just making sure if same varialbe is not calculated as done multiple times
	        	{
	        		numer_of_done++;
	        	}
	        	variables[i].done = true;
	        }
	    }
	}

}

// helper function for printing result (includes sorting)
void print_result(std::vector <var> &variables)
{
	// sorting using dedicated comparison function
	sort(variables.begin(), variables.end(), name_cmp);

	// printing values of all variables in alphabetical order
	for( size_t i = 0; i < variables.size(); i++ )
	{
		std::cout << variables[i].name << " = " << variables[i].value << std::endl;
    }
}

// helper finction for reding source file
std::vector <var> read_input(char* fname)
{
	std::ifstream infile(fname);
	std::string line;
	std::vector < var >variables;
	while (getline(infile, line))
	{
	    variables.push_back(var(line));
	}

	return variables;
}