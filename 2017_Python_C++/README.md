# Using C++ code in Python

This code was used in blog entry [http://morony.pl/?p=1052].

This example shows how to speed up Python execution by moving calculation into c++ code. 

Problem used is fairly simple: we take list of `N=1000` numbers and calculate how many sets of three numbers out of this list have sum smaller than `threshold = 10e-8`. We go brut force. 

To compile C++ code run:
```
python3 setup.py build_ext --inplace
```

To run test:
```
python3 progrm.py
```

Sample result:
```C++ start
C++ finish
C++: 13 0.12128806114196777
Python: 13 106.85409307479858
Speed: 880.9943210298809
```

Speedup of 880 times is very tempting, isn't it?
