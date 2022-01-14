import random
A = []
for i in range(50):
    N = random.randint(0, 100)
    A.append(N)

#A=[9, 38, 44, 12, 97, 7, 60, 69, 49, 40, 18, 94, 20, 94, 91, 70, 78, 11, 0, 41, 62, 93, 61, 40, 50, 59, 44, 57, 65, 16, 64, 39, 55, 27, 43, 69, 70, 94, 85, 43, 45, 57, 89, 8, 62, 3, 8, 23, 86, 94]
numbers_count = []
result = 0
A.sort()
duplicate_numbers = []
for i in range(len(A)):
    current_num_counter = A.count(A[i])
    if current_num_counter > 1:
        if A[i] not in duplicate_numbers:
            duplicate_numbers.append(A[i])
print("A=",A)
print("There are",len(duplicate_numbers), "duplicate numbers")
