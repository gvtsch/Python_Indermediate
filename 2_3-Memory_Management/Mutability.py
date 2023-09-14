import random
random.seed(42)

def print_memory_address(var):
    print(hex(id(var)))

### --- Mutability --- ###
"""
Immutable types: int, float, bool, str, tuple, None
Mutable types: list, dict, set, ..."""

my_int = 42
print_memory_address(my_int)
my_int = 22
print_memory_address(my_int)

my_list = [1, 2, 3]
print(my_list)
print_memory_address(my_list)

my_list[0] = -1
print_memory_address(my_list)

"""When you change a mutable type, then no new python object is created. The allready
existing object is modified."""

my_list.append(4)
print_memory_address(my_list)

my_tuple = (1, 2, 3)
print(my_tuple)
print_memory_address(my_tuple)

my_tuple = (-1, my_tuple[1], my_tuple[2])
print(my_tuple) # Tuples are immutable, therefore a new object is created