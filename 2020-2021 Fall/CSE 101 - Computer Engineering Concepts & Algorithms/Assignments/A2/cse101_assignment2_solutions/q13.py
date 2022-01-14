mylist = [1, 2, 3, 56, 708, 501]
print("mylist=", mylist)
input_num = int(input("Enter a number which is not in the list= "))
check_num = 0
for i in range(len(mylist)):
    if input_num == mylist[i]:
        print(input_num, "in mylist", True)
        print(input_num, "not in mylist", False)
        check_num += 1
if check_num == 0:
    print(input_num, "in mylist", False)
    print(input_num, "not in mylist", True)