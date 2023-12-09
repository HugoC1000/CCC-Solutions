n = int(input())
counter = 0

liste = []
liste.append(input())
liste.append(input())
o = liste[0]
r = liste[1]
for i in range(n):
    if r[i]==o[i] and r[i] == "C":
        counter +=1
print(counter)


