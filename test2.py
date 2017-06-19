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

a, b, c = symbols("x, y, z")

_propositions = [a,  b]

f = And(Or(x, y), x)

pprint(f)
