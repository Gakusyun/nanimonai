a = input()
b = input()
c = input()
if a < b:
    a, b = b, a
if b < c:
    b, c = c, b
if a < b:
    a, b = b, a
print("{},{},{}".format(a, b, c))

