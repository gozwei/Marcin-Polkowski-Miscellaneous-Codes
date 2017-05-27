
plus = dict()
plus[0] = [8]
plus[1] = [7]
plus[2] = []
plus[3] = [9]
plus[4] = []
plus[5] = [9]
plus[6] = [8]
plus[7] = []
plus[8] = []
plus[9] = [8]

minus = dict()
minus[0] = []
minus[1] = []
minus[2] = []
minus[3] = []
minus[4] = []
minus[5] = []
minus[6] = []
minus[7] = [1]
minus[8] = [0, 6, 9]
minus[9] = [3, 5]

swap = dict()
swap[0] = [6, 9]
swap[1] = []
swap[2] = [3]
swap[3] = [2, 5]
swap[4] = []
swap[5] = [3]
swap[6] = [0, 9]
swap[7] = []
swap[8] = []
swap[9] = [0, 6]


def test_single(a, o1, b, o2, c):
	if o2 == "=":
		if o1 == "+":
			return a+b==c
		elif o1 == "-":
			return a-b==c
		else:
			print('ERROR')
	elif o1 == "=":
		if o2 == "+":
			return a+b==c
		elif o2 == "-":
			return a-b==c
		else:
			print('ERROR')
	else:
		print('ERROR')
def print_result(a, o1, b, o2, c,debug):
	print("{5}: {0}{1}{2}{3}{4}:".format(a,o1,b,o2,c,debug), test_single(a, o1, b, o2, c));


def all_comb(a, o1, b, o2, c):
	#print("SWAPY")
	for a1 in swap[a]:
		print_result(a1, o1, b, o2, c,1)
	for b1 in swap[b]:
		print_result(a, o1, b1, o2, c,2)
	for c1 in swap[c]:
		print_result(a, o1, b, o2, c1,3)
	if o1 == '-':
		print_result(a, "=", b, "-", c,4)
	#print("A minus")
	for a1 in minus[a]:
		for b1 in plus[b]:
			print_result(a1, o1, b1, o2, c,5)
		for c1 in plus[c]:
			print_result(a1, o1, b, o2, c1,6)
		if o1 == "-":
			print_result(a1, "+", b, o2, c,7)
		if o2 == "-":
			print_result(a1, o1, b, "+", c,8)
	#print("B minus")
	for b1 in minus[b]:
		for a1 in plus[a]:
			print_result(a1, o1, b1, o2, c,9)
		for c1 in plus[c]:
			print_result(a, o1, b1, o2, c1,10)
		if o1 == "-":
			print_result(a, "+", b1, o2, c,11)
		if o2 == "-":
			print_result(a, o1, b1, "+", c,12)
	#print("C minus")
	for c1 in minus[c]:
		for b1 in plus[b]:
			print_result(a, o1, b1, o2, c1,13)
		for a1 in plus[a]:
			print_result(a1, o1, b, o2, c1,14)
		if o1 == "-":
			print_result(a, "+", b, o2, c1,15)
		if o2 == "-":
			print_result(a, o1, b, "+", c1,16)

	#print("+ minus")
	if o1 == "+":
		for a1 in plus[a]:
			print_result(a1, "-", b, o2, c,17)
		for b1 in plus[b]:
			print_result(a, "-", b1, o2, c,18)
		for c1 in plus[c]:
			print_result(a, "-", b, o2, c1,19)


all_comb(1,"+",2,"=",8)