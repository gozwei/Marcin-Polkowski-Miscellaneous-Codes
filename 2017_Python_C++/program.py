import numpy
import CALC
import time
start_time = time.time()

N = 1000
treshold = 10e-8

DATA = numpy.random.uniform(0, 1, size=N)
RESULT = numpy.zeros((1,), dtype=numpy.int)

start_time = time.time()
CALC.CALC(DATA, RESULT, N, treshold)
t1 = (time.time() - start_time)
print("C++:", RESULT[0], t1)


start_time = time.time()
count = 0;
for a in range(0,N):
	for b in range(a+1,N):
		for c in range(b+1,N):
			if abs(DATA[a]+DATA[b]+DATA[c]-1) < treshold:
				count =count + 1
t2 = (time.time() - start_time)
print("Python:", count, t2)

print("Speed:", t2/t1)