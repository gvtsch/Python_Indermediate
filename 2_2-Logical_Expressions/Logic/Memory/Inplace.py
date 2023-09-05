import copy

def print_memory_address(var):
    print(hex(id(var) % 0xFFFF))
          
####### In-Place Functions #######
#######  Immutable Types   #######
my_number = 10
increment = 2
print_memory_address(my_number)
my_number = my_number + increment
print_memory_address(my_number)
print(my_number)


my_number2 = 10
increment2 = 2
print_memory_address(my_number2)
my_number2 += increment2
print_memory_address(my_number2)
print(my_number)

###### Mutable Types (but not In-Place)
def inc_list(lst, inc_value):
    for value in lst:
        value = value + inc_value
    return lst

my_list = [1, 2, 3]
increment = 2

print_memory_address(my_list)
my_list = inc_list(my_list, increment)
print_memory_address(my_list)

print(f"My_list after incrementing: {my_list}")
""" Mem add before and after are the same. But the values didn't change/increment. 
"""

def inc_list(lst, inc_value):
    for idx in range(len(lst)):
        lst[idx] = lst[idx] + inc_value

my_list2 = [1, 2, 3]
increment2 = 2

print_memory_address(my_list2)
print_memory_address(my_list2[0])
inc_list(my_list2, increment2)
print_memory_address(my_list2)
print_memory_address(my_list2[0])
print(my_list2)

###
print("----- Concat two lists -----")
def concat_lists(l1, l2):
    return l1 + l2

l1 = [1, 2]
l2 = [3, 4]

print_memory_address(l1)
print_memory_address(l2)
print(l1)
l1 = concat_lists(l1, l2)
print(l1)
print_memory_address(l1)
print_memory_address(l2)

####### In-Place on Mutable Types ######
""" For immutable types there are no inplace operations at all """
print("----- Inplace on mutable types -----")
def concat_lists_inplace(l1, l2):
    l1 += l2 # += is an inplace operation

l3 = [1, 2]
l4 = [3, 4]

print_memory_address(l3)
print_memory_address(l4)
print(l3)
concat_lists_inplace(l3, l4)
print(l3)
print_memory_address(l3)
print_memory_address(l4)
""" The above adresses still are the same. Due to the inplace operation, they
are still the same object. """

##### Shallow and Deep Copy #####
print("-----Shallow Copy-----")
""" If we want two variables with the same content, but pointing to completly
different mem adresses, than we need a copy. """
list1 = [[1, 2], [3, 4]]
print_memory_address(list1)
print_memory_address(list1[0])
print_memory_address(list1[0][0])
print(list1)

list1[0][0] = 10
print_memory_address(list1)
print_memory_address(list1[0])
print_memory_address(list1[0][0])
print(list1)
""" All entries but [0][0] are pointing to the same adresses like before. """

list1[0] = [-1, -2]
print_memory_address(list1)
print_memory_address(list1[0])
print(list1)

print("----- Copy -----")
list2 = copy.copy(list1)
print_memory_address(list1)
print_memory_address(list2)
print_memory_address(list1[0])
print_memory_address(list2[0])
print(list2)
""" The entries have the same memory adresses / values. 
The lists themselves have differing adresses. """

""" Making a change in list2 will also make a change in list 1: """
list2[0][0] = 10
print_memory_address(list2)
print_memory_address(list2[0])
print(list2)

print_memory_address(list1)
print_memory_address(list1[0])
print(list1)

print("----- Deep copy -----")
""" if you want complete new adresses / values """
list3 = copy.deepcopy(list1)
print_memory_address(list1)
print_memory_address(list3)
print_memory_address(list1[0])
print_memory_address(list3[0])

list3[0][0] = -10
print_memory_address(list3)
print_memory_address(list3[0])
print(list3)
print_memory_address(list1)
print_memory_address(list1[0])
print(list1)
""" Now the change in list3 does not forward to list1 """