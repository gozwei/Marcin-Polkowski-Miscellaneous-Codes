# Some C++ fun with floating point numbers

This code was used in blog entry [http://morony.pl/?p=1017].

## `double.cpp`

This code will print min and max double precision numbers for all possible (`2^11=2048`) exponents. This example is made to show that there is the same number of different numbers between `0.5 - 1` and `1 - 2` and so on. 

```
g++ --std=gnu++11 double.cpp
./a.out
```

## `float.cpp`

This example will use brut force to produce all possible bit combinations and calculate number of corresponding floating point numbers (single precision) in given ranges. 

```
g++ --std=gnu++11 float.cpp
./a.out
```
