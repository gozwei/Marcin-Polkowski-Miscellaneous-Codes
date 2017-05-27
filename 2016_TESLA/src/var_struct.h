#ifndef MYSTRUCT_H
#define MYSTRUCT_H
#include <string>
#include <vector>


// Main data structure for each variable
struct var
{
	std::string name;
	std::string definition; // Full RHS string
	std::vector <std::string> dependencies; // Vector containg all dependencies of variable (all elements from RHS) 
	int value = 0; // Initial numeric value of variable
	bool done = false; // Check if final value is calculated
	
	var(std::string d) : definition(d) {}
};

#endif