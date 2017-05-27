# Tesla Motors Coding Challenge

This code is a solution to Tesla Coding Challenge by Marcin Polkowski

To compile you can use g++ directly:
```
g++ -std=c++11   -c -o src/functions.o src/functions.cpp
g++ -std=c++11   -c -o src/str_func.o src/str_func.cpp
g++ -std=c++11   -c -o src/TeslaCC.o src/TeslaCC.cpp
g++ -std=c++11  -o TeslaCC  ./src/functions.o  ./src/str_func.o  ./src/TeslaCC.o 
```

Or you can use attached makefile:
```
make clean
make all
```

Resulting binary can be executed:
```
./TeslaCC input.txt
```

Program accepts one and only one name of input file with format as explained in Problem Description (see below).

The result (alphabetically sorted list of variables with values) is printed to standard output.

Example:
```
>> ./TeslaCC input.txt 
location = 16
offset = 7
origin = 8
random = 2
```

Notes:
1) Solution assumes well formed input
2) Solution was tested using g++ on Mac OS X: (Apple LLVM version 7.3.0 (clang-703.0.31), Target: x86_64-apple-darwin15.5.0)
3) Solution was tested using g++ on Windows 7 (gcc version 4.8.1 (GCC))

# Problem Description

Your task is to write a command-line program to evaluate a set of equations, each specified on separate lines. An equation is defined by:
```
<LHS> = <RHS>
```

`<LHS>` is the left-hand side of the equation and is always a variable name. A variable name can only be composed of letters from the alphabet (e.g. for which isalpha(c) is 1). `<RHS>` is the right hand side of the equation and can be composed of variables, unsigned integers, and the + operator.

Here is one example set of equations:
```
offset = 4 + random + 1
location = 1 + origin + offset
origin = 3 +5
random = 2
```

Your program should take a filename as input. The file contains a set of equations, like the above. It should evaluate the set of equations and print the unsigned integer value of each variable.
```
<variable name> = <unsigned integer value>
```

The output should be sorted by in ascending order by variable name.

The output for the example above would be:
```
location = 16
offset = 7
origin = 8
random = 2
```

You may assume the following: You may assume the input is well formed. There will be one or more white spaces between each token. You may use C++, the Standard C libraries and the Standard Template Library (STL). You may use std::sort and qsort. All variables in the equation set will have a definition. You may  also assume a variable is only defined once and will have a valid integer solution.

## Submission

We recognize that your time is valuable so please wind down your investigations if you hit the 3 hour mark, or earlier if you hit diminishing returns.

Submit your submission to me via email with the following:
1. Source code
2. Example output
3. (if necessary) instructions on how to build and execute your code
4. (optionally) any thoughts you'd like to share

# Disclaimer 

The Coding Challenge was not described by Tesla Motors as confidential.
