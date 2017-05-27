# Some C++ fun with floating point numbers

This code was used in blog entry [http://morony.pl/?p=1017].

## `double.cpp`

This code will print min and max double precission numbers for all possibile (`2^11=2048`) exponents. This example is made to show that there is the same number of different numbers between `0.5 - 1` and `1 - 2` and so on. 

```
g++ --std=gnu++11 double.cpp
./a.out
```

## `float.cpp`

This example will use brutforce to produce all posibile bit combinations and calculate number of corresponding floating point numbers (single precission) in given ranges. 

```
g++ --std=gnu++11 float.cpp
./a.out
```