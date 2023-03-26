lst = []
x = int(input("Enter number of elements : "))
for i in range(0, x):
    ele = int(input("Enter number : "))
    lst.append(ele)
print("The list is:", lst)

list = []
y = int(input("Enter number of elements : "))
for z in range(0, y):
    ele1 = int(input("Enter number : "))
    list.append(ele1)
print("The other list is:", list)

# Nested list
list_size = int(input("Enter the number of sub list : "))
final_list = [[int(input("Enter number : ")) for _ in range(list_size)] for _ in range(list_size)]
print("List is", final_list)

# Length
def list_length(list):
    return len(list)
print("Length of first list : ",list_length(lst))
print("Length of second list : ",list_length(final_list))

# Concatenation
list_joined = lst + final_list
print("Concatenated list : ", list_joined)

# Membership
def overlapping(lst,list):
 
    c=0
    d=0
    for i in lst:
        c+=1
    for i in list:
        d+=1
    for i in range(0,c):
        for j in range(0,d):
            if(lst[i]==list[j]):
                return 1
    return 0
if(overlapping(lst, list)):
    print("Overlapping")
else:
    print("Not overlapping")

# Iteration
import itertools 
for (a, b) in itertools.zip_longest(lst, list):
    print ("Iteration", a, b)

# Indexing
for index, val in enumerate(list):
    print("The Index is", index, "for", val)

# Slicing
del list[:2]
print(list)
