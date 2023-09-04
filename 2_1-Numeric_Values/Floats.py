import sys
import math

### --- Floats --- ###
"""
- C, C++, Java etc.: Float (32bits/4byt) Double(62bits/8byte)
- Python: Float (64bits/8byte)
- sign: 1 bit
- exponent: 11 bits
- significant: 52 bits
"""

my_value = 42.000000000153
print(f"Size: {sys.getsizeof(my_value)}") # 8 bytes for the value, 16 for the rest

def float_print(value):
    print(f"{value:.32f}")

print(my_value) # 42.000000000153

float_print(my_value) # 42.00000000015300116729122237302363

# --- Float equality --- #
my_fraction = 1/100
float_print(my_fraction) # 0.01000000000000000020816681711722

my_fraction2 = 1/10 + 1/10 + 1/10
float_print(my_fraction2) # 0.30000000000000004440892098500626

my_fraction3 = 0.3
float_print(my_fraction3) # 0.29999999999999998889776975374843

def float_is_equal(x, y):
    epsilon = 1e-15
    difference = math.fabs(x - y)
    is_equal = difference < epsilon
    return is_equal

print(f"Is equal: {float_is_equal(my_fraction2, my_fraction3)}") # True
print(f"Is close: {math.isclose(my_fraction2, my_fraction3, abs_tol=1e-15, rel_tol=1e-9)}") # True

### --- Float rounding --- ###
my_float = 42.4242424242
float_print(my_float) # 42.42424242420000268793955910950899

my_float_rounded = round(my_float)
float_print(my_float_rounded) # 42.00000000000000000000000000000000

my_float_rounded2 = round(my_float, 4)
float_print(my_float_rounded2) # 42.42419999999999902229319559410214

my_float_rounded3 = round(my_float, -1) # -1 -> Nearest multiple of 10
float_print(my_float_rounded3) # 40.00000000000000000000000000000000

my_float_rounded4 = round(162.424242, -2) # -2 -> Nearest multiple of 100
float_print(my_float_rounded4) # 40.00000000000000000000000000000000
