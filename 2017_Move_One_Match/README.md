# Solution to all Move One Match Problem

This code was written just for fun to solve problems similar to those:

![alt Move One Match Problem](http://morony.pl/wp-content/uploads/2016/11/IMG_1110-1024x503.jpg "Move One Match Problem")

## test.py

This code is used for debugging. You need to set your initial state (ex. 1+2=8):

```
all_comb(1,"+",2,"=",8)
```
 
Program will print all possible equations afer moving one match with information about method used (see code) and test if result is mathematically correct:

```
2: 1+3=8: False
14: 7+2=0: False
14: 7+2=6: False
14: 7+2=9: True
17: 7-2=8: False
```

## all.py

This is production code: prints all possibile start equation that can be transformed to correct equation after one match is moved.

You can use `grep` to search for problems. For example to find solution to top most problem form picture above you can run:
```
python3 all.py | grep 0-9=5
```

This should produce two solutions: `8-3=5` and `0+5=5`.

Have fun!