a = int(input("Please write an integer: "))
b = int(input("Please write an other integer: "))
def o_assign(v1, v2):
    v1=v2
    return v1
def o_add(v1, v2):
    v1+=v2
    return v1
def o_subtract(v1, v2):
    v1-=v2
    return v1
def o_multiply(v1, v2):
    v1*=v2
    return v1
def o_divide(v1, v2):
    v1/=v2
    return v1
def o_modules(v1, v2):
    v1%=v2
    return v1
def o_fdivide(v1, v2):
    v1//=v2
    return v1
print("After a=b", "a=", o_assign(a,b))
print("After a+=b", "a=", o_add(a,b))
print("After a-=b", "a=", o_subtract(a,b))
print("After a*=b", "a=", o_multiply(a,b))
print("After a/=b", "a=", o_divide(a,b))
print("After a%=b", "a=", o_modules(a,b))
print("After a//=b", "a=", o_fdivide(a,b))