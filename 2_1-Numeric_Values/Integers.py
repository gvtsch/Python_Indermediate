import sys
import math

### --- Integers --- ###
# Java / C/C++: Int 32bit/4Byte
# Python uses a variable num of bits

my_value = 42
print("Integer size: ", sys.getsizeof(my_value)) #28
my_value = 0
print("Integer size: ", sys.getsizeof(my_value)) #24
my_value = 2**64
print("Integer size: ", sys.getsizeof(my_value)) # 36

# No Integer Overflow possible until it was so big, it would take up alle the RAM


### --- Arithmetic Operations --- ###
# int/int -> float

result = 10 + 5
print("Result: ", result, " Type: ", type(result)) # int
result = 10 - 5
print("Result: ", result, " Type: ", type(result)) # int
result = 10 * 5
print("Result: ", result, " Type: ", type(result)) # int
result = 10 / 5
print("Result: ", result, " Type: ", type(result)) # float
result = 10 // 3 # Integer devision
print("Result: ", result, " Type: ", type(result)) # Int

# Float -> Int
my_float = -2.7
print(my_float) # -2.7
my_int = int(my_float) 
print(my_int) # -2

# --- Rounding --- #
my_float2 = 2.7
print(my_float2)
my_int2 = math.floor(my_float2) # 2
print(my_int2)
my_int3 = math.ceil(my_float2) # 3
print(my_int3)

my_float3 = -2.7
print(my_float3)
my_int3 = math.floor(my_float3) # -3
print(my_int3)
my_int3 = math.ceil(my_float3) # -2
print(my_int3)

# --- Integer Bases --- #
# decimal: base 10
# binary: base 2
# hex: base 16

my_decimal = int("42", base = 10)
print("Value: ", my_decimal) # 42

my_hexadecimal = int("42", base = 16)
print("Value: ", my_hexadecimal) # 66

my_binary = int("101010", base = 2)
print("Value: ", my_binary) # 42

my_binary2 = int("0b101010", base = 0)
print("Value: ",  my_binary2) #42

my_binary3 = 0b101010
print("Value: ", my_binary3) #42

