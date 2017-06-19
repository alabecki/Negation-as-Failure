import sympy.abc
from sympy.logic.boolalg import Not, And, Or
from sympy import*
from sympy.logic.inference import satisfiable, valid
from sympy.logic.boolalg import to_cnf
from mpmath import*
import mpmath
from itertools import product
from itertools import*
import pprint
import re
from copy import deepcopy



def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


# A, B, C, D, E, F, G, H, I, J, K, L, M, N = symbols("A, B, C, D, E, F, G, H, I, J, K, L, M, N")

a, b, c = symbols("a, b, c")

orx = Or(a,b)
ory = Or(a)
print(orx)

_propositions = [a,  b,]

propositions = deepcopy(_propositions)

for p in propositions:
	neg = Symbol()"~"+str(p))
	propositions.append(neg)
###for p in _propositions:
	#p = Symbol(p)
	#q = "~"
	#propositions.append("~"+p)
print("propositions")
for p in propositions:
	print(p)

#power = powerset(propositions)
#power = list(power)
#for p in power:
	#p =
	#print (p)


_subsets =  list(combinations(propositions, 2))
subsets = deepcopy(_subsets)

print("Before:")
for s in subsets:
	print (s)

count = 0
for i in range (len(_subsets)):
	if str(_subsets[i]).replace('Not', '') =


	print(count)
	print(str(_subsets[i])[0])
	print("Not(" + str(_subsets[i])[1] + ")  -")
	print(str(_subsets[i])[1])
	print("Not(" + str(_subsets[i])[0] + ")  -")
	if (str(_subsets[i])[1] == "Not(" + str(_subsets[i])[1] + ")") or (str(_subsets[i])[1] == "Not(" + str(_subsets[i])[0] + ")"):


		del subsets[i- count]
		count += 1
	#print(len(str(_subsets[i])[1]), (len(str(_subsets[i])[0])))
	#if len(str(_subsets[i][1])) == 2 and len(str(_subsets[i][0])) == 1:
		#if str(_subsets[i])[0][0] == str(_subsets[i])[1][1]:
			#del subsets[i- count]
		#	count += 1
	#print(len(str(_subsets[i])[0]), (len(str(_subsets[i])[1])))
	#if len(str(_subsets[i][0])) == 2 and len(str(_subsets[i][1])) == 1:
		#if str(_subsets[i])[0][1] == str(_subsets[i])[1][0]:
			#del subsets[i- count]
			#count += 1
print("After:")
for s in subsets:
	print (s)

print("\n")

formulas = []

for s in subsets:
	s = list(s)
	count = 0
	#s = symbols(s)
	#print("%s, %s " % (s[0], s[1]))
	#s[0] = symbols(s[0])
	#s[1] = symbols(s[1])
	print(s)

for s in subsets:
	a = s[0]
	b = s[1]
	formulas.append(Or(a, b))
	formulas.append(And(a, b))

for f in formulas:
	print(f)
