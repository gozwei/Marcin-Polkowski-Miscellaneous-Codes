#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

// helper function for splitting string by character 
std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) 
    {
        elems.push_back(item);
    }
    return elems;
}

// helper function for removing spaces from beginning and end of string. 
std::string trim(std::string str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

// helper function for checking if strig represents number
bool is_number(const std::string& s)
{
    return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}
