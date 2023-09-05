import random
random.seed(42)

def print_memory_address(var):
    print(hex(id(var)))

### --- Variable Memory Reference --- ###
my_value = 10
print_memory_address(my_value)

my_value2 = 12
print_memory_address(my_value2)

my_int1 = 42
my_int2 = 42
my_int3 = 42

print_memory_address(my_int1)
print_memory_address(my_int2)
print_memory_address(my_int3)

my_bool1 = True
my_bool2 = True
my_bool3 = False
my_bool4 = False

print_memory_address(my_bool1)
print_memory_address(my_bool2)
print_memory_address(my_bool3)
print_memory_address(my_bool4)

my_float1 = 42.0
my_float2 = 42.0
my_float3 = 42.0

print_memory_address(my_float1)
print_memory_address(my_float2)
print_memory_address(my_float3)

"""Primitive datatypes which are immutable and point to the same location, 
if the value is the same:
- Int
- Bool 
- None"""

my_None1 = None
my_None2 = None

print_memory_address(my_None1)
print_memory_address(my_None2)

my_list1 = [1, 2, 3]
my_list2 = my_list1
my_list3 = [1, 2, 3]

print_memory_address(my_list1)
print_memory_address(my_list2)
print_memory_address(my_list3)

my_list1[0] = -1
print_memory_address(my_list1)
print_memory_address(my_list2)