import sys

### --- Booleans --- ###
my_bool = True
print(sys.getsizeof(my_bool)) # 28
my_bool = False
print(sys.getsizeof(my_bool)) # 24

print(issubclass(bool, int)) # True
print(isinstance(True, bool)) # True
print(isinstance(False, bool)) # True

print(isinstance(1, bool)) # False
print(isinstance(0, bool)) # False

### --- Is vs. Equal --- ###
"""
- is and is not: memory (address) equality (Check if to "variables" are pointing to the same mem loc)
-- In python we just have names, which are pointers under the hood, that are pointing to a location in the memory
- == and !=: value equality
- Is: Identity operator (mempry adresses)
Value Equality: Operator to compare object values 
"""

my_bool = True
my_int = 1

print(my_bool == my_int) # True
# values are equal, bit names dont point at the same mem loc

print(my_bool is my_int) # False

print(my_bool is True) # True
print(my_bool is False) # False

### --- Boolean Evaluation --- ###
"""
Every object of a built-in type has Truth Value.
An instance is True ifg it is not: None, False, 0 or empty.
"""
def print_truth_value(var):
    print(bool(var))

value1 = None
value2 = 0
value3 = False
value4 = []

print_truth_value(value1) # False
print_truth_value(value2) # False
print_truth_value(value3) # False
print_truth_value(value4) # False

value5 = 1
value6 = True
value7 = [1]

print_truth_value(value5) # True
print_truth_value(value6) # True
print_truth_value(value7) # True

### --- Boolean Comparison --- ###
"""
Boolean operatros: and, or not
Comparison operators: <, >, <=, >=, ==, !=

Operator order:
1. ()
2. Comparison
3. not
4. and
5. or 
"""

a = True
b = False
c = True

check = a > b and c == a or not a and c
print(f"Check: {check}") # True

check2 = (a > b) and ((c == a) or (not a)) and c
print(f"Check2: {check2}") # True

### --- Boolean Shortcuts --- ###
A = True
B = False

def func_a(a):
    print("Called func_a")
    return a

def func_b(b):
    print("Called func_b")
    return b

if func_a(A) and func_b(B):
    print("func_a(A) and func_b(B) => True") # not executed

A = False
B = True
if func_a(A) and func_b(B):
    print("func_a(A) and func_b(B) => True") # not executed
    # func_b not even called, since first part of if is not fulfilled

if func_a(A) or func_b(B):
    print("func_a(A) or func_b(B) ") # executed
    # First part of if is true, which is sufficient. func_b not even called