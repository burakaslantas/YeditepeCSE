a = int(input("Enter an integer. a= "))
b = int(input("Enter an integer. b= "))
c = int(input("Enter an integer. c= "))

print("a>b is", a>b)
print("b==c is", b==c)
print("b!=c is", b!=c)
print("((a>b) and (b==c)) is", ((a>b) and (b==c)))
print("((a>b) or (b==c)) is", ((a>b) or (b==c)))
#IMPORTANT NOTE: Output of line 9 is "True" in tutorial pdf
#I think, this is a mistake, it should be "False".
print("The reverse logical state of b!=c is", not(b!=c))