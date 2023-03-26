rows = int(input("Enter the Number of rows: " ))
column = int(input("Enter the Number of Columns: "))

print("Enter the elements of the Matrix:")
matrix_a= [[int(input()) for i in range(column)] for i in range(rows)]
print("The Matrix is: ")
for n in matrix_a:
    print(n)


result=[[0 for i in range(column)] for i in range(rows)]

for i in range(rows):
    for j in range(column):
        result[i][j] = matrix_a[j][i]
print("The Transpose of the Matrix is: ")
for r in result:
    print(r)