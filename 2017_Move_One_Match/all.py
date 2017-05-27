
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
minus[6] = [5]
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
def print_result(wa,wo1,wb,wo2,wc,a, o1, b, o2, c):
	if test_single(a, o1, b, o2, c):
		print("{0}{1}{2}{3}{4} -> {5}{6}{7}{8}{9}".format(wa,wo1,wb,wo2,wc,a,o1,b,o2,c))
		return 1
	else:
		return 0;


def all_comb(a, o1, b, o2, c):
	count = 0
	for a1 in swap[a]:
		count = count + print_result(a,o1,b,o2,c,a1, o1, b, o2, c)
	for b1 in swap[b]:
		count = count + print_result(a,o1,b,o2,c,a, o1, b1, o2, c)
	for c1 in swap[c]:
		count = count + print_result(a,o1,b,o2,c,a, o1, b, o2, c1)
	if o1 == '-':
		count = count + print_result(a,o1,b,o2,c,a, "=", b, "-", c)
	for a1 in minus[a]:
		for b1 in plus[b]:
			count = count + print_result(a,o1,b,o2,c,a1, o1, b1, o2, c)
		for c1 in plus[c]:
			count = count + print_result(a,o1,b,o2,c,a1, o1, b, o2, c1)
		if o1 == "-":
			count = count + print_result(a,o1,b,o2,c,a1, "+", b, o2, c)
		if o2 == "-":
			count = count + print_result(a,o1,b,o2,c,a1, o1, b, "+", c)
	for b1 in minus[b]:
		for a1 in plus[a]:
			count = count + print_result(a,o1,b,o2,c,a1, o1, b1, o2, c)
		for c1 in plus[c]:
			count = count + print_result(a,o1,b,o2,c,a, o1, b1, o2, c1)
		if o1 == "-":
			count = count + print_result(a,o1,b,o2,c,a, "+", b1, o2, c)
		if o2 == "-":
			count = count + print_result(a,o1,b,o2,c,a, o1, b1, "+", c)
	for c1 in minus[c]:
		for b1 in plus[b]:
			count = count + print_result(a,o1,b,o2,c,a, o1, b1, o2, c1)
		for a1 in plus[a]:
			count = count + print_result(a,o1,b,o2,c,a1, o1, b, o2, c1)
		if o1 == "-":
			count = count + print_result(a,o1,b,o2,c,a, "+", b, o2, c1)
		if o2 == "-":
			count = count + print_result(a,o1,b,o2,c,a, o1, b, "+", c1)
	if o1 == "+":
		for a1 in plus[a]:
			count = count + print_result(a,o1,b,o2,c,a1, "-", b, o2, c)
		for b1 in plus[b]:
			count = count + print_result(a,o1,b,o2,c,a, "-", b1, o2, c)
		for c1 in plus[c]:
			count = count + print_result(a,o1,b,o2,c,a, "-", b, o2, c1)
	return count

for to1 in ["+", "-"]:
	for ta in range(10):
		for tb in range(10):
			for tc in range(10):
				tcount = all_comb(ta,to1,tb,"=",tc)
				#if tcount > 2:
				#	print("{0}{1}{2}{3}{4}".format(ta,to1,tb,"=",tc), tcount)