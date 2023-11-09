import random

list = []
while len(list) < 20:
    temp = random.randint(1, 33)
    if temp in list:
        continue
    else:
        list.append(temp)
for i in list:
    print(i, end="\t")
