def one_dimentional_list(n):
    for i in range(len(n)):
        n[i] = int(n[i])
    return n

def two_dimentional_list(row, colomn, list):
    temp_row = []
    for i in range(row):
        temp_colomn = []
        for j in range(colomn):
            temp_colomn.append(list[colomn * i + j])
        temp_row.append(temp_colomn)
    return temp_row

def matrix_print(row, colomn, list):
    for i in range(row):
        for j in range(colomn):
            print(list[colomn * i + j], end=" ")
        print()

def result_temp(n, p):
    result_zero_list = []
    for i in range(n*p):
        result_zero_list.append(0)
    c = two_dimentional_list(n, p, result_zero_list)
    return c

def matrix_product(listA, listB):
    result = result_temp(n, p)
    for i in range(len(listA)):
        for j in range(len(listB[0])):
            for k in range(len(listB)):
                result[i][j] += listA[i][k] * listB[k][j]
    return result


n = int(input())
m = int(input())
p = int(input())

#A = input("Entries of matrix A :")
A = (input("Entries of matrix A :")).split(" ")
print("Matrix A")
matrix_print(n, m, one_dimentional_list(A))
A_two_dimentional = two_dimentional_list(n, m, one_dimentional_list(A))

#B = input("Entries of matrix B :")
B = (input("Entries of matrix B :")).split(" ")
print("Matrix B")
matrix_print(m, p, one_dimentional_list(B))
B_two_dimentional = two_dimentional_list(m, p, one_dimentional_list(B))

mproduct_list = matrix_product(A_two_dimentional, B_two_dimentional)
print("Matrix Product")
for i in range(len(mproduct_list)):
    for j in range(len(mproduct_list[0])):
        print(mproduct_list[i][j], end=" ")
    print()
result_temp(n, p)
